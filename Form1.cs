using NvAPIWrapper.GPU;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Management;
using System.Net.NetworkInformation;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Arduino_System_Stats
{
    public partial class Form1 : Form
    {
        private int cpuUsage;
        private Timer timer1;
        string selectedPort;
        SerialPort port;
        String[] ports;
        int ite = 0;
        double network;
        private double _tempnetwork;
        private string _avaiableRam;
        private string finalTotalRam;
        private string finalAvailRam;
        private string finalPercentUsedRam;
        private static GPUThermalSensor[] tamerelapute;
        private static string finalGPUTemp;
        private static string zebilamoule;
        private static string finalGPUSage;

        public Form1()
        {
            InitializeComponent();
            
            InitPorts();
        }

        private void InitPorts()
        {
            ports = SerialPort.GetPortNames();
  
            // TODO not working


            foreach (string port in ports)
            {
                listPort.Items.Add(port);

                if (ports[0] != null)
                {
                    listPort.SelectedItem = ports[0];
                }
            }
        }

        private void StartTimer()
        {
            timer1 = new Timer();
            timer1.Tick += new EventHandler(Timer1_Tick);
            timer1.Interval = 700; // in miliseconds
            timer1.Start();
        }
        private async void Timer1_Tick(object sender, EventArgs e)
        {
            await Task.Run(() =>
            {
                System.Globalization.CultureInfo customCulture = (System.Globalization.CultureInfo)System.Threading.Thread.CurrentThread.CurrentCulture.Clone();
                customCulture.NumberFormat.NumberDecimalSeparator = ".";
                System.Threading.Thread.CurrentThread.CurrentCulture = customCulture;

                PrintGPUSensors();
                GetCurrentCpuUsage();
                getAvailableRAM();
                ite++;
                
                string cardname = printNetworkCards();
                if (ite > 5)
                {
                    ite = 0;
                    try
                    {
                        Debug.WriteLine("SENDING NET USAGE RESETTING ITE : ", ite.ToString());
                            network = getNetworkUtilization(cardname);
                        _tempnetwork = network;
                    }
                    catch
                    {

                    }
                }
                SendSystemValuesToArd(cpuUsage, _tempnetwork, finalPercentUsedRam);
                cpuUsage = 0;
            });
        }

        public void GetCurrentCpuUsage()
        {
            ManagementObjectSearcher searcher = new ManagementObjectSearcher("select * from Win32_PerfFormattedData_PerfOS_Processor");
            foreach (ManagementObject obj in searcher.Get())
            {
                var usage = obj["PercentProcessorTime"];
                int usageToInt = Convert.ToInt32(usage);
                var name = obj["Name"];
                string nameString = name.ToString();

                if (nameString.Contains("Total") == true)
                {
                    cpuUsage = usageToInt;
                }
            }
        }

        public void getAvailableRAM()
        {
            PerformanceCounter ramCounter;
            ramCounter = new PerformanceCounter("Memory", "Available MBytes");
            _avaiableRam = ramCounter.NextValue().ToString();

            ObjectQuery wql = new ObjectQuery("SELECT * FROM Win32_OperatingSystem");
            ManagementObjectSearcher searcher = new ManagementObjectSearcher(wql);
            ManagementObjectCollection results = searcher.Get();

            double res;
            foreach (ManagementObject result in results)
            {
                res = Convert.ToDouble(result["TotalVisibleMemorySize"]);
                double _totalRamInGB = res / 1024 ;
                int totalraminted =  Convert.ToInt32(_totalRamInGB);
               
                //    Debug.WriteLine("Total usable memory size: " + res + "KB");
                long calcun = Convert.ToInt32(_avaiableRam) * 100;
                long percentram = calcun / totalraminted;
                finalTotalRam = totalraminted.ToString();
                finalAvailRam = _avaiableRam.ToString();
                finalPercentUsedRam = percentram.ToString();
                Debug.WriteLine("finalTotalRam : " + finalTotalRam + "  " + "  finalAvailRam : " + finalAvailRam + "  " + "FinalPERCENT  : " + finalPercentUsedRam);
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            ManagementObjectSearcher searcher = new ManagementObjectSearcher("select * from Win32_PerfFormattedData_PerfOS_Processor");
            foreach (ManagementObject obj in searcher.Get())
            {
                var usage = obj["PercentProcessorTime"];
                int usageToInt = Convert.ToInt32(usage);
                var name = obj["Name"];
                string nameString = name.ToString();
             
                if (nameString.Contains("Total") == true)
                {
                    cpuUsage = usageToInt;
                   // Debug.WriteLine("From Management" + name + " : " + usage);
                }
            }
            GetCurrentCpuUsage();
            printNetworkCards();

        }



        public double getNetworkUtilization(string networkCard)
        {
            string first25 = "";
            double netconverted = 0;
            const int numberOfIterations = 200;

            PerformanceCounter bandwidthCounter = new PerformanceCounter("Network Interface", "Current Bandwidth", networkCard);
            float bandwidth = bandwidthCounter.NextValue();//valor fixo 10Mb/100Mn/

            PerformanceCounter dataSentCounter = new PerformanceCounter("Network Interface", "Bytes Sent/sec", networkCard);

            PerformanceCounter dataReceivedCounter = new PerformanceCounter("Network Interface", "Bytes Received/sec", networkCard);

            System.Globalization.CultureInfo customCulture = (System.Globalization.CultureInfo)System.Threading.Thread.CurrentThread.CurrentCulture.Clone();
            customCulture.NumberFormat.NumberDecimalSeparator = ".";

            System.Threading.Thread.CurrentThread.CurrentCulture = customCulture;

            float sendSum = 0;
            float receiveSum = 0;

            for (int index = 0; index < numberOfIterations; index++)
            {
               // System.Threading.Thread.Sleep(100);
                sendSum += dataSentCounter.NextValue();
                receiveSum += dataReceivedCounter.NextValue();
            }
            float dataSent = sendSum;
            float dataReceived = receiveSum;

            double utilization = (8 * (dataSent + dataReceived)) / (bandwidth * numberOfIterations) * 100;
            double _moctets = utilization * 0.125;
            double _decaldot = _moctets * 10;
            string _tempUtil = _decaldot.ToString();
            try { 
                first25 = _tempUtil.Remove(5);
                 
            }
            catch { }

            netconverted = Convert.ToDouble(first25);
            Debug.WriteLine("utilization : " + utilization + "_moctets : " + _moctets);
            return netconverted;
        }


        public string printNetworkCards()
        {
            PerformanceCounterCategory category = new PerformanceCounterCategory("Network Interface");
            String[] instancename = category.GetInstanceNames();
            string cardname = null;
            foreach (string name in instancename)
            {
                cardname = name;
               // Debug.WriteLine(name);
            }
            
            return cardname;
        }
        private void DrawCpuBar(int cpu)
        {
           // Refresh();
            int formWidth = this.Width;
            int formCalculus = formWidth / 100;
            int cpuDynamicValue = formCalculus * cpu;
            Debug.WriteLine("Form Width : " + formWidth);
            SolidBrush myBrush = new SolidBrush(Color.Red);
            Graphics formGraphics;
            
            formGraphics = this.CreateGraphics();
            formGraphics.Clear(SystemColors.GrayText);
            formGraphics.FillRectangle(myBrush, new Rectangle(0, 0, cpuDynamicValue, 30));
            
            myBrush.Dispose();
            
            
            formGraphics.Dispose();
        }

        private static void PrintGPUSensors()
        {
           // NVIDIA.Initialize();

            var test = PhysicalGPU.GetPhysicalGPUs();
         
            PhysicalGPU.GetPhysicalGPUs();
             tamerelapute = test[0].ThermalInformation.ThermalSensors.ToArray();
            string _arraytemp = tamerelapute[0].ToString();

            string parseGPUTemp = _arraytemp.Substring(_arraytemp.IndexOf(":") + 2);
            finalGPUTemp = parseGPUTemp.Substring(0, parseGPUTemp.IndexOf("°"));

            zebilamoule = test[0].UsageInformation.GPU.ToString();
            string parseGPUsage = zebilamoule.Substring(zebilamoule.IndexOf(" ") + 1);
            finalGPUSage = parseGPUsage.Remove(parseGPUsage.Length - 1);
            Debug.WriteLine(finalGPUTemp);
            Debug.WriteLine(finalGPUSage);
        }

        private void btn_connect_Click(object sender, EventArgs e)
        {
            port = new SerialPort(selectedPort, 9600, Parity.None, 8, StopBits.One);
            port.Open();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            selectedPort = listPort.GetItemText(listPort.SelectedItem);
        }
        private void SendSystemValuesToArd(int cpuvalue, double network, string rampercentavaiable)
        {
            string chain = ("CCPU:"+ cpuvalue.ToString() + "|" + "RAM:" + rampercentavaiable + "|" + "NET:" + network + "|" + "GPUU:" + finalGPUSage + "|" + "GPUT:" + finalGPUTemp);
            port.WriteLine(chain);
            Debug.WriteLine(chain);

        }

       
        private void BtnSendValues_Click(object sender, EventArgs e)
        {
            StartTimer();
        }

        public Process getHighProcess()
        {
            const int delay = 500;
            Process[] processes = Process.GetProcesses();

            var counters = new List<PerformanceCounter>();

            foreach (Process process in processes)
            {
                var counter = new PerformanceCounter("Process", "% Processor Time", process.ProcessName);
                counter.NextValue();
                counters.Add(counter);
            }
            System.Threading.Thread.Sleep(delay);
            //You must wait(ms) to ensure that the current
            //application process does not have MAX CPU
            int mxproc = -1;
            double mxcpu = double.MinValue, tmpcpu;
            for (int ik = 0; ik < counters.Count; ik++)
            {
                tmpcpu = Math.Round(counters[ik].NextValue(), 1);
                if (tmpcpu > mxcpu)
                {
                    mxcpu = tmpcpu;
                    mxproc = ik;
                }

            }
            return processes[mxproc];
        }

        public void processtest()
        {
            Process[] processlist = Process.GetProcesses();
            //require elevated
            foreach (Process theprocess in processlist)
            {
                Debug.WriteLine("Process: {0} ID: {0} TIME : {0}", theprocess.ProcessName, theprocess.Id, theprocess.UserProcessorTime);
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {

            
        }

        private void networkusetest()
        {
            NetworkInterface[] interfaces = NetworkInterface.GetAllNetworkInterfaces();

            foreach (NetworkInterface ni in interfaces)
            {
                if (ni.NetworkInterfaceType.ToString().ToLower() == "ethernet")
                {
                /*    MessageBox.Show(ni.GetIPv4Statistics().BytesSent.ToString());
                    MessageBox.Show(ni.GetIPv4Statistics().BytesReceived.ToString());
                    MessageBox.Show(ni.GetIPv4Statistics().IncomingPacketsDiscarded.ToString());
                    MessageBox.Show(ni.GetIPv4Statistics().IncomingPacketsWithErrors.ToString());
                    MessageBox.Show(ni.GetIPv4Statistics().IncomingUnknownProtocolPackets.ToString());
                    MessageBox.Show(ni.GetIPv4Statistics().NonUnicastPacketsReceived.ToString());*/
                 //   Debug.WriteLine(ni.GetIPv4Statistics().BytesReceived.ToString());
                   // Debug.WriteLine("UNICAST " + ni.GetIPv4Statistics().NonUnicastPacketsReceived.ToString());
                }
            }
        }

        private void gpugpu_Click(object sender, EventArgs e)
        {
            PrintGPUSensors();
        }
    }
}

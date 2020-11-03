// https://oleddisplay.squix.ch/#/home
// https://github.com/ImpulseAdventure/GUIslice-Builder/releases
//320*240
#include <UTFT.h>

// Declare which fonts we will be using
//extern uint8_t Roboto_Mono_Thin_65[];
extern unsigned short finaldisco[6400];
extern unsigned short cpu[2500];
extern unsigned short ramicon[2500];
extern unsigned short netusagebitmap[2500];
extern unsigned short gpubitmap[4880];
extern unsigned short celicon[900];
extern unsigned short usedrambitmap[5380];

extern uint8_t Roboto64x96Num[];

extern uint8_t franklingothic_normal[];
extern uint8_t arial_bold[];

extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t SevenSegNumFont[];
extern uint8_t AraMedDigits[];
String lVisit = "";
bool _hpstats = false;
String inString = "";
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String commandString = "";
int cpuDynamicValuePlus = 0;
int ramDynamicValuePlus = 0;
double screenWidth = 269;
double gpubarWidth = 192;
double formCalculus;
double formCalculusGpu;
int formCalculusRam;
int cpuDynamicValue;
int ramDynamicValue;
int gpuDynamicValue;

String subtest = "";
String subram = "";
String subnet = "";
String subgpuu = "";
String subgput = "";
int ramfinal = 0;
double netfinal = 0;
int totalRam = 0;
int gpuufinal = 0;
int gputfinal = 0;
unsigned long avaiableRam = 0;
int percentram = 0;

// Set the pins to the correct ones for your development shield
// ------------------------------------------------------------
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41
// CTE TFT LCD/SD Shield for Arduino Due       : <display model>,25,26,27,28
// Teensy 3.x TFT Test Board                   : <display model>,23,22, 3, 4
// ElecHouse TFT LCD/SD Shield for Arduino Due : <display model>,22,23,31,33
//
// Remember to change the model parameter to suit your display module!
UTFT myGLCD(ILI9341_16,38,39,40,41);

String  incomingByte;
void setup()
{
  Serial.begin(9600);
  myGLCD.InitLCD();
  myGLCD.clrScr();

  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);

  DrawBitmaps();
}

void loop()
{

  // delay(1000);                    
  myGLCD.setColor(0, 255, 0);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setFont(BigFont);

  // Read serial input:
  while (Serial.available() > 0) {
    int inChar = Serial.read();
    String GoodString = Serial.readStringUntil('\n');
    ParseAllData(GoodString);
    GoodString = "";

    Serial.print("GoodString : " + GoodString);
    if (isDigit(inChar)) {

      // convert the incoming byte to a char and add it to the string:
      inString += (char)inChar;
    }
    

  }
}
void DrawNet (double netusage) {

  String netreceived =  String(netusage);
  //  myGLCD.setColor(0, 0, 255); // set color of clean bg
  //  myGLCD.fillRect(0,200,110,100); // cleaner reactangle

  myGLCD.setFont(franklingothic_normal);
  myGLCD.setBackColor(0, 0, 255);
  myGLCD.setColor(255, 255, 255);

  myGLCD.print(netreceived , 10, 175);
}

void DrawGpTemp(int gpTemp) {
  myGLCD.setFont(AraMedDigits);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  String boby = String(gpTemp);
  myGLCD.print(boby ,190, 160);
}

void DrawGpUsage(int gpUsage) {
  myGLCD.setColor(0, 0,0); // set color of clean bg
  myGLCD.fillRect(113,207,305,225);

  formCalculusGpu = gpubarWidth / 100;
  gpuDynamicValue = formCalculusGpu * gpUsage;
  int test = gpuDynamicValue + 113;
  myGLCD.setColor(200, 20,20); // set color of clean bg
  myGLCD.setColor(200, 20,20); // set color of clean bg
  myGLCD.fillRect(113,207,test,225); // from 113 to 305
}

void DrawCpuBar(int cpuValue) {
  delay(30); 
  myGLCD.setColor(0, 0, 0); // set color of clean bg
  myGLCD.fillRect(50,0,319,50); // cleaner reactangle
  formCalculus = screenWidth / 100;
  cpuDynamicValue = formCalculus * cpuValue;
  cpuDynamicValuePlus = cpuDynamicValue + 50;

  myGLCD.setColor(200, 20,20); // set color of clean bg

  myGLCD.fillRect(50,15,cpuDynamicValuePlus,35); // bg clean the three dots // x1, y1, x2, y2
}

void DrawRam(int ramValue)
{
  formCalculusRam = screenWidth / 100;
  ramDynamicValue = formCalculus * ramValue;
  ramDynamicValuePlus = ramDynamicValue + 50;
  myGLCD.drawBitmap(50, 65, 269, 21, usedrambitmap);
  
  myGLCD.setColor(0, 0, 0);     
  myGLCD.fillRect(315,65,319,85);
  myGLCD.setColor(0, 200,20); // set color of clean bg
  myGLCD.fillRect(50,65,ramDynamicValuePlus,85); // bg clean the three dots // x1, y1, x2, y2
  myGLCD.setColor(0, 0, 0);  
  myGLCD.fillRect(310,65,319,85);
}

void ParseAllData(String chain) {
  // Example of received chain : 
  // "CPU:67|RAM:26|NET:0.246|GPUU:1|GPUT:48" percent, percent, value, percent, value
  subram = "";
  subtest = "";
  subnet = "";
  subgpuu = "";
  subgput = "";
  int cpuindex = chain.indexOf(":", +1);
  int cpubar = chain.indexOf("|");
  int ramindex = chain.indexOf(":", cpuindex+2);
  int rambar = chain.indexOf("|",cpubar+2);
  int netindex = chain.indexOf(":", ramindex+1);
  int netbar = chain.indexOf("|",rambar+1);
  int gpuuindex = chain.indexOf(":", netindex+1);
  int gpuubar = chain.indexOf("|",netbar+1);
  int gputindex = chain.indexOf(":", gpuuindex+1);
  int gputbar = chain.indexOf("|",gpuubar+1);
  subram = chain.substring(ramindex+1,rambar);

  //Serial.println(ramindex);
  subtest = chain.substring(cpuindex+1,cpubar);
  subnet = chain.substring(netindex+1,netbar);
  subgpuu = chain.substring(gpuuindex+1,gpuubar);
  subgput = chain.substring(gputindex+1,gputbar);
  Serial.println(gpuuindex);
  Serial.println(netbar);
  Serial.println("CPU : " + subtest);
  Serial.println("RAM : " + subram);
  Serial.println("NET : " + subnet);
  Serial.println("GPU USAGE : " + subgpuu);
  Serial.println("GPU TEMP : " + subgput);
  ramfinal = subram.toInt();
  netfinal = subnet.toDouble(); 
  gpuufinal = subgpuu.toInt();
  gputfinal = subgput.toInt();
  if (gputfinal > 99)
  {
    gputfinal = 00;
  }

  DrawCpuBar(subtest.toInt());
  DrawRam(ramfinal);
  DrawNet(netfinal);
  DrawGpUsage(gpuufinal);
  DrawGpTemp(gputfinal);
}

void DrawBitmaps() {
  // drawgrid
  myGLCD.setColor(30, 30,30); // set color of clean bg
  myGLCD.fillRect(0,100,319,103); // bg clean the three dots // x1, y1, x2, y2
  myGLCD.fillRect(92,100,95,239); // bg clean the three dots // x1, y1, x2, y2
  //

  //CPU + RAM
  myGLCD.setColor(0, 0, 255);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.drawBitmap(0, 0, 50, 50, cpu);
  myGLCD.drawBitmap(0, 50, 50, 50, ramicon);

  //GPU AREA
  myGLCD.drawBitmap(130, 130, 61, 80, gpubitmap);
  myGLCD.drawBitmap(240, 130, 30, 30, celicon);
  myGLCD.setColor(30, 30,30); // set color of clean bg
  myGLCD.fillRect(110,200,118,233); // left gpu percent bar
  myGLCD.fillRect(300,200,308,233); // left gpu percent bar

  //netusage region
  //  myGLCD.fillRoundRect(
  myGLCD.drawBitmap(25, 120, 50, 50, netusagebitmap);
  myGLCD.setBackColor(0, 0, 0);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setFont(SmallFont);
  myGLCD.print("MO/s" , 20, 200);
}

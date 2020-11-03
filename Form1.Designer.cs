namespace Arduino_System_Stats
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btn_connect = new System.Windows.Forms.Button();
            this.listPort = new System.Windows.Forms.ComboBox();
            this.BtnSendValues = new System.Windows.Forms.Button();
            this.getprocess = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btn_connect
            // 
            this.btn_connect.Location = new System.Drawing.Point(139, 75);
            this.btn_connect.Name = "btn_connect";
            this.btn_connect.Size = new System.Drawing.Size(110, 23);
            this.btn_connect.TabIndex = 4;
            this.btn_connect.Text = "Connect";
            this.btn_connect.UseVisualStyleBackColor = true;
            this.btn_connect.Click += new System.EventHandler(this.btn_connect_Click);
            // 
            // listPort
            // 
            this.listPort.FormattingEnabled = true;
            this.listPort.Location = new System.Drawing.Point(12, 75);
            this.listPort.Name = "listPort";
            this.listPort.Size = new System.Drawing.Size(121, 23);
            this.listPort.TabIndex = 5;
            this.listPort.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // BtnSendValues
            // 
            this.BtnSendValues.Location = new System.Drawing.Point(139, 12);
            this.BtnSendValues.Name = "BtnSendValues";
            this.BtnSendValues.Size = new System.Drawing.Size(110, 23);
            this.BtnSendValues.TabIndex = 6;
            this.BtnSendValues.Text = "Send values";
            this.BtnSendValues.UseVisualStyleBackColor = true;
            this.BtnSendValues.Click += new System.EventHandler(this.BtnSendValues_Click);
            // 
            // getprocess
            // 
            this.getprocess.Location = new System.Drawing.Point(12, 12);
            this.getprocess.Name = "getprocess";
            this.getprocess.Size = new System.Drawing.Size(75, 23);
            this.getprocess.TabIndex = 7;
            this.getprocess.Text = "getprocess";
            this.getprocess.UseVisualStyleBackColor = true;
            this.getprocess.Click += new System.EventHandler(this.button2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(270, 122);
            this.Controls.Add(this.getprocess);
            this.Controls.Add(this.BtnSendValues);
            this.Controls.Add(this.listPort);
            this.Controls.Add(this.btn_connect);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button btn_connect;
        private System.Windows.Forms.ComboBox listPort;
        private System.Windows.Forms.Button BtnSendValues;
        private System.Windows.Forms.Button getprocess;
    }
}


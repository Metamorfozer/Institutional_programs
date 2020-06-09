using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace z1forms
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            float x, y;
            x = Convert.ToSingle(textBoxX.Text);
            y = Convert.ToSingle(textBoxY.Text);
            double z1 = Math.Cos(x) * Math.Cos(x) * Math.Cos(x) * Math.Cos(x) + Math.Sin(y) * Math.Sin(y) + 1.0 / 4.0 * Math.Sin(2 * x) * Math.Sin(2 * x) - 1;
            double z2 = Math.Sin(y + x) * Math.Cos(y - x);
            label1.Text = z1.ToString();
            label2.Text = z2.ToString();
            //Console.WriteLine("\nz1 = {0}\nz2 = {1}", z1, z2);

        }

    }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Timers;

namespace Calculate
{
    public partial class fCalc : Form
    {
        
        public fCalc()
        {
            InitializeComponent();
        }

        // Новая операция
        bool NewOp = true;
        // начальное положение операции
        int op = -1;
        double a = 0, b = 0, c = 0;

        private void tb_Calc_KeyPress(object sender, KeyPressEventArgs e)
        {
            // если нажата одна из клавиш
            if (e.KeyChar == ((char)Keys.Back) || e.KeyChar == '.' || e.KeyChar == ',' || e.KeyChar >= '0' && e.KeyChar <= '9')
            {
                // Если новая операция True
                if (NewOp)
                {
                    // Стираем текст
                    tb_Calc.Text = "";
                    // Присваеваем False
                    NewOp = false;
                }
                // Если нажата точка, заменяем её запятой
                if (e.KeyChar == '.') e.KeyChar = ',';
                // Если уже нажата запятая, запрещяем ввод второй
                if (e.KeyChar == ',' && tb_Calc.Text.IndexOf(',') > -1) e.Handled = true;
                // Если уже нажат ноль, запрещяем ввод второго
                if (e.KeyChar == '0' && tb_Calc.Text == "0") e.Handled = true;
                // Если уже нажат ноль и после введено число, отчищаем
                if (tb_Calc.Text == "0" && e.KeyChar >= '1' && e.KeyChar <= '9') tb_Calc.Text = "";
            }
            else e.Handled = true;
        }

        private void bNum1_Click(object sender, EventArgs e)
        {
            // Если новая операция или введен ноль
            if (NewOp == true || tb_Calc.Text == "0")
            {
                //Вставляем ноль из кнопки
                tb_Calc.Text = (sender as Button).Text;
                // Выключаем новую операцию
                NewOp = false;
            }
            // Иначе прибавляем текст в textBox
            else tb_Calc.Text += (sender as Button).Text;
        }

        private void bClear_Click(object sender, EventArgs e)
        {
            // Ставим начальное положение
            op = -1;
            tb_Calc.Text =  "0";
            NewOp = true;
        }

        private void bPoint_Click(object sender, EventArgs e)
        {
            if(NewOp)
            {
                tb_Calc.Text = "0";
                NewOp = false;
            }
            // Если запятая
            if (tb_Calc.Text.IndexOf(",") == -1) tb_Calc.Text += ',';

        }

        private void bRavno_Click(object sender, EventArgs e)
        {
            b = Convert.ToDouble(tb_Calc.Text);
            switch (op)
            {
                case 1:
                    c = a + b;
                    break;
                case 2:
                    c = a - b;
                    break;
                case 3:
                    c = a * b;
                    break;
                case 4:
                    c = a / b;
                    break;
            }
            // Вставляем в textBox ответ
            tb_Calc.Text = Convert.ToString(c);
            // Ставим новую операцию
            NewOp = true;
            // начальное положение
            op = -1;
            
                    
            
        }

        // Кнопка плюс
        private void bPlus_Click(object sender, EventArgs e)
        {
            if (tb_Calc.Text == "") tb_Calc.Text = "0";
            else
            {
                if (op > 0)
                    bRavno_Click(sender, e);
                a = Convert.ToDouble(tb_Calc.Text);
                NewOp = true;
                // операция сложения
                op = 1;
                
            }
        }

        // Кнопка минус
        private void bMinus_Click(object sender, EventArgs e)
        {
            if (!(tb_Calc.Text.IndexOf("-")>-1&& tb_Calc.Text.Length - 1 == tb_Calc.Text.IndexOf("-")))
            {
                if (tb_Calc.Text == "" || tb_Calc.Text == "0")
                {
                    tb_Calc.Text = "-";
                    NewOp = false;
                    op = -1;
                }
                else
                {
                    

                    if (op > 0)
                        bRavno_Click(sender, e);
                    a = Convert.ToDouble(tb_Calc.Text);
                    NewOp = true;
                    op = 2;
                }

            }
            
        }

        // Кнопка умножить
        private void bUmn_Click(object sender, EventArgs e)
        {
            if (tb_Calc.Text == "") tb_Calc.Text = "0";
            else
            {
                
                if (op > 0)
                    bRavno_Click(sender, e);
                a = Convert.ToDouble(tb_Calc.Text);
                NewOp = true;
                op = 3;
            }
        }

        // Кнопка делить
        private void bDelenie_Click(object sender, EventArgs e)
        {
            if (tb_Calc.Text == "") tb_Calc.Text = "0";
            else
            {
                
                if (op > 0)
                    bRavno_Click(sender, e);
                a = Convert.ToDouble(tb_Calc.Text);
                NewOp = true;
                op = 4;
            }
        }
    }
}

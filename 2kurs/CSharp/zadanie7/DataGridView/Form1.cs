using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DataGridView
{
  public partial class Form1 : Form
  {
    double[,] Массив;
    public Form1()
    {
      InitializeComponent();
      Массив = new double[1, 1];
      // Включаем "ручное" управление данными для элемента DataGridView
      dataGridView1.VirtualMode = true;
      // Выключаем отображение строки, содержащей заголовки столбцов
      dataGridView1.ColumnHeadersVisible = false;
      // Выключаем отображение столбца, содержащего заголовки строк
      dataGridView1.RowHeadersVisible = false;
      // Отключаем автоматическое изменение размеров столбца
      dataGridView1.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.None;
      // Запрещаем пользователям изменять размеры столбцов и строк "мышкой"
      dataGridView1.AllowUserToResizeColumns = false;
      dataGridView1.AllowUserToResizeRows = false;
      // Запрещаем пользователям добавлять и удалять строки
      dataGridView1.AllowUserToDeleteRows = false;
      dataGridView1.AllowUserToAddRows = false;
      // Количество строк
      dataGridView1.RowCount = 1;
      // Количество столбцов
      dataGridView1.ColumnCount = 1;
      // Ширина первого (нулевого) столбца
      dataGridView1.Columns[0].Width = 43;
      // Отключаем изменение размеров первого столбца
      dataGridView1.Columns[0].Resizable = DataGridViewTriState.False;
    }
    // Происходит при изменении значения данного в NumericUpDown
    private void numericUpDown1_ValueChanged(object sender, EventArgs e)
    {
      Массив = new double[(int)numericUpDown1.Value, (int)numericUpDown1.Value];
      dataGridView1.RowCount = (int)numericUpDown1.Value;
      dataGridView1.ColumnCount = (int)numericUpDown1.Value;
      foreach (DataGridViewColumn col in dataGridView1.Columns)
      {
        col.Width = 43;
        col.Resizable = DataGridViewTriState.False;
      }
    }
    // Возникает, когда DataGridView требует значение для ячейки
    // для форматирования и отображения ячейки.
    private void dataGridView1_CellValueNeeded(object sender, DataGridViewCellValueEventArgs e)
    {
      e.Value = string.Format("{0:F3}",Массив[e.RowIndex, e.ColumnIndex]);
    }
    // Возникает, когда в DataGridView значение ячейки изменяется и
    // требует сохранения в базовом источнике данных.
    private void dataGridView1_CellValuePushed(object sender, DataGridViewCellValueEventArgs e)
    {
      try
      {
        Массив[e.RowIndex, e.ColumnIndex] = Double.Parse(e.Value.ToString());
      }
      catch (FormatException)
      {
        Массив[e.RowIndex, e.ColumnIndex] = 0.0;
      }
    }
    private void button1_Click(object sender, EventArgs e)
    {
      double минимальное, максимальное;
      int строка, столбец;
      минимальное = максимальное = Массив[0, 0];
      for(строка = 0; строка < dataGridView1.RowCount; строка++)
        for (столбец = 0; столбец < dataGridView1.ColumnCount; столбец++)
        {
          if (минимальное > Массив[строка, столбец])
            минимальное = Массив[строка, столбец];
          if (максимальное < Массив[строка, столбец])
            максимальное = Массив[строка, столбец];
        }
      label2.Text = string.Format("Минимальный элемент = {0:F}, максимальный элемент = {1:F}",
                    минимальное, максимальное);
    }
    private void button2_Click(object sender, EventArgs e)
    {
      int строка, столбец;
      Random rnd = new Random();
      for (строка = 0; строка < dataGridView1.RowCount; строка++)
        for (столбец = 0; столбец < dataGridView1.ColumnCount; столбец++)
          Массив[строка, столбец] = rnd.NextDouble()*(5-rnd.Next(10));
      // Заставляем "перерисоваться" dataGridView1
      dataGridView1.Refresh();
    }
  }
}

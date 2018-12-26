using System;


namespace ConsoleApp1 {
 class Program {
  static void Main() {
   //Создание объекта для генерации чисел
   Random rnd = new Random();

   //Получить случайное число (в диапазоне от 0 до 10)
   const int m = 5,
    n = 5;
   int[, ] a = new int[m, n];
   int i, j, jmin, imax, jmax, imax2, jmax2, min, minbuff;
   min = 100000;
   minbuff = -1;
   imax = 0;
   jmax = 0;
   imax2 = 0;
   jmax2 = 0;
   for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
     int value = rnd.Next(0, 10);
     a[i, j] = value;
     Console.Write("{0} ", a[i, j]);
    }
    Console.Write("\n");
   }
   for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
     if (min > a[i, j]) {
      min = a[i, j];
      imax = i;
      jmax = j;
     }

    }
    if (minbuff < min) {
     minbuff = min;
     imax2 = imax;
     jmax2 = jmax;
    }
    Console.Write("Максимальный среди минимальных в позиции: {0}\n", min);
    Console.Write("Индексы: {0}, {1}\n", imax, jmax);
    min = 100000;

   }
   Console.Write("Максимальный среди минимальных в позиции: {0}, {1}\n", imax2, jmax2);
   Console.ReadKey();

  }
 }
}
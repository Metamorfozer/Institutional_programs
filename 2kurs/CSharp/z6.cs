using System;

namespace ConsoleApp1 {
 class Program {
  static void Main() {
   int i, j, n;
   int[, ] a = new int[50, 50];
   Console.Write("Введите n: ");
   n = int.Parse(Console.ReadLine());
   for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
     if (i == j)
      a[i, j] = 1;
     else
     if (i > j) {
      a[i + 1, j] = a[i, j] + 1;
      a[i, j] = a[i, j] + 1;
      a[i, j] = a[i, j] + 1;
     } else
     if (i < j) {
      a[i, j + 1] = a[i, j] + 1;
      a[i, j] = a[i, j] + 1;
      a[i, j] = a[i, j] + 1;
     }
     Console.Write(" {0} ", a[i, j]);
    }
    Console.Write("\n\n");
   }
  }
 }
}
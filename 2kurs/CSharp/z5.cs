using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1 {
 class Program {
  static void Main() {
   int i;
   double n, a, a1 = 1, S = 0;
   Console.Write("\nВведите n: ");
   n = double.Parse(Console.ReadLine());
   Console.Write("\nВведите a: ");
   a = double.Parse(Console.ReadLine());
   S = 1 / a;
   for (i = 2; i <= n; i++) {
    a1 *= a * a;
    Console.WriteLine("{0}\n", a1);
    S += 1 / a1;
   }
   Console.WriteLine("S = {0}\n", S);
  }
 }
}
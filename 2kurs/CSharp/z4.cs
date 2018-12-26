using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1 {
 class Program {
  static void Main() {
   const double eps = 1E-6;
   double a, b, s, x;
   int i;
   x = double.Parse(Console.ReadLine());
   a = -x;
   b = 1.0;
   s = Math.PI / 2.0;
   for (i = 0; Math.Abs(a / b) > eps; i++) {
    s = s + a / b;
    a = -a * x * x;
    b = b + 2.0;
   }
   Console.WriteLine("nc = {0}\n s = {1}", Math.Atan(-x) + Math.PI / 2, s);
  }
 }
}
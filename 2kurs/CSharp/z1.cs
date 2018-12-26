using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1 {
 class Program {
  static void Main() {
   float x, y;
   Console.Write("\nВведите х:");
   x = float.Parse(Console.ReadLine());
   Console.Write("\nВведите y:");
   y = float.Parse(Console.ReadLine());
   double z1 = Math.Cos(x) * Math.Cos(x) * Math.Cos(x) * Math.Cos(x) + Math.Sin(y) * Math.Sin(y) + 1.0 / 4.0 * Math.Sin(2 * x) * Math.Sin(2 * x) - 1;
   double z2 = Math.Sin(y + x) * Math.Cos(y - x);
   Console.WriteLine("\nz1 = {0}\nz2 = {1}", z1, z2);
  }
 }
}
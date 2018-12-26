using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1 {
 class Program {
  static void Main() {
   float x, y;
   bool oa, ob, p, k, lt, pt, v;
   Console.Write("\nВведите координату x: ");
   x = float.Parse(Console.ReadLine());
   Console.Write("\nВведите координату y: ");
   y = float.Parse(Console.ReadLine());
   oa = (((x * x + y * y) < 1) && (y > 0));
   ob = (((x * x + y * y) <= 1) && (y <= 0));
   p = ((x >= -1) && (x < 1) && (y > -4) && (y < 0));
   k = ((x >= -1) && (x <= 1) && (y >= 0) && (y <= 2));
   lt = ((x >= -3) && (x <= -1) && (y >= 0) && (y <= 2) && (((x / -3) + (y / 2)) <= 1));
   pt = ((x >= 1) && (x <= 3) && (y >= 0) && (y <= 2) && (((x / 3) + (y / 2)) <= 1));
   v = ((x >= -3) && (x <= 3) && (y >= -9) && (y <= 0) && (((x * x) - y - 9) <= 0));
   if (lt || pt || (k && !oa) || (v && !p) || ob)
    Console.WriteLine("Да\n");
   else
    Console.WriteLine("Нет\n");

  }
 }
}
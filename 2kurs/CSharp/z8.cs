using System;
using System.Linq;

namespace ConsoleApp1 {
 class Program {
  static void Main() {
   char[] s = new char[50];
   Console.Write("\nСтрока: ");
   s = Console.ReadLine().ToCharArray();
   bool flag = false;
   Console.Write("\nВывод: ");
   for (int i = 0; i < s.Length; i++) {
    if (s[i] == '(') {
     i++;
     flag = true;
    }
    if (s[i] == ')') {
     flag = false;
     Console.Write(" ");
    }
    if (flag)
     Console.Write("{0}", s[i]);
   }
   Console.Write("\n");
   Console.ReadKey();
  }
 }
}
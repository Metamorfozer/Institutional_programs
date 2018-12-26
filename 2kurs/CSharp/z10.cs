using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zadanie10 {
 class Program {
  static void Main() {
   //Считываем текст
   string text = Console.ReadLine();
   //Считываем с какой позиции анализировать
   int pos = Convert.ToInt32(Console.ReadLine());
   //Выводим результат функции
   Console.WriteLine(F(text, pos - 1));
   Console.ReadKey();
  }

  static int F(string S, int pos) {
   if (pos < 0 || pos > S.Length) {
    return -1;
   }
   for (int i = pos; i < S.Length; i++) {
    if (S[i] == '+') {
     return i + 1;
    }
   }
   return 0;
  }
 }
}
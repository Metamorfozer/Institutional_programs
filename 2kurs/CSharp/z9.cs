using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp9 {
 class Program {
  static void Main(string[] args) {
   string text = Console.ReadLine();
   Dictionary < string, int > wordsstat = new Dictionary < string, int > ();
   List < string > words = new List < string > (text.Split(' '));
   int count = Convert.ToInt32(Console.ReadLine());
   for (int i = 0; i < words.Count; i++) {
    if (wordsstat.ContainsKey(words[i]) || wordsstat.ContainsKey(Reverse(words[i]))) {
     if (wordsstat.ContainsKey(words[i])) {
      wordsstat[words[i]]++;
     }
     if (wordsstat.ContainsKey(Reverse(words[i]))) {
      wordsstat[Reverse(words[i])]++;
     }
    } else {
     wordsstat.Add(words[i], 1);
    }
   }
   for (int i = 0; i < wordsstat.Count; i++) {
    if (wordsstat.ElementAt(i).Value == count) {
     while (words.Contains(wordsstat.ElementAt(i).Key)) {
      words.Remove(Reverse(wordsstat.ElementAt(i).Key));
      words.Remove(wordsstat.ElementAt(i).Key);
     }

    }
   }
   for (int i = 0; i < words.Count; i++) {
    Console.Write(words[i] + " ");
   }
   Console.ReadKey();
  }

  public static string Reverse(string word) {
   char[] arr = word.ToCharArray();
   Array.Reverse(arr);
   return new string(arr);
  }
 }
}
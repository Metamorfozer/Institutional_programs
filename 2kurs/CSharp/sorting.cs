using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;


namespace puz {
 class Program {
  const int NUMS = 1000;
  static void puz(int[] mas, int size) //сорт. пузырьком
  {
   int t;
   for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - i - 1; j++)
     if (mas[j] > mas[j + 1]) {
      t = mas[j];
      mas[j] = mas[j + 1];
      mas[j + 1] = t;
     }
   }
  }

  static void choose(int[] array, int size) //сорт. выбором
  {
   for (int i = 0; i < size - 1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
     if (array[j] < array[min]) {
      min = j;
     }
    }

    if (min != i) {
     int dummy = array[i];
     array[i] = array[min];
     array[min] = dummy;
     min = i;
    }
   }
  }

  static void insert(int[] arr, int n) //сорт. вставками 
  {
   for (int i = 1; i < n; i++) {
    for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
     int tmp = arr[j - 1];
     arr[j - 1] = arr[j];
     arr[j] = tmp;
    }
   }
  }

  static void Swap(int[] items, int left, int right) {
   if (left != right) {
    int temp = items[left];
    items[left] = items[right];
    items[right] = temp;
   }
  }

  static void fast(int[] items) {
   quicksort(items, 0, items.Length - 1);
  }

  static void quicksort(int[] items, int left, int right) {
   Random _pivotRng = new Random();
   if (left < right) {
    int pivotIndex = _pivotRng.Next(left, right);
    int newPivot = partition(items, left, right, pivotIndex);

    quicksort(items, left, newPivot - 1);
    quicksort(items, newPivot + 1, right);
   }
  }

  static int partition(int[] items, int left, int right, int pivotIndex) {
   int pivotValue = items[pivotIndex];

   Swap(items, pivotIndex, right);

   int storeIndex = left;

   for (int i = left; i < right; i++) {
    if (items[i].CompareTo(pivotValue) < 0) {
     Swap(items, i, storeIndex);
     storeIndex += 1;
    }
   }

   Swap(items, storeIndex, right);
   return storeIndex;
  }

  static void myShakerSort(int[] mas) {
   int left = 0, right = mas.Length - 1;
   while (left <= right) {
    for (int i = left; i < right; i++) {
     if (mas[i] > mas[i + 1]) {
      int glass = mas[i];
      mas[i] = mas[i + 1];
      mas[i + 1] = glass;
     }
    }
    right--;
    for (int i = right; i > left; i--) {
     if (mas[i - 1] > mas[i]) {
      int glass = mas[i - 1];
      mas[i - 1] = mas[i];
      mas[i] = glass;
     }
    }
    left++;
   }
  }

  static void Main(string[] args) {
   int[] DAT = new int[NUMS];
   int a;
   Random rnd = new Random();
   FileInfo f = new FileInfo(@ "file.dat");
   using(BinaryWriter bw = new BinaryWriter(f.OpenWrite()))

   for (ulong i = 0; i < NUMS; i++) {
    a = rnd.Next(0, 10000);
    bw.Write(a);
   }

   using(BinaryReader br = new BinaryReader(f.OpenRead()))
   for (ulong i = 0; i < NUMS; i++) {
    DAT[i] = br.ReadInt32();
   }
   Console.WriteLine();
   int[] vs = new int[NUMS];
   int[] vi = new int[NUMS];
   int[] sh = new int[NUMS];
   int[] fa = new int[NUMS];
   Array.Copy(DAT, 0, vs, 0, NUMS);
   Array.Copy(DAT, 0, vi, 0, NUMS);
   Array.Copy(DAT, 0, sh, 0, NUMS);
   Array.Copy(DAT, 0, fa, 0, NUMS);
   DateTime Start;
   DateTime Stoped;
   TimeSpan Elapsed = new TimeSpan();

   Console.WriteLine("Массив до пузырька: ");
   for (ulong i = 0; i < NUMS; i++) Console.Write(" {0}", DAT[i]);
   Start = DateTime.Now;
   puz(DAT, NUMS);
   Stoped = DateTime.Now;
   Elapsed = Stoped.Subtract(Start);
   Console.WriteLine("\nМассив после пузырька: ");
   for (ulong i = 0; i < NUMS; i++) Console.Write(" {0}", DAT[i]);
   Console.WriteLine(Environment.NewLine + "Время выполнения: " + Convert.ToString(Elapsed.TotalMilliseconds)); // Время выполнения в миллисекундах с плавующей запятой

   Console.WriteLine("\nМассив до вставки: ");
   for (ulong i = 0; i < NUMS; i++) Console.Write(" {0}", vs[i]);
   Start = DateTime.Now;
   insert(vs, NUMS);
   Stoped = DateTime.Now;
   Elapsed = Stoped.Subtract(Start);
   Console.WriteLine("\nМассив после вставки: ");
   for (ulong i = 0; i < NUMS; i++) Console.Write(" {0}", vs[i]);
   Console.WriteLine(Environment.NewLine + "Время выполнения " + Convert.ToString(Elapsed.TotalMilliseconds));

   Console.WriteLine("\nМассив до выбора: ");
   for (ulong i = 0; i < NUMS; i++) Console.Write(" {0}", vi[i]);
   Start = DateTime.Now;
   choose(vi, NUMS);
   Stoped = DateTime.Now;
   Elapsed = Stoped.Subtract(Start);
   Console.WriteLine("\nМассив после выбора: ");
   for (ulong i = 0; i < NUMS; i++) Console.Write(" {0}", vi[i]);
   Console.WriteLine(Environment.NewLine + "Время выполнения " + Convert.ToString(Elapsed.TotalMilliseconds));

   Console.WriteLine("\nМассив до слияния: ");
   for (ulong i = 0; i < NUMS; i++) Console.Write(" {0}", sh[i]);
   Start = DateTime.Now;
   myShakerSort(sh);
   Stoped = DateTime.Now;
   Elapsed = Stoped.Subtract(Start);
   Console.WriteLine("\nМассив после слияния: ");
   for (ulong i = 0; i < NUMS; i++) Console.Write(" {0}", sh[i]);
   Console.WriteLine(Environment.NewLine + "Время выполнения " + Convert.ToString(Elapsed.TotalMilliseconds));

   Console.WriteLine("\nМассив до быстрой: ");
   for (ulong i = 0; i < NUMS; i++) Console.Write(" {0}", fa[i]);
   Start = DateTime.Now;
   fast(fa);
   Stoped = DateTime.Now;
   Elapsed = Stoped.Subtract(Start);
   Console.WriteLine("\nМассив после быстрой: ");
   for (ulong i = 0; i < NUMS; i++) Console.Write(" {0}", fa[i]);
   Console.WriteLine(Environment.NewLine + "Время выполнения " + Convert.ToString(Elapsed.TotalMilliseconds));

   Console.ReadKey();
  }
 }
}
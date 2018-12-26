#include <iostream>
#include <ctime>

using namespace std;

int random(int a, int b);
void Swap(int items[], int left, int right);
void puz(int *items, int size);
void insert(int *arrayPtr, int size);
void choose(int *arrayPtr, int size);
void fast(int *items, int size);
void quicksort(int items[], int left, int right);
int partition(int items[], int left, int right, int pivotIndex);
void myShakerSort(int *items, int size);

int main()
{
    setlocale(LC_ALL, "rus");
    const int num = 100000;
    int *mas = new int[num];
    FILE *bfil;
    bfil = fopen("C:\\Users\\Студент\\Desktop\\Уразов\\Си#\\othersortfun\\othersortfun\\bin\\Debug\\file.dat", "rb");
    fread(mas, sizeof(int), num, bfil);

    int *vs = new int[num];
    cout << endl;
    for (int i = 0; i < num; i++)
    {
        vs[i] = mas[i];
    }
    int *vi = new int[num];
    for (int i = 0; i < num; i++)
    {
        vi[i] = mas[i];
    }
    int *fa = new int[num];
    for (int i = 0; i < num; i++)
    {
        fa[i] = mas[i];
    }
    int *sh = new int[num];
    for (int i = 0; i < num; i++)
    {
        sh[i] = mas[i];
    }

    cout << "\nмассив до пузырька:" << endl;
    for (int i = 0; i < num; i++)
        cout << " " << mas[i];

    unsigned int start_time = clock();
    puz(mas, num);
    unsigned int end_time = clock();

    cout << "\nмассив после пузырька:" << endl;
    for (int i = 0; i < num; i++)
        cout << " " << mas[i];
    cout << "\nПузырьковая сортировка " << end_time - start_time << endl;

    cout << "\nмассив до выставки:" << endl;
    for (int i = 0; i < num; i++)
        cout << " " << vs[i];

    start_time = clock();
    insert(vs, num);
    end_time = clock();

    cout << "\nмассив после выставки:" << endl;
    for (int i = 0; i < num; i++)
        cout << " " << vs[i];

    cout << "\nСортировка вставками " << end_time - start_time << endl;

    cout << "\nмассив до выбора:" << endl;
    for (int i = 0; i < num; i++)
        cout << " " << vi[i];

    start_time = clock();
    choose(vi, num);
    end_time = clock();

    cout << "\nмассив после выбора:" << endl;
    for (int i = 0; i < num; i++)
        cout << " " << vi[i];
    cout << "\nСортировка выбором " << end_time - start_time << endl;

    cout << "\nмассив до быстрой:" << endl;
    for (int i = 0; i < num; i++)
        cout << " " << fa[i];

    start_time = clock();
    fast(fa, num);
    end_time = clock();

    cout << "\nмассив после быстрой:" << endl;
    for (int i = 0; i < num; i++)
        cout << " " << fa[i];
    cout << "\nБыстрая сортировка " << end_time - start_time << endl;

    cout << "\nмассив до шейкера:" << endl;
    for (int i = 0; i < num; i++)
        cout << " " << sh[i];

    start_time = clock();
    myShakerSort(sh, num);
    end_time = clock();

    cout << "\nмассив после шейкера:" << endl;
    for (int i = 0; i < num; i++)
        cout << " " << sh[i];

    cout << "\nСортировка слиянием " << end_time - start_time << endl;
    fclose(bfil);
}

int random(int a, int b)
{
    srand(time(NULL));
    if (a > 0)
        return a + rand() % (b - a);
    else
        return a + rand() % (abs(a) + b);
}

void Swap(int items[], int left, int right)
{
    if (left != right)
    {
        int temp = items[left];
        items[left] = items[right];
        items[right] = temp;
    }
}

void puz(int *mas, int size) //сорт. пузырьком
{
    int t;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
            if (mas[j] > mas[j + 1])
            {
                t = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = t;
            }
    }
}

void choose(int *array, int size) //сорт. выбором
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }

        if (min != i)
        {
            int dummy = array[i];
            array[i] = array[min];
            array[min] = dummy;
            min = i;
        }
    }
}

void insert(int *arr, int n) //сорт. вставками
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) //сначала первый потом первые две
        {
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
        }
    }
}

void fast(int *A, int l, int r)
{
    int i = l, j = r, te, w;
    te = A[(l + r) / 2];
    do
    {
        while (A[i] < te)
            i++;
        while (A[j] > te)
            j--;
        if (i <= j)
        {
            w = A[i];
            A[i] = A[j];
            A[j] = w;
            i++;
            j--;
        }
    } while (!(i > j));
    if (l < j)
        fast(A, l, j);
    if (i < r)
        fast(A, i, r);
}

void myShakerSort(int *arr, int size)
{
    int n = 2;
    int leftMark = 1;
    int rightMark = size - 1;
    while (leftMark <= rightMark)
    {
        if (n % 2 == 0)
        {
            for (int i = rightMark; i >= leftMark; i--)
                if (arr[i - 1] > arr[i])
                    Swap(arr, i - 1, i);
            leftMark++;
            n++;
        }

        else
        {
            for (int i = leftMark; i <= rightMark; i++)
                if (arr[i - 1] > arr[i])
                    Swap(arr, i - 1, i);
            rightMark--;
            n++;
        }
    }
}

#include <iostream>
using namespace std;

void Q_S_R(int* mass, int size) {
    int i = 0;
    int j = size - 1;
    int mid = mass[size / 2];

    do {
        while(mass[i] < mid) {
            i++;
        }

        while(mass[j] > mid) {
            j--;
        }

        if (i <= j) {
            int tmp = mass[i];
            mass[i] = mass[j];
            mass[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        Q_S_R(mass, j + 1);
    }
    if (i < size) {
        Q_S_R(&mass[i], size - i);
    }
}

void Quick_Sorting(int* mass, int size) {
    int* a = new int[size];
    for (int i = 0; i < size; i++)
        a[i] = mass[i];
    Q_S_R(a, size);

    cout << "Результат работы алгоритма быстрой сортировки: ";
    for (int i = 0; i < size; i++)
        cout << a[i] << "\t";
    cout << endl;
}

void H_S(int* mass, int n, int i)
{
    int largest = i;   
    int l = 2*i + 1; 
    int r = 2*i + 2; 

    if (l < n && mass[l] > mass[largest])
        largest = l;

    if (r < n && mass[r] > mass[largest])
        largest = r;

    if (largest != i)
    {
        swap(mass[i], mass[largest]);
        H_S(mass, n, largest);
    }
}

void Heap_Sorting(int* mass, int size)
{
    int* a = new int[size];
    for (int i = 0; i < size; i++)
        a[i] = mass[i];

    for (int i = size / 2 - 1; i >= 0; i--)
        H_S(a, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        H_S(a, i, 0);
    }

    cout << "Результат работы алгоритма сортировки кучей: ";
    for (int i = 0; i < size; i++)
        cout << a[i] << "\t";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int size;

    cout << "\t\t Введите количество чисел в массиве: ";
    cin >> size;

    cout << "Введите числа: ";
    int* arr = new int [size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    Quick_Sorting(arr, size);
    Heap_Sorting(arr, size);
}
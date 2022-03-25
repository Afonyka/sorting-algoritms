#include <iostream>
using namespace std;

void SelectionSort(int* mass, int size) 
{
    int count, key;
    int* a = new int[size];
    for (int i = 0; i < size; i++)
        a[i] = mass[i];
    for (int i = 0; i < size - 1; i++){
      count = a[i]; key = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[key]) 
               key = j;
            if (key != i){
               a[i] = a[key];
               a[key] = count;
            }
    }
    cout << "Результат работы алгоритма сортировки Выбором: ";
    for (int i = 0; i < size; i++) 
        cout << a[i] << "\t"; 
    cout << endl;
}

void Shell_Sorting(int* mass, int size)
{
    int i, j, step;
    int tmp;
    int* a = new int[size];
    for (int i = 0; i < size; i++)
        a[i] = mass[i];
    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; i++)
        {
            tmp = a[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < a[j - step])
                    a[j] = a[j - step];
                else
                    break;
            }
            a[j] = tmp;
        }
    cout << "Результат работы алгоритма сортировки \" Шелла \": ";
    for (i = 0; i < size; i++) 
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

    SelectionSort(arr, size);
    Shell_Sorting(arr, size);
}

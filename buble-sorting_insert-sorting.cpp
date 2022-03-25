#include <iostream>
using namespace std;

void Bubble_Sorting(int* mass, int size) {
    if (size <= 0) {
        cout << "Неверный размер" << endl;
    }
    int* a = new int[size]; 
    for (int i = 0; i < size; i++){
        a[i] = mass[i];
    }
    int temp; 
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "\t Результат сортировки \" Пузырбком \": ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << "\t";
    }
    cout << endl; 
}

void Insert_Sorting(int* mass, int size) {
    int* a = new int[size];
    for (int i = 0; i < size; i++)
        a[i] = mass[i];
    for(int i = 1; i < size; i++)     
	   for(int j = i; j > 0 && a[j - 1] > a[j]; j--) 
             swap(a[j-1],a[j]);
    
    cout << "\t Результат работы алгоритма \" Вставки \": ";
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

    Bubble_Sorting(arr, size);
    Insert_Sorting(arr, size);
}

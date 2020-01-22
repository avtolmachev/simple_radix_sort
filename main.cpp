#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h
using namespace std;


// Функция цифровой сортировки
void radixSort(int *numbers, int array_size)
{
     int m = 256;
     union UN
     {
         unsigned int integer;
         unsigned char array[4];
     };

     int* digits = new int[m];
     UN* arr = new UN[array_size];
     for (int i = 0; i < array_size; ++i)
         arr[i].integer = numbers[i];

     for (int k = 0; k < 4; ++k)
     {
         for (int j = 0; j < m; ++j)
             digits[j] = 0;

         for (int j = 0; j < array_size; ++j)
         {
             ++digits[arr[j].array[k]];
         }

         for (int j = 1; j < m; ++j)
             digits[j] += digits[j - 1];

         for (int j = array_size - 1; j >=0; --j)
         {
             --digits[arr[j].array[k]];
             numbers[digits[arr[j].array[k]]] = arr[j].integer;
         }
         for (int j = 0; j < array_size; ++j)
             arr[j].integer = numbers[j];
         for (int j = 0; j < m; ++j)
             digits[j] = 0;
     }

     for (int i = 0; i < array_size; ++i)
     {
         numbers[i] = arr[i].integer;
     }

     delete[] digits;
     delete[] arr;
}

int main()
{
    //Объект для работы с файлами
    ReadWriter rw;

    int *brr = nullptr;
    int n;

    //Ввод из файла
    n = rw.readInt();

    brr = new int[n];
    rw.readArray(brr, n);

    //Запуск сортировки, ответ в том же массиве (brr)
    radixSort(brr, n);
    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}

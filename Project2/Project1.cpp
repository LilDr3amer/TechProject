#include <iostream>
#include <iomanip>
using namespace std;

int findMin(int numbers[], int size) { //поиск минимального
    int min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

int findMax(int numbers[], int size) { //поиск максимального
    int max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

double findAverage(int arr[], int size ) { //среднее арифметическое
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

int main() {
    setlocale(LC_ALL, "rus");
    int size;
     cout << "Введите размер массива от 1 до 10: \n";
     while (!(cin >> size) || size <= 0 || size > 10) {             //проверка на правильность числа
         cout << "Введите положительное число 1 до 10: \n";
         cin.clear();                                               //убирает ошибку
         cin.ignore(10000, '\n');                                   //выбрасывает мусор из буфера
     }

     int* numbers = new int[size];
     cout << "Введите " << size << " целых положительных чисел:\n\n";

    for (int i = 0; i < size; ++i) {                                //заполнение массива с последующими проверками
        int value;
        bool valid = false;
         while (!valid) {
             cout << "Элемент " << i + 1 << ": ";

             if (!(cin >> value)) {
                 cout << "Ошибка! Введите целое число: \n";
                 cin.clear();
                 cin.ignore(10000, '\n');
                 continue;
             }

             if (cin.peek() == '.' || cin.peek() == ',') {
                 cout << "Дробные не принимаются! Введите целое: \n";
                 cin.ignore(10000, '\n');
                 continue;
             }

             if (value <= 0) {
                 cout << "Число должно быть положительным! Введите: \n";
                 continue;
             }
             valid = true;
         }
         numbers[i] = value;
    }

    cout << "Минимальное\t"<< findMin(numbers, size)<<'\n';
    cout << "Максимальное\t"<< findMax(numbers, size)<<'\n';
    cout << fixed << setprecision(2);
    cout << "Ср. Ар.\t" << findAverage(numbers, size) << '\n';

    delete[] numbers;

    system("pause");
    return 0;
    }
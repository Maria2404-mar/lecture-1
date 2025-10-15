 

#include <iostream>
    using namespace std;

    int main() {
       
        // Часть 1: обработка последовательности
        int count;
        cout << "Enter the number of numbers: ";//Введите количество чисел в последовательности:
        cin >> count;

        int num;
        int sum = 0;          // Сумма чётных чисел
        int msum = -1;        // Самое большое чётное число
        int mindex = -1;      // Позиция самого большого чётного числа

        for (int i = 1; i <= count; ++i) {
            cout << "Enter a number №" << i << ": ";  // Исправлена строка ввода
            cin >> num;

            if (num % 2 == 0) {                     // Проверка на чётность
                sum += num;

                if (msum == -1 || num > msum) {
                    msum = num;
                    mindex = i;
                }
            }
        }

        if (mindex != -1) {
            cout << "The sum of even numbers: " << sum << "\n";//Сумма чётных чисел
            cout << "The largest even number: " << msum << ", позиция: " << mindex << "\n";//Самое большое чётное число
        }
        else {
            cout << "There are no even numbers.\n";//Нет чётных чисел
        }

        // Часть 2: минимальная цифра, отличная от 0 и 7
        int inputNumber;
        cout << "Enter a whole number less than 1000: ";//Введите целое число меньше 1000
        cin >> inputNumber;

        int firstValidDigit = -1;  // Переименовали переменную

        while (inputNumber > 0) {
            int lastDigit = inputNumber % 10; // Получаем последнюю цифру
            if (lastDigit != 0 && lastDigit != 7) {
                firstValidDigit = lastDigit;
                break;                      // Останавливаемся, как только нашли подходящую цифру
            }
            inputNumber /= 10;             // Отбрасываем последнюю цифру
        }

        if (firstValidDigit != -1) {
            cout << "The first digit that is not 0 or 7: " << firstValidDigit << "\n";  // Сообщение немного скорректировано,Первая цифра, отличная от 0 и 7
        }
        else {
            cout << "All digits are 0 or 7.\n";//Все цифры равны 0 или 7
        }

        return 0;
    }



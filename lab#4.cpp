

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    const int n = 10; // Размер массива
    int a[n];

    // Заполняем массив числами
    cout << "Enter " << n << " numbers: "; // ИСПРАВЛЕНО: добавлен пробел
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Вычисляем младшие значащие цифры первого и последнего числа
    int firstnumber = a[0] % 10;
    int lastnumber = a[n - 1] % 10;

    // Сортируем массив, если младшие цифры совпадают
    if (firstnumber == lastnumber) {
        sort(a, a + n);

        // Печать отсортированного массива
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl; // ИСПРАВЛЕНО: добавлен перевод строки
    }
    else {
        cout << "error" << endl; // ИСПРАВЛЕНО: добавлен перевод строки
    }

    
    //часть 2
    int mtx[3][4], bsm = INT_MAX, index = 0;//создаем матрицу,переменную с макс знач целого числа,индекс строки
    // Ввод матрицы и поиск нужной строки одновременно
    cout << "Enter matrix 3x4:" << endl;

    // Ввод матрицы и поиск нужной строки одновременно
    for (int i = 0; i < 3; i++) {//перебираем строки матрицы
        int sum = 0;//переменная,которая собирает сумму
        for (int j = 0; j < 4; j++) {//складываем их в sum
            cin >> mtx[i][j];
            sum += mtx[i][j];
        }
        if (abs(sum) < abs(bsm)) {//проверяем насколько близка сумма ряда к нулю относ предыд
            bsm = sum;
            index = i;
        }
    }

    // Меняем строку на нули
    for (int j = 0; j < 4; j++) {//цикл меняет все элементы стоки с номером index
        mtx[index][j] = 0;
    }
    // Печать результирующей матрицы
    cout << "Result matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mtx[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
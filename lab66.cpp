#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int point;
    cout << "введите номер пункта (1 или 2):";
    cin >> point;

    if (point == 1) {
        // Создаем массив 2x2
        int** arr = (int**)malloc(2 * sizeof(int*));
        for (int i = 0; i < 2; i++) {
            arr[i] = (int*)malloc(2 * sizeof(int));
        }

        // Заполняем массив
        cout << "введите 4 числа для матрицы 2x2:" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int num;
                do {
                    cin >> num;
                    if (num < 0) cout << "ошибка, введите снова: ";
                } while (num < 0);
                arr[i][j] = num;
            }
        }

        // Получаем A, B, C, D
        int A = arr[0][0];  // строки добавить
        int B = arr[0][1];  // столбцы добавить  
        int C = arr[1][0];
        int D = arr[1][1];

        // Создаем новую матрицу
        int new_rows = 2 + A;
        int new_cols = 2 + B;
        int** new_arr = (int**)malloc(new_rows * sizeof(int*));
        for (int i = 0; i < new_rows; i++) {
            new_arr[i] = (int*)malloc(new_cols * sizeof(int));
        }

        // Заполняем по формуле
        for (int i = 0; i < new_rows; i++) {
            for (int j = 0; j < new_cols; j++) {
                new_arr[i][j] = (i - 1) * C + (j - 1) * D;
            }
        }

        // Ищем столбцы с нулями
        int* zero_cols = (int*)malloc(new_cols * sizeof(int));
        int count = 0;

        for (int j = 0; j < new_cols; j++) {
            for (int i = 0; i < new_rows; i++) {
                if (new_arr[i][j] == 0) {
                    zero_cols[count++] = j;
                    break;
                }
            }
        }

        // Удаляем столбцы с нулями
        int final_cols = new_cols - count;
        int** final_arr = (int**)malloc(new_rows * sizeof(int*));
        for (int i = 0; i < new_rows; i++) {
            final_arr[i] = (int*)malloc(final_cols * sizeof(int));
            int k = 0;
            for (int j = 0; j < new_cols; j++) {
                bool is_zero = false;
                for (int n = 0; n < count; n++) {
                    if (j == zero_cols[n]) {
                        is_zero = true;
                        break;
                    }
                }
                if (!is_zero) {
                    final_arr[i][k++] = new_arr[i][j];
                }
            }
        }

        // Вывод результатов
        cout << "результат:" << endl;
        for (int i = 0; i < new_rows; i++) {
            for (int j = 0; j < final_cols; j++) {
                cout << final_arr[i][j] << " ";
            }
            cout << endl;
        }

        // Освобождаем память
        for (int i = 0; i < 2; i++) free(arr[i]);
        free(arr);
        for (int i = 0; i < new_rows; i++) free(new_arr[i]);
        free(new_arr);
        for (int i = 0; i < new_rows; i++) free(final_arr[i]);
        free(final_arr);
        free(zero_cols);

    }
    else if (point == 2) {
        float a, b;
        cout << "введите два числа: ";
        cin >> a >> b;

        float* p1 = &a;
        float* p2 = &b;

        *p1 = *p1 * 3;  // увеличиваем a в 3 раза

        // меняем местами
        float temp = *p1;
        *p1 = *p2;
        *p2 = temp;

        cout << "результат: a = " << a << ", b = " << b << endl;
    }
    else {
        cout << "ERROR" << endl;
    }

    return 0;
}
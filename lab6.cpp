
#include <iostream>
#include <cstdlib>

void fillMatrix(int** matrix, int rows, int cols, int C, int D, int A, int B) {
    // Заполнение начальной матрицы
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = -1 * C + (j + 1) * D;
        }
    }

    // Добавление новых строк
    for (int i = 0; i < A; i++) {
        matrix[rows + i] = (int*)malloc((cols + B) * sizeof(int));
        for (int j = 0; j < cols + B; j++) {
            matrix[rows + i][j] = i * C + (j - B + 1) * D;
        }
    }
}

int* findZeroColumns(int** matrix, int rows, int cols, int* zeroCount) {
    int* zeroIndices = (int*)malloc(cols * sizeof(int));
    *zeroCount = 0;

    for (int j = 0; j < cols; j++) {
        bool isZeroColumn = true;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] != 0) {
                isZeroColumn = false;
                break;
            }
        }
        if (isZeroColumn) {
            zeroIndices[*zeroCount] = j;
            (*zeroCount)++;
        }
    }

    return zeroIndices;
}

int** removeColumns(int** matrix, int rows, int cols, int* zeroIndices, int zeroCount) {
    int newCols = cols - zeroCount;
    int** newMatrix = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++) {
        newMatrix[i] = (int*)malloc(newCols * sizeof(int));
        int newIndex = 0;

        for (int j = 0; j < cols; j++) {
            bool isZeroColumn = false;
            for (int k = 0; k < zeroCount; k++) {
                if (j == zeroIndices[k]) {
                    isZeroColumn = true;
                    break;
                }
            }
            if (!isZeroColumn) {
                newMatrix[i][newIndex++] = matrix[i][j];
            }
        }
    }

    return newMatrix;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    const int initialRows = 2;
    const int initialCols = 2;

    // Ввод значений A и B
    int A, B;

    std::cout << "Введите количество строк для добавления (A): ";
    std::cin >> A;
    while (A < 0) {
        std::cout << "Ошибка! Введите неотрицательное значение для A: ";
        std::cin >> A;
    }

    std::cout << "Введите количество столбцов для добавления (B): ";
    std::cin >> B;
    while (B < 0) {
        std::cout << "Ошибка! Введите неотрицательное значение для B: ";
        std::cin >> B;
    }

    // Ввод значений C и D
    int C, D;
    std::cout << "Введите значение C: ";
    std::cin >> C;

    std::cout << "Введите значение D: ";
    std::cin >> D;

    // Выделение памяти для начальной матрицы
    int** matrix = (int**)malloc((initialRows + A) * sizeof(int*));

    for (int i = 0; i < initialRows + A; i++) {
        matrix[i] = (int*)malloc((initialCols + B) * sizeof(int));
    }

    // Заполнение матрицы
    fillMatrix(matrix, initialRows, initialCols, C, D, A, B);

    // Поиск нулевых столбцов
    int zeroCount;
    int* zeroIndices = findZeroColumns(matrix, initialRows + A, initialCols + B, &zeroCount);

    // Удаление нулевых столбцов
    int** newMatrix = removeColumns(matrix, initialRows + A, initialCols + B, zeroIndices, zeroCount);

    // Вывод новой матрицы
    std::cout << "Полученная матрица:\n";
    for (int i = 0; i < initialRows + A; i++) {
        for (int j = 0; j < initialCols + B - zeroCount; j++) {
            std::cout << newMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Освобождение памяти
    free(zeroIndices);
    freeMatrix(matrix, initialRows + A);
    freeMatrix(newMatrix, initialRows + A);

    return 0;
}

#include <iostream>

int main() {
    double a, b;

    std::cout << "Введите значение переменной a: ";
    std::cin >> a;

    std::cout << "Введите значение переменной b: ";
    std::cin >> b;

    std::cout << "\nИсходные значения:" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    // Создаем указатели и направляем их на переменные
    double* ptrA = &a;
    double* ptrB = &b;

    // Увеличиваем a в 3 раза через указатель
    *ptrA = *ptrA * 3;
    std::cout << "После увеличения a в 3 раза: a = " << a << ", b = " << b << std::endl;

    // Меняем местами значения через указатели
    double temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

    std::cout << "После обмена значений: a = " << a << ", b = " << b << std::endl;

    return 0;
}

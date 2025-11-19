
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для просмотра массива
void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) {
            cout << " ";
        }
    }
    cout << "]" << endl;
}

// Функция для добавления элемента в начало
void addToBeginning(vector<int>& arr, int value) {
    cout << "До: ";
    printArray(arr);
    arr.insert(arr.begin(), value);
    cout << "После: ";
    printArray(arr);
}

// Функция для добавления элемента в конец
void addToEnd(vector<int>& arr, int value) {
    cout << "До: ";
    printArray(arr);
    arr.push_back(value);
    cout << "После: ";
    printArray(arr);
}

// Функция для очистки массива
void clearArray(vector<int>& arr) {
    cout << "До: ";
    printArray(arr);
    arr.clear();
    cout << "После: ";
    printArray(arr);
}

// Функция для поиска элемента
void findElement(const vector<int>& arr, int value) {
    cout << "Индексы элемента " << value << ": [";
    bool found = false;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == value) {
            if (found) cout << ",";
            cout << i;
            found = true;
        }
    }
    cout << "]" << endl;

    if (!found) {
        cout << "Элемент не найден" << endl;
    }
}

// Функция для выполнения задания варианта
void processArray(vector<int>& arr) {
    cout << "До: ";
    printArray(arr);

    for (int& num : arr) {
        if (num % 2 == 0) {
            num += 2;  // Четные числа увеличиваем на 2
        }
        else {
            num = -num;  // Нечетным меняем знак
        }
    }

    cout << "После: ";
    printArray(arr);
}

// Функция для отображения меню
void showMenu() {
    cout << "\n=== МЕНЮ ===" << endl;
    cout << "0. Выход" << endl;
    cout << "1. Просмотр массива" << endl;
    cout << "2. Добавить элемент в начало" << endl;
    cout << "3. Добавить элемент в конец" << endl;
    cout << "4. Очистка всего массива" << endl;
    cout << "5. Поиск элемента в массиве" << endl;
    cout << "6. Задание варианта" << endl;
    cout << "Выберите пункт меню: ";
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<int> array;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Выход из программы..." << endl;
            break;

        case 1:
            cout << "Текущий массив: ";
            printArray(array);
            break;

        case 2: {
            int value;
            cout << "Введите элемент для добавления в начало: ";
            cin >> value;
            addToBeginning(array, value);
            break;
        }

        case 3: {
            int value;
            cout << "Введите элемент для добавления в конец: ";
            cin >> value;
            addToEnd(array, value);
            break;
        }

        case 4:
            clearArray(array);
            break;

        case 5: {
            int value;
            cout << "Введите элемент для поиска: ";
            cin >> value;
            findElement(array, value);
            break;
        }

        case 6:
            processArray(array);
            break;

        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}


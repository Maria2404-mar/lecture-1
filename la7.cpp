#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <random>
#include <ctime>

using namespace std;

// ==================== РАЗДЕЛ 1: Работа с vector ====================

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

// Функция для отображения меню раздела 1
void showMenu() {
    cout << "\n=== МЕНЮ (vector) ===" << endl;
    cout << "0. Выход в главное меню" << endl;
    cout << "1. Просмотр массива" << endl;
    cout << "2. Добавить элемент в начало" << endl;
    cout << "3. Добавить элемент в конец" << endl;
    cout << "4. Очистка всего массива" << endl;
    cout << "5. Поиск элемента в массиве" << endl;
    cout << "6. Задание варианта" << endl;
    cout << "Выберите пункт меню: ";
}

// Функция для запуска раздела 1
void runPart1() {
    vector<int> array;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Возврат в главное меню..." << endl;
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
}

// ==================== РАЗДЕЛ 2: Работа с array ====================

// Функция для вывода массива (шаблонная)
template<typename T>
void printArrayTemplate(const T& arr, const string& label = "") {
    if (!label.empty()) cout << label;
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i != arr.size() - 1) cout << " ";
    }
    cout << "]" << endl;
}

void sortByValue(array<int, 10> arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "После сортировки по значению (внутри функции): ";
    printArrayTemplate(arr);
}

void sortByReference(array<int, 10>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        for (size_t j = 0; j < arr.size() - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sortByPointer(array<int, 10>* arr) {
    for (size_t i = 0; i < arr->size() - 1; ++i) {
        for (size_t j = 0; j < arr->size() - i - 1; ++j) {
            if ((*arr)[j] > (*arr)[j + 1]) {
                swap((*arr)[j], (*arr)[j + 1]);
            }
        }
    }
}

void runPart2() {
    cout << "\n=== РАЗДЕЛ 2 (std::array) ===" << endl;

    array<int, 10> arr;
    for (int& x : arr) x = rand() % 21 - 10; // [-10; 10]

    cout << "Исходный массив: ";
    printArrayTemplate(arr);

    sortByValue(arr);

    sortByReference(arr);
    cout << "После сортировки по ссылке: ";
    printArrayTemplate(arr);

    mt19937 rng(static_cast<unsigned>(time(nullptr)));
    shuffle(arr.begin(), arr.end(), rng);
    cout << "После перемешивания: ";
    printArrayTemplate(arr);

    sortByPointer(&arr);
    cout << "После сортировки по указателю: ";
    printArrayTemplate(arr);

    cout << "\n(Раздел 2 выполнен)" << endl;
}

// ==================== ГЛАВНОЕ МЕНЮ ====================

void showMainMenu() {
    cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << endl;
    cout << "1. Раздел 1 - Работа с vector" << endl;
    cout << "2. Раздел 2 - Работа с array" << endl;
    cout << "0. Выход из программы" << endl;
    cout << "Выберите раздел: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(static_cast<unsigned>(time(nullptr)));

    int mainChoice;

    do {
        showMainMenu();
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            runPart1();
            break;
        case 2:
            runPart2();
            break;
        case 0:
            cout << "Выход из программы..." << endl;
            break;
        default:
            cout << "Неверный выбор! Попробуйте снова." << endl;
        }

    } while (mainChoice != 0);

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <array>

using namespace std;

// Функция для просмотра массива
void printArray(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "[] (массив пуст)" << endl;
        return;
    }

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
    if (arr.empty()) {
        cout << "Массив пуст. Поиск невозможен." << endl;
        return;
    }

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
    if (arr.empty()) {
        cout << "Массив пуст. Нет элементов для обработки." << endl;
        return;
    }

    cout << "До: ";
    printArray(arr);

    for (int& num : arr) {
        if (num % 2 == 0) {
            num += 2;  // Четные числа увеличиваем на 2
        }
        else {
            num = -num;  // Нечётным меняем знак
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
    cout << "7. Показать размер массива" << endl;
    cout << "Выберите пункт меню: ";
}

// Демонстрация работы с std::array (не используется в основном меню)
void demonstrateArray() {
    cout << "\n=== Пример работы с std::array ===" << endl;

    array<int, 5> fixedArray = { 1, 2, 3, 4, 5 };

    cout << "Статический массив (std::array): ";
    cout << "[";
    for (size_t i = 0; i < fixedArray.size(); ++i) {
        cout << fixedArray[i];
        if (i != fixedArray.size() - 1) {
            cout << " ";
        }
    }
    cout << "]" << endl;

    cout << "Размер фиксированного массива: " << fixedArray.size() << endl;
    cout << "Первый элемент: " << fixedArray.front() << endl;
    cout << "Последний элемент: " << fixedArray.back() << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Генерация случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(-10, 10);

    // Массив случайных чисел
    vector<int> array;

    // Заполняем массив 10 случайными числами
    cout << "Инициализация массива 10 случайными числами..." << endl;
    for (int i = 0; i < 10; ++i) {
        array.push_back(dis(gen));
    }

    cout << "Начальный массив: ";
    printArray(array);

    int choice;

    do {
        showMenu();
        cin >> choice;

        // Проверка на корректность ввода
        if (cin.fail()) {
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
            cout << "Ошибка ввода! Пожалуйста, введите число." << endl;
            continue;
        }

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

        case 7:
            cout << "Размер массива: " << array.size() << " элементов" << endl;
            if (!array.empty()) {
                cout << "Вместимость массива: " << array.capacity() << " элементов" << endl;
                cout << "Первый элемент: " << array.front() << endl;
                cout << "Последний элемент: " << array.back() << endl;
            }
            break;

        default:
            cout << "Неверный выбор! Пожалуйста, выберите число от 0 до 7." << endl;
            break;
        }

    } while (choice != 0);

    // Небольшая демонстрация std::array перед выходом
    demonstrateArray();

    return 0;
}
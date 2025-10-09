

#include <iostream>
#include<bitset>
using namespace std;


int main(){
    cout << "ex 1" << endl;//задание 1

    short A;//тип который вмещает целые числа
    int i;//стандартный целочислепнный вид

    cout << " Enter a number A (short): ";//ввести число а
    cin >> A;

    cout << "Enter the bit number i (0–7): ";//ввисти номер бита
    cin >> i;

    if (i < 0 || i > 7) {//может быть только 8 бит 
        cout << "Error" << endl;// ошибка если i>8

        return 0;
    }
    // Выводим A в двоичном виде
    cout << "The number A in block form(16 бит) : " << bitset<16>(A) << endl;

    // Извлекаем i-й бит
    int bit = (A >> i) & 1; // значение i бита

    if (bit == 1) {
        cout << "bit " << i << " =1." << endl;//равен 1

        int x, y;
        cout << " Enter two integers\n";//ввести два целых числа
        cout << "The first number: ";//первое число
        cin >> x;

        cout << "the second number: ";//второе число
        cin >> y;

        if (x > y) {
            cout << "max: " << x << endl;//максимальное число
        }
        else if (y > x) {
            cout << "max: " << y << endl;//максимальное число
        }
        else {
            cout << "numbers== " << endl;//числа равны
        }
        // Установить i-й бит в 0
        short A0;

        A0 = A & ~(1 << i); // сбрасываем i бит 

        cout << " Number A with a zeroed bit" << i << ": " << bitset<16>(A0) << endl;//число A c обнуленным видом
    }


    else {
        cout << "bit " << i << " =0." << endl;

        // Инвертировать все биты
        

        A = ~A; // инвертируем (меняем 0 на 1 и 1на 0)

        cout << "The result after inversion: " << bitset<16>(A) << endl;
    }
    //второе задание
    int monthNumber;
    std::cin >> monthNumber;
    switch (monthNumber) {
    case 1: std::cout << "Junuary"; break;
    case 2: std::cout << "Febreary"; break;
    case 3:std::cout << "March"; break;
    case 4:std::cout << "April"; break;
    case 5:std::cout << "May"; break;
    case 6: std::cout << "June"; break;
    case 7: std::cout << "July"; break;
    case 8:std::cout << "August"; break;
    case 9:std::cout << "September"; break;
    case 10:std::cout << "Octobeer"; break;
    case 11:std::cout << "November"; break;
    case 12:std::cout << "December"; break;
    default:std::cout << "Unknown month";

    }
    return  0;
}

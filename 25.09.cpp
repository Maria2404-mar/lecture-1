

#include <iostream>//библиотека
using namespace std;//библиотека что бы в дальнейшем не писать std

int main()
{
    int x;//первое целое число
    int y;//второе целое число
    float w;//число с плавующей запятой
    cin >> x >> y;//ввод
    w = sqrt((x * x) + (y * y));//находим гипотинузу треугольника
    cout << w << endl;//выводим значение переменной w и переходим на новую строчку
    std::cout << (x + y + w);//находим периметр треугольника
    //вывод информации о типе данных
    cout << "type of values:float" << endl;
    cout << "type of values:int" << endl;
    cout << "size in bits:" << sizeof(float) * 8 << endl;//размер в битах
    cout << "size in bits:" << sizeof(int) * 8 << endl;// размер в битах
    cout << "min value:" << numeric_limits<float>::lowest() << endl;//минимальное значение
    cout << "max value" << numeric_limits<float>::lowest() << endl;//максимальное значение
    cout << "min value:" << numeric_limits<int>::lowest() << endl;//минимальное значение
    cout << "max value" << numeric_limits<int>::lowest() << endl;//максимальное значение

    return 0;
}



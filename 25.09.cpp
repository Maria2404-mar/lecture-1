

#include <iostream>
using namespace std;

int main()
{
    int x;
    int y;
    float w;
    cin >> x >> y;
    w = sqrt((x * x) + (y * y));
    cout << w << endl;
    std::cout << (x + y + w);
    cout << "type of values:float" << endl;
    cout << "type of values:int" << endl;
    cout << "size in bits:" << sizeof(float) * 8 << endl;
    cout << "size in bits:" << sizeof(int) * 8 << endl;
    cout << "min value:" << numeric_limits<float>::lowest() << endl;
    cout << "max value" << numeric_limits<float>::lowest() << endl;
    cout << "min value:" << numeric_limits<int>::lowest() << endl;
    cout << "max value" << numeric_limits<int>::lowest() << endl;

    return 0;
}


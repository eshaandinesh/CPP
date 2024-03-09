#include <iostream>
using namespace std;
class Number
{

    int a, b;

public:
    int c;
    void setData(int n1, int n2);
    void display();
};

void Number::setData(int n1, int n2)
{
    a = n1;
    b = n2;
    c = a + b;
}
void Number::display()
{
    cout << "1st number: " << a << endl;
    cout << "2nd number: " << b << endl;
    cout << "Sum: " << c << endl;
}

int main()
{
    Number obj;
    obj.setData(10, 20);
    obj.display();
}

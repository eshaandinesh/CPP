#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex();
    Complex(int r, int i);
    Complex(int r);

    void getData()
    {
        cout << real << " + " << imag << "i" << endl;
    }
    void add(Complex c1, Complex c2)
    {
        Complex c3;
        c3.real = c1.real + c2.imag;
        c3.imag = c2.real + c2.imag;
        cout << "Sum: " << c3.real << " + " << c3.imag << "i" << endl;
    }
};

Complex::Complex(int r, int i)
{
    real = r;
    imag = i;
}

Complex::Complex(int r)
{
    real = r;
    imag = 0;
}

Complex::Complex()
{
    real = 0;
    imag = 0;
}

int main()
{
    Complex c3;
    Complex c1(10, 20);
    Complex c2(30, 40);
    cout << "1st complex no. is " << endl;
    c1.getData();
    cout << "2nd complex no. is " << endl;
    c2.getData();
    c3.add(c1, c2);
    return 0;
}

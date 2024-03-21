#include <iostream>
#include <cmath>
using namespace std;

// Class 1
class SimpleCalculator_23BAI1407
{
public:
    int additionSimple_Eshaan(int, int);
    int subtractionSimple_Eshaan(int, int);
    int multiplicationSimple_Eshaan(int, int);
    float divisionSimple_Eshaan(int, int);
    int remainderSimple_Eshaan(int, int);
    double squarerootSimple_Eshaan(int);
};

int SimpleCalculator_23BAI1407::additionSimple_Eshaan(int x, int y)
{
    return x + y;
}

int SimpleCalculator_23BAI1407::subtractionSimple_Eshaan(int x, int y)
{
    return x - y;
}

int SimpleCalculator_23BAI1407::multiplicationSimple_Eshaan(int x, int y)
{
    return x * y;
}

float SimpleCalculator_23BAI1407::divisionSimple_Eshaan(int x, int y)
{
    if (x != 0)
    {
        return y / x;
    }
    else
    {
        cout << "Error: Trying to divide by 0" << endl;
        return 0;
    }
}

int SimpleCalculator_23BAI1407::remainderSimple_Eshaan(int n, int m)
{
    return n % m;
}

double SimpleCalculator_23BAI1407::squarerootSimple_Eshaan(int n)
{
    if (n > 0)
    {
        return sqrt(n);
    }
    else
    {
        cout << "Error: Trying to square root a -ve number" << endl;
        return 0;
    }
}

// Class 2
class CalculateSquare_23BAI1407 : public SimpleCalculator_23BAI1407
{
public:
    int calculateSquare_Eshaan(int);
};

int CalculateSquare_23BAI1407::calculateSquare_Eshaan(int num)
{
    return SimpleCalculator_23BAI1407::multiplicationSimple_Eshaan(num, num);
}

// Class 3
class PrimeNumber_23BAI1407 : public SimpleCalculator_23BAI1407
{
public:
    bool checkPrimeNumber_Eshaan(int);
};

bool PrimeNumber_23BAI1407::checkPrimeNumber_Eshaan(int num)
{
    int root = SimpleCalculator_23BAI1407::squarerootSimple_Eshaan(num);
    for (int i = 2; i <= root; i++)
    {
        if (SimpleCalculator_23BAI1407::remainderSimple_Eshaan(num, i) == 0)
        {
            return false;
        }
    }
    return true;
}

// Class 4
class FibonacciNumber_23BAI1407 : public SimpleCalculator_23BAI1407
{
public:
    void printFibonacciNumbers_Eshaan(int, int, int);
};

void FibonacciNumber_23BAI1407::printFibonacciNumbers_Eshaan(int n, int a = 0, int b = 1)
{
    if (a == 0)
    {
        cout << a << " " << b << " ";
    }
    if (n > 0)
    {
        cout << SimpleCalculator_23BAI1407::additionSimple_Eshaan(a, b) << " ";
        n = SimpleCalculator_23BAI1407::subtractionSimple_Eshaan(n, 1);
        printFibonacciNumbers_Eshaan(n, b, SimpleCalculator_23BAI1407::additionSimple_Eshaan(a, b));
    }
}

// Class 5
class EuclideanDistance_23BAI1407 : public CalculateSquare_23BAI1407
{
public:
    float calculateEuclideanDistance_Eshaan(int, int, int, int);
};

float EuclideanDistance_23BAI1407::calculateEuclideanDistance_Eshaan(int x1, int y1, int x2, int y2)
{
    return SimpleCalculator_23BAI1407::squarerootSimple_Eshaan(CalculateSquare_23BAI1407::calculateSquare_Eshaan(x2 - x1) + CalculateSquare_23BAI1407::calculateSquare_Eshaan(y2 - y1));
}

// Class 6
class Palindrome_23BAI1407 : public SimpleCalculator_23BAI1407
{
public:
    bool checkPalindrome_Eshaan(int);
};

bool Palindrome_23BAI1407::checkPalindrome_Eshaan(int n)
{
    int rev = 0;
    int i = n;
    while (i > 0)
    {
        rev = SimpleCalculator_23BAI1407::additionSimple_Eshaan(SimpleCalculator_23BAI1407::multiplicationSimple_Eshaan(rev, 10), SimpleCalculator_23BAI1407::remainderSimple_Eshaan(i, 10));
        i = (int)(SimpleCalculator_23BAI1407::divisionSimple_Eshaan(10, i));
    }
    if (n == rev)
    {
        return true;
    }
    return false;
}

int main()
{
    int choice = 0;
    int n = 0;
    bool retval;
    cout << "1. Square of number" << endl;
    cout << "2. Check if prime number" << endl;
    cout << "3. Fibonacci series" << endl;
    cout << "4. Euclidean Distance" << endl;
    cout << "5. Check if Palindrome" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        int square;
        CalculateSquare_23BAI1407 sqr;
        cout << "Enter the number: ";
        cin >> n;
        square = sqr.calculateSquare_Eshaan(n);
        cout << "The square is: " << square << endl;
        break;
    case 2:
        PrimeNumber_23BAI1407 prime;
        cout << "Enter the number: ";
        cin >> n;
        retval = prime.checkPrimeNumber_Eshaan(n);
        if (retval)
        {
            cout << "It is a prime number" << endl;
        }
        else
        {
            cout << "It is not a prime nummber" << endl;
        }
        break;
    case 3:
        FibonacciNumber_23BAI1407 fib;
        cout << "Enter the number of outputs wanted: ";
        cin >> n;
        fib.printFibonacciNumbers_Eshaan(n);
        break;
    case 4:
        int x1, x2, y1, y2;
        float dist;
        EuclideanDistance_23BAI1407 euDist;
        cout << "Enter the coordinates x1 y1 x2 y2: ";
        cin >> x1 >> y1 >> x2 >> y2;
        dist = euDist.calculateEuclideanDistance_Eshaan(x1, y1, x2, y2);
        cout << "Distance between the points is: " << dist << endl;
        break;
    case 5:
        Palindrome_23BAI1407 pal;
        cout << "Enter the number: ";
        cin >> n;
        retval = pal.checkPalindrome_Eshaan(n);
        if (retval)
        {
            cout << "It is a palindrome" << endl;
        }
        else
        {
            cout << "It is not a palindrome" << endl;
        }
        break;
    default:
        cout << "Invalid Input" << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

class Student
{
    char reg[10];
    static int count; // static variable

public:
    Student()
    {
        cout << "Enter the registration no. " << endl;
        cin >> reg;
        count++;
    }
    void display()
    {
        cout << "Reg no. =" << reg << endl;
        // cout << "Total student count = " << count << endl;
    }
    static void getCount() // static function
    {
        cout << "Current count = " << count << endl;
    }
};
int Student::count;

int main()
{
    Student s1;
    s1.display();
    Student::getCount();
    Student s2;
    s2.display();
    Student::getCount();
    return 0;
}

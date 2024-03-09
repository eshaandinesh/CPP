#include <iostream>
#include <iomanip>
#include <string>
// #include <cmath>
using namespace std;

class Student
{
    char name[50];
    char registerNo[10];
    int cat1;
    int cat2;
    int fat;
    char grade;
    float percentage;

public:
    Student()
    {
        // cin>>name;
        cin.getline(name, 50);
        cin >> registerNo;
        cin >> cat1;
        cin >> cat2;
        cin >> fat;
    }
    void calcPercentage();
    void calcGrade();
    void display();
};

void Student::calcPercentage()
{
    percentage = (cat1 + cat2 + fat) * 100.0 / 120.0;
}
void Student::calcGrade()
{
    if (percentage >= 0 && percentage < 50)
    {
        grade = 'N';
    }
    else if (percentage >= 50 && percentage < 60)
    {
        grade = 'D';
    }
    else if (percentage >= 60 && percentage < 70)
    {
        grade = 'C';
    }
    else if (percentage >= 70 && percentage < 80)
    {
        grade = 'B';
    }
    else if (percentage >= 80 && percentage < 90)
    {
        grade = 'A';
    }
    else
    {
        grade = 'S';
    }
}
void Student::display()
{
    if (cat1 <= 30 && cat1 >= 0 && cat2 >= 0 && cat2 <= 30 && fat >= 0 && fat <= 60)
    {
        cout << name << endl;
        cout << registerNo << endl;
        printf("%.2f%\n", percentage);
        // cout<<round(percentage,2)<<"%"<<endl;
        cout << grade << endl;
    }
    else
    {
        cout << "Wrong entry" << endl;
    }
}

int main()
{
    Student s;
    s.calcPercentage();
    s.calcGrade();
    s.display();
}

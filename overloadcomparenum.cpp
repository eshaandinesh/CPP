#include <iostream>
using namespace std;

class Number
{
    int num1,num2;
    public:
        Number(int a)
        {
            num1 = a;
            num2 = 25;
        }
        Number(int a,int b)
        {
            num1 = a;
            num2 = b;
        }
        void compare()
        {
            if(num1>num2)
            {
                cout<<num1<<endl<<num2<<endl;
            }
            else
            {
                cout<<num2<<endl<<num1<<endl;
            }
        }
};

int main()
{
    int num;
    cin>>num;
    int b = 0;
    if(num == 2)
    {
        int a,b;
        cin>>a>>b;
        if(a<0||b<0)
        {
            cout<<"Negative number entry not allowed"<<endl;
            return 0;
        }
        Number n(a,b);
        n.compare();
    }
    else
    {
        int a;
        cin>>a;
        if(a<0)
        {
            cout<<"Negative number entry not allowed"<<endl;
            return 0;
        }
        Number n(a);
        n.compare();
    }
    return 0;
}

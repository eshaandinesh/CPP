#include <iostream>
using namespace std;

const int MAX = 20;
class Stack
{
    int top;
    int *items;
    int count;

public:
    Stack()
    {
        top = -1;
        count = 0;
        items = new int[MAX];
    }
    ~Stack()
    {
        delete[] items;
        items = 0;
        top = -1;
        count = 0;
    }
    bool push(const int val)
    {
        bool retval = false;
        if (count < MAX)
        {
            top++;
            count++;
            items[top] = val;
            retval = true;
        }
        else
        {
            cout << "Stack full" << endl;
        }
        return retval;
    }
    bool pop(int &ret)
    {
        bool retval = false;
        if (count > 0)
        {
            ret = items[top];
            top--;
            count--;
            retval = true;
        }
        else
        {
            cout << "Stack empty" << endl;
        }
        return retval;
    }

    unsigned int getCount()
    {
        return count;
    }
    void display()
    {
        for (int i = 0; i < count; i++)
        {
            cout << items[i] << "     ";
        }
        cout << endl;
    }

    bool peek(int &ret)
    {
        bool retval = false;
        if (count > 0)
        {
            ret = items[top];
            retval = true;
        }
        else
        {
            cout << "Stack empty" << endl;
        }
        return retval;
    }
};

int main()
{
    Stack s;
    int retval;
    s.push(3);
    s.push(5);
    s.push(8);
    s.push(1);
    s.push(4);
    s.display();
    s.pop(retval);
    s.push(10);
    int count = s.getCount();
    s.display();
    s.pop(retval);
    cout << "last element = " << retval << endl
         << "Count = " << count << endl;
    s.push(19);
    s.push(18);
    s.push(17);
    s.push(16);
    s.push(15);
    s.push(14);
    s.push(13);
    s.push(12);
    s.push(11);
    s.push(10);
    s.push(9);
    s.push(8);
    s.push(7);
    s.push(6);
    s.push(5);
    s.push(4);
    cout << s.getCount() << endl;
    s.display();
    s.push(3);
    s.peek(retval);
    cout << retval << endl;

    return 0;
}

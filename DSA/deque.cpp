#include <iostream>

#define MAX 5
using namespace std;

class Deque
{
private:
    int front;
    int rear;
    int count;
    int *items;
    // int items[MAX];

public:
    Deque();
    ~Deque();
    bool isEmpty();
    bool isFull();
    bool insertFront(const int);
    bool insertRear(const int);
    bool getFront(int &);
    bool getRear(int &);
    unsigned int getCount();
    void display();
    bool deleteFront();
    bool deleteRear();
};

Deque::Deque()
{
    front = -1;
    rear = -1;
    count = 0;
    items = new int[MAX];
}

Deque::~Deque()
{
    delete[] items;
    items = 0;
    count = 0;
    rear = -1;
    front = -1;
}

bool Deque::isEmpty()
{
    bool retval = false;
    // if(rear == -1)
    if (count == 0)
    {
        retval = true;
    }
    return retval;
}

bool Deque::isFull()
{
    bool retval = false;
    // if(rear == MAX - 1)
    if (count >= MAX)
    {
        retval = true;
    }
    return retval;
}

unsigned int Deque::getCount()
{
    return count;
}

bool Deque::getFront(int &val)
{
    bool retval = false;
    if (front != -1)
    {
        val = items[front];
    }
    else
    {
        cout << "Queue is empty" << endl;
    }
    return retval;
}

bool Deque::getRear(int &val)
{
    bool retval = false;
    if (rear != -1)
    {
        val = items[rear];
    }
    else
    {
        cout << "Queue is empty" << endl;
    }
    return retval;
}

bool Deque::insertFront(const int val)
{
    bool retval = true;
    if (!(isFull()))
    {
        if (front == 0)
        {
            front = MAX - 1;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front--;
        }
        items[front] = val;
        count++;
    }
    else
    {
        cout << "Queue is full" << endl;
        retval = false;
    }
    return retval;
}

bool Deque::insertRear(const int val)
{
    bool retval = true;
    if (!(isFull()))
    {
        if (rear == MAX - 1)
        {
            rear = 0;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        items[rear] = val;
        count++;
    }
    else
    {
        cout << "Queue is full" << endl;
        retval = false;
    }
    return retval;
}

bool Deque::deleteFront()
{
    bool retval = false;
    if (!(isEmpty()))
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        count--;
        retval = true;
    }
    else
    {
        cout << "Queue is empty" << endl;
    }
    return retval;
}

bool Deque::deleteRear()
{
    bool retval = false;
    if (!(isEmpty()))
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }
        count--;
        retval = true;
    }
    else
    {
        cout << "Queue is empty" << endl;
    }
    return retval;
}

void Deque::display()
{
    if (!(isEmpty()))
    {
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX) // loop stops when it reaches last element so it needs to be displayed after loop
        {
            cout << items[i] << "    ";
        }
        cout << items[i] << endl;
    }
    else
    {
        cout << "Queue is empty" << endl;
    }
}

int main()
{
    Deque q;
    q.insertFront(1);
    cout << q.getCount() << endl;
    int retval;
    q.deleteRear();
    cout << q.getCount() << endl;
    q.display();
    q.insertFront(1);
    q.insertFront(2);
    q.display();
    q.getFront(retval);
    cout << retval << endl;

    q.insertRear(1);
    q.insertRear(2);
    q.insertFront(3);
    q.display();
    // int retval;
    q.getFront(retval);
    cout << retval << endl;
    q.deleteFront();
    q.insertRear(1);
    q.insertFront(2);
    cout << endl;
    q.display();
    q.deleteRear();
    q.deleteRear();
    q.display();
    q.insertRear(1);
    q.insertRear(2);
    q.display();

    return 0;
}

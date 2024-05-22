#include <iostream>

#define MAX 5
using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int count;
    int *items;

public:
    Queue();
    ~Queue();
    bool isEmpty();
    bool isFull();
    bool enQueue(const int);
    bool deQueue(int &);
    bool peek(int &);
    unsigned int getCount();
    void display();
};

Queue::Queue()
{
    front = -1;
    rear = -1;
    count = 0;
    items = new int[MAX];
}

Queue::~Queue()
{
    delete[] items;
    items = 0;
    count = 0;
    rear = -1;
    front = -1;
}

bool Queue::isEmpty()
{
    bool retval = false;
    // if(rear == -1)
    if (count == 0)
    {
        retval = true;
    }
    return retval;
}

bool Queue::isFull()
{
    bool retval = false;
    // if(rear == MAX - 1)
    if (count >= MAX)
    {
        retval = true;
    }
    return retval;
}

unsigned int Queue::getCount()
{
    return count;
}

bool Queue::enQueue(const int val)
{
    bool retval = true;
    if (!(isFull()))
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
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

bool Queue::deQueue(int &val)
{
    bool retval = true;
    if (!(isEmpty()))
    {
        val = items[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        count--;
    }
    else
    {
        cout << "Queue is empty" << endl;
        retval = false;
    }
    return retval;
}

bool Queue::peek(int &val)
{
    bool retval = true;
    if (!(isEmpty()))
    {
        val = items[front];
    }
    else
    {
        cout << "Queue is empty" << endl;
        retval = false;
    }
    return retval;
}

void Queue::display()
{
    if(!(isEmpty()))
    {
        int i;
        for (i = front; i != rear; i = (i + 1) % MAX) //loop stops when it reaches last element so it needs to be displayed after loop
        {
            cout << items[i] << "    ";
        }
        cout << items[i] << endl;
    }
    else
    {
        cout<<"Queue is empty"<<endl;
    }
    
}

int main()
{
    Queue q;
    q.enQueue(1);
    cout<<q.getCount()<<endl;
    int retval;
    q.deQueue(retval);
    cout<<q.getCount()<<endl;
    q.display();
    q.enQueue(1);
    q.enQueue(2);
    q.display();
    q.peek(retval);
    cout<<retval<<endl;

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.display();
    //int retval;
    q.deQueue(retval);
    cout << retval << endl;
    q.enQueue(1);
    q.enQueue(2);
    cout<<endl;
    q.display();
    q.deQueue(retval);
    q.deQueue(retval);
    q.display();
    q.enQueue(1);
    q.enQueue(2);
    q.display();


    return 0;
}

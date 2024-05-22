#include <iostream>

#define MAX 5
using namespace std;

class Queue
{
    private:
        //int front;   Not needed as im moving each element while popping, only needed when its not being moved
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
    //front = -1;
    rear = -1;
    count = 0;
    items = new int [MAX];
}

Queue::~Queue()
{
    delete[] items;  
    items = 0;
    count = 0;
    rear = -1;
    //front = -1;
}

bool Queue::isEmpty()
{
    bool retval = false;
    if(count == 0)
    {
        retval = true;
    }
    return retval;
}

bool Queue::isFull()
{
    bool retval = false;
    if(count >= MAX)
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
    if(!(isFull()))
    {
        rear++;
        items[rear] = val;
        count++;
    }
    else
    {   
        cout<<"Queue is full"<<endl;
        retval = false;
    }
    return retval;
}

bool Queue::deQueue(int &val)
{
    bool retval = true;
    if(!(isEmpty()))
    {
        val = items[0];
        for(int i = 0; i < count; i++){
            items[i] = items[i+1];
        }
        count--;
        rear--;
    }
    else
    {
        cout<<"Queue is empty"<<endl;
        retval = false;
    }
    return retval;
}

bool Queue::peek(int &val)
{
    bool retval = true;
    if(!(isEmpty()))
    {
        val = items[0];
    }
    else
    {
        cout<<"Queue is empty"<<endl;
        retval = false;
    }
    return retval;
}

void Queue::display()
{
    
    if(!(isEmpty()))
    {
        for(int i = 0; i < count ; i++)
        {
            cout<<items[i]<<"    ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"Queue is empty"<<endl;
    }
}

int main(){
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

    cout<<q.isEmpty()<<endl;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.display();
    q.deQueue(retval);
    cout<<retval<<endl;
    q.enQueue(5);
    q.display();
    q.enQueue(5);
    q.enQueue(5);
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

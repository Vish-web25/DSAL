#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
private:
    int queue[MAX];
    int front;
    int rear;

public:

    // Constructor
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        cout << value << " inserted into queue." << endl;
    }

    // Dequeue operation
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow!" << endl;
            return;
        }

        cout << queue[front] << " removed from queue." << endl;
        front++;

        // Reset queue when it becomes empty
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }

    // Peek operation
    void peek()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Front element: " << queue[front] << endl;
    }

    // Check if queue is empty
    void isEmpty()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
        }
        else
        {
            cout << "Queue is not empty." << endl;
        }
    }

    // Check if queue is full
    void isFull()
    {
        if (rear == MAX - 1)
        {
            cout << "Queue is full." << endl;
        }
        else
        {
            cout << "Queue is not full." << endl;
        }
    }

    // Display queue
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.peek();

    q.dequeue();

    q.display();

    q.isEmpty();

    q.isFull();

    return 0;
}
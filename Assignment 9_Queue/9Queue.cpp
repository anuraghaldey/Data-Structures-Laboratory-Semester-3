#include <iostream>
using namespace std;
#define n 5
class Queue
{
    int Q[n], front = -1, rear = -1;

public:
    void Enqueue()
    {
        int c;
        if (rear == n - 1)
        {
            cout << "QUEUE OVERFLOW " << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            cout << "ENTER AN ELEMENT: " << endl;
            cin >> c;
            Q[rear] = c;
        }
        else
        {
            rear++;
            cout << "ENTER AN ELEMENT" << endl;
            cin >> c;
            Q[rear] = c;
        }
    }

public:
    void Dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "QUEUE UNDERFLOW, NO ELEMENTS TO DELETE " << endl;
        }
        else if (front == rear && front > -1)
        {
            cout << "THE ELEMENT DELETED IS: " << Q[front] << endl;
            front = front - 1;
            rear = rear - 1;
        }
        else
        {
            cout << "THE ELEMENT DELETED IS: " << Q[front] << endl;
            front++;
        }
    }

public:
    void Display()
    {
        if (front == -1)
        {
            cout << "NO ELEMENTS TO DISPLAY" << endl;
        }
        else
        {
            cout << "THE ELEMENTS ARE: " << endl;
            for (int i = front; i <= rear; i++)
            {
                cout << Q[i] << endl;
            }
        }
    }
};

int main()
{
    Queue Q;

    int d;
    cout << "1.ENQUEUE/ENTER." << endl;
    cout << "2.DEQUEUE/DELETE." << endl;
    cout << "3.DISPLAY." << endl;
    cout << "4.EXIT." << endl;

    do
    {
        cout << "ENTER YOUR CHOICE: " << endl;
        cin >> d;
        switch (d)
        {
        case 1:
            Q.Enqueue();
            break;
        case 2:
            Q.Dequeue();
            break;
        case 3:
            Q.Display();
            break;
        case 4:
            cout << "EXIT" << endl;
            break;
        default:
            cout << "INVALID INPUT." << endl;
        }
    } while (d != 4);
}
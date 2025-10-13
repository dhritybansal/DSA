#include <iostream>
using namespace std;
class Deque 
{
private:
    int *arr;
    int front;
    int rear;
    int size;

public:
   Deque (int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }
    // pushes x in front of deque returns true if it gets pushed
    bool pushFront(int x)
    {
        // check full or not
        if ((front == 0 && rear == size -1)
            || (rear == (front - 1 + size) % (size )))
            { // isfull()
                return false;
            }
        else if (front == -1)
        { // isempty()
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        { // cyclic
            front = size - 1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // pushes x in back of deque
    bool pushRear(int x)
    {
        if ((front == 0 && rear == size - 1)
            || (rear == (front - 1 + size) % (size )))
            { // isfull()
                return false;
            }
        else if (front == -1)
        { // isempty()
            front = rear = 0;
        }
        else if (front != 0 && rear == size - 1)
        { // cyclic
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // pops an element from front off deque
    int popFront()
    {
        if (front == -1)
        { // isempty()
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0; // cyclic
        }
        else
        {
            front++;
        }
        return ans;
    }

    // pops an element from back of deque
    int popRear()
    {
        if (front == -1)
        { // isempty()
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear)
        { // single element is present
            front = rear = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1; // cyclic
        }
        else
        {
            rear--;
        }
        return ans;
    }
    int getFront()
    {
        if (isempty())
        {
            return -1;
        }
        return arr[front];
    }
    int getRear()
    {
        if (isempty())
        {
            return -1;
        }
        return arr[rear];
    }
    bool isempty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }
};
int main() {
  Deque dq(5);

    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(5);
    dq.pushFront(1);

    cout << "Front: " << dq.getFront() << "\n";
    cout << "Rear: " << dq.getRear() << "\n";

    cout << "Popped Front: " << dq.popFront() << "\n";
    cout << "Popped Rear: " << dq.popRear() << "\n";

    cout << "Front: " << dq.getFront() << "\n";
    cout << "Rear: " << dq.getRear() << "\n";

    return 0;
}
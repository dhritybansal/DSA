//Develop a menu driven program demonstrating the following operations on Circular Queues:
//enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int front, rear, size;

public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
       if (front == -1)
       return true;
       else return false;
    }

    bool isFull() {
  if ((front == 0 && rear == size - 1)
            || (rear == (front - 1 + size) % (size ))){
                return true;
            }
            else 
            return false;
    }

  bool enqueue(int x) {
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
    }

    int dequeue() {
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

    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
        } else {
            cout << "Front element: " << arr[front] << "\n";
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << "\n";
    }
};

int main() {
    int n, choice, value;
    cout << "Enter size of queue ";
    cin >> n;

    Queue q(n);

    do {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                 if (q.enqueue(value))
                    cout << "Value enqueued.\n";
                else
                    cout << "Queue is FULL.\n";
                break;
            case 2:
                 if (q.dequeue())
                    cout << "Value dequeued.\n";
                else
                    cout << "Queue is EMPTY.\n";
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << (q.isEmpty() ? "Queue is EMPTY.\n" : "Queue is NOT EMPTY.\n");
                break;
            case 5:
                cout << (q.isFull() ? "Queue is FULL.\n" : "Queue is NOT FULL.\n");
                break;
            case 6:
                q.display();
                break;
            case 7:
                cout << "Exiting\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}

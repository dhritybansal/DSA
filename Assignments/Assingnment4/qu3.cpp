// Write a program interleave the first half of the queue with second half.
// Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9
#include <iostream>
#include <queue>
using namespace std;
void Queue(queue<int> &q)
{
    int n = q.size();
    if (n % 2 != 0)
    {
        cout << "Queue size must be even!\n";
        return;
    }
    int half = n / 2;
    queue<int> temp;

    for (int i = 0; i < half; i++)
    {
        temp.push(q.front());
        q.pop();
    }

    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();

        q.push(q.front());
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    Queue(q);

    cout << "Interleaved queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
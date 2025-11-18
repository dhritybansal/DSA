// Implement priority queues using heaps.
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> pq;
    // max heap;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    pq.push(19);
    cout << "top: " << pq.top() << endl;
    pq.pop();
    cout << "top: " << pq.top() << endl;
    cout << "size is: " << pq.size() << endl;
    pq.empty() ? cout << "empty " : cout << "not empty\n ";

    // min heap
    priority_queue<int, vector<int>, greater<int>> heapq;

    heapq.push(4);
    heapq.push(2);
    heapq.push(5);
    heapq.push(3);
    heapq.push(19);
    cout << "top: " << heapq.top() << endl;
    heapq.pop();
    cout << "top: " << heapq.top() << endl;
    cout << "size is: " << heapq.size() << endl;
    heapq.empty() ? cout << "empty " : cout << "not empty ";
}
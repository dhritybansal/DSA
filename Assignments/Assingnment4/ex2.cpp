
//Sorting a Queue without extra space
//Time Complexity: O(n^2)
//Space Complexity: O(1)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sortQueue(queue<int> &q)
{
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX, idx = -1;

        //  to find min in unsorted part
        for (int j = 0; j < n; j++)
        {
            int x = q.front();
            q.pop();
            if (j < n - i && x < min)
            {  // only checking unsorted part
                min = x;
                idx = j;
            }
            q.push(x);
        }

        // Moving min to back
        for (int j = 0; j < n; j++)
        {
            int x = q.front();
            q.pop();
            if (j != idx)
                q.push(x);
        }
        q.push(min); // inserting min at back
    }
}

int main()
{
    queue<int> q;
    q.push(30);
    q.push(11);
    q.push(15);
    q.push(4);

    sortQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
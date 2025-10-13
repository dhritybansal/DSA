//3) Given a Queue consisting of first n natural numbers (in random order). The task is to check whether
// the given Queue elements can be arranged in increasing order in another Queue using a stack. The
// operation allowed are:
// 1. Push and pop elements from the stack
// 2. Pop (Or Dequeue) from the given Queue.
// 3. Push (Or Enqueue) in the another Queue.
//Time Complexity: O(n)
//Space Complexity: O(n)

#include <iostream>
#include <queue>   
#include <stack>
#include <vector>
using namespace std;

class sorting
{
public:
    stack<int> st;
    int expected = 1;
    bool check(queue<int> &q)
    {
        int n = q.size();
        while (!q.empty())
        {
            int fnt = q.front();
            q.pop();
            if (fnt == expected)
            {
                expected++;
            }
            else
            {
                if (st.empty())
                    st.push(fnt);

                else if (!st.empty() && st.top() < fnt)
                    return false;

                else
                    st.push(fnt);
            }
            while (!st.empty() && st.top() == expected)
            {
                st.pop();
                expected++;
            }
        }
        if (expected - 1 == n && st.empty())
        {
            return true;
        }
        return false;
    }
};
int main()
{
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    sorting s;

    (s.check(q) ? (cout << "Yes") : (cout << "No"));

    return 0;
}
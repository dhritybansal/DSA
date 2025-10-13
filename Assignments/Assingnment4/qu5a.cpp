#include <iostream>
#include <queue>
using namespace std;
class mystack
{
public:
    queue<int> q1;
    queue<int> q2;
    void push(int x)
    {

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop()
    {
        if (q1.empty())
        {
            cout << "Stack underflow\n";
            return -1;
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};
int main()
{
    mystack st;
    st.push(5);
    st.push(2);
    cout << endl
         << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.top() << endl;
    cout << st.empty() << endl;
}

#include <iostream>
#include <queue>
using namespace std;
class mystack
{
private:
    queue<int> q;

public:
    void push(int x)
    {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    int pop()
    {
        if (q.empty())
        {
            cout << "Stack underflow\n";
            return -1;
        }
        int ans = q.front();
        q.pop();
        return ans;
    }

    int top()
    {
        if (q.empty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    bool empty()
    {
        return q.empty();
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

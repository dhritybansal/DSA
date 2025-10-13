#include <iostream>
#include <queue>
using namespace std;
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        queue<int> q;
        for (auto s : students)
            q.push(s);

        int i = 0;
        int rotations = 0;

        while (!q.empty() && rotations < q.size())
        {
            if (q.front() == sandwiches[i])
            {
                q.pop();
                i++;
                rotations = 0;
            }
            else
            {
                q.push(q.front());
                q.pop();
                rotations++;
            }
        }

        return q.size();
    }
};
int main()
{
    Solution s;
    vector<int> st = {1, 1, 0, 0};
  vector<int> sand = {0, 1, 0, 1};
    cout << s.countStudents( st, sand);
}

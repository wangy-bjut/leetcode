#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string res;
        int n = s.size();
        stack<string> stack;
        int i = 0;
        while (i < n)
        {
            while (s[i] == ' ' && i < n)
            {
                i++;
            }
            if (i < n)
            {
                string str;
                while (s[i] != ' ' && i < n)
                {
                    str.push_back(s[i]);
                    i++;
                }
                stack.push(str);
            }
        }

        while (!stack.empty())
        {
            res.append(stack.top());
            res.push_back(' ');
            stack.pop();
        }

        return res;
    }
};

int main()
{
    Solution A;

    string str = "  hello world  ";

    string res = A.reverseWords(str);
}
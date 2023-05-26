#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        for(auto str:tokens)
        {
            if(str == "+" || str == "-" || str == "*" || str == "/")
            {
                int temp1 = stack.top();
                stack.pop();
                int temp2 = stack.top();
                stack.pop();
                if(str == "+")
                {
                    stack.push(temp1+temp2);
                }
                else if(str == "-")
                {
                    stack.push(temp2-temp1);
                }
                else if(str == "*")
                {
                    stack.push(temp2*temp1);
                }
                else
                {
                    stack.push(temp2/temp1);
                }
                
            }
            else
            {
                stack.push(str[0]-'0');
            }
        }

        return stack.top();

    }
};

int main()
{
    Solution A;
    vector<string> token{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    int res = A.evalRPN(token);
}
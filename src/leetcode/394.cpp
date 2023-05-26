#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> stanum;
        stack<string> stastr;

        string res = "";

        string temp = "";
        int num = 0;

        for(auto str:s)
        {
            if(str-'0' >0 && str-'0'<=9)
            {
                num = num*10+str-'0';
            }
            else if(str == '[' && num != 0)
            {
                stanum.push(num);
                num = 0;
            }
            else if(str == ']' && temp!="")
            {
                stastr.push(temp);
                temp = "";
            }
            else
            {
                temp.push_back(str);
            }
        }

        return res;


    }
};


int main()
{
    Solution A;
    string res =  "3[a2[c]]";
    
    string re = A.decodeString(res);
}
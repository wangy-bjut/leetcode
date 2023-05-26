#include<string>
#include<stack>

using namespace std;

class Solution { 
public:
    string reverseWords(string s) {
       stack<string> sta;

       bool start = false;
       bool end = false;
       for(int i = 0;i<s.size();i++)
       {
          if(s[i] == ' ')
          {
              continue;
          }
          else
          {
              string temp;
              while(s[i] != ' '&&i<s.size())
              {
                  temp.push_back(s[i]);
                  i++;
              }
              sta.push(temp);
          }
       }

       string res;
       while(!sta.empty())
       {
           res.append(sta.top());
           sta.pop();
       }

       return res;
    }
};

int main()
{
    Solution A;
    string s = "the sky is blue";
    string res = A.reverseWords(s);
}
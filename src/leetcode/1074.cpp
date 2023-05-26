#include<string>
#include<deque>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> deque;
        int n = s.size();
        int start = n, end = 0;
     
         for(int i = 0;i<s.size();i++)
         {
             if(!deque.empty()&&deque.front() == s[i])
             {
                 deque.pop_front();
                 continue;
             }
             else
             {
                 deque.push_front(s[i]);
             }
             
         }
        string temp;
         while(!deque.empty())
         {
             temp.push_back(deque.back());
             deque.pop_back();
         }
         s = temp;
         

     

     return s;
        

    }
};

int main()
{
    Solution A;

    string str = "abbaca";

    string res = A.removeDuplicates(str);
}
#include<string>
#include<unordered_set>

using namespace std;



class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.length();
        string s = password;
        bool little = false,big = false,number = false,spec = false;
        unordered_set<char> specials = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};

        if(n<8)
        {
            return false;
        }

        for(int i =0;i<n;i++)
        {
            char ch = s[i];
            if(s[i] == s[i+1])
            {
                return false;
            }

            if(ch>='a'&& ch <='z')
            {
                little = true;
            }
            else if(ch>='A'&&ch <='Z')
            {
                big = true;
            }
            else if( specials.count(s[i]))
            {
                spec = true;

            }
            else if(ch >= '0' && ch<= '9')
            {
                number = true;
            }
        }

        if(little == true && big == true && number == true && spec == true)
        {
            return true;
        }
        else
        return false;
        
    }
};

int main()
{
    string x = "IloveLe3tcode!";
    Solution A;
    bool res;
    res = A.strongPasswordCheckerII(x);

}
#include<string>

using namespace std;


class Solution {
    void reverse(string &s, int l, int r)
    {
        while(l<r)
        {
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
public:
    string reverseStr(string s, int k) {
        int i = 0,l = 0;
        int n = s.size();
        int num = n/(2*k);
        
        while(i<num)
        {
            reverse(s,l,l+k-1);
            l += 2*k;
            i++; 
        }

        if(n%(2*k)<k)
        {
            reverse(s,num*2*k,n-1);
        }
        else if(n%(2*k)<2*k && n%(2*k)>=k)
        {
            reverse(s,num*2*k,num*2*k+k-1);
        }

  

        return s;

    }
};
int main()
{
    Solution A;
    string input = "abcdefgab";

    string res = A.reverseStr(input,2);
}
#include<string>
#include<vector>

using namespace std;

class Solution {
    vector<string> res;

    bool iseffect( string &s, int l, int r)
    {
        int num = 0;
        while(l<=r)
        {
            if(s[l] <'0' || s[l] > '9')
            {
                return false;
            }
            num =  num*10+s[l]-'0';
            if(num>255)
            {
                return false;
            }
            l++;
        }
        if(num>=0 && num <=255)
        {
            return true ;
        }

        return false;
    }
    void getnum( string &s, int index, int num)
    {
        if(num == 3 && iseffect(s,index,s.size()-1))
        {
            
            res.push_back(s);
            return;
        }
        
        for(int i = index;i<s.size();i++)
        {
          
            if(iseffect(s,index,i))
            {
                s.insert(s.begin()+i+1,'.');
                getnum(s,i+1,num+1);
                s.erase(s.begin()+i+1);
            }
            else
                break;
           
        }

        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
    getnum(s,0,0);

    return res;   

    }
};

int main()
{
    Solution A;

    string str = "25525511135";

    vector<string> res = A.restoreIpAddresses(str);
}
#include<string>
#include<vector>

using namespace std;

class Solution {
    vector<vector<string>> res;
    vector<string> temp;

    bool isstr(string &s,int l, int r)
    {
        
        while(l<=r)
        {
            if(s[l] != s[r])
            {
                return false;
            }
            l++;
            r--;
        }

        return true;
    }

    void getnum(string s,int index)
    {
        if(index >= s.size())
        {
            res.push_back(temp);
            return;
        }

        for(int i = index;i<s.size();i++)
        {
            
            if(isstr(s,index,i))
            {
                string str = s.substr(index,i-index+1);
                temp.push_back(str);
            }
            else
            {
                continue;
            }

            getnum(s,i+1);
            temp.pop_back();
            
        }

        return;
    }
public:
    vector<vector<string>> partition(string s) {

        getnum(s,0);

        return res;
    }
};


int main()
{
    Solution A;
    string str = "aab";
    vector<vector<string>> res;
    res = A.partition(str);
}
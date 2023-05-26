#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        unordered_map<int,char> hash;
        int num = 0,res = 0;
        for(int i=0;i<pref.size();i++)
        {
            hash[i] = pref[i];
        }

        for(int i=0;i<words.size();i++)
        {
            for(int j = 0;j<pref.size();j++)
            {
                char a = words[i][j];
                
                if(hash[j]!=a)
                {
                    break;
                }
                num++;
            }
            if(num == pref.size())
            {
                res++;
            }
            num = 0;
        }

        return res;
        
    }
};

int main()
{
    vector<string> vec={"pay","attention","practice","attend"};

    string pre = "at";

    Solution A;
    int res;

    res = A.prefixCount(vec,pre);
}    
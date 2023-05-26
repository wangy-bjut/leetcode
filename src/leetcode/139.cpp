#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        string res;
        int n = s.size();
        string s1 =s;
        int k = 0;
        for(auto &st:wordDict)
        {
            hash.emplace(st);
        }

        for(int i = 0;i<n;i++)
        {
            res.push_back(s[i]);
            k++;
            if(hash.count(res))
            {
                s1.erase(0,k);
                res.clear();
                k = 0;
            }
        }

        if(s1.empty())
        {
            return true;
        }

        return false;

    }
};

int main()
{   
    Solution A;
    vector<string> vec{{"aaa"},{"aaaa"}};
    string s = "aaaaaaa";

    bool a = A.wordBreak(s,vec);
}
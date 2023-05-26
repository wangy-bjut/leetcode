#include<vector>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        string temp;
        vector<vector<string>> res; 
        vector<string> vec;
        while(!strs.empty())
        {
            vector<string> vec;
            temp = strs.back();
            vec.push_back(temp);
            sort(temp.begin(),temp.end());
            int n = strs.size();
            for(int i = n-1;i>=0;i-- )
            {
                string temp1 = strs[i];
                sort(temp1.begin(),temp1.end());
                if(temp == temp1)
                {
                    vec.push_back(strs[i]);
                    swap(strs[i],strs.back());
                    strs.pop_back();
                }
            
            }
            res.push_back(vec);

        }

        return res;
        


    }
};

int main()
{
    Solution A;
    vector<vector<string>> res;
    vector<string> vec{"eat","tea","tan","ate","nat","bat"};

    res = A.groupAnagrams(vec); 
}

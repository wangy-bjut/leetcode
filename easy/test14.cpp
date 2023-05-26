#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size()-1;
        int min_len = strs[0].size();
        int min_num;
        for(int i=0;i<num;i++)
        {
            if(strs[i].size()<min_len)
            {
                 min_len=strs[i].size();
                 min_num = i;
            }
               
        }
        for(int i=0;i<min_len;i++)
        {
            for(int j=0;j<num;j++)
            {
                if(i==0 && strs[j][i]!=strs[j+1][i])
                {
                    return "";
                }
                else if(strs[j][i]!=strs[j+1][i])
                {
                    return strs[min_num].substr(0,i);
                }
        
            }
          
        }
        return strs[min_num];

    }
};
int main()
{
    string sum;
    Solution sol;
    vector<string> strs={
        "flower",
        "flow",
        "flight"
    };
    sum = sol.longestCommonPrefix(strs);

    cout<<sum;


}
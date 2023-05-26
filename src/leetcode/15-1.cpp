#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i = 0; i<n;i++)
        {
            if(i>0&&nums[i] == nums[i+1])
            {
                continue;
            }
            
            for(int l = i+1; l<n;l++)
            {
                if(l>i+1 && nums[l] == nums[l+1])
                {
                    continue;
                }
                
                for(int r = n-1;r>l;r--)
                {
                    if(r<n-1&&nums[r] == nums[r-1])
                    {
                        continue;
                    }

                    if(nums[i]+nums[l]+nums[r] == 0)
                    {
                        res.push_back({nums[i],nums[l],nums[r]});
                    }
                }
            }
        }

        return res;
 

    }
};

int main()
{
    Solution A;
    vector<int> vec{-1,0,1,2,-1,-4};
    vector<vector<int>>  res;

    res = A.threeSum(vec);
}
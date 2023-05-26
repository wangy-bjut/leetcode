#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
    void back(vector<int> &nums,int target, unordered_set<int> &hash, int sum)
    {
        if(hash.size() == nums.size())
        {
            return;
        }

        for(int i = 0;i<nums.size();i++)
        {
           
        
            if(hash.count(i) || sum > target )
            {
                continue;
            }
            if(sum == target)
            {
                back(nums,target,hash,0);

            }
            else
            {
                hash.emplace(i);
                back(nums,target,hash,sum+nums[i]);
                hash.erase(i);
             

            }

           
        }
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
       int sum = 0;
       for(auto num:nums)
       {
           sum+=num;
       }
       if(sum%k == 1)
       {
           return false;
       }

       int target = sum/k;

        unordered_set<int> hash; 
       
       back(nums,target,hash,0);

       if(hash.size() == nums.size())
       {
           return true;
       }

       return false;

    }
};


int main()
{
    Solution A;
    vector<int> vec{1,1,1,1,2,2,2,2};

    int x = 4;

    bool res = A.canPartitionKSubsets(vec,4);
}
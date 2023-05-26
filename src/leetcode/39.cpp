#include<vector> 
#include<algorithm>
#include<unordered_set>
#include<unordered_map>



using namespace std;


class Solution {

    void back(vector<int> &candidates, vector<vector<int>> &res, vector<int> &nums, int target, int index,int sum,int n)
    {
        for(int i = index;i<n;i++)
        {
            if(sum>target)
            {
                return;
            }
             if(sum == target)
            {
                res.push_back(nums); 
                
            }
            
            if(sum < target )
            {
            nums.push_back(candidates[i]);
            back(candidates,res,nums,target,i,sum+candidates[i],n);
            nums.pop_back();
            }


        
        }
       

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> nums;
        int temp = 0;
        
        if(candidates[0]>target)
        {
            return res;
        }

        if(candidates[0] == target)
        {
            vector<int> temp{candidates[0]};
            res.push_back(temp);
        }

        back(candidates,res,nums,target,0,temp,n);

       

        return res;
        
    }
};

int main()
{
    Solution A;
    vector<vector<int>>  res;

    vector<int> vec{2,3,6,7};
    int target = 7;

    res = A.combinationSum(vec,target);
    
}
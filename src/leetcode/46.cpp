#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
    void back(vector<vector<int>> &res, vector<int> &temp, vector<int> &nums,  int n, int index)
    {

         if(temp.size() == n )
        {
            res.push_back(temp);
        }

        for(int i = index;i<n;i++)
        {
                
            temp.push_back(nums[i]);
            swap(nums[i],nums[index]);
            back(res,temp,nums,n,index+1);
            swap(nums[i],nums[index]);
            temp.pop_back();
            
        }
       

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        unordered_set<int> hash;

        int n = nums.size();

        back(res,temp,nums,n,0);

        return res;

    }
};
int main()
{
    Solution A;
    vector<vector<int>> res;
    vector<int> vec{1,2,3};

    res = A.permute(vec);
}
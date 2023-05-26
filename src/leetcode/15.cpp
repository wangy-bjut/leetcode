#include<vector>
#include<unordered_set>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
       
        int n = nums.size();
        int l,r;
        // 插入排序
        for(int i = 1;i<n;i++)  
        {
            int key = nums[i];
            for(int j = i-1;j>=0;j--)
            {   
                if(key<nums[j])
                {
                    
                    nums[j+1] = nums[j];
                    nums[j] = key;
                }
              
            }
        }
        
        
        for(int i = 0;i<n;i++)
        {
          if(nums[i]>0)
          {
              break;
          }

          if(i>0 && nums[i] == nums[i-1])
          {
              continue;
          }
          l = i+1;
          r = n-1;

          while(l<r)
          {
              if(nums[i]+nums[l]+nums[r] == 0)
              {
                  vector<int> num;
                  num.push_back(nums[i]);
                  num.push_back(nums[l]);
                  num.push_back(nums[r]);

                  vec.push_back(num);
                while(l<r&&nums[l] == nums[l+1])
              {
                  l++;
              }

               while(l<r&&nums[r] == nums[r-1])
              {
                  r--;
              }
              l++;
              r--;
    
              }
              else if(nums[i]+nums[l]+nums[r] > 0)
              {
                  r--;
              }
              else
              {
                  l++;
              }

          }
                   
        }

        return vec;
    }
};

int main()
{
    Solution A;
    vector<int> vec{-1,0,1,2,-1,-4};
    vector<vector<int>>  res;

    res = A.threeSum(vec);
}
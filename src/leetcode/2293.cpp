#include<vector>

using namespace std;

class Solution {
public:

     int minMaxGame1(vector<int>& nums) {

        

        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        

            vector<int> newNums(n/2);
            for(int i = 0;i<n/2;i++)
            {
                if(i%2==0)
                {
                    newNums[i] = min(nums[2*i],nums[2*i+1]);
                }
                else
                {
                    newNums[i] = max(nums[2*i],nums[2*i+1]);
                }
            }
           

        return minMaxGame1(newNums);
      
        
    }


    int minMaxGame(vector<int>& nums) {

        int n = nums.size();
        
        while(n != 1)
        {
            vector<int> newNums(n/2);
            for(int i = 0;i<n/2;i++)
            {
                if(i%2==0)
                {
                    newNums[i] =  min(nums[2*i],nums[2*i+1]);
                }
                else
                {
                    newNums[i] = max(nums[2*i],nums[2*i+1]);
                }
            }
            n = newNums.size();
            nums = newNums;
        }

        return nums[0];
      
        
    }

    
};

int main()
{
    int res;
    Solution A;
    vector<int> vec{1,3,5,2,4,8,2,2};

    res = A.minMaxGame1(vec);
}
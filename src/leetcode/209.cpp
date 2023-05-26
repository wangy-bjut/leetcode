#include<vector>
#include<algorithm>


using namespace std;

class Solution1 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        
        int sum = 0;
        int res = 0;
       
       for(int r = 0;r<n;r++)
       {
           sum+=nums[r];

           while(sum>=target)
           {
               if(res == 0)
               {
                   res = r-l+1;
               }
               else
               {
                   res = min(res,r-l+1);
               }
               sum-=nums[l];
               l++;
           }
       }
               

        return res;


    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        
        int sum = 0;
        int res = 0;
        while(r<n )
        {
            sum-=nums[l];
            while(sum >=target)
            {
                if(res == 0)
                {
                    res = r-l+1;
                }
                else
                {
                    res = min(res,r-l+1);
                }
                
                l++;
            } 
            sum+=nums[r];
            r++;
            

        }

        return res;


    }
};


int main()
{
    Solution A;
    vector<int> vec{2,3,1,2,4,3};
    int targte = 7;

    int res;

    res = A.minSubArrayLen(targte,vec);
}
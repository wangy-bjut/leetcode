#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size();
        int l = 0,r = n-1;

        if(!n)
        {
            return -1;
        }
        if(n == 1)
        {
            if(nums[0] == target)
            {
                return 0;

            }
            else
            return -1;
        }
        

        while(l<=r)
        {
            int mid = l+((r-l)>>1);
            if(nums[mid] == target)
            {
                return mid;
            }
            if(nums[l] <nums[mid])
            {
                if(nums[l]<target && target<nums[mid])
                {
                    r = mid;
                }
                else
                l = mid;
            }
            else{
                if(nums[mid]<target && target < nums[r])
                {
                    l = mid;
                }
                else
                r = mid;
            }

            
        }
        
       
            return -1;
    


    }
};

int main()
{
    vector<int> num{1};
    int target = 0;
    Solution A;
    int res;
    res = A.search(num,target);
}
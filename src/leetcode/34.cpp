#include<vector>

using namespace std;



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> res(2,-1);

       int l = 0;
       int r = nums.size()-1;

       int m = 0;

       while(l<=r)
       {
           int mid = l+((r-l)/2);
           if(nums[mid]>target)
           {
               r = mid-1;
           }
           else if(nums[mid]<target)
           {
               l = mid+1;
           }
           else
           {
               m = mid;
               break;
           }
       }

       if(l > r)
       {
           return res;
       }

       l = m-1;
       r = m+1;
       while(l>=0 && nums[l] == target)
       {
        if(nums[l] == target)
        {
            res[0] = l;
            l--;
        }
       }

       while (r<=nums.size()-1 && nums[r] == target)
       {
            if(nums[r] == target)
            {
                res[1] = r;
                r++;
            }
       }
       
       if(res[0] == -1)
       {
           res[0] = m;
       }
       if(res[1] == -1)
       {
           res[1] = m;
       }

       return res;
    }
};

int main()
{
    Solution A;

    vector<int> nums{5,7,7,8,8,10};

    vector<int> res;
    res = A.searchRange(nums,8);
}
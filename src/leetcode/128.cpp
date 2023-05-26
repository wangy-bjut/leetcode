#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;


class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int maxm = 0;
        int n = nums.size();
        int l = 0, r = 1;
        int sum = 1;

        if(n == 0 || n == 1)
        {
            return n;
        }
        while(r<n)
        {
            if(nums[l] == nums[r]-1)
            {
                sum++;
                r++;
                l++;
            }
            else if(nums[l] == nums[r])
            {
                l = r;
                r = l+1;
            }
            else
            {
                maxm = max(maxm,sum);
                sum = 1;
                l = r;
                r = l+1;
            }
        }

        if(sum == n)
        {
            maxm = n;
        }

        return maxm;

    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int maxm = 0;
        int n = nums.size();
        int  r = 1;
        int sum = 1;

        if(n == 0 || n == 1)
        {
            return n;
        }
        while(r<n)
        {
            if(nums[r] == nums[r-1]+1)
            {
                sum++;
                r++;
            }
            else if(nums[r] == nums[r-1])
            {
                r++;
            }
            else{
                maxm = max(maxm,sum);
                sum = 1;
                r++;
            }


        }

        return maxm;
    }
};


int main()
{
    Solution A;

    vector<int> vec{0,3,7,2,5,8,4,6,0,1};

    int res = A.longestConsecutive(vec);
}
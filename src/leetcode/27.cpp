#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int l = 0,r = n-1;
        int num = 0;

        while(l<=r)
        {
            if(nums[l]==val)
            {
                swap(nums[l],nums[r]);
                r--;
                num++;
            }
            else
            {
                l++;
            }
        }

        for(int i= 0;i<num;i++)
        {
            nums.pop_back();
        }

        return num;

    }
};

int main()
{
    Solution A;

    vector<int> vec{0,1,2,2,3,0,4,2};

    int res = A.removeElement(vec,2);
}
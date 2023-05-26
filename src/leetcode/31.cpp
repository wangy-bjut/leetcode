#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int  tem = nums[n-1];
        int index = n+1;
        int index1 = n+1;
        for(int i = n-1; i>0 ; i--)
        {
            if(nums[i]>nums[i-1])
            {
               index = i-1;
               break;
            }
        }

        if(index == n+1)
        {
            sort(nums.begin(),nums.end());
            return;
        }

        for(int i = n-1;i>index;i--)
        {
            // 我们的目的是找到逆序对之前的比index值大的元素中最小的一个值， 因为逆序对之前我们都是按升序拍好的，所以遍历到的第一个值就是此值
            if(nums[i]>nums[index]  )
            {
                index1 = i;
            }
        }

        swap(nums[index],nums[index1]);

        sort(nums.end()-n+index+1, nums.end());

    }
};

int main()
{
    Solution A;
    vector<int> vec{2,3,1};

    A.nextPermutation(vec);
}
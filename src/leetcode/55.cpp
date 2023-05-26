#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int index = 0;
        int end = index+nums[0];
        int res = 0;
        while(end>=nums.size()-1)
        {  
            int in = 0,temp = nums[index];
            for(int i =index;i<=end;i++)
            {
                if(nums[i]>temp)
                {
                    temp = nums[i];
                    in = i;
                }
            }
            res++;
            index = in;
            end = index+nums[index];
        }

        return res+1;

    }
};

int main()
{
    Solution A;
    vector<int> vec{2,3,1,1,4};

    int ress = A.jump(vec);
}
#include<vector>

using namespace std;


class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        int sum1 = 0,sum2 = 0;

        for(int i = 0;i<n;i++)
        {
            if(i%2 == 0)
            {
                sum2++;
            }
            else
                sum1++;
        }

        int cur1 = 0,cur2 = 0;

        for(int i = 0;i<n;i++)
        {
            if(i%2 == 0)
            {
                if(cur2 + sum1 - cur1 == cur1 + sum2 - cur2 - nums[i]  )
                {
                    res++;
                    
                }
                cur2+=nums[i];
            }
            else
            {
                if(cur2 + sum1 - cur1 - nums[i] == cur1 + sum2 - cur2 )
                {
                    res++;
                    
                }
                cur1+=nums[i];
            }
        }
        
       

    return res;


    }
};
int main()
{
    Solution A;
    int res ;
    vector<int> vec{2,1,6,4};

    res = A.waysToMakeFair(vec);
}
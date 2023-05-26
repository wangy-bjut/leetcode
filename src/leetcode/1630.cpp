#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<vector<int>> vec;
        vector<bool> res;

        for(int i = 0;i<l.size();i++)
        {
            int left = l[i],right = r[i];

            vec.push_back(vector<int>(nums.begin()+l[i],nums.begin()+r[i]+1));
        }

        for(auto num:vec)
        {
            sort(num.begin(),num.end());
            if(num.size()>1)
            {
                int l = 0,r = l+1;
                int errror = num[r] - num[l];
                while(r<num.size())
                {
                    if(num[r] - num[l] != errror)
                    {
                        res.push_back(false);
                        break;
                    }
                    l++;
                    r++;
                }

                if(r == num.size())
                {
                    res.push_back(true);
                }
                
            }
            else
            {
                res.push_back(false);
            }
        }

        return res;
    }
};

int main()
{
    Solution A;

    vector<int> nums{4,6,5,9,3,7}, l{0,0,2},r{2,3,5};

    vector<bool> res = A.checkArithmeticSubarrays(nums,l,r);
}
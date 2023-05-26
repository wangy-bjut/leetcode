#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {

   int rev(int num)
    {
        int x = 0;
        while(num/10 != 0)
        {
            x = 10*x;
            x  += num%10;
            num = num/10;
        }

        x = x*10+num;
        return x;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int MOD = 1000000007;
        int res = 0;
        int n = nums.size();
        unordered_map<int,int> hash;
        

        for(int i = 0;i<n;i++ )
        {
            res=(res+hash[nums[i]-rev(nums[i])]);
            hash[nums[i]-rev(nums[i])]++;
            
            
        }
        
        

       

        return res;


    }
};

int main()
{
    int x = 0;
    Solution A;

    vector<int> vec{13,10,35,24,76};

    x = A.countNicePairs(vec);
    
}
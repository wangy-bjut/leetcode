#include<string>
#include<vector>
#include<numeric>

using namespace std;



class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l=0,r=0;
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int ans=n+1;
        if(sum < x)
        {
            return -1;
        }
        if(sum == x)
        {
            return ans;
        }
        
        for(l=0;l<n;l++)
        {
           
          
            while(sum>x && r<n)
            {
                sum -= nums[r];
                r++;
            }

            if(sum == x)
            {
                ans = min(ans,n-r+l);
            }
            
            
            sum+=nums[l];

            

          
        }
      

        return ans>n ? -1: ans;
       
    }


};



int main()
{
    Solution A;
    vector<int> vec={8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309};
    int x = 134365;
    int res;
    res = A.minOperations(vec,x);
}
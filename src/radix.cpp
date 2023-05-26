#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void radixsort(vector<int> &nums)
    {

        int n = nums.size();
        int maxm = nums[0];
        int digital = 0;
        for (int i = 0; i < n; i++)
        {
            maxm = max(maxm, nums[i]);
        }

        while (maxm != 0)
        {
            maxm /= 10;
            digital++;
        }

        radix(nums, digital);
    }

    // 利用前缀和完成 不同数位的入桶 出桶的排序
    
    void radix(vector<int> &nums, int digital)
    {
        int n = nums.size();
        vector<int> res(n, 0);

        for (int i = 1; i <= digital; i++)
        {
            int num[10] = {};

            for (int j = 0; j < n; j++)
            {
                num[getbit(nums[j],i)]++;
                
            }
            for (int j = 1; j < 10; j++)
            {
                num[j] = num[j] + num[j - 1];
            }

            for (int j = n - 1; j >= 0; j--)
            {
              
               res[--num[getbit(nums[j],i)]] = nums[j];
              
            }

            for (int j = 0; j < n; j++)
            {
                nums[j] = res[j];
            }
        }
    }

    int getbit(int num, int bit)
    {
        int res = 0;
        for(int i=0;i<bit;i++)
        {
            res = num%10;
            num/=10;
        }

        return res;
    
    }
};

int main()
{
    Solution A;
    vector<int> res{3,4,8,5,32, 134, 111,0};

   
    A.radixsort(res);
}
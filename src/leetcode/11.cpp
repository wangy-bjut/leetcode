#include<vector>

using namespace std;



// 时间不符合； 应该采用双指针， 移动指针时， 选择数值较小的进行移动
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxw = 0;
        int num = height.size();
        int s = 0 ;
        int l = 0,r= num;
        while(l<r)
        {
            s = min(height[l],height[r]) * (r-l);
            maxw = max(maxw,s);

            if(height[l]>height[r])
            {
                r--;
            }
            else
            {
                l++;
            }
        }
       

        return maxw;

    }
};

int main()
{
    Solution A;

    vector<int> vec{1,8,6,2,5,4,8,3,7};

    int res;
    res = A.maxArea(vec);
}
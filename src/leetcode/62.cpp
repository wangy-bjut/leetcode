using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {

    int nums[m][n]={};
        

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(j == 0 || i == 0)
            {
                nums[i][j] = 1;
            }
            else
            {
                nums[i][j] = nums[i-1][j] + nums[i][j-1];
            }
        }
    }

    return nums[m-1][n-1];

    }
};

int main()
{
    Solution A;

    int m = 3, n = 7;

    int res = A.uniquePaths(m,n);
}
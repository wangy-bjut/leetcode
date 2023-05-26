#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] == 1 || obstacleGrid[0][0] == 1)
        {
            return 0;
        }

        int res[m][n];
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) res[i][0] = 1;
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) res[0][j] = 1;
        for(int i=1;i<m;i++)
        {
            for(int j =1;j<n;j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    continue;
                }
                res[i][j] = res[i-1][j] + res[i][j-1];

            }
        }

        return res[m-1][n-1];

    }
};
int main()
{
    Solution A;

    vector<vector<int>> vec{{0,0},{1,1},{0,0}};

    int res = A.uniquePathsWithObstacles(vec);
}
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void bag_problem()
    {
        vector<int> weight = {1, 2, 4};
        vector<int> vaule = {15, 20, 30};

        int begweight = 4;

        vector<vector<int>> dp(weight.size(), vector<int>(begweight + 1, 0));

        for (int i = weight[0]; i <= begweight; i++)
        {
            dp[0][i] = vaule[0];
        }

        for (int i = 0; i < weight.size(); i++)
        {
            for (int j = 0; j <= begweight; j++)
            {
                if (weight[i] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + vaule[i]);
                }
            }
        }

        cout << dp[weight.size() - 1][begweight] << endl;
    }
};


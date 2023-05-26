#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

class Solution {

    void back(const vector<int> &obstacles, int now , int i , int step,int &mstep )
    {
        if(i == obstacles.size()-1)
        {
            mstep = min(step, mstep);
            return;
        }
       

        if(now == obstacles[i])
        {
            for(int j = 1;j<=3;j++)
            {
                if(j == obstacles[i] || j == obstacles[i-1])
                {
                    continue;
                }
                back(obstacles,j,i+1,step+1,mstep);
            }
        }
        else
        {
            back(obstacles,now,i+1,step,mstep);
        }

      
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        int i = 1;
        int mstep = n+1;
        int step = 0;
        back(obstacles,2,i,0,mstep);

        return mstep;

    }
};

class Solution1 {
    static constexpr int inf = 0x3f3f3f3f;
public:
    int minSideJumps(vector<int> &obstacles) {
        int n = obstacles.size() - 1;
        vector<int> d = {1, 0, 1};
        for (int i = 1; i <= n; i++) {
            int minCnt = inf;
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1) {
                    d[j] = inf;
                } else {
                    minCnt = min(minCnt, d[j]);
                }
            }
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1) {
                    continue;
                }
                d[j] = min(d[j], minCnt + 1);
            }
        }
        return *min_element(d.begin(), d.end());
    }
};




int main()
{
    Solution1 A;
    vector<int> vec{0,2,1,0,3,0};
    int res;
    res = A.minSideJumps(vec);
}
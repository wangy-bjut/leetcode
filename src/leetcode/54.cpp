#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int loop = m*n;

        int l=  0,r = m-1,u = 0,d = n-1;
        int end=0;

        vector<int> res;

        while(loop>0)
        {
            for(int i = l;i<r;i++)
            {
                res.push_back(matrix[l][i]);
                loop--;
            }

            for(int i = u;i<d;i++)
            {
                res.push_back(matrix[i][r]);
                loop--;
            }

            for(int i = r;i>l;i-- )
            {
                res.push_back(matrix[d][i]);
                loop--;
            }

            for(int i = d;i>u;i--)
            {
                res.push_back(matrix[i][l]);
                loop--;
            }

            l++;
            u++;
            d--;
            r--;
        
        }

        return res;

    }
};

int main()
{
    Solution A;
    
    vector<vector<int>> vec{{1,2,3},{4,5,6},{7,8,9}};

    vector<int> res = A.spiralOrder(vec);
}
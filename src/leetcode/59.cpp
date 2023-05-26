#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));

        int t = 0,r = n-1,d = n-1,l = 0;
        int loop = 1;
        int m = n*n;
        int e = 0;

        while(loop<=m)
        {
            for(int i = t;i<n-1;i++)
            {
                res[t][i] = loop;
                loop++;
            }
           
            if(loop>m)
            {
                return res;
            }
            for(int i = t;i<n-1;i++)
            {
                
                res[i][r] = loop;
                loop++;
                
            }
            
            if(loop > m)
            {
                return res;
            }

            for(int i = d;i>e;i--)
            {
               res[d][i] = loop;
               loop++;

            }
            
            if(loop > m)
            {
                return res ;
            }
            
            for(int i = d;i>0;i--)
            {
                res[i][l] = loop;
                loop++;
            }
            
            n--;
            t++;
            r--;
            d--;
            l++;
            e++;

        }

        return res;
    }
};

int main()
{
    Solution A;

    vector<vector<int>> res;

    res = A.generateMatrix(5);

}
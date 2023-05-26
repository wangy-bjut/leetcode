

class Solution {

    
public:
    int numTrees(int n) {
        int res = 0;
        int a[n] = {};
        a[0] = 1;
        a[1] =1;
        
         for(int i = 2;i<n;i++)
         {
             for(int j = i;j>=0;j--)
             {
                 a[i] += a[j-1]*a[n-j];
             }
         }

        return a[n];
    }
};

int main()
{
    Solution A;
    int n = 3;

    int res = 0;

    res =   A.numTrees(n);
}
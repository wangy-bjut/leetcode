#include<vector>

using namespace std;

class Solution
{
public:
//归并排序  注意空数组以及一个数的情况单独考虑
    int process(vector<int> &num, int L, int R)
    {
        if(L == R)
        {
            return 0;
        }
         
        int mid = L + ((R-L) >> 1);
        int x1,x2,x3;
        x1 = process(num,L,mid);
        x2 = process(num,mid+1,R);
        x3 = merge(num,L,mid,R);
        
        return x1+x2+x3;

    }

    int merge(vector<int> &num, int L, int M, int R)
    {
        vector<int> temp;
        int p = M+1;
        int p1 = L;
        int res=0;
        
        while(p1<=M && p<=R)
        {
            res+= num[p1]<num[p] ? num[p1]*(R-p+1) : 0;
            
            if(num[p1]<num[p])
            {
                //res+=num[p1]*(R-p+1);
                temp.push_back(num[p1]);
                p1++;
            }
            else 
            {
                temp.push_back(num[p]);
                p++;
            }
           
        }
        while(p1<=M)
        {
            temp.push_back(num[p1]);
            p1++;
        }
        while (p<=R)
        {
            temp.push_back(num[p]);
            p++;
        }

        for(int i = 0;i<temp.size();i++)
        {
            num[L+i] = temp[i];
        }

       

      

        return res;
        

    }


};

int main()
{
    Solution A;
    vector<int> vec{5,3,8,1,0};
    vector<int> res1,res2;
    int res;
   // res1 = A.select(vec);
   // res2 = A.MaoPao(vec);
   int L = 0,R = vec.size()-1;
   res = A.process(vec,L,R);
   int i = 0;

}
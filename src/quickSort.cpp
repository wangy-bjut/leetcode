#include<vector>
#include<algorithm>
#include<random>


using namespace std;

// 空间复杂度 logn
class Solution
{
public:

    void quickSort2(vector<int> &num, int l, int r)
    {
        if(l<r)
        {
            /*
            快速排序3.0 随机选择一个数作为标准
            int ran = rand()%(r-l+1)+l;
            swap(num[r],num[ran]);
            */
            

            /*
            快排2.0
            vector<int> vec = partition2(num,l,r);
            quickSort2(num,l,vec[0]-1);
            quickSort2(num,vec[1]+1,r);
            */

           //快排1.0
           int m = partition1(num,l,r);
           quickSort2(num,l,m-1);
           quickSort2(num,m+1,r);

        }
       

    }


    int partition1(vector<int> &num, int l,int r)
    {
        int less = l-1;
        int more = r-1;
        int mid;

        while(l<r)
        {
            if(num[l]<num[r])
            {
                swap(num[less+1],num[l]);
                less++;

            }
            l++;
           
        }

        swap(num[less+1],num[r]);
        
        mid = less+1;

        return mid;

    }



    vector<int> partition2(vector<int> &num, int l,int r)
    {
        int less = l-1;
        int more = r;
        int temp;
        vector<int> res(2,0);

        while(l<more)
        {
            if(num[l]<num[r])
            {
                swap(num[less+1],num[l++]);
                //l++;
                less++;

            }
            else if(num[l]>num[r])
            {
                //more--;
                swap(num[l],num[--more]);
            }
            else{
                l++;
            }
        }

        swap(num[more],num[r]);

        res[0] = less+1;
        res[1] = more;

        return res;

    }

};

int main()
{
    Solution A;
    vector<int> vec{3,2,5,7,8,1,0,6,1,1,19};

    int l = 0, r= vec.size()-1;
    A.quickSort2(vec,l,r);
    int i=0;



}
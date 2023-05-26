#include<vector>

using namespace std;

class Solution
{
public:
    
//选择排序
    vector<int> select(vector<int> &vec)
    {
        int n = vec.size();
        int temp;
        for (int i = 0; i < n ; i++)
        {
            for(int j = i; j < n ; j++)
            {   
                if(vec[i]>vec[j])
                {
                    temp = vec[i];
                    vec[i] = vec[j];
                    vec[j] = temp;
                }
            }
        }
        return vec;
        
    }

    vector<int> select1(vector<int> &vec)
    {
        int n = vec.size();
        
        for(int i =0;i<n;i++)
        {
            for(int j = i;j<vec.size();j++)
            {
                if(vec[i]>vec[j])
                {
                    swap(vec[i],vec[j]);
                }
            }
        }
        return vec;
    }

//冒泡排序
    vector<int> MaoPao(vector<int> &num)
    {
        int n = num.size();
        int temp;
        for(int i = n-1;i>0;i--)
        {
            for(int j = 0;j<i;j++)
            {
                if(num[j]>num[j+1])
                {
                   temp = num[j];
                   num[j] = num[j+1];
                   num[j+1] = temp;

                }

            }
        }

        return num;
    }

    void MaoPao1(vector<int> &nums)
    {
        for(int i = nums.size()-1;i>=0;i--)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[j]>nums[j+1])
                {
                    swap(nums[j],nums[j+1]);
                }
            }
        }
    }


//插入排序(从后向前看逐渐将 i转移到合适位置)
    vector<int> insert(vector<int> &num)
    {
        int n = num.size();
        int temp;
        for(int i = 1;i<n;i++)
        {
            int key = num[i];
            for(int j = i-1;j>=0;j--)
            {  
                if(key>num[j])
                {
                    break;
                  
                }
                else
                {
                    num[j+1] = num[j];
                    num[j] = key;
                }

            }
        }

        return num;

    } 

    void insert1(vector<int> &nums)
    {
        for(int i =0;i<nums.size();i++)
        {
            int temp = nums[i];
            for(int j = i-1;j>=0;j--)
            {
                if(nums[j]>temp)
                {
                    swap(nums[j],nums[j+1]);
                }
                else
                {
                    break;
                }
            }
        }
    }



//归并排序(process 退出条件，  边界范围)
    void  process(vector<int> &num, int L, int R)
    {
        if(L == R)
        {
            return;
        }
         
        int mid = L + ((R-L) >> 1);
        // 注意小括号 位移运算符优先级 比加优先级低
        //int mid1 = (L + (R-L) >> 1);

        process(num,L,mid);
        process(num,mid+1,R);
        merge(num,L,mid,R);

    }

    void merge(vector<int> &num, int L, int M, int R)
    {
        vector<int> temp;
        int p = M+1;
        int p1 = L;
        while(p1<=M && p<=R)
        {
            if(num[p1]<num[p])
            {
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
        

    }


    void process1(vector<int> &nums, int l, int r)
    {
        if(l==r)
        {
            return;
        }

        int mid = l +((r-l)>>1);

        process1(nums,l,mid);
        process1(nums,mid+1,r);
        merge1(nums,l,mid,r);

    }

    void merge1(vector<int> &nums, int l, int m, int r)
    {
        vector<int> res;

        int left = l,right = m+1;
        while(left<=m && right<=r)
        {
            if(nums[left]<nums[right])
            {
                res.push_back(nums[left]);
                left++;
            }
            else
            {
                res.push_back(nums[right]);
                right++;
            }
        }

        while(left<=m)
        {
            res.push_back(nums[left]);
            left++;
        }

        while(right<=r)
        {
            res.push_back(nums[right]);
            right++;
        }

        for(int i = 0;i<res.size();i++)
        {
            nums[l+i] = res[i];   
        }

    }

   //快速排序
};

int main()
{
    Solution A;
    vector<int> vec{3,2,1,5,6,2};
    vector<int> res1,res2;
   // res1 = A.select(vec);
    int l =0,r = vec.size();
    A.process1(vec,l,r);

    A.insert(vec);
  


    int i = 0;
}
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

//空间复杂度 O1
//时间复杂度 nlogn

class Solution
{
public:

    void heapSort(vector<int> &num)
    {
        int heapsize = num.size();
        if(heapsize < 2)
        {
            return;
        }

        // for(int i = 0; i < heapsize ; i++)
        // {
        //     heapInsert(num,i);
        // }

        // 整体会比上面 快一点
        for(int i = num.size() - 1; i>=0 ; i--)
        {
            heapify(num, i,heapsize);
        }

        //swap(num[0],num[--heapsize]);
     
        while(heapsize>0)
        {
            swap(num[0],num[--heapsize]);
           
            heapify(num,0,heapsize);
            

        }


    }

    void heapInsert(vector<int> &num, int index)
    {
        while(num[index]>num[(index-1)/2])
        {
            swap(num[index],num[(index-1)/2]);
            index = (index-1)/2;
        }

    }

    void heapify(vector<int> &num, int index, int heapsize)
    {
        int left = index*2+1;

        while(left<heapsize)
        {
            //对比子节点 选最大值对应的下标
            int largest = left+1 < heapsize && num[left+1] > num[left] ? left+1 : left;
            //对比子节点和父节点， 选择最大
            largest = num[largest] > num[index] ? largest : index;

            if(largest == index)
            {
                break;
            }

            swap(num[largest],num[index]);
            index = largest;
            left = index*2 +1;
        }

        
    }


    void heapOther(vector<int> &num )
    {
        int heapsize = num.size();

        for(int i = 0; i<heapsize ; i++)
        {
            heapInsertSmall(num,i);
            
        }
    }

    void heapInsertSmall(vector<int> &num, int index)
    {
        while(num[index] < num[(index-1)/2])
        {
            swap(num[index],num[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    void heapSort1(vector<int> &nums)
    {
        int heapsize = nums.size();

        for(int i = 0;i<heapsize;i++)
        {
            heapInert1(nums,i);
        }

        while(heapsize>0)
        {
            swap(nums[0],nums[--heapsize]);
            heapIfy1(nums,0,heapsize);
        }
        
    }

    void heapInert1(vector<int> &nums,int index)
    {
        while(nums[index] > nums[(index-1)/2])
        {
            swap(nums[index],nums[(index-1)/2]);
            index = (index-1)/2;   
        }
    }

    void heapIfy1(vector<int> &nums, int index,int heapsize)
    {
        int left = index*2+1;

        while(left<heapsize)
        {
            int largest = left+1 <heapsize && nums[left] < nums[left+1] ? left+1 : left ;

            largest = nums[index] > nums[largest] ? index : largest;

            if(index == largest)
            {
                break;
            }

            swap(nums[largest],nums[index]);

            index = largest;

            left = index*2+1;

        }

       

    }
};



int main()
{
    vector<int> vec{3,8,1,0,9};
    vector<int> res;
    Solution A;

    A.heapSort1(vec);

}
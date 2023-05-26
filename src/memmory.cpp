#include <vector>
// #include<algorithm>
// #include<math.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    // 选择排序
    void answer1(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (nums[i] > nums[j])
                {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }
    // 冒泡排序
    void answer2(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
    // 插入排序
    void answer3(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            int temp = nums[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] > temp)
                {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }

    // 归并排序

    int merge(vector<int> &nums, int l, int r, int mid)
    {

        vector<int> temp;
        int l1 = l, l2 = mid + 1;
        int sum = 0;

        while (l2 <= r && l1 <= mid)
        {
            if (nums[l1] < nums[l2])
            {
                sum += nums[l1] * (r - l2 + 1); // 右侧已经排好序， 因此后面所有都会大于num[l1]

                temp.push_back(nums[l1]);
                l1++;
            }
            else
            {
                temp.push_back(nums[l2]);
                l2++;
            }
        }

        while (l2 <= r)
        {
            temp.push_back(nums[l2]);
            l2++;
        }

        while (l1 <= mid)
        {
            temp.push_back(nums[l1]);
            l1++;
        }

        for (int i = 0; i < temp.size(); i++)
        {
            nums[l + i] = temp[i];
        }

        return sum;
    }

    int process(vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            return 0;
        }

        int mid = l + ((r - l) >> 1);
        int x1 = process(nums, l, mid);
        int x2 = process(nums, mid + 1, r);
        int x3 = merge(nums, l, r, mid);

        return x1 + x2 + x3;
    }

    ////////////////////quicksort

    void helan1(vector<int> &num, int target)
    {
        int n = num.size();
        int less = -1;
        for (int i = 0; i < n; i++)
        {
            if (num[i] < target)
            {
                swap(num[i], num[less + 1]);
                less++;
            }
        }
    }

    void helan2(vector<int> &num, int target)
    {
        int n = num.size();
        int less = -1, more = n;
        int i = 0;
        while (i < more)
        {
            if (num[i] < target)
            {
                swap(num[less + 1], num[i]);
                less++;
                i++;
            }
            else if (num[i] > target)
            {
                swap(num[more - 1], num[i]);
                more--;
            }
            else
            {
                i++;
            }
        }
    }

    void quicksort(vector<int> &nums, int l, int r)
    {

        if (l < r)
        {
            /*
                  int mid =  partation(nums,l,r);
                quicksort(nums,l,mid-1);
                quicksort(nums,mid+1,r);
            */

            /*
            2.0
             vector<int> res;
             res = partation2(nums, l, r);
             int r1 = res[0], l1 = res[1];
             quicksort(nums, l, r1);
             quicksort(nums, l1, r);
            */

            /*
            3.0
            */

            vector<int> res;
            int ran = rand() % (r - l + 1) + l;
            swap(nums[r], nums[ran]);
            res = partation2(nums, l, r);
            int r1 = res[0], l1 = res[1];
            quicksort(nums, l, r1);
            quicksort(nums, l1, r);
        }
    }

    int partation(vector<int> &nums, int l, int r)
    {
        int less = l - 1;
        int more = r;

        while (l < r)
        {
            if (nums[l] < nums[r])
            {
                swap(nums[l], nums[less + 1]);
                less++;
            }
            l++;
        }
        swap(nums[less + 1], nums[r]);

        return less + 1;
    }

    vector<int> partation2(vector<int> &nums, int l, int r)
    {
        int less = l - 1;
        int more = r;
        vector<int> res;
        while (l < more)
        {
            if (nums[l] < nums[r])
            {
                swap(nums[l], nums[less + 1]);
                less++;
                l++;
            }
            else if (nums[l] > nums[r])
            {
                swap(nums[l], nums[more - 1]);
                more--;
            }
            else
            {
                l++;
            }
        }

        swap(nums[r], nums[more]);

        res.push_back(less);
        res.push_back(more);

        return res;
    }

    ///////////////////heapsort

    void heapsort(vector<int> &nums)
    {
        int n = nums.size();
        int heapsize = nums.size();

        for (int i = 0; i < heapsize; i++)
        {
            heapinsert(nums, i);
        }

    
        while(heapsize>0)
        {
            swap(nums[0],nums[--heapsize]);  
            heapify(nums,0,heapsize);
              
        }


        
    }

    void heapinsert(vector<int> &nums, int i)
    {

        while (nums[i] > nums[(i - 1) / 2])
        {
            swap(nums[i], nums[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void heapify(vector<int> &nums,int index, int heapsize)
    {
       
        int left = index*2+1;
      

        while(left<heapsize)
        {
        
           // int largest = nums[left] > nums[left+1] ? left : (left+1);
            int largest = left+1 < heapsize && nums[left+1] > nums[left] ? left+1 : left;  // left +1 为真条件的值 是有原因的， 因为 left+1如果不成立，说明没有右节点，那么取左节点
                    
            largest = nums[index] > nums[largest] ? index : largest;

            if (largest == index)
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
    Solution A;
    vector<int> vec{3, 8, 1, 0, 9};

    int l = 0, r = vec.size() - 1;

    int target = 3;

    A.heapsort(vec);
}
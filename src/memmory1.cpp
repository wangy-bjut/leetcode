#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void insert(vector<int> &num)
    {
        int n = num.size();

        for (int i = 1; i < n; i++)
        {
            int key = num[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (num[j] > key)
                {
                    swap(num[j], num[j + 1]);
                }
            }
        }
    }

    // merge
    int process(vector<int> &nums, int L, int R)
    {
        if (L == R)
        {
            return 0;
        }

        int mid = L + ((R - L) >> 1); // L + (R-L)>>1;  注意运算的优先级

        int x1 = process(nums, L, mid);
        int x2 = process(nums, mid + 1, R);
        int x3 = merge(nums, L, mid, R);

        return x1 + x2 + x3;
    }

    int merge(vector<int> &nums, int L, int mid, int R)
    {
        vector<int> temp;
        int l1 = mid + 1;
        int l = L;
        int res = 0;
        while (l <= mid && l1 <= R)
        {
            if (nums[l] < nums[l1])
            {
                res += nums[l] * (R - l1 + 1);
                temp.push_back(nums[l]);
                l++;
            }
            else
            {
                temp.push_back(nums[l1]);
                l1++;
            }
        }
        while (l <= mid)
        {
            temp.push_back(nums[l]);
            l++;
        }
        while (l1 <= R)
        {
            temp.push_back(nums[l1]);
            l1++;
        }
        for (int i = 0; i < temp.size(); i++)
        {
            nums[L + i] = temp[i]; // 注意下标的匹配 L+i 即 merge操作的是从 L开始的数字
        }

        return res;
    }

    void quicksort(vector<int> &nums, int l, int r)
    {

        if (l < r)
        {

            int temp = rand() % (r - l + 1) + l;

            swap(nums[temp], nums[r]);

            vector<int> res = partation2(nums, l, r);

            quicksort(nums, l, res[0]);
            quicksort(nums, res[1], r);
        }
    }

    int partation1(vector<int> &nums, int l, int r)
    {
        int less = l - 1, more = r;
        while (l < more)
        {
            if (nums[l] < nums[r])
            {
                swap(nums[less + 1], nums[l]);
                less++;
                l++;
            }
            else if (nums[l] == nums[r])
            {
                l++;
            }
            else
            {
                swap(nums[l], nums[more - 1]);
                more--;
            }
        }

        swap(nums[r], nums[less + 1]);

        return less + 1;
    }

    vector<int> partation2(vector<int> &nums, int l, int r)
    {
        int less = l - 1, more = r;
        vector<int> res(2, 0);

        while (l < more)
        {
            if (nums[l] < nums[r])
            {
                swap(nums[less + 1], nums[l]);
                less++;
                l++;
            }
            else if (nums[l] == nums[r])
            {
                l++;
            }
            else
            {
                swap(nums[l], nums[more - 1]);
                more--;
            }
        }

        swap(nums[r], nums[more++]);
        res[0] = less;
        res[1] = more;

        return res;
    }

    void heapsort(vector<int> &nums)
    {
        int heapsize = nums.size();

        for (int i = 0; i < heapsize; i++)
        {
            heapInsert(nums, i);
        }

        while (heapsize > 0)
        {
            swap(nums[0], nums[--heapsize]);

            heapify(nums, heapsize);
        }
    }

    void heapInsert(vector<int> &nums, int index)
    {

        while (nums[index] > nums[(index - 1) / 2])
        {
            swap(nums[index], nums[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapify(vector<int> &nums, int heapsize)
    {
        int largest = 0;
        int index = 0;
        int left = 2 * index + 1;
        while (left < heapsize)
        {
            largest = nums[left] < nums[left+1] && left+1 < heapsize ? left+1: left;

            largest = nums[largest] > nums[index] ? largest : index;

            if(largest == index)
            {
                break;
            } 

            swap(nums[index],nums[largest]);
            
            index = largest;
            left = 2*index +1;
        }
    }
};

int main()
{
    Solution A;
    vector<int> vec{3, 8, 1, 0, 9};

    int L = 0, R = vec.size() - 1;

    // int mid1 = L + ((R-L)>>1);
    // int mid2 = L + (R-L)>>1;
    // A.quicksort(vec,L,R);

    A.heapsort(vec);
}
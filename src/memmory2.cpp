#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    void mergesort(vector<int> &nums, int l, int r)
    {
        if (l == r)
        {
            return;
        }

        int mid = l + ((r - l) >> 1);

        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, r);
        merge(nums, l, r, mid);
    }

    void merge(vector<int> &nums, int l, int r, int mid)
    {
        int l1 = l;
        int l2 = mid + 1;
        vector<int> temp;

        while (l1 <= mid && l2 <= r)
        {
            if (nums[l1] < nums[l2])
            {
                temp.push_back(nums[l1]);
                l1++;
            }
            else
            {
                temp.push_back(nums[l2]);
                l2++;
            }
        }

        while (l1 <= mid)
        {
            temp.push_back(nums[l1]);
            l1++;
        }

        while (l2 <= r)
        {
            temp.push_back(nums[l2]);
            l2++;
        }

        for (int i = 0; i < temp.size(); i++)
        {
            nums[l + i] = temp[i];
        }
    }

    void quicksort(vector<int> &nums, int l, int r)
    {
        if (l > r)
        {
            return;
        }
        int ran = rand() % (r - l + 1) + l;
        swap(nums[ran], nums[r]);
        vector<int> res = partation(nums, l, r);
        quicksort(nums, l, res[0]);
        quicksort(nums, res[1], r);
    }

    vector<int> partation(vector<int> &nums, int l, int r)
    {
        int less = l - 1;
        int more = r;

        vector<int> res(2, 0);

        while (l < more)
        {
            if (nums[l] < nums[r])
            {
                swap(nums[l], nums[less + 1]);
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
        swap(nums[r], nums[more]);
        more++;

        res[0] = less;
        res[1] = more;

        return res;
    }
};

class Solution1
{
public:
    void quickSort(vector<int> &nums, int l, int r)
    {
        if(l>r)
        {
            return;
        }
        vector<int> retu = partation(nums,l,r);
        quickSort(nums,l,retu[0]);
        quickSort(nums,retu[1],r);

    }
    vector<int> partation(vector<int> &nums, int l, int r)
    {
        int less = l-1;
        int more = r;
        vector<int> res(2,0);

        while(l<more)
        {
            if(nums[l]<nums[r])
            {
                swap(nums[l],nums[++less]);
                l++;
            }
            else if(nums[l]>nums[r])
            {
                swap(nums[l],nums[++more]);
                
            }
            else
            {
                l++;
            }

        }

        swap(nums[r],nums[more--]);
        res[0] = less;
        res[1] = more;

        return res;

    }

    //merge
    void mergeSort(vector<int> &nums,int l, int r)
    {
        if(l == r)
        {
            return ;
        }

        int mid = l+((r-l)>>1);
       mergeSort(nums,l,mid);
       mergeSort(nums,mid+1,r);
       merge(nums,l,mid,r);

    }
    void merge(vector<int> &nums, int l,int mid, int r)
    {
        int l1 = l;
        int l2 = mid+1;
        vector<int> temp;
        while(l1<=mid && l2<=r)
        {
            if(nums[l1]<nums[l2])
            {
                temp.push_back(nums[l1]);
                l1++;
            }
            else
            {
                temp.push_back(nums[l2]);
                l2++;
            }
        }
        while(l1<=mid)
        {
            temp.push_back(l1++);
        }
        while(l2<=r)
        {
            temp.push_back(l2++);
        }

        for(int i = 0;i<temp.size();i++)
        {
            nums[l+i] = temp[i];
        }

    }

    //heapsort
    void heapSort(vector<int> &nums)
    {
        int heapsize = nums.size();

        for(int i = 0;i<heapsize;i++)
        {
            heapInsert(nums,i);
        }

        while(heapsize )
        {
            swap(nums[0],nums[--heapsize]);
            heapIfy(nums,heapsize);
        }
        
    }

    void heapInsert(vector<int> &nums,int index)
    {
        
        while(nums[index] > nums[(index-1)/2])
        {
         
            swap(nums[index],nums[(index-1)/2]);
            
            index = (index-1)/2;

        }
    }

    void heapIfy(vector<int> &nums, int heapsize)
    {
        int index = 0;
        int left = index*2+1;
        int largest;
        while(left<heapsize)
        {
            largest = left+1 < heapsize && nums[left+1]>nums[left] ? left+1 : left;

            largest = nums[index]>nums[largest] ? index : largest;
            
            if(largest == index)
            {
                return;
            }

            swap(nums[index],nums[largest]);
            index = largest;
            left = index*2+1;
        }
    }


};

int main()
{
    Solution1 A;
    vector<int> vec{3, 2, 8, 5, 0};

    int l = 0;
    int r = vec.size() - 1;

    A.heapSort(vec);
    
    

    
}
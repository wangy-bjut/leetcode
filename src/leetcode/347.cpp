#include<vector>
#include<utility>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
    void heapSort(vector<pair<int,int>> &nums, int heapsize)
    {
        while(heapsize>0)
        {
            swap(nums[0],nums[--heapsize]);
            heapify(nums,0,heapsize);
        }
    
    }
    void heapinsert(vector<pair<int,int>> &nums,int index)
    {
        while(nums[index].second<nums[(index-1)/2].second )
        {
            swap(nums[index],nums[(index-1)/2]);
            index = (index-1)/2;
        }

    }
    void heapify(vector<pair<int,int>> &nums, int index, int heapsize)
    {
        int left = index*2+1;
        while(left<heapsize)
        {
            int largest = left+1<heapsize && nums[left+1].second<nums[left].second ?left+1:left;
        
            largest  = nums[index].second<nums[largest].second ? index : largest;

            if(largest == index)
            {
                break;
            }

            swap(nums[index],nums[largest]);
            index = largest;
            left = index*2+1;

        }
        
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        vector<int> res;
        int l = 0;
        for(auto num:nums)
        {
            hash[num]++;
        }

        vector<pair<int,int>> vec;
        for(auto it:hash)
        {
            pair<int,int> temp;
            temp.first = it.first;
            temp.second = it.second;
            vec.push_back(temp);
        }

        for(int i = 0;i<k;i++)
        {
            heapinsert(vec,i);
        }

        for(int i = k;i<vec.size();i++)
        {
           if(vec[i].second>vec[0].second)
           {
               swap(vec[i],vec[0]);
               heapify(vec,0,k);
           }
           
        }

        for(int i = 0;i<k;i++)
        {
            res.push_back(vec[i].first);
        }

        return res;
 
    }
    
};

int main()
{
    Solution A;
    vector<int> vec{1,1,1,2,2,3};

    vector<int> res = A.topKFrequent(vec,2);
}
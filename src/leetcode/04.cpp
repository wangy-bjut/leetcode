#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;



class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int mea = nums.size()/2;
        int result = 0;

        unordered_map<int,int> hash;

        for(int i = 0;i<nums.size();i++)
        {
            hash[nums[i]]++;
            if(hash[nums[i]] >= mea)
            {
                result = nums[i];
            }

        }

        return result;

    }
};

int main()
{
    Solution A;
    vector<int> nums={3,3,4} ;

    int res[2];

    res[0] = 1;

    //res = A.majorityElement(nums);


}
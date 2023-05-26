#include<vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>> res;
        for(int i = 1;i<n;i++)
        {
            vector<int> key =  intervals[i];
            for(int j = i-1;j>=0;j--)
            {
                 if(intervals[j][0]>key[0])
                 {
                     swap(intervals[j],intervals[j+1]);
                 }

            }
           
        }

        int l = 0, r= 1;
        while(r<n)
        {
            vector<int> temp;
            if(intervals[l][1]>=intervals[r][0] && intervals[l][1]<=intervals[r][1])
            {   
                temp.push_back(intervals[l][0]);
                temp.push_back(intervals[r][1]);
                res.push_back(temp);
                l = r+1;
                r = l+1;
            }
            else
            {
                if(intervals[l][1]>intervals[r][1])
                {
                    res.push_back(intervals[l]);
                    l = r+1;
                    r = l+1;
                }
                else
                {
                    res.push_back(intervals[l]);
                    l = r;
                    r = r+1;
                }
            }
            
        }


        return res;


    }
};

int main()
{
    Solution A;

    vector<vector<int>> vec{{1,4},{0,4}};

    vector<vector<int>> res;

    res =  A.merge(vec);
}
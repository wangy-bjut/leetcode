#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[0]>b[0];
    }
    vector<vector<int>> eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        return intervals;

    }
};

int main()
{
    Solution A;

    vector<vector<int>> vec{{1,2},{2,3},{3,4},{1,3}};
    vector<vector<int>> res = A.eraseOverlapIntervals(vec);
}
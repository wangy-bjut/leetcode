#include<vector>
#include<algorithm>

using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(!s.empty() && !g.empty())
        {
            if(s.back()>=g.back())
            {
                res++;
                s.pop_back();
                g.pop_back();
            }
            else
            {
                g.pop_back();
            }
        }

        return res;

    }
};

int main()
{
    Solution A;

    int res = 0;
    vector<int> vec1{1,2,3},vec2{1,1};

    res = A.findContentChildren(vec1,vec2);

}
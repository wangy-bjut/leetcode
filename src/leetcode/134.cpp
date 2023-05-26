#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = -1 ;

        for(int i = 0;i<gas.size();i++)
        {
            int sum = 0;
            int index = i;
            bool mark = false;
            while( mark == false)
            {
                sum+=gas[index];
                if(sum<cost[index])
                {
                    break;
                }
                else
                {
                    sum-=cost[index];
                }
                index++;
                if(index == gas.size())
                {
                    index-=gas.size();
                }

                if(index == i)
                {
                    mark == true;
                }

            }

            if(index == i && mark == true)
            {
                res = i;
                break;
            }
        }

        return res;
    }
};

int main()
{
    Solution A;

    vector<int> gas{1,2,3,4,5},cost{3,4,5,1,2};

    int res = A.canCompleteCircuit(gas,cost);
}
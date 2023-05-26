#include<vector>
#include<unordered_set>

using namespace std;


class Solution {
    vector<int> process(int n)
    {
        vector<int> res;
        while(n!=0)
        {
            res.push_back(n%10);
            n = n/10;
        }

        return res;
    }
public:
    bool isHappy(int n) {
        int sum = 0;
        unordered_set<int> hash;
        
        while(sum != 1)
        {
            vector<int> res = process(n);
            sum = 0;
            for(auto &num:res)
            {
                sum += num*num; 
            }
            n = sum;
            if(hash.count(sum))
            {
                return false;
            }
            else
            {
                hash.insert(sum);
            }
        }

        return true;

    }
};

int main()
{
    Solution A;
    int n = 19;

    bool res = A.isHappy(n);
}
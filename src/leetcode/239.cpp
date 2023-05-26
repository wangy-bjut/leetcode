#include <deque>
#include <vector>

using namespace std;

class Solution
{
private:
    class Myqueue
    {
    public:
        deque<int> deque;

        void push(int val)
        {
            while (!deque.empty() && deque.back() < val)
            {
                deque.pop_back();
            }
            deque.push_back(val);
        }

        void pop(int val)
        {
            if (!deque.empty() && val == deque.front())
            {
                deque.pop_front();
            }
        }

        int front()
        {
            return deque.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;

        Myqueue myqu;

        for (int i = 0; i < k; i++)
        {
            myqu.push(nums[i]);
        }
        res.push_back(myqu.front());
        for (int i = k; i < nums.size(); i++)
        {
            myqu.pop(nums[i - k]);
            myqu.push(nums[i]);
            res.push_back(myqu.front());
        }

        return res;
    }
};

int main()
{
    Solution A;

    vector<int> vec{1};

    vector<int> res = A.maxSlidingWindow(vec, 1);
}
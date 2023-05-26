#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;


class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> activeMinutes;
        for (auto &&log : logs) {
            int id = log[0], time = log[1];
            activeMinutes[id].emplace(time);
        }
        vector<int> answer(k);
        // && 为啥要俩
        for (auto &&[_, minutes] : activeMinutes) {
            int activeCount = minutes.size();
            answer[activeCount - 1]++;
        }
        return answer;
    }
};

int main()
{
    Solution A;
    vector<vector<int>> vec{{0,5},{1,2},{0,2},{0,5},{1,3}};
    vector<int> res;
    res = A.findingUsersActiveMinutes(vec,5);
}
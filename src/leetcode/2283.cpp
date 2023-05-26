#include<string>
#include<unordered_map>

using namespace std;


class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char,int> hash{{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9}};
        unordered_map<char,string> hash2{{{'1'},{"abc"}}};
        unordered_map<int,int> hash1;
        int nums[10]{10,0};


        for(int i = 0 ; i<num.size(); i++)
        {
            
            nums[i] = hash[num[i]];
            hash1[nums[i]]++;

        }

        for(int i = 0;i<num.size();i++)
        {
            if(nums[i] != hash1[i])
            {
                return false;
            }
        }

        return true;

        
    }
};

int main()
{
    Solution A;
    string a="1210";

    bool res;
    res = A.digitCount(a);
}
#include <unordered_map>
#include <string>

using namespace std;
// 牛客  一个字符串 每次删除一对相同的字母，并在末尾添加一个字母

class Solution
{
public:
    int strnum(string s)
    {
        unordered_map<char,int> hash;
        for(auto str:s)
        {
            hash[str]++;
        }

        int num = 0,letter = 0;

        for(auto it:hash)
        {
            if(it.second%2==0)
            {
                num+=it.second/2;
                letter+=it.second/2;
            }
            else if(it.second%2 != 0 && it.second >0)
            {
                num+=it.second/2;
                letter+=it.second/2+1;
            }
            else if(it.second == 1)
            {
                letter++;
            }
        }

        if(letter>26)
        {
            num+=letter-26;   // 考虑字母使用次数
        }
    }
};
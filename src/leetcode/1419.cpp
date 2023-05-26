#include<unordered_map>
#include<vector>
#include<string>


using namespace std;



class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char,int> hash;
        string target = "croak";
        vector<string> res;

        int sum = 0;

        if(croakOfFrogs[0] != 'c')
        {
            return -1;
        }
        for(auto str:target)
        {
            hash[str] = 0;
        }

        for(int i = 0; i < croakOfFrogs.size() ; i++)
        {
            char str = croakOfFrogs[i];
            hash[str]++;

            if(str == 'c')
            {
                if(i == 0)
                {
                    sum++;
                }
                string temp = "c";
                if(res.size()>0 && res[res.size()-1] != target)
                {
                    sum++;
                }
                
                
                res.push_back(temp);
            
            }
            else
            {
                int index = hash[str]-1;
                res[index].push_back(str);
            }
        }


    return sum;
    }
};

int main()
{
    Solution A;

    string str = "crocakcroraoakk";

    int res = A.minNumberOfFrogs(str);
}
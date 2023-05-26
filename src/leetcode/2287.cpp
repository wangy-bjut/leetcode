#include<string>
#include<unordered_map>

using namespace std;



class Solution {
public:
    int rearrangeCharacters(string s, string target) {

        
        unordered_map<char,int> hash1,hash2;
        int n1 = s.length(),n2 = target.length();
        int num = n1+1;

        for(int i = 0;i<n2;i++)
        {
            hash1[target[i]]++;
        }
        
        for(int i = 0;i<n1;i++)
        {
            if(hash1.find(s[i]) != hash1.end())
            {
                hash2[s[i]]++;
            }
        }

        for(auto &kv:hash1)
        {
            auto it = hash1.find(kv.first);
            auto a = it->first;
          
            if(hash2.find(kv.first) != hash2.end())
            {
                hash2[kv.first] = hash2[kv.first] / kv.second;
                num = min(num,hash2[kv.first]);
            }
            else
            {
                num = 0;
                break;
                
            }
            
        }

        int o;

        return num;
        
    }
};
int main()
{
    Solution A;
    int res;
    string s{"lrn"};
    string target{"woijih"};

    res=A.rearrangeCharacters(s,target);
}
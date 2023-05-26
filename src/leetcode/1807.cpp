#include<string>
#include<vector>
#include<unordered_map>

using namespace std;


class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        vector<char> res;
        int n = s.length();
        unordered_map<string,string> hash;
        string temp1,temp2;
        int l,r;
      
       for (auto &kd : knowledge) {
            hash[kd[0]] = kd[1];
        }

        //for(int i =0 ;i<knowledge.size();i++)
        //{
        //    hash[knowledge[i][0]] = knowledge[i][1];
        //}
        for(int i=0;i<n;i++)
        {
            while(s[i] != '(' && s[i] != '\0')
            {
                res.push_back(s[i]);
                i++;
            }
            if(s[i] == '(')
            {
            
                i++;
                l = i;
                while(s[i] != ')')
                {
                    
                    i++;
                }
                r = i;
                
                temp1 = s.substr(l,r-l);

                // 此处最好不用 nullptr ，因为 不一定返回空指针， find含义为 找不到 则返回指向end的迭代器
                //if(hash.find(temp1) != nullptr)
                if(hash.find(temp1) != hash.end())
                {
                    temp2 = hash[temp1]; 
                }
                else
                {
                    temp2 = '?';
                }
                for(auto s:temp2)
                {
                    res.push_back(s);
                }
            
                
            }
    
        }
        
        
        string result(res.begin(),res.end());
         

         return  result ;
    



    }
};

int main()
{
    Solution A;

    string s1;

    string s{"(name)is(age)yearsold"};
    vector<vector<string>> knowledge{{{"name"},{"bob"}},{{"age"},{"two"}}};

    s1 = A.evaluate(s,knowledge);

}
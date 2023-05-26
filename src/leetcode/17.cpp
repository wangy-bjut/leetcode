#include<vector>
#include<string>
#include<unordered_map>
#include<iostream>

using namespace std;


class Solution {
    void back( unordered_map<char,string> &hash, const string &digits, string &s1,int index,vector<string> &res)
        {
            if(index == digits.length())
            {
                res.push_back(s1);
            }
            else
            {
                char x = digits[index];
                const string &s2 = hash[x];
                for(auto &str : s2)
                {
                    s1.push_back(str);
                    back(hash,digits,s1,index+1,res);
                    s1.pop_back();
                }
                
            }
        }


public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string s1,s2;
        int n = digits.size();
        int index = 0;
        unordered_map<char,string> hash{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

        if(digits.empty() )
        {
            return res;
        }

        back(hash,digits,s1,index,res);

        return res;

        
        

    }
};

class Solution1 {
    vector<string> res;
     const string lettermap[10] = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        };
    void goback(const string &digits, string temp,int index)
    {
        if(index == digits.size())
        {
            return;
        }
        if(temp.size() == digits.size())
        {
            res.push_back(temp);
            return;
        }
        string  letter = lettermap[digits[index]-'0'];
        for(int i = 0;i<letter.size();i++)
        {
            temp.push_back(letter[i]);
            goback(digits,temp,index+1);
            temp.pop_back();
        }

        return;
    }
   
public:
    vector<string> letterCombinations(string digits) {
     
        string temp;
        goback(digits,temp,0);

        return res;


    }
};

int main()
{
    Solution1 A;
    vector<string> res;
    string dig = "23";
    
    res = A.letterCombinations(dig);
    

}
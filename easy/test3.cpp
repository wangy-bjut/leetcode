#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        map<string,int> dirt={
            {"I",1},
            {"V",5},
            {"X",10},
            {"L",50},
            {"C",100},
            {"D",500},
            {"M",1000},
        };
        vector<string> vec;
        string str;
        int sum=0;
        for(int i = 0; i<s.size();i++)
        {
            str = s[i];
            vec.push_back(str);
        }
        for( int i=0;i<s.size();i++)
        {
            if(i<s.size()-1&&dirt[vec[i]]<dirt[vec[i+1]])
            {
                sum-=dirt[vec[i]];
            }
            else
            sum+=dirt[vec[i]];
            
        }
    

        return sum;


    }
};

int main()
{
    int sum;
    Solution sol;
    sum = sol.romanToInt("XLIX");

    cout<<sum;


}
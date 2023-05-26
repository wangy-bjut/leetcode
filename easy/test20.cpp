#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int num=s.size();
        if(num%2 == 0)
        {
            for(int i=0;i<num-1;i+=2)
            {
                if((s[i] == '('&&s[i+1]!=')')||(s[i] == '['&&s[i+1]!=']')||(s[i] == '{'&&s[i+1]!='}'))
                {
                    return false;
                }

            }
            return true;

        }
        else
        {
            return false;
        }

    }
};
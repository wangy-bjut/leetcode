#include<string>

using namespace std;


class Solution {
    void getnext(string &s, int *next)  // 获取 前缀后缀相等位置减1列表
    {
        // j指向前缀末尾  i指向后缀末尾
        int j = -1;
        next[0] = j;
        for(int i = 1;i<s.size();i++)
        {
            while(j>=0 && s[i] != s[j+1])
            {
                j = next[j];
            }

            if(s[i] == s[j+1])
            {
                j++;
            }
            next[i] = j;
        }
    }

    void getnext(string &s, int *next)
    {
        int j = -1;
        next[0] = j;
        for(int i = 1;i<s.size();i++)
        {
            while (j>=0 && s[i] != s[j+1])
            {
                j = next[j];
            }

            if(s[i] == s[j+1])
            {
                j++;
            }
            next[i] = j;
            
        }
    }
    
 
public:

    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
        {
            return 0;
        }

        int next[needle.size()];
        getnext(needle,next);

        int j = -1;
        for(int i = 0;i<haystack.size();i++)
        {
            while(j>=0 && haystack[i] != needle[j+1])
            {
                j = next[j];
            }

            if(haystack[i]== needle[j+1])
            {
                j++;
            }

            if(j == (needle.size()-1))
            {
                return (i-needle.size()+1);
            }
        }

        return -1;
    }

    int kmp(string haystack, string needle)
    {
        if(needle.size()==0)
        {
            return 0;
        }
        
        int next[needle.size()];
        getnext(haystack,next);
        int j = -1;
        for(int i = 0;i<haystack.size();i++)
        {
            while(j>=0 && haystack[i] != needle[j+1] )
            {
                j = next[j];
            }

            if(haystack[i] == needle[j+1])
            {
                j++;
            }

            if(j == needle.size()-1)
            {
                return i-needle.size()+1;
            }
        }

        return -1;       
    }
   
};
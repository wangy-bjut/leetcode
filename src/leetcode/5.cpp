#include<string>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
      int n = s.size();
      int ans = 0;
      char vec[n+1];

      if(n <= 1)
      {
          return s;
      }


      for(int l = 0;l<n;l++ )
      {
          for(int r = l;r<n;r++)
          {
              if(s[l] != s[r])
              {
                  continue;
              }
              else
              {
                int l1 = l, r1 = r;
                while(l1<r1)
                {
                    l1++;
                    r1--;
                    if(s[l1] != s[r1])
                    {
                        break;
                    }
                    
                }
                if(l1>=r1)
                {
                    
                    int l2 = l,r2 = r;
                    if((r-l+1)>ans)
                    {
                        int i = 0;
                        while(l2<=r2)
                        {
                        vec[i] = s[l2];
                        l2++;
                        i++;
                        }

                        ans = r-l+1;

                    }
                   
                }
              }
          }
      } 

      vec[ans] = '\0';
      return vec; 

    }
};

int main()
{
    Solution A;
    string res;
    string s="babad";

    res = A.longestPalindrome(s);
}
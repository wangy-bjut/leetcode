#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int ans = 0;
        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            i = max(i, m[s[j]]);
            m[s[j]] = j + 1;
            cout<<int(s[j]);
            ans = max(ans, j - i + 1);
        }
        return ans;
    }

int main()
{
    string s = "abcabcbb";
    int ans = 0;

    ans = lengthOfLongestSubstring(s);
    cout<<ans;
}


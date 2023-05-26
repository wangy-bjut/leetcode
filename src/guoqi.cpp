#include<vector>

using namespace std;

class Solution
{
public:
    int helan(vector<int> &num, int target)
    {
        int i=-1,j=0;
        int n = num.size();
        int temp;
        while(j<n)
        {
            if(num[j]<target)
            {
                temp = num[i+1];
                num[i+1] = num[j];
                num[j] = temp;
                i++;

            }
            
            j++;
        }

        return i;
    }

    vector<int> helan2(vector<int> &num, int target)
    {
        int n = num.size();
        int l = -1, r = n, i = 0;
        int temp;
        vector<int> res;
        while(i<r)
        {
            if(num[i]<target)
            {
                temp = num[l+1];
                num[l+1] = num[i];
                num[i] = temp;
                i++;
                l++;
            }
            else if(num[i]>target)
            {
                temp = num[i];
                num[i] = num[r-1];
                num[r-1] = temp;
                r--;
            }
            else{
                i++;
            }
            
        }

        res.push_back(l);
        res.push_back(r);
        return res;
        

    }


};

int main()
{
    Solution A;
    vector<int> num{3,5,6,5,8};

    int res;
    vector<int> res1;
    int tar = 5;
    
  //  res = A.helan(num,tar);

    res1 = A.helan2(num,tar);
    

}
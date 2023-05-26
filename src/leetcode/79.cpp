#include<vector>
#include<string>

using namespace std;


class Solution {
    
    void find(vector<vector<char>> &board, vector<vector<int>> &pos, string &word,int i,int j,int m, int n,int k,bool &res)
    {
        if(board[i][j] != word[k])
        {
            return  ;
        }
        else if( k == word.size()-1)
        {
            res = true; 
            return;
        }

        pos[i][j] = true;

        vector<pair<int, int>> nums{{0,1},{0,-1},{1,0},{-1,0}};
    
        for(auto &num:nums)
        {
            int newi = i+num.first, newj = j+num.second;
            if(newi>=0&&newi<m && newj>=0&&newj<n)
            {
                if(board[newi][newj] == word[k+1] && !pos[newi][newj])
                {
                  find(board,pos,word,newi,newj,m,n,k+1,res);
                }
                
                
            }
            
        }
        
        pos[i][j] = false;
        return;
    
    }
   
public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();
        bool  res = false;

        vector<vector<int>> pos(m,vector<int>(n));
       
        
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                find(board,pos,word,i,j,m,n,0,res);
                if(res)
                {
                    return true;
                }
                
            }
        }

        return res;


    }
};


int main()
{
    Solution A;
    vector<vector<char>> vec{{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},
    {'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
    
    string word = "AAAAAAAAAAAAAAB";
    bool res = A.exist(vec,word);

    int i = 0;
    
}
#include<vector>

using namespace std;

struct TrieNode{
    int pass;
    int end;
    TrieNode *next;
    TrieNode(int p, int e):pass(p),end(e) {};
};

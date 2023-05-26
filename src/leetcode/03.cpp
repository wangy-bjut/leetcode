#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<unordered_set>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<int> hash;
        bool result;

        while(head != nullptr )
        {
            if(hash.count(head->val))
            {
                result = true;
                break;
            }
            hash.insert(head->val);
            head = head->next;
       

        }

        return result;
        
    }
};

int main()
{
    ListNode a = ListNode(1);
    ListNode *head = &a;

    Solution A;

    bool  result;

    result = A.hasCycle(head);

    cout<<result;

}
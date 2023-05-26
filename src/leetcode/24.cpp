#include<vector>
#include<stack>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
    
        ListNode *dumpnode  = new ListNode();
        dumpnode->next = head->next;
        stack<ListNode*> stack;
        ListNode *pre = nullptr;

        while(head != nullptr)
        {
            stack.push(head);
            head = head->next;
            if(stack.size() == 2)
            {
                ListNode *temp1 = stack.top();
                stack.pop();
                ListNode *temp2 = stack.top();
                stack.pop();
                temp1->next = temp2;
                if(pre != nullptr)
                {
                    pre->next = temp1;
                }
                pre = temp2;

            }
           
        }

        return dumpnode->next;



    }
};



int main()
{
    ListNode *head, *root;
    root = new ListNode(1);
    head = root;
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
   

    ListNode *res;
    
    Solution A;

    res = A.swapPairs(head);
}
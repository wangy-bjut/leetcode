#include<vector>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *low = head;
        ListNode *fast = head;
        while(fast != nullptr && low != nullptr)
        {
            low = low->next;
            if(fast->next = nullptr )
            {
                return nullptr;
            }
            fast = fast->next->next;
            if(low == fast)
            {
                break;
            }
        }

        fast = head;

        while(fast != low && fast != nullptr && low != nullptr)
        {
            fast = fast->next;
            low = low->next;
        }

        if(fast == nullptr || low == nullptr)
        {
            return nullptr;
        }
        
        return fast;
    }
};

int main()
{
    ListNode *head, *root;
    root = new ListNode(3);
    head = root;
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next = new ListNode(-4);
    root->next->next->next = root->next;

    ListNode *res;
    
    Solution A;

    res = A.detectCycle(head);
}
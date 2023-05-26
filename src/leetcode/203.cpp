#include<vector>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); 
        dummyHead->next = head; 
        ListNode* cur = dummyHead;
        while (cur->next != nullptr) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};


int main()
{
    ListNode *head, *root;
    root = new ListNode(3);
    head = root;
    root->next = new ListNode(3);
    root->next->next = new ListNode(3);
    
    

    ListNode *res;
    
    Solution A;

    res = A.removeElements(head,3);
}
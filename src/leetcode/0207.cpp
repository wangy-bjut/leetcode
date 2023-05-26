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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *temp1 = headA,*temp2 = headB;
        int rediusA = 0,rediusB=0;
        if(temp1 == nullptr || temp2 == nullptr)
        {
            return nullptr;
        }
        while(temp1->next!= nullptr && temp2->next != nullptr)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1->next != nullptr)
        {
            rediusA++;
            temp1 = temp1->next;
        }

        while(temp2->next != nullptr)
        {
            rediusB++;
            temp2 = temp2->next;
        }

        if(temp1 != temp2)
        {
            return nullptr;
        }


        while(headA != headB )
        {
            // 以下过程 要在while循环外面进行， 否则 如果走完插值步，正好是结尾节点， 则失败。
            while(rediusA--)
            {
                
                headA = headA->next;
            }
            while(rediusB--)
            {
                
                headB = headB->next;
            }

            headA = headA->next;
            headB = headB->next;
            
        }

        return headB;

        
        
    }
};


int main()
{
    ListNode *headA, *root, *headB,*root2;
    root = new ListNode(0);
    headA = root;
    root->next = new ListNode(9);
    root->next->next = new ListNode(1);
    root->next->next->next = new ListNode(2);
    root->next->next->next->next = new ListNode(4);

    root2 = new ListNode(3);
    headB = root2;
    root2->next = root->next->next->next ;
   
    ListNode *res;
    
    Solution A;

    res = A.getIntersectionNode(headA,headB);
    
}
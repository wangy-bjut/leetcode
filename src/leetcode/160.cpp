#include<algorithm>
#include<math.h>

using namespace std;
 
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *head1 = headA, *head2 = headB;
        int n = 0;
        while(head1 != NULL)
        {
            head1 = head1->next;
            n++;
        }

        while(head2 != NULL)
        {
            head2 = head2->next;
            n--;
        }
        
        head1 = n>=0 ? headA : headB;
        head2 = n<0 ? headA: headB;

        n = abs(n);
        while(n>0)
        {
            head1 = head1->next;
            n--;
        }

        while(head1 != head2 &&  head2 != NULL)
        {
            head1 = head1->next;
            head2 = head2->next;
        }

        
        return head1;
       

      
    }

       
};

int main()
{
    ListNode *head1 = new ListNode(2);
    ListNode *head2 = new ListNode(2);

    ListNode *temp;

    head1->next = new ListNode(2);
    head2->next = new ListNode(2);

    temp = new ListNode(4);
    head1->next->next = temp;
    head2->next->next = temp;

    temp->next = new ListNode(5);

    Solution A;

    ListNode *res;

    res = A.getIntersectionNode(head1,head2);
   



}
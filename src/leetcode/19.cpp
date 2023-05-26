
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {

      void back(ListNode *head, int n,int &i)
        {
            if(head->next != nullptr)
        {
            back(head->next,n,i);

        }
        i++;

         if((i-1)==n)
        {
            ListNode *temp ;
            temp = head->next->next;
            delete head->next;
            head->next = temp;
        }
        }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0;
        ListNode *temp = new ListNode();
        ListNode *res = head;
        if(head->next == nullptr)
        {
            return nullptr;
        }
        back(head,n,i);

        if(n == i)
        {
            res = res->next;
        }
 
        return res;

    }
};

int main()
{
    Solution A;

    ListNode *head = new ListNode(1);
    ListNode *toe = head;
    ListNode *head1 ;
    
       for(int i = 0;i<2;i++)
    {
        toe->next = new ListNode(i+2);
        toe = toe->next;
    }

    head1 = A.removeNthFromEnd(head,2);

  
    
}
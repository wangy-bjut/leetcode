#include<iostream>
#include<string>
#include<vector>

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
    ListNode* reverseList(ListNode* head) {

        vector<ListNode*> vec;

        ListNode *pre,*next,*result;
        pre = nullptr;

        int num;

        while(head != nullptr)
        {
            vec.push_back(head);
            head = head->next;
        }

        while(vec.size() != 0 )
        {
            if(pre == nullptr)
            {
                pre = vec.back();
                result = pre;
                vec.pop_back();
            }
          
            next = vec.back();
            vec.pop_back();
            pre->next = next;
            pre = next;

        }

        pre->next = nullptr;

        return result;


    }
};

int main()
{
    Solution A;

    ListNode *head = new ListNode(1);
    ListNode *toe = head;
    ListNode *head1 ;
    for(int i = 0;i<4;i++)
    {
        toe->next = new ListNode(i+2);
        toe = toe->next;
    }

    head1 = A.reverseList(head);

    while (head1 != nullptr)
    {
        cout<<head1->val;
        head1 = head1->next;
    }
    
}
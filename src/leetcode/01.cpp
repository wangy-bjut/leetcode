#include<iostream>
#include<string>
#include<map>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x = 0;
        ListNode* tail = new ListNode(); 
        ListNode* l3 = new ListNode();
        l3->next = tail;
        int sum = 0;
        
        while(l1 != nullptr && l2 != nullptr)  // 使用l1 || l2  将所有情况放在一个循环中处理
        {
            sum = l1->val + l2->val + x;        // int n1 = l1 ? l1->val: 0;
                                                // int n2 = l2 ? l2->val: 0;   
            if (sum<10)
            {
                tail->val = sum;
                     
            }
            else 
            {
                tail->val = sum%10;   
                    
            }

            x = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            if(l1 != nullptr && l2 != nullptr)
            {
                tail->next = new ListNode();  
                tail = tail->next; 
            }
               
        }
   
        if(l1 != nullptr ) 
        {
            if(x == 0)
            {
                tail->next  =l1;
            }
            else
            {
                while(l1!=nullptr)
                {
                sum = l1->val + x;
                if(sum<10)
                {
                    tail->next = new ListNode();
                    tail = tail->next;
                    tail->val = sum;

                }
                else
                {
                    tail->next = new ListNode();
                    tail = tail->next;
                    tail->val = sum%10;

                }
                x = sum/10;
                l1 = l1->next;

                }

            }
            
        }
        else if(l2 != nullptr )
        {
           if(x == 0)
            {
                tail->next  =l2;
            }
            else
            {
                while(l2!=nullptr)
                {
                sum = l2->val + x;
                if(sum<10)
                {
                    tail->next = new ListNode();
                    tail = tail->next;
                    tail->val = sum;

                }
                else
                {
                    tail->next = new ListNode();
                    tail = tail->next;
                    tail->val = sum%10;

                }
                x = sum/10;
                l2 = l2->next;

                }

            }
        }

        if (x != 0)
        {
            tail->next = new ListNode();
            tail->next->val = 1;
        }
        
        return l3->next;   


    
    }

};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};


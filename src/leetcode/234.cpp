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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        vector<int>::iterator fro, back;
        int num;

        while(head != nullptr)
        {
            vec.push_back(head->val);
            head = head->next;
        }

        num = vec.size();

        if(vec.size()%2 != 0)
        {
            fro = vec.begin();
            back = vec.end()-1;
            while(fro != back)
            {
                if(*fro != *back)
                {
                    return false;
                }
                fro++;
                back--;
            }
        }
        else
        {
            fro = vec.begin();
            back = vec.end()-1;
            for(int i = 0;i<2;i++)
            {
                if(*fro != *back)
                {
                    return false;
                }
                fro++;
                back--;
            }

        }


        return true;
    }
};

int main()
{
    Solution A;

    ListNode *head = new ListNode(1);
    ListNode *toe = head;
    ListNode *head1 ;

    toe->next = new ListNode(2);
    toe = toe->next;
    toe->next = new ListNode(2);
    toe = toe->next;
    toe->next = new ListNode(1);
    toe = toe->next;
    

    bool res;

    res = A.isPalindrome(head);

 
    
}
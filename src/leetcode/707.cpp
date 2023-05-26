class MyLinkedList {
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val):val(val),next(nullptr) {};
    };
public:
    MyLinkedList() {
        dumpNode = new ListNode(0);
        size = 0;
    }
    
    int get(int index) {
        if(index<0 || index >=size )
        {
            return -1;
        }
        ListNode *cur = dumpNode->next;
        while(cur != nullptr && index>0 )
        {
            cur = cur->next;
            index--;
        }
       
        return cur->val;


    }
    
    void addAtHead(int val) {
        if(size == 0)
        {
            dumpNode->next = new ListNode(val);
        }
        else
        {
            ListNode *temp = dumpNode->next;
            dumpNode->next = new ListNode(val);
            dumpNode->next->next = temp;
            
        }
        size++;

    }
    
    void addAtTail(int val) {
        ListNode *temp = dumpNode->next;
        if(temp == nullptr)
        {
            addAtHead(val);  // 首先套用的时候注意size的变化叠加
        }
        else
        {
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new ListNode(val);
            size++;
        }
        
    

    }
    
    void addAtIndex(int index, int val) {
        if(size == index)
        {
            addAtTail(val);
            
        }
        else if(index > size)
        {
            return;
        }
        else if(index < 0)
        {
            addAtHead(val);
            
        }
        else
        {
           ListNode *temp = dumpNode,*temp1;  // 添加节点，注意 如果让temp 为头节点 ，即temp = dumpnde->next则无法在头节点前添加节点
           while(index--)
           {
               temp = temp->next;
    
           }
           temp1 = temp->next;
           temp->next = new ListNode(val);
           temp->next->next = temp1;
           size++;
        }

    }
    
    void deleteAtIndex(int index) {
        if(index>=0 && index < size)
        {
            ListNode *temp = dumpNode,*temp1;  // 遍历的时候 注意利用创建的零食变量
            

            while(index--)
            {
                temp = temp->next;
            }

            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
            size--;

        }

    }
private:
ListNode *dumpNode;
int size;

};

int main()
{
    MyLinkedList linklist =  MyLinkedList();

   
    linklist.addAtIndex(0,10);
    linklist.addAtIndex(0,20);
    linklist.addAtIndex(1,30);
    int res = linklist.get(0);
}
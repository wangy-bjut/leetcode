#include <vector>
#include <stack>
#include <climits> //最值的宏定义头文件
#include <algorithm>
#include<unordered_map>
#include<unordered_set>
#include<string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class balance
{
public:
    balance(const int &hei, const bool &is) : height(hei), isornot(is) {}

    int height;
    bool isornot;
};

class sousuoe
{
    sousuoe(bool is, int maxn, int minn) : issou(is), maxnum(maxn), minnum(minn) {}

    bool issou;
    int maxnum;
    int minnum;
};

class Solution
{
public:
    void frontErg(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
        {
            return;
        }
        nums.push_back(root->val);

        frontErg(root->left, nums);
        frontErg(root->right, nums);
    }

    void front(TreeNode *root, vector<int> &nums)
    {
        stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            root = stack.top();
            stack.pop();

            nums.push_back(root->val);

            if (root->right != nullptr)
            {
                stack.push(root->right);
            }
            if (root->left != nullptr)
            {
                stack.push(root->left);
            }
        }
    }

    void front2(TreeNode *root, vector<int> &nums)
    {
        stack<TreeNode *> stack;

        while (!stack.empty() || root != nullptr)
        {
            if (root != nullptr)
            {
                nums.push_back(root->val);
                stack.push(root);
                root = root->left;
            }
            else
            {
                root = stack.top();
                stack.pop();

                root = root->right;
            }
        }
    }

    void midErg(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
        {
            return;
        }

        midErg(root->left, nums);

        nums.push_back(root->val);

        midErg(root->right, nums);
    }

    void mid(TreeNode *root, vector<int> &nums)
    {
        stack<TreeNode *> stack;
        while (!stack.empty() || root != nullptr)
        {
            if (root != nullptr)
            {
                stack.push(root);
                root = root->left;
            }
            else
            {
                root = stack.top();
                stack.pop();
                nums.push_back(root->val);

                root = root->right;
            }
        }
    }

    void backErg(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
        {
            return;
        }

        backErg(root->left, nums);
        backErg(root->right, nums);
        nums.push_back(root->val);
    }

    // 实现后序遍历 用栈的方式  可以先进行先序遍历 并将左节点先push  之后将遍历结果反转
    void back(TreeNode *root, vector<int> &nums)
    {
        stack<TreeNode *> stack;
        if(root == nullptr)  // 注意
        {
            return ;
        }

        stack.push(root);

        while (!stack.empty())
        {
            root = stack.top();
            stack.pop();

            nums.push_back(root->val);

            if (root->left != nullptr)
            {
                stack.push(root->left);
            }

            if (root->right != nullptr)
            {
                stack.push(root->right);
            }
        }

        reverse(nums.begin(), nums.end());
    }

    //统一法 迭代实现 后序遍历
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != NULL) {
                st.pop(); // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right) st.push(node->right);  // 添加右节点（空节点不入栈）

                st.push(node);                          // 添加中节点
                st.push(NULL); // 中节点访问过，但是还没有处理，加入空节点做为标记。

                if (node->left) st.push(node->left);    // 添加左节点（空节点不入栈）
            } else { // 只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();           // 将空节点弹出
                node = st.top();    // 重新取出栈中元素
                st.pop();
                result.push_back(node->val); // 加入到结果集
            }
        }
        return result;
    }

    
    void levelOrder(TreeNode *root, vector<int> &nums)
    {
        deque<TreeNode *> deq;
        deq.push_back(root);

        while (!deq.empty())
        {
            int n = deq.size();

            for (int i = 0; i < n; i++)
            {
                root = deq.front();
                deq.pop_front();
                nums.push_back(root->val);

                if (root->left)
                {
                    deq.push_back(root->left);
                }

                if (root->right)
                {
                    deq.push_back(root->right);
                }
            }
        }
    }

    // 递归 巧妙
    void order(TreeNode *root, int deepsize, vector<vector<int>> &res)
    {
        if (root == nullptr)
        {
            return;
        }
        if (deepsize == res.size())
        {
            res.push_back(vector<int>());
        }
        res[deepsize].push_back(root->val);

        order(root->left, deepsize + 1, res);
        order(root->right, deepsize + 1, res);
    }
    void levelOrderE(TreeNode *root, vector<vector<int>> &res)
    {
        int deepsize = 0;

        order(root, deepsize, res);
    }
};

// 二叉树相关问题
class Solution1
{
    long long preVaule = LONG_MIN;

public:
    // 判断是否是搜索二叉树 -递归
    bool sousuoTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        bool isLeft = sousuoTree(root->left);
        if (!isLeft)
        {
            return false;
        }
        if (root->val <= preVaule)
        {
            return false;
        }
        else
        {
            preVaule = root->val;
        }

        return sousuoTree(root->right);
    }

    sousuoe sousuo(TreeNode *root)
    {
        if (root == nullptr)
        {
        }
    }
    // 判断是否是完全二叉树  按宽度遍历   根据满二叉树性质判断
    bool isCBT(TreeNode *root)
    {
        deque<TreeNode *> deq;

        bool islr = false;

        TreeNode *left, *right;

        deq.push_back(root);
        while (!deq.empty())
        {
            root = deq.front();

            left = root->left;
            right = root->right;

            // 两个条件可用 或连接
            if (right != nullptr && left == nullptr)
            {
                return false;
            }
            else if (islr && (left != nullptr || right != nullptr))
            {
                return false;
            }

            if (left != nullptr)
            {
                deq.push_back(left);
            }

            if (right != nullptr)
            {
                deq.push_back(right);
            }

            if (right == nullptr || left == nullptr)
            {
                islr = true;
            }
        }

        return true;
    }

    // 判断是否是满二叉树
    vector<int> isfull(TreeNode *root)
    {
        if (root == nullptr)
        {
            vector<int> a{0, 0};
            return a;
        }

        vector<int> left = isfull(root->left);
        vector<int> right = isfull(root->right);
        int height = max(left[0], right[0]) + 1;
        int node = left[1] + right[1] + 1;

        vector<int> res{height, node};

        return res;
    }

    // 判断平衡二叉树
    // 套路 leetcode 不知原因为无法返回类  利用pair<int,bool>  结构 将两个值合并为一个值
    balance pingheng(TreeNode *root)
    {
        if (root == nullptr)
        {
            return balance(0, true);
        }
        balance left = pingheng(root->left);
        balance right = pingheng(root->right);

        int height = max(left.height, right.height) + 1;
        bool isornot = false;
        if (left.isornot && right.isornot && abs(left.height - right.height) < 2)
        {
            isornot = true;
        }

        return balance(height, isornot);
    }


    // 给出两个节点 求公共祖先  哈希表记录父节点 ，node1 向上回溯。
    TreeNode* lownode(TreeNode *root,TreeNode *node1,TreeNode *node2)
    {
        if(root == nullptr || node1 == root || node2 == root)
        {
            return root; 
        }

        TreeNode *left = lownode(root->left,node1,node2);
        TreeNode *right = lownode(root->right,node1,node2);

        if(left != nullptr && right != nullptr)
        {
            return root;
        }

        return left != nullptr ? left : right;   
    }  

    void process(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &hash)
    {   
        if(root == nullptr)
        {
           return;
        }

        if(root->left != nullptr)    //key如果可以是空 可以不加此判断
        {
            hash.emplace(root->left,root);
            process(root->left,hash);
        }

        if(root->right != nullptr)
        {
            hash.emplace(root->right,root);
            process(root->right,hash);
        }
  
    }
    TreeNode *lownode1(TreeNode *root, TreeNode *node1, TreeNode *node2)
    {
        unordered_map<TreeNode*,TreeNode*> hash;
        hash.emplace(root,root);
        process(root,hash);

        unordered_set<TreeNode*> hash1;
        while (node1 != hash[node1])
        {
            hash1.emplace(node1);
            node1 = hash[node1];
        }
        hash1.emplace(node1);

        while(node2 != hash[node2])
        {
            if(hash1.count(node2))
            {
                return node2;
            }
            node2 = hash[node2];
        }

        return node2;
        
    }    

    //后继节点  中序遍历的后一个节点 

    //序列化  中序遍历
    string bittree(TreeNode *root)
    {
        if(root == nullptr)
        {
            return "#_";
        }
        string res = to_string(root->val) + "_";

        res+=bittree(root->left);
        res+=bittree(root->right);

        return res;
        
    }

    //反序列化

    TreeNode *order(deque<char> &deq)
    {
       
            char str = deq.front();
            deq.pop_front();
            if(str == '#')
            {
                return nullptr;
            }

            TreeNode *root ;
            root = new TreeNode(str-'0');
            root->left = order(deq);
            root->right = order(deq); 

            return root;

    }
    TreeNode* resbittree(string &res)
    {
        deque<char> deque;

        for(auto &str:res)
        {
            if(str == '_')
            {
                continue;
            }
            else
            {
                deque.push_back(str);
            }
        }

        TreeNode *head = order(deque);

      return head;

    }

    //记录所有出现的凹凸情况i 节点层数  n 一共的层数
    void write(int i,int N,bool down,vector<int> &nums)
    {
        if(i>N)
        {
            return ;
        }

        write(i+1,N,true,nums);
        nums.push_back(down ? 1:-1);
        write(i+1,N,false,nums);

    }

};

int main()
{
    Solution A;
    Solution1 A1;

    TreeNode *root = new TreeNode(1), *head;

    head = root;

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    string res;
    res = A1.bittree(head);

    TreeNode *re = A1.resbittree(res);
    
}
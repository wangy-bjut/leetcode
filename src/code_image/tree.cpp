#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
//完全二叉树的节点数目。  递归如果是满二叉树  则用公式计算节点个数  否则继续递归
    int numNodes(TreeNode *root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftdeep = 0;
        int rightdeep = 0;
        while(left != nullptr)
        {
            left = left->left;
            leftdeep++;
        }
        while(right != nullptr)
        {
            right = right->right;
            rightdeep++;
        }

        if(leftdeep == rightdeep)
        {
            return (2<<leftdeep)-1;
        }

        return numNodes(root->left)+numNodes(root->right)+1;
    }

    // 二叉树的最大深度  根节点的深度为最大深度。  一般后序遍历用来求高度   先序遍历求深度 根节点的高度就是最大深度
    int get_height(TreeNode *root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int leftdeep = get_height(root->left);
        int rightdeep = get_height(root->right);

        return max(leftdeep,rightdeep)+1;
    }
    //求二叉树深度  先序遍历
    int result;
    int get_deep(TreeNode *root, int deep)
    {
        result = result > deep ? result:deep;
        if(root->left == nullptr && root->right == nullptr)
        {
            return ;
        }


        if(root->left)
        {
          get_deep(root->left,deep+1);
        }

        if(root->right)
        {
           get_deep(root->right,deep+1);
        }

        return ;
        
    }




};

int main()
{
    Solution A;
    
}




 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {

    void recur(bool &res,TreeNode *root)
    {
        if(root->left != nullptr)
        {
            if(root->left->val >= root->val)
            {
                res =  false;
            }
            recur(res,root->left);
        }

        if(root->right != nullptr)
        {
            if(root->right->val <= root->val)
            {
              res =  false;
            }
            recur(res,root->right);
        }

     
  
        
    }
public:
    bool isValidBST(TreeNode* root) {
        bool res = true;

        recur(res,root);

        return res;

    }
};


int main()
{
    Solution A;

    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode();

    bool res = A.isValidBST(root);
}
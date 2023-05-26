 #include<vector>

 using namespace std;

 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {

public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
       vector<TreeNode*> vec;
        if(root1 == nullptr )
        {
            return root2;
        }
        if(root2 == nullptr)
        {
            return root1;
        }

        vec.push_back(root1);
        vec.push_back(root2);
       
       while(vec.size())
       {
           TreeNode *r2 = vec.back();
           vec.pop_back();
           TreeNode *r1 = vec.back();
           vec.pop_back();

           if(r1!=nullptr && r2!=nullptr)
           {
              
               r1->val += r2->val;
           }
           //此if没有必要， push进去的肯定存在；
           if(r1 == nullptr)
           {
               r1 = r2;
           }
        
           
           if(r1->left != nullptr && r2->left != nullptr)
           {
               vec.push_back(r1->left);
               vec.push_back(r2->left);

           }
           else if(r1->left == nullptr)
           {
            r1->left = r2->left;
           
           }
        
           

            if(r1->right != nullptr && r2->right != nullptr)
           {
               vec.push_back(r1->right);
               vec.push_back(r2->right);

           }
           else if(r1->right == nullptr)
           {
            r1->right = r2->right;
           }
           
       
           
           

       }

       return root1;
       

    }
};

int main()
{
    TreeNode *root1;
    root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode *root2;
    root2 = new TreeNode(2);
    (root2->left) = new TreeNode(1);
    (root2->right) = new TreeNode(3);
    (root2->left->right) = new TreeNode(4);
    (root2->right->right) = new TreeNode(7);

    Solution A;

    TreeNode *root3;

    root3 = A.mergeTrees(root1,root2);



}
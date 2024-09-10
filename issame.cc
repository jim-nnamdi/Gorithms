 #include <iostream>
 #include <queue>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if (p == nullptr && q == nullptr)
        return true;

       if (p == nullptr || q == nullptr)
        return false;

        std::queue<TreeNode*> px, qx;
        px.push(p), qx.push(q);

        while(!px.empty() && !qx.empty()){
            TreeNode* pval =  px.front(); px.pop();
            TreeNode* qval =  qx.front(); qx.pop();
            
            if(pval != qval) return false;
            px.push(pval->left);
            px.push(qval->left);
            qx.push(pval->right);
            qx.push(qval->right);
        }
    }
};


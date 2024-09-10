/* maxdepth is getting the number of nodes */
/* from the root node to the farthest node */
/* goes from the root node to the leaf node */

 #include <iostream>
 #include <vector>
 #include <queue>
 #include <algorithm>
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while(!q.empty()){
            int levelsize = q.size();
            depth++;
            for(int i =0; i < levelsize; ++i){
                TreeNode* node = q.front();q.pop();
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
        }
        return depth;
    }
};
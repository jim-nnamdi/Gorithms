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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int levelsize = q.size();
            vector<int> currlevel;
            for(int i=0; i < levelsize; ++i){
                TreeNode* node = q.front(); q.pop();
                currlevel.push_back(node->val);
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            result.insert(result.begin(), currlevel);
        }
        return result;
    }
};
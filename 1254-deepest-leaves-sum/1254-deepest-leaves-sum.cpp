/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        
        while(q.size()!=0){
            int n = q.size();
            sum=0;
            for(int i=0;i<n;i++){
                TreeNode* n = q.front();
                q.pop();
                sum+=n->val;
                if(n->left!=nullptr) q.push(n->left);
                if(n->right!=nullptr) q.push(n->right);
            
            }

        }
        return sum;
        
    }
};
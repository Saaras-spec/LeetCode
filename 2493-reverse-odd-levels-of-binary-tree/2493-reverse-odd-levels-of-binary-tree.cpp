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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==nullptr) return root;
        queue<TreeNode*> q;
        q.push(root);
        int level =0;
        vector<TreeNode*> v;

        while(!q.empty()){
            int n = q.size();
            v.clear();
            for(int i=0;i<n;i++){
                TreeNode* nn = q.front();
                q.pop();

                if(level%2==1){
                    v.push_back(nn);
                }
                if(nn->left!=nullptr) q.push(nn->left);
                if(nn->right!=nullptr) q.push(nn->right);
            }
            if(level%2==1){
                int i=0;
                int j = v.size()-1;

                while(i<j){
                    swap(v[i]->val,v[j]->val);
                    i++;
                    j--;
                }
            }
            level++;

        }
        return root;
        
    }
};
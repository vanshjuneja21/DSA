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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxWidth = 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int minIndex = q.front().second;
            int first = 0;
            int last = 0;
            for(int i=0;i<size;i++){
                long long currIndex = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = currIndex;
                if(i==size-1) last = currIndex;
                if(node->left) q.push({node->left,2*currIndex+1});
                if(node->right) q.push({node->right,2*currIndex+2});
            }
            maxWidth = max(maxWidth,last-first+1);
        }
        return maxWidth;
    }
};
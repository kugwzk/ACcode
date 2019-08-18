/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum[100000];
    void dfs(TreeNode* rt, int depth) {
        sum[depth] += rt->val;
        if(rt->left) {
            dfs(rt->left, depth+1);
        }
        if(rt->right) {
            dfs(rt->right,depth+1);
        }
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,1);
        int ans = 1;
        for(int i=2;i<=10010;i++) {
            if(sum[ans] < sum[i]) ans = i;
        }
        return ans;
    }
};
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
    int Size[200];
    vector<int>vec[200];
    void dfs(TreeNode* rt) {
        if(!rt) return ;
        int val = rt->val;
        Size[val] += 1;
        if(rt->left) {
            vec[val].push_back(rt->left->val);
            dfs(rt->left);
            Size[val] += Size[rt->left->val];
        }
        if(rt->right) {
            vec[val].push_back(rt->right->val);
            dfs(rt->right);
            Size[val] += Size[rt->right->val];
        }
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dfs(root);

        if(Size[x] < n-Size[x]) return 1;
        else {
            for(auto son: vec[x]){
                if(Size[son] > n-Size[son]) return 1;
            }
            return 0;
        }
    }
};
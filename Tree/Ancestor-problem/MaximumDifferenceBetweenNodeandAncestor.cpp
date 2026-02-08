#include <bits/stdc++.h>
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

    int result = INT_MIN ; 

    int dfs(TreeNode* root ){

        if(!root->left && !root->right){
            return 0 ; 
        }

        int value = INT_MAX  ; 

        value = min(value , dfs(root ->left)) ; 
        value = min(value , dfs(root->right)) ; 

        result = max(result , root->val - value) ; 

        // Go in left subtree 

        dfs(root -> left) ; 
        dfs(root -> right) ; 

        return result ; 

       
    }


    int maxAncestorDiff(TreeNode* root){

    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    // Tree: [8,3,10,1,6,null,14,null,null,4,7,13]
    TreeNode* root1 = new TreeNode(8);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(10);

    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(6);

    root1->left->right->left = new TreeNode(4);
    root1->left->right->right = new TreeNode(7);

    root1->right->right = new TreeNode(14);
    root1->right->right->left = new TreeNode(13);

    cout << sol.maxAncestorDiff(root1) << endl; // Expected: 7

    // ---------- Example 2 ----------
    // Tree: [1,null,2,null,0,3]
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->right = new TreeNode(0);
    root2->right->right->left = new TreeNode(3);

    cout << sol.maxAncestorDiff(root2) << endl; // Expected: 3

    return 0;
}

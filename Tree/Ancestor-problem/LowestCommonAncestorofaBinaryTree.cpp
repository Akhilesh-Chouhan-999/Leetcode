#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* dfs(TreeNode* root , TreeNode* p , TreeNode *q){
        
        if(!root) 
        return  NULL;

        if(root == p || root == q) 
        return root ; 


        TreeNode* rootLeft = dfs(root -> left , p  , q) ;
        TreeNode* rootRight = dfs(root->right , p , q ) ; 
        
        
        if(rootLeft && rootRight)
        return root ;


        else if(rootLeft && !rootRight)
        return rootLeft ; 

        else if(!rootLeft && rootRight){
            return rootRight ; 
        }

        return nullptr  ;

        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

        return dfs(root , p , q ) ; 
    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    // Tree: [3,5,1,6,2,0,8,null,null,7,4]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(8);

    TreeNode* p1 = root1->left;   // 5
    TreeNode* q1 = root1->right;  // 1

    cout << sol.lowestCommonAncestor(root1, p1, q1)->val << endl; // Expected: 3

    // ---------- Example 2 ----------
    TreeNode* p2 = root1->left;                    // 5
    TreeNode* q2 = root1->left->right->right;      // 4

    cout << sol.lowestCommonAncestor(root1, p2, q2)->val << endl; // Expected: 5

    // ---------- Example 3 ----------
    // Tree: [1,2]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);

    TreeNode* p3 = root2;          // 1
    TreeNode* q3 = root2->left;    // 2

    cout << sol.lowestCommonAncestor(root2, p3, q3)->val << endl; // Expected: 1

    return 0;
}

// Time Complexity : O(n) where n is the no . of nodes . 
// Space Complexity : O(h) where h is the height . 
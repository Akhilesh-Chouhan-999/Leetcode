#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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

    int dfs(TreeNode *root , bool &flag){

        if(!root){
            return 0 ; 
        }

        int leftSubTree = dfs(root -> left , flag) ; 
        int rightSubTree = dfs(root-> right , flag) ;
        
        
        if(abs(rightSubTree - leftSubTree) > 1 ){
            flag = false ; 
        }


        return 1 + max(leftSubTree , rightSubTree) ; 

    }
    bool isBalanced(TreeNode* root){

        bool result = true ; 

        dfs(root , result) ;
        
        return result ; 
    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    // Tree: [3,9,20,null,null,15,7]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    cout << "Output: " << sol.isBalanced(root1)
         << " | Expected: 1" << endl;  // true -> 1

    // ---------- Example 2 ----------
    // Tree: [1,2,2,3,3,null,null,4,4]
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(3);
    root2->left->left->left = new TreeNode(4);
    root2->left->left->right = new TreeNode(4);

    cout << "Output: " << sol.isBalanced(root2)
         << " | Expected: 0" << endl;  // false -> 0

    // ---------- Example 3 ----------
    // Tree: []
    TreeNode* root3 = nullptr;

    cout << "Output: " << sol.isBalanced(root3)
         << " | Expected: 1" << endl;  // true -> 1

    return 0;
}

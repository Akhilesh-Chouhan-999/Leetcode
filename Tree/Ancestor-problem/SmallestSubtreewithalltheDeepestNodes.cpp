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

    TreeNode* result ; 

    int calculateHeight(TreeNode *root){

        if(!root)
        return 0 ; 

        int leftSubTree = 1 + calculateHeight(root -> left) ; 
        int rightSubTree = 1 + calculateHeight(root -> right) ; 

        return max(leftSubTree , rightSubTree) ; 

    }

    void dfs(TreeNode* root){

        if(!root)
        return  ;

        int left = calculateHeight(root -> left) ; 
        int right = calculateHeight(root -> right) ; 

        if(left == right){
            result = root ; 
            return  ; 
        }
        
        else if(left > right) 
         dfs(root->left) ; 

         else
         dfs(root->right) ;

    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root){

        result = NULL ; 

         dfs(root) ; 

         return result ; 
    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    // root = [3,5,1,6,2,0,8,null,null,7,4]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(5);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(6);
    root1->left->right = new TreeNode(2);
    root1->left->right->left = new TreeNode(7);
    root1->left->right->right = new TreeNode(4);
    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(8);

    TreeNode* ans1 = sol.subtreeWithAllDeepest(root1);
    cout << "Output root: " << ans1->val << " | Expected: 2" << endl;

    // ---------- Example 2 ----------
    // root = [1]
    TreeNode* root2 = new TreeNode(1);

    TreeNode* ans2 = sol.subtreeWithAllDeepest(root2);
    cout << "Output root: " << ans2->val << " | Expected: 1" << endl;

    // ---------- Example 3 ----------
    // root = [0,1,3,null,2]
    TreeNode* root3 = new TreeNode(0);
    root3->left = new TreeNode(1);
    root3->right = new TreeNode(3);
    root3->left->right = new TreeNode(2);

    TreeNode* ans3 = sol.subtreeWithAllDeepest(root3);
    cout << "Output root: " << ans3->val << " | Expected: 2" << endl;

    return 0;
}

// Time Complexity : O( n ^ 2)
// Space Complexity : O( n )


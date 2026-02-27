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

    int totalSum  ;


    void dfs(TreeNode *root , int currSum , int mul){

        if(!root->left && !root->right){
            currSum += root->val * mul ; 
            totalSum +=  currSum ;

            return  ; 
        }

        currSum += root -> val * mul ; 

        dfs(root -> left , currSum , 2 * mul) ; 
        dfs(root -> right , currSum , 2 * mul) ; 

        return ; 
    }

    int sumRootToLeaf(TreeNode* root){

        totalSum = 0 ;
        
        dfs(root , 0 , 1 ) ; 

        return totalSum ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    // Tree: [1,0,1,0,1,0,1]
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(0);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(1);
    root1->right->left = new TreeNode(0);
    root1->right->right = new TreeNode(1);

    cout << "Output: " << sol.sumRootToLeaf(root1)
         << " | Expected: 22" << endl;

    // Example 2
    // Tree: [0]
    TreeNode* root2 = new TreeNode(0);

    cout << "Output: " << sol.sumRootToLeaf(root2)
         << " | Expected: 0" << endl;

    return 0;
}
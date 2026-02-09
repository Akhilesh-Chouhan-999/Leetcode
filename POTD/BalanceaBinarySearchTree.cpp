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

    void inOrder(TreeNode* root , vector<int>&vec){
        if(!root) return ; 

        inOrder(root -> left , vec) ; 

        vec.push_back(root->val) ; 

        inOrder(root -> right , vec) ; 

        return  ; 

    }

    TreeNode * constructBBST(vector<int>&temp , int start , int end ){


        if(start > end ) return NULL ; 

            int mid = start + ( end - start ) / 2 ; 

            TreeNode * root = new TreeNode(temp[mid]) ; 
            root -> left =  constructBBST(temp , start , mid - 1) ;
            root -> right = constructBBST(temp , mid + 1 , end ) ; 

            return root  ; 
    }

    TreeNode* balanceBST(TreeNode* root){

        vector<int>temp ; 

        inOrder(root , temp) ;


        return constructBBST(temp , 0 , temp.size() - 1 ) ; 

    }
};


int main() {
    Solution sol;

    // ---------- Example 1 ----------
    // Input: [1,null,2,null,3,null,4]
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->right = new TreeNode(3);
    root1->right->right->right = new TreeNode(4);

    TreeNode* balanced1 = sol.balanceBST(root1);

    cout << "Output root value: " << balanced1->val
         << " | Expected: any valid balanced BST (e.g., root = 2 or 3)" << endl;

    // ---------- Example 2 ----------
    // Input: [2,1,3]
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);

    TreeNode* balanced2 = sol.balanceBST(root2);

    cout << "Output root value: " << balanced2->val
         << " | Expected: 2" << endl;

    return 0;
}

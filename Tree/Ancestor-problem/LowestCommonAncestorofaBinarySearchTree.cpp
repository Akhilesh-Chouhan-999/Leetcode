/*

#include <bits/stdc++.h>
using namespace std;

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

        return NULL ; 

        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

        return dfs(root , p , q ) ; 
    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    // Tree: [6,2,8,0,4,7,9,null,null,3,5]
    TreeNode* root1 = new TreeNode(6);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(4);
    root1->left->right->left = new TreeNode(3);
    root1->left->right->right = new TreeNode(5);
    root1->right->left = new TreeNode(7);
    root1->right->right = new TreeNode(9);

    TreeNode* p1 = root1->left;        // 2
    TreeNode* q1 = root1->right;       // 8

    cout << sol.lowestCommonAncestor(root1, p1, q1)->val << endl; // Expected: 6

    // ---------- Example 2 ----------
    TreeNode* p2 = root1->left;              // 2
    TreeNode* q2 = root1->left->right;       // 4

    cout << sol.lowestCommonAncestor(root1, p2, q2)->val << endl; // Expected: 2

    // ---------- Example 3 ----------
    // Tree: [2,1]
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);

    TreeNode* p3 = root2;          // 2
    TreeNode* q3 = root2->left;    // 1

    cout << sol.lowestCommonAncestor(root2, p3, q3)->val << endl; // Expected: 2

    return 0;
}

Time Complexity : O(n) where n is the no. of nodes .  
Space Complexity : O(h) where h is the height . 
*/


#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

        while(root){

            if( p->val < root->val && q->val < root -> val){
                root = root -> left ; 
            }
            else if(p -> val > root->val && q -> val > root->val) {
                root = root -> right ; 
            }
            else{
                return root ; 
            }
        }
        
        return NULL ; 
    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    // Tree: [6,2,8,0,4,7,9,null,null,3,5]
    TreeNode* root1 = new TreeNode(6);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(0);
    root1->left->right = new TreeNode(4);
    root1->left->right->left = new TreeNode(3);
    root1->left->right->right = new TreeNode(5);
    root1->right->left = new TreeNode(7);
    root1->right->right = new TreeNode(9);

    TreeNode* p1 = root1->left;        // 2
    TreeNode* q1 = root1->right;       // 8

    cout << sol.lowestCommonAncestor(root1, p1, q1)->val << endl; // Expected: 6

    // ---------- Example 2 ----------
    TreeNode* p2 = root1->left;              // 2
    TreeNode* q2 = root1->left->right;       // 4

    cout << sol.lowestCommonAncestor(root1, p2, q2)->val << endl; // Expected: 2

    // ---------- Example 3 ----------
    // Tree: [2,1]
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);

    TreeNode* p3 = root2;          // 2
    TreeNode* q3 = root2->left;    // 1

    cout << sol.lowestCommonAncestor(root2, p3, q3)->val << endl; // Expected: 2

    return 0;
}
// Time Complexity : O(n)
// Space Complexity : O(1)


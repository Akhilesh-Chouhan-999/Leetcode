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
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        int level =  0; 
        int maximalSum = INT_MIN ; 
        int result = 1 ; 

        queue<TreeNode*> que ; 
        que.push(root) ; 

        while(!que.empty()){
            
            int size = que.size() ; 
            int sumLevel = 0 ; 

            for(int i = 0 ; i < size ; i ++ ){

                TreeNode* node = que.front() ;
                que.pop() ;

                sumLevel += node->val ; 

                if(node->left) que.push(node->left) ; 
                if(node->right) que.push(node->right) ; 

            }

            level ++ ; 


            if(maximalSum < sumLevel){
                result = level ; 
                maximalSum = sumLevel ; 
            }


        }

      return result ; 

     
    }
};

int main() {
    Solution sol;

    // Example 1: root = [1,7,0,7,-8,null,null]
    TreeNode* root1 = new TreeNode(
        1,
        new TreeNode(7, new TreeNode(7), new TreeNode(-8)),
        new TreeNode(0)
    );

    cout << "Output (Example 1): "
         << sol.maxLevelSum(root1) << endl; // Expected: 2

    // Example 2: root = [989,null,10250,98693,-89388,null,null,null,-32127]
    TreeNode* root2 = new TreeNode(
        989,
        nullptr,
        new TreeNode(
            10250,
            new TreeNode(98693, nullptr, new TreeNode(-32127)),
            new TreeNode(-89388)
        )
    );

    cout << "Output (Example 2): "
         << sol.maxLevelSum(root2) << endl; // Expected: 2

    return 0;
}


// Time Complexity : O(n)
// Space Complexity : O(n) where n is total nodes . 

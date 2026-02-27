/*
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

    int result = 0 ; 

    bool checkPalindrome(vector<int>&vec){

        unordered_map<int , int> mpp ; 

        for(int v : vec){
            mpp[v] ++ ; 
        }

        bool flag = false ; 

        for(auto p : mpp){

            int first = p.first  ; 
            int second = p.second ; 

            if(second % 2 == 1) {
                if(flag) return false ; 
                flag = true ; 
            }
        
        }

        return true ; 

    }

    void dfs(TreeNode* root , vector<int>&vec ){

        if(!root)
        return ; 

        vec.push_back(root->val) ; 
        
        if(!root->left && !root->right){
            if(checkPalindrome(vec)) 
            result ++ ; 

            vec.pop_back() ; 
            return ; 
        }


        dfs(root->left , vec) ; 
        dfs(root->right , vec) ;

        vec.pop_back()  ; 

        return ; 

    }
    int pseudoPalindromicPaths(TreeNode* root){

        vector<int>vec ; 
        dfs(root , vec) ; 

        return result  ; 

    }
};


int main() {
    Solution sol;

    // ---------- Example 1 ----------
    // Tree: [2,3,1,3,1,null,1]
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(1);
    root1->right->right = new TreeNode(1);

    cout << "Output: " << sol.pseudoPalindromicPaths(root1)
         << " | Expected: 2" << endl;

    // ---------- Example 2 ----------
    // Tree: [2,1,1,1,3,null,null,null,null,null,1]
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    root2->left->right->right = new TreeNode(1);

    cout << "Output: " << sol.pseudoPalindromicPaths(root2)
         << " | Expected: 1" << endl;

    // ---------- Example 3 ----------
    // Tree: [9]
    TreeNode* root3 = new TreeNode(9);

    cout << "Output: " << sol.pseudoPalindromicPaths(root3)
         << " | Expected: 1" << endl;

    return 0;
}

Time Complexity : O(n^2)
Space Complexity : O(n)

*/


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

    int result = 0 ; 


    void dfs(TreeNode* root , int mask  ){

        if(!root)
        return ; 

        mask ^= ( 1 << root->val ) ; 

        if(!root->left && !root->right){
            if((mask & ( mask - 1)) == 0)
            result ++ ; 

            return ; 
        }
        
        dfs(root->left , mask) ; 
        dfs(root->right , mask) ; 
        
        return ; 

    }


    int pseudoPalindromicPaths(TreeNode* root){

     
        dfs(root  , 0) ; 

        return result  ; 

    }
};


int main() {
    Solution sol;

    // ---------- Example 1 ----------
    // Tree: [2,3,1,3,1,null,1]
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(1);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(1);
    root1->right->right = new TreeNode(1);

    cout << "Output: " << sol.pseudoPalindromicPaths(root1) << endl;

    // ---------- Example 2 ----------
    // Tree: [2,1,1,1,3,null,null,null,null,null,1]
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(1);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(3);
    root2->left->right->right = new TreeNode(1);

    cout << "Output: " << sol.pseudoPalindromicPaths(root2) << endl ;

    // ---------- Example 3 ----------
    // Tree: [9]
    TreeNode* root3 = new TreeNode(9);

    cout << "Output: " << sol.pseudoPalindromicPaths(root3);

    return 0;
}





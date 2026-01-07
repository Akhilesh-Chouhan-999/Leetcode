/*
    #include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    long long maxi = LLONG_MIN ; 

    int sumOfTree(TreeNode *root){
        
        if(!root) return 0 ; 

        int sum = root->val ;

        // LeftSubTree sum 
        sum += sumOfTree(root->left) ; 

        // RightSubTree sum 
        sum += sumOfTree(root->right) ; 

        return sum ; 
    }

    void solve(TreeNode * root , int sum ){

        if(!root){
            return  ; 
        }

        int leftTreeSum = sumOfTree(root->left) ; 
        long long ans1 = leftTreeSum * (sum - leftTreeSum) ; 
        maxi = max(ans1 , maxi) ; 

        int rightTreeSum = sumOfTree(root->right);
        long long ans2 =  rightTreeSum * ( sum - rightTreeSum) ; 
        maxi = max(maxi , ans2) ; 


        solve(root->left , sum) ; 
        solve(root->right , sum) ;

        return   ; 
      
    }
    
    int maxProduct(TreeNode* root) {
      
     int sum =  sumOfTree(root) ; 

     solve(root , sum) ; 

     return maxi % 1000000007 ; 


    }
};

int main() {
    Solution sol;

    //  -------- Example 1 --------
    //    Tree: [1,2,3,4,5,6]
    //         1
    //        / \
    //       2   3
    //      / \  /
    //     4  5 6
    //    Expected Output: 110
    
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);

    cout << "Output (Example 1): " << sol.maxProduct(root1) << endl;

    return 0;
}


Time Complexity : O(n^2)
Space Complexity : O(n)
*/ 


#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    long long maxi = LLONG_MIN ; 

     int sumOfTree(TreeNode *root){
        
        if(!root) return 0 ; 

        int sum = root->val ;

        // LeftSubTree sum 
        sum += sumOfTree(root->left) ; 

        // RightSubTree sum 
        sum += sumOfTree(root->right) ; 

        return sum ; 
    }


    int solve(TreeNode * root , long long totalSum ){

        if(!root) 
        return 0 ; 

        long long leftSum = solve(root -> left , totalSum) ; 
        long long rightSum = solve(root->right , totalSum) ;

        long long currSum = root->val + leftSum + rightSum ; 

        maxi = max(maxi , currSum * ( totalSum - currSum) ) ; 

        return currSum ;

    }
    
    int maxProduct(TreeNode* root) {

        long long sum = sumOfTree(root) ; 

        solve(root , sum) ; 

         return maxi % 1000000007 ; 


    }
};

int main() {
    Solution sol;

    //  -------- Example 1 --------
    //    Tree: [1,2,3,4,5,6]
    //         1
    //        / \
    //       2   3
    //      / \  /
    //     4  5 6
    //    Expected Output: 110
    
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    root1->right->left = new TreeNode(6);

    cout << "Output (Example 1): " << sol.maxProduct(root1) << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(h) where h equals to n . 

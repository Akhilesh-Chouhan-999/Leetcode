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
    TreeNode* addOneRow(TreeNode* root, int val, int depth){

        if(depth == 1){
            TreeNode *node = new TreeNode(val) ; 
            node -> left =  root ; 
            return node ; 
        }


        queue<TreeNode*>que ; 
        que.push(root) ; 
        int dep = 1 ;

        while(!que.empty()){
            
            int size = que.size() ; 
          
            while(size -- ){

                TreeNode *node = que.front() ; 
                que.pop() ; 


                if(dep + 1 == depth){

                    TreeNode* newLeft = new TreeNode(val);
                    TreeNode* newRight = new TreeNode(val);

                    newLeft->left = node->left;
                    newRight->right = node->right;

                    node->left = newLeft;
                    node->right = newRight;

                }
            
                else{

                    if(node->left)
                    que.push(node->left) ; 

                    if(node->right)
                    que.push(node->right) ; 
                }
            }

            if(dep + 1 == depth)
            break;

         dep ++ ; 

        }

        return root ; 

    }
};

// Helper function to print tree level order
void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {

    Solution sol;

    // ================== Test Case 1 ==================
    // Input: root = [4,2,6,3,1,5], val = 1, depth = 2

    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(1);
    root1->right->left = new TreeNode(5);

    TreeNode* result1 = sol.addOneRow(root1, 1, 2);

    cout << "Test Case 1 Output (Level Order): ";
    printLevelOrder(result1);


    // ================== Test Case 2 ==================
    // Input: root = [4,2,null,3,1], val = 1, depth = 3

    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);
    root2->left->right = new TreeNode(1);

    TreeNode* result2 = sol.addOneRow(root2, 1, 3);

    cout << "Test Case 2 Output (Level Order): ";
    printLevelOrder(result2);

    return 0;
}


// Time Complexity : O(n)
// Space Complexity : O(n)
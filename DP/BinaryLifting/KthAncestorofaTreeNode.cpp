/*
#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:

    vector<int>par ; 

    TreeAncestor(int n, vector<int>& parent){
        par = parent  ; 
    }
    int getKthAncestor(int node, int k){

        while( k > 0 && node != -1){
            node = par[node] ; 
            k -- ; 
        }


        return node ; 
    }
};

int main() {
    // Example from problem
    int n = 7;
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};

    TreeAncestor* treeAncestor = new TreeAncestor(n, parent);

    cout << "Output: " << treeAncestor->getKthAncestor(3, 1)
         << " | Expected: 1" << endl;

    cout << "Output: " << treeAncestor->getKthAncestor(5, 2)
         << " | Expected: 0" << endl;

    cout << "Output: " << treeAncestor->getKthAncestor(6, 3)
         << " | Expected: -1" << endl;

    delete treeAncestor;

    return 0;
}

// Time Complexity : O(n^2)
// Space Complexity : O(n)
*/


#include <bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:


    const int LOG = 18 ;
    vector<vector<int>>up ; 


    TreeAncestor(int n, vector<int>& parent){

        up.resize(LOG , vector<int>(n , -1)) ; 

        for(int i = 0 ; i < n ; i ++ )
        up[0][i] = parent[i] ; 

        for(int i = 1 ; i < LOG ; i ++ ){
            for(int j = 0 ; j < n ; j ++ ){

                if(up[i-1][j] != -1){
                    up[i][j] = up[i-1][ up[i-1][j] ] ; 
                }
            }
        }

    }


    int getKthAncestor(int node, int k){

        for(int i = 0 ; i < LOG ; i ++ ){
            if(k &   ( 1 << i )){
                node = up[i][node] ; 
            }


            if(node == -1 )
            return -1 ; 
        }


        return node ; 

    }
};

int main() {
    // Example from problem
    int n = 7;
    vector<int> parent = {-1, 0, 0, 1, 1, 2, 2};

    TreeAncestor* treeAncestor = new TreeAncestor(n, parent);

    cout << "Output: " << treeAncestor->getKthAncestor(3, 1)
         << " | Expected: 1" << endl;

    cout << "Output: " << treeAncestor->getKthAncestor(5, 2)
         << " | Expected: 0" << endl;

    cout << "Output: " << treeAncestor->getKthAncestor(6, 3)
         << " | Expected: -1" << endl;

    delete treeAncestor;

    return 0;
}

// Time Complexity : O(n*log2(n))
// Space Complexity : O(n)
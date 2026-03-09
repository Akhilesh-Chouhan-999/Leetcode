#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[501][501] ;

    int solve(vector<int>&piles , int start , int end){

        if(start == end)
        return piles[start] ; 

        if(memo[start][end] != -1)
        return memo[start][end] ; 

        int left  = piles[start] - solve(piles , start + 1 , end) ; 
        int right = piles[end]   - solve(piles , start , end - 1) ; 

        return memo[start][end] =  max(left , right) ; 

    }

    bool stoneGame(vector<int>& piles){ 

        int n = piles.size() ; 

        memset(memo , -1 , sizeof(memo)) ; 

        return solve(piles , 0 , n - 1 ) ;

    }
};

int main() {
    Solution obj;

    vector<int> piles1 = {5,3,4,5};
    vector<int> piles2 = {3,7,2,3};
    vector<int> piles3 = {1,2,3,4};
    vector<int> piles4 = {8,15,3,7};

    cout << obj.stoneGame(piles1) << endl;
    cout << obj.stoneGame(piles2) << endl;
    cout << obj.stoneGame(piles3) << endl;
    cout << obj.stoneGame(piles4) << endl;

    return 0;
}

// Time Complexity : O(n*n)
// Space Complexity : O(n * n)
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {

        
    }
};

int main(){
    Solution sol ; 


    vector<vector<int>> squares1 = {{0, 0, 2}, {1, 1, 3}};
    double result1 = sol.separateSquares(squares1) ; 
    cout << "Test Case 1 Input: squares = {{0, 0, 2}, {1, 1, 3}}" << endl;
    cout << "Test Case 1 Result: " << result1 << " (Expected: approx 2.50000)" << endl;


    vector<vector<int>> squares2 = {{0, 0, 1}, {2, 0, 1}};
    double result2 = sol.separateSquares(squares2) ; 
    cout << "Test Case 2 Input: squares = {{0, 0, 1}, {2, 0, 1}}" << endl;
    cout << "Test Case 2 Result: " << result2 << " (Expected: approx 0.50000)" << endl;

    return 0 ; 

}
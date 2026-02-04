#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       
         int n = fruits.size() ; 
         
         int i = 0 ; 
         int j = 0 ; 

         unordered_map<int,int>mpp ; 
         int result = INT_MIN ; 

         while(j < n){

            mpp[fruits[j]] ++ ; 

            while(mpp.size() == 3 ) {
            
                if(-- mpp[fruits[i]] == 0)
                mpp.erase(fruits[i]) ; 

                i ++ ; 

            }

            result = max(result , j - i + 1 ) ; 

            j ++ ;

         }

         return result ;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> testCases = {
        {1, 2, 1},
        {0, 1, 2, 2},
        {1, 2, 3, 2, 2},
        {5, 5, 5, 5, 5},
        {1, 2, 1, 2, 1, 2},
        {1, 2, 3, 4, 5},
        {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4},
        {7},
        {8, 9},
        {1, 2, 1, 3, 4, 3, 5, 1, 2}
    };

    vector<int> expected = {
        3,  // {1,2,1}
        3,  // {0,1,2,2}
        4,  // {1,2,3,2,2}
        5,  // {5,5,5,5,5}
        6,  // {1,2,1,2,1,2}
        2,  // {1,2,3,4,5}
        5,  // {3,3,3,1,2,1,1,2,3,3,4}
        1,  // {7}
        2,  // {8,9}
        3   // {1,2,1,3,4,3,5,1,2}
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": ";
        cout << "Output = " << obj.totalFruit(testCases[i]);
        cout << " | Expected = " << expected[i] << endl;
    }

    return 0;
}


// Time Complexity : O(n)
// Space Complexity : O(1) : Constant Space . 
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {

        int n = apple.size() ; 
        int m = capacity.size() ; 

        sort(capacity.begin() , capacity.end() , greater<int>()) ; 

        int totalApples = accumulate(begin(apple) , end(apple) , 0 ) ; 

       for(int i = 0 ; i < m ; i ++ ){

         totalApples -= capacity[i] ; 

         if(totalApples <= 0 )
         {
            return i + 1 ; 
         }

       }

       return -1 ; 
        
        
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> apple1 = {1, 3, 2};
    vector<int> cap1 = {4, 3, 1, 5, 2};
    cout << "Output: " << sol.minimumBoxes(apple1, cap1)
         << " | Expected: 2" << endl;

    // Test Case 2
    vector<int> apple2 = {5, 5, 5};
    vector<int> cap2 = {2, 4, 2, 7};
    cout << "Output: " << sol.minimumBoxes(apple2, cap2)
         << " | Expected: 4" << endl;

    // Test Case 3 (single apple pack)
    vector<int> apple3 = {10};
    vector<int> cap3 = {3, 5, 2, 10};
    cout << "Output: " << sol.minimumBoxes(apple3, cap3)
         << " | Expected: 1" << endl;

    // Test Case 4 (exact match)
    vector<int> apple4 = {2, 2, 2};
    vector<int> cap4 = {2, 2, 2};
    cout << "Output: " << sol.minimumBoxes(apple4, cap4)
         << " | Expected: 3" << endl;

    // Test Case 5 (many small apples, few large boxes)
    vector<int> apple5 = {1,1,1,1,1,1,1};
    vector<int> cap5 = {10, 1};
    cout << "Output: " << sol.minimumBoxes(apple5, cap5)
         << " | Expected: 1" << endl;

    // Test Case 6 (need all boxes)
    vector<int> apple6 = {4,4,4};
    vector<int> cap6 = {3,3,3,3};
    cout << "Output: " << sol.minimumBoxes(apple6, cap6)
         << " | Expected: 4" << endl;

    return 0;
}

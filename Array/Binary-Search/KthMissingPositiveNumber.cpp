#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size() ;


        int low = 0 ; 
        int high = n - 1 ; 

        while(low < high){

            int mid = low + (high - low) / 2 ; 
            int missingNumber = (arr[mid] - (mid + 1)) ;

            if(missingNumber < k){
                low = mid + 1 ; 
            }
            else{
                high = mid - 1 ; 
            }
        }

        return low + k ; 
        
       
    }
};

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {2, 3, 4, 7, 11},   
        {1, 2, 3, 4},      
        {5, 6, 7},         
        {1, 3, 5, 7, 9},    
        {10, 11, 12, 13}  
    };

    vector<int> ks = {5, 2, 4, 3, 1};

    for (int i = 0; i < tests.size(); i++) {
        cout << "Test Case " << i + 1 << ": "
             << sol.findKthPositive(tests[i], ks[i])
             << endl;
    }

    return 0;
}

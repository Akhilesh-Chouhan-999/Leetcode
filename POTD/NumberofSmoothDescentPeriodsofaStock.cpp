
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {

        int n = prices.size() ; 
        long long result = 0;

        int i = 0 ; 
        int j = 0 ; 

        while(j < n ){

            if(prices[i] - ( j - i ) != prices[j] ){
                long long len = j - i ; 
                result += ((long long) (len * (len + 1)) ) / 2 ; 
               i = j   ;
            }
            
            j ++ ; 
        }

        long long len = j - i ; 
        result += ((long long) (len * (len + 1)) ) / 2 ;
        
        return result;
    }
};

int main() {
    Solution obj;

    vector<int> prices1 = {3, 2, 1, 4};
    vector<int> prices2 = {8, 6, 7, 7};
    vector<int> prices3 = {1};

    cout << "Test Case 1 Output: " << obj.getDescentPeriods(prices1) << endl;
    cout << "Test Case 2 Output: " << obj.getDescentPeriods(prices2) << endl;
    cout << "Test Case 3 Output: " << obj.getDescentPeriods(prices3) << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

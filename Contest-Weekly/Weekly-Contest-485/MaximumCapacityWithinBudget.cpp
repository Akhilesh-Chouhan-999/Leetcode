/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {

        int n = costs.size() ; 
        int result = INT_MIN  ; 

        for(int i = 0 ; i < n ; i ++ ){
            for(int j  = i + 1 ; j < n ; j ++ ){

                if(costs[i] + costs[j] < budget)
                result = max(result , capacity[i] + capacity[j]) ;
            }


            if(costs[i] < budget)
            result = max(result , capacity[i]) ; 
    
        }
        return result == INT_MIN ? 0 : result ; 
    }
};
 
int main() {
    Solution sol;

    // Example 1
    vector<int> costs1 = {4, 8, 5, 3};
    vector<int> capacity1 = {1, 5, 2, 7};
    int budget1 = 8;
    cout << sol.maxCapacity(costs1, capacity1, budget1) << endl; // Expected: 8

    // Example 2
    vector<int> costs2 = {3, 5, 7, 4};
    vector<int> capacity2 = {2, 4, 3, 6};
    int budget2 = 7;
    cout << sol.maxCapacity(costs2, capacity2, budget2) << endl; // Expected: 6

    // Example 3
    vector<int> costs3 = {2, 2, 2};
    vector<int> capacity3 = {3, 5, 4};
    int budget3 = 5;
    cout << sol.maxCapacity(costs3, capacity3, budget3) << endl; // Expected: 9

    return 0;
}

Time Complexity : O(n ^ 2)
Space Complexity : O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {

        int n = costs.size() ;

        
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> costs1 = {4, 8, 5, 3};
    vector<int> capacity1 = {1, 5, 2, 7};
    int budget1 = 8;
    cout << sol.maxCapacity(costs1, capacity1, budget1) << endl; // Expected: 8

    // Example 2
    vector<int> costs2 = {3, 5, 7, 4};
    vector<int> capacity2 = {2, 4, 3, 6};
    int budget2 = 7;
    cout << sol.maxCapacity(costs2, capacity2, budget2) << endl; // Expected: 6

    // Example 3
    vector<int> costs3 = {2, 2, 2};
    vector<int> capacity3 = {3, 5, 4};
    int budget3 = 5;
    cout << sol.maxCapacity(costs3, capacity3, budget3) << endl; // Expected: 9

    return 0;
}

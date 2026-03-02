/*
#include <bits/stdc++.h>
using namespace std;


//  1 <= rods.length <= 20
//  1 <= rods[i] <= 1000
// sum(rods[i]) <= 5000

class Solution {
public:

    vector<vector<vector<int>>>dp ; 

    int solve(vector<int>&rods , int idx ,  int rod1 , int rod2 ){
       
        if (rod1 > rod2)
            return 0;

        if (rod1 == rod2)
            return rod1;

        if (idx == rods.size())
            return 0;

        if(dp[idx][rod1][rod2] != -1)
        return dp[idx][rod1][rod2] ; 


        int addToFirstRod  = solve(rods , idx +     1 , rod1 + rods[idx] , rod2 - rods[idx]) ;
        int addToSecondRod = solve(rods , idx + 1 , rod1 , rod2) ; 
        int skip           = solve(rods , idx + 1 , rod1 , rod2 - rods[idx]) ;

        return  dp[idx][rod1][rod2] = max({addToFirstRod , addToSecondRod , skip }) ; 

    }
    int tallestBillboard(vector<int>& rods){

           int total = accumulate(rods.begin(), rods.end(), 0);

           dp.resize( rods.size()  ,
                vector<vector<int>>(total + 1,
                    vector<int>(total + 1, -1)));

           return solve(rods , 0 , 0 , total); 
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> rods1 = {1, 2, 3, 6};
    cout << "Output: " << sol.tallestBillboard(rods1)
         << " | Expected: 6" << endl;

    // Example 2
    vector<int> rods2 = {1, 2, 3, 4, 5, 6};
    cout << "Output: " << sol.tallestBillboard(rods2)
         << " | Expected: 10" << endl;

    // Example 3
    vector<int> rods3 = {1, 2};
    cout << "Output: " << sol.tallestBillboard(rods3)
         << " | Expected: 0" << endl;

    return 0;
}

 Memory Limit Exceeded .




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    unordered_map<string , int>dp ; 

    int solve(vector<int>&rods , int idx ,  int rod1 , int rod2 ){
       
        if (rod1 > rod2)
            return 0;

        if (rod1 == rod2)
            return rod1;

        if (idx == rods.size())
            return 0;
        
        string key = to_string(rod1) + "#" + to_string(rod2) + "#" + to_string(idx) ;  

        if(dp.count(key))
        return dp[key] ; 

        int addToFirstRod  = solve(rods , idx +     1 , rod1 + rods[idx] , rod2 - rods[idx]) ;
        int addToSecondRod = solve(rods , idx + 1 , rod1 , rod2) ; 
        int skip           = solve(rods , idx + 1 , rod1 , rod2 - rods[idx]) ;

        return  dp[key] = max({addToFirstRod , addToSecondRod , skip }) ; 

    }
    int tallestBillboard(vector<int>& rods){

           int total = accumulate(rods.begin(), rods.end(), 0);

           return solve(rods, 0, 0, total);
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> rods1 = {1, 2, 3, 6};
    cout << "Output: " << sol.tallestBillboard(rods1)
         << " | Expected: 6" << endl;

    // Example 2
    vector<int> rods2 = {1, 2, 3, 4, 5, 6};
    cout << "Output: " << sol.tallestBillboard(rods2)
         << " | Expected: 10" << endl;

    // Example 3
    vector<int> rods3 = {1, 2};
    cout << "Output: " << sol.tallestBillboard(rods3)
         << " | Expected: 0" << endl;

    return 0;
}

Time Limit Exceeded ( to_string )  

*/





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

   
    int tallestBillboard(vector<int>& rods){

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> rods1 = {1, 2, 3, 6};
    cout << "Output: " << sol.tallestBillboard(rods1)
         << " | Expected: 6" << endl;

    // Example 2
    vector<int> rods2 = {1, 2, 3, 4, 5, 6};
    cout << "Output: " << sol.tallestBillboard(rods2)
         << " | Expected: 10" << endl;

    // Example 3
    vector<int> rods3 = {1, 2};
    cout << "Output: " << sol.tallestBillboard(rods3)
         << " | Expected: 0" << endl;

    return 0;
}

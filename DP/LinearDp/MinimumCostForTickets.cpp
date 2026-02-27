#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result ; 
    int solve(vector<int>&days , vector<int>&costs , int cost , int idx ){

        if(idx == days.size() ){
            result = max(result , cost) ; 
            return ; 
        }

        int oneDayPass = days[idx] ; 
        cost += costs[0] ; 
        idx ++ ; 

        solve(days , costs , cost , idx) ; 

        int sevenDayPass = days[idx] + 6 ; 
        cost += costs[1] ;

        while(idx < days.size() && sevenDayPass >= days[idx]) idx ++ ; 
        solve(days , costs , cost , idx) ; 


        int ThirtyDayPass = days[idx] + 29 ;
        cost += costs[2]  ;

        while (idx < days.size() && ThirtyDayPass >= days[idx]) idx ++ ; 
        solve(days , costs , cost , idx ) ; 




    }
    int mincostTickets(vector<int>& days, vector<int>& costs){

    }
};

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    vector<int> days1 = {1, 4, 6, 7, 8, 20};
    vector<int> costs1 = {2, 7, 15};

    cout << "Output: " << sol.mincostTickets(days1, costs1)
         << " | Expected: 11" << endl;

    // ---------- Example 2 ----------
    vector<int> days2 = {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs2 = {2, 7, 15};

    cout << "Output: " << sol.mincostTickets(days2, costs2)
         << " | Expected: 17" << endl;

    return 0;
}

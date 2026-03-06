/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[1001][1002] ;

    int solve(vector<pair<int , int>>&vec , int idx , int prevScoreIdx ){

        if(idx >= vec.size())
        return 0 ; 
        
        if(memo[idx][prevScoreIdx + 1] != -1)
        return memo[idx][prevScoreIdx + 1] ; 

        int skip = solve(vec , idx + 1 , prevScoreIdx) ; 
        int take = 0;

        if(prevScoreIdx == -1 || vec[idx].second >= vec[prevScoreIdx].second)
        take =  vec[idx].second + solve(vec , idx + 1 , idx) ;

        return memo[idx][prevScoreIdx + 1] = max(skip , take) ;
     
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages){

        int n = scores.size() ; 

        vector<pair<int , int>>scoreAges ; 

        for(int i = 0 ; i < n ; i ++ ){
            scoreAges.push_back({ages[i] , scores[i]}) ; 
        }

        sort(begin(scoreAges) , end(scoreAges)) ; 

        memset(memo , -1 , sizeof(memo)) ; 

        return solve(scoreAges , 0 , -1 ) ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> scores1 = {1,3,5,10,15};
    vector<int> ages1   = {1,2,3,4,5};
    cout << "Output: " << sol.bestTeamScore(scores1, ages1)
         << " | Expected: 34" << endl;

    // Example 2
    vector<int> scores2 = {4,5,6,5};
    vector<int> ages2   = {2,1,2,1};
    cout << "Output: " << sol.bestTeamScore(scores2, ages2)
         << " | Expected: 16" << endl;

    // Example 3
    vector<int> scores3 = {1,2,3,5};
    vector<int> ages3   = {8,9,10,1};
    cout << "Output: " << sol.bestTeamScore(scores3, ages3)
         << " | Expected: 6" << endl;

    return 0;
}

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:



    int bestTeamScore(vector<int>& scores, vector<int>& ages){

        int n = scores.size() ; 

        vector<pair<int , int>>scoreAges ; 

        for(int i = 0 ; i < n ; i ++ ){
            scoreAges.push_back({ages[i] , scores[i]}) ; 
        }

        sort(begin(scoreAges) , end(scoreAges)) ; 


        vector<vector<int>>dp( n + 1 , vector<int>(n+2)) ; 

        for(int i = 0 ; i <= n ; i ++ ){
            dp[n][i] = 0  ; 
        }


        for(int idx = n-1 ; idx >= 0 ; idx--){

            for(int prevIdx = idx-1 ; prevIdx >= -1 ; prevIdx--){
                
                int skip = dp[idx+1][prevIdx+1];
                int take = 0;

                if(prevIdx == -1 || scoreAges[idx].second >= scoreAges[prevIdx].second)
                    take = scoreAges[idx].second + dp[idx+1][idx+1];

                dp[idx][prevIdx+1] = max(skip, take);
            }
        }

        return dp[0][0] ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> scores1 = {1,3,5,10,15};
    vector<int> ages1   = {1,2,3,4,5};
    cout << "Output: " << sol.bestTeamScore(scores1, ages1)
         << " | Expected: 34" << endl;

    // Example 2
    vector<int> scores2 = {4,5,6,5};
    vector<int> ages2   = {2,1,2,1};
    cout << "Output: " << sol.bestTeamScore(scores2, ages2)
         << " | Expected: 16" << endl;

    // Example 3
    vector<int> scores3 = {1,2,3,5};
    vector<int> ages3   = {8,9,10,1};
    cout << "Output: " << sol.bestTeamScore(scores3, ages3)
         << " | Expected: 6" << endl;

    return 0;
}

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)


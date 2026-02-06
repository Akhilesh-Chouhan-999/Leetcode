#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int manhattanDistance(int x1, int y1, int x2, int y2) {
            return abs(x1 - x2) + abs(y1 - y2);
        }

    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {

        int n = towers.size() ;

        int maxQualityFactor = INT_MIN ; 
        vector<int>result ; 

        int cx = center[0] ; 
        int cy = center[1]  ;

        for(vector<int>tower : towers){

            int x = tower[0] ;
            int y = tower[1] ; 
            int Q = tower[2] ; 

            if(manhattanDistance(x , y , cx , cy)  <= radius){

                if(maxQualityFactor < Q){
                    maxQualityFactor = Q ; 
                    result = { x , y } ; 
                } else if(maxQualityFactor == Q){
                    int resultX = result[0] ; 
                    int resultY = result[1] ; 

                    if( x < resultX || ( x == resultX && y < resultY)){
                        result = { x , y} ; 
                    }
                }
            }

        }

        if(result.empty())
        return { -1 , -1 } ; 


        return result ; 
    }
};

void printResult(const vector<int>& res) {
    cout << "[" << res[0] << ", " << res[1] << "]" << endl;
}

int main() {
    Solution sol;

    // -------- Test Case 1 --------
    vector<vector<int>> towers1 = {
        {1, 2, 5},
        {2, 1, 7},
        {3, 1, 9}
    };
    vector<int> center1 = {1, 1};
    int radius1 = 2;

    vector<int> result1 = sol.bestTower(towers1, center1, radius1);
    printResult(result1);

    // -------- Test Case 2 --------
    vector<vector<int>> towers2 = {
        {1, 3, 4},
        {2, 2, 4},
        {4, 4, 7}
    };
    vector<int> center2 = {0, 0};
    int radius2 = 5;

    vector<int> result2 = sol.bestTower(towers2, center2, radius2);
    printResult(result2);

    // -------- Test Case 3 --------
    vector<vector<int>> towers3 = {
        {5, 6, 8},
        {0, 3, 5}
    };
    vector<int> center3 = {1, 2};
    int radius3 = 1;

    vector<int> result3 = sol.bestTower(towers3, center3, radius3);
    printResult(result3);

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
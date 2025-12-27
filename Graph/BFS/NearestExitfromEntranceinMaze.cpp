#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int m = maze.size() ; 
        int n = maze[0].size() ; 

        int start = entrance[0] ; 
        int end = entrance[1] ; 

        queue<pair<pair<int ,int> , int >> que; 
        vector<vector<int>>visited(m , vector<int>(n , false)) ; 

        que.push({{start , end} , 0}) ; 
        visited[start][end] = true ; 

        while(!que.empty()) {

            auto top = que.front() ; 
            que.pop() ; 
            
            int u = top.first.first ; 
            int v = top.first.second ; 
            int cnt = top.second ; 

            int dx[4] = { } ; 
            int dy[4] = { } ; 

            for(int i = 0 ; i < 4 ; i ++ ){

            }

        }

        
    }
};

int main() {
    Solution sol;

    // 🔹 Test Case 1
    vector<vector<char>> maze1 = {
        {'+','+','.','+'},
        {'.','.','.','+'},
        {'+','+','+','.'}
    };
    vector<int> entrance1 = {1, 2};
    cout << sol.nearestExit(maze1, entrance1) << endl; // Expected: 1

    // 🔹 Test Case 2
    vector<vector<char>> maze2 = {
        {'+','+','+'},
        {'.','.','.'},
        {'+','+','+'}
    };
    vector<int> entrance2 = {1, 0};
    cout << sol.nearestExit(maze2, entrance2) << endl; // Expected: 2

    // 🔹 Test Case 3
    vector<vector<char>> maze3 = {
        {'.','+'}
    };
    vector<int> entrance3 = {0, 0};
    cout << sol.nearestExit(maze3, entrance3) << endl; // Expected: -1

    return 0;
}

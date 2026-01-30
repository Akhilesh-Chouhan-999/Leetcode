#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    using ll = long long ; 

    void floydsWarshall(vector<vector<ll>>&adjMatrix , 
                        vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost){


        for(int i = 0 ; i < original.size() ; i ++){
            int x = original[i] - 'a' ; 
            int y = changed[i] - 'a' ; 

            adjMatrix[x][y] = min(adjMatrix[x][y] , (long long)cost[i]) ; 
        }

        for(int k = 0 ; k < 26 ; k ++){
            for(int i = 0 ; i < 26 ; i ++){
                for(int j = 0 ; j < 26 ; j ++){
                    adjMatrix[i][j] = min(adjMatrix[i][j] , adjMatrix[i][k] + adjMatrix[k][j]) ; 
                }
            }
        }


      }


    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

            int n = source.length() ; 

            vector<vector<ll>>adjMatrix(26 , vector<ll>(26 , LLONG_MAX)) ; 

            floydsWarshall(adjMatrix , original , changed , cost) ; 

            long long result = 0 ; 

            for(int i = 0 ; i < n ; i ++){
                int s = source[i] - 'a' ; 
                int t = target[i] - 'a' ;

                if(source[i] == target[i]) continue;

                else if(adjMatrix[s][t] == LLONG_MAX) return -1 ; 

                else
                    result += adjMatrix[s][t] ; 
            }

        return result;
    }
};

int main() {
    Solution sol;

    // -------- Test Case 1 --------
    {
        string source = "abcd";
        string target = "acbe";

        vector<char> original = {'a','b','c','c','e','d'};
        vector<char> changed  = {'b','c','b','e','b','e'};
        vector<int> cost      = {2, 5, 5, 1, 2, 20};

        cout << "Test Case 1 Output: "
             << sol.minimumCost(source, target, original, changed, cost)
             << endl;
    }

    // -------- Test Case 2 --------
    {
        string source = "aaaa";
        string target = "bbbb";

        vector<char> original = {'a','c'};
        vector<char> changed  = {'c','b'};
        vector<int> cost      = {1, 2};

        cout << "Test Case 2 Output: "
             << sol.minimumCost(source, target, original, changed, cost)
             << endl;
    }

    // -------- Test Case 3 --------
    {
        string source = "abcd";
        string target = "abce";

        vector<char> original = {'a'};
        vector<char> changed  = {'e'};
        vector<int> cost      = {10000};

        cout << "Test Case 3 Output: "
             << sol.minimumCost(source, target, original, changed, cost)
             << endl;
    }

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

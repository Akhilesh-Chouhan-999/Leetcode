#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        queue<pair<string , int>> que ; 
        unordered_set<string>dict(bank.begin() , bank.end()) ; 
        unordered_set<string>visited ; 
        vector<char>mutatateString = { 'A', 'C', 'G', 'T' } ; 

        if(dict.find(endGene) == dict.end()) 
        return -1 ; 

        que.push({startGene  , 0 }) ; 
        visited.insert(startGene) ; 

        while(!que.empty()) {

             auto top = que.front() ;
             que.pop() ; 

             string currGene = top.first ; 
             int level = top.second ; 

             if(currGene == endGene)
                return level ; 

             for (int i = 0; i < 8 ; i++){
                char current = currGene[i] ; 

                for(char &ch : mutatateString ){
                    if(ch == current)
                    continue; 

                    currGene[i] = ch ; 

                    if(dict.find(currGene) == dict.end()) continue;
                    

                    if(visited.find(currGene) != visited.end()){
                        continue;
                    }else{
                        que.push({currGene , level + 1}) ; 
                        visited.insert(currGene) ; 
                    }

                }

                currGene[i] = current ; 
             }
             
        }

        return -1 ; 
        
    }
};  
int main() {
    Solution sol;

    // Test Case 1
    {
        string startGene = "AACCGGTT";
        string endGene = "AACCGGTA";
        vector<string> bank = {"AACCGGTA"};
        cout << "Test 1 Output: "
             << sol.minMutation(startGene, endGene, bank)
             << " | Expected: 1\n";
    }

    // Test Case 2
    {
        string startGene = "AACCGGTT";
        string endGene = "AAACGGTA";
        vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
        cout << "Test 2 Output: "
             << sol.minMutation(startGene, endGene, bank)
             << " | Expected: 2\n";
    }

    // Test Case 3 – No possible mutation path
    {
        string startGene = "AAAAACCC";
        string endGene = "AACCCCCC";
        vector<string> bank = {"AAAACCCC","AAACCCCC","AACCCCCC"};
        cout << "Test 3 Output: "
             << sol.minMutation(startGene, endGene, bank)
             << " | Expected: -1\n";
    }

    // Test Case 4 – End gene not in bank
    {
        string startGene = "AACCGGTT";
        string endGene = "AACCGGTA";
        vector<string> bank = {"AACCGCTA","AAACGGTA"};
        cout << "Test 4 Output: "
             << sol.minMutation(startGene, endGene, bank)
             << " | Expected: -1\n";
    }

    // Test Case 5 – Multiple paths, choose shortest
    {
        string startGene = "AAAAACCC";
        string endGene = "AACCCCCC";
        vector<string> bank = {
            "AAAACCCC","AAACCCCC","AACCCCCC",
            "AAAAACCC","AAAACCCA"
        };
        cout << "Test 5 Output: "
             << sol.minMutation(startGene, endGene, bank)
             << " | Expected: 3\n";
    }

    // Test Case 6 – Start equals end
    {
        string startGene = "AACCGGTT";
        string endGene = "AACCGGTT";
        vector<string> bank = {"AACCGGTA","AACCGCTA"};
        cout << "Test 6 Output: "
             << sol.minMutation(startGene, endGene, bank)
             << " | Expected: 0\n";
    }

    return 0;
}


// Time Complexity : O( N * 32 ) where n is the length of bank 
// Space Complexity : O(n)  
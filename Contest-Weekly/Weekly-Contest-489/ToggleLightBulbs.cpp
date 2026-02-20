#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs){

        int n = bulbs.size() ; 

        map<int , bool>mpp ; 

        for(int bulb : bulbs){

            if(!mpp.count(bulb)){
                mpp[bulb] = true ; 
                continue; 
            }

            mpp[bulb] = !mpp[bulb] ; 

        }

        vector<int>result ; 

        for(pair<int , int>p : mpp){
            
            int first = p.first ; 
            int second = p.second ; 

            if(second){
                result.push_back(first) ; 
            }
        }
        
        return result ; 
    }
};

void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1
    vector<int> bulbs1 = {10, 30, 20, 10};
    vector<int> res1 = sol.toggleLightBulbs(bulbs1);
    cout << "Output: ";
    printVector(res1);
    cout << " | Expected: [20, 30]" << endl;

    // Example 2
    vector<int> bulbs2 = {100, 100};
    vector<int> res2 = sol.toggleLightBulbs(bulbs2);
    cout << "Output: ";
    printVector(res2);
    cout << " | Expected: []" << endl;

    return 0;
}

// Time Complexity : O( n * log(n))
// Space Complexity : O(n) 



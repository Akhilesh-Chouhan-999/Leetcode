
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        int n = rains.size() ; 

        vector<int>result(n , INT_MAX); 
        unordered_map<int , int>filled ; 
        set<int>dry ; 

        for(int i = 0 ; i < n ; i ++){
            
            if(rains[i] > 0 ){
                
                if(!filled.count(rains[i])){
                    filled[rains[i]] = i ;
                    result[i] = -1 ;
                    continue; 
                }
                else{
                    int low = filled[rains[i]] + 1 ; 
                    int high = i - 1 ; 

                    bool flag = false ; 
                    for(int idx = low ; idx <= high ; idx ++){
                        if(dry.find(idx) != dry.end()){
                            result[idx] = rains[i] ; 
                            dry.erase(idx) ; 
                            filled[rains[i]] = i ; 
                            flag = true ; 
                            break ; 
                        }
                    }

                    if(!flag) 
                    return {} ; 
                }


            }
            else{
                dry.insert(i) ; 
            }
        }

        for(int i = 0 ; i < n ; i ++ ){
            if(result[i] == INT_MAX){
                if(rains[i] == 0) {
                    result[i] = 1 ;
                }
                else
                {
                    result[i] = -1 ; 
                }
            }
        }

        return result ; 
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> rains = {1, 2, 0, 0, 2, 1};

    vector<int> result = obj.avoidFlood(rains);

    // Output result
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

 Time Complexity : O(n*n)
 Space Complexity : O(n)

*/



#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        int n = rains.size();

        vector<int> result(n, INT_MAX);
        unordered_map<int, int> filled;  
        set<int> dry;                     

        for (int i = 0; i < n; i++) {

            if (rains[i] > 0) {

            
                if (!filled.count(rains[i])) {
                    filled[rains[i]] = i;
                    result[i] = -1;
                }
                else {
                    int lastRain = filled[rains[i]];

                    auto it = dry.upper_bound(lastRain);

                    if (it == dry.end() || *it >= i) {
                        return {};
                    }

                    result[*it] = rains[i];
                    dry.erase(it);
                    filled[rains[i]] = i;
                    result[i] = -1;
                }
            }
            else {
                dry.insert(i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (result[i] == INT_MAX) {
                if (rains[i] == 0)
                    result[i] = 1;   
                else
                    result[i] = -1;
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    // Example input
    vector<int> rains = {1, 2, 0, 0, 2, 1};

    vector<int> result = obj.avoidFlood(rains);

    // Output result
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
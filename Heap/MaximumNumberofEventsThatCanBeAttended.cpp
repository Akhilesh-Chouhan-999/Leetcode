/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        sort(begin(events) , end(events) , [](const vector<int>&a , const vector<int>&b ){
            return a[1] < b[1] ; 
        }) ; 

        unordered_set<int>st ; 

        for(vector<int>event : events){
            int start = event[0] ; 
            int end = event[1] ; 

            for(int index = start ; index <= end; index ++ ){
                if(st.find(index) == st.end()){
                    st.insert(index) ; 
                    break ;
                }
            }
        }

        return st.size() ; 

    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> events1 = {{1,2},{2,3},{3,4}};
    cout << sol.maxEvents(events1) << endl; // Expected output: 3

    // Example 2
    vector<vector<int>> events2 = {{1,2},{2,3},{3,4},{1,2}};
    cout << sol.maxEvents(events2) << endl; // Expected output: 4

    vector<vector<int>>events3 = {{1,2} , {1,2} , {3,3} , {1,5} , {1,5} } ; 
    cout << sol.maxEvents(events3) << endl; // Expected Output : 5

    return 0;
}

Time Complexity : O(n*log(n) + m*(end - start + 1))
Space Complexity : O(m)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {

        int m = events.size() ; 

        sort(begin(events) , end(events) , [](const vector<int>&a , const vector<int>&b ){
            return a[1] < b[1] ; 
        }) ; 

        priority_queue<int>pq ; 

        int maxSize = events.back()[1] ; 

        for(int i = 1 ; i <= maxSize; i ++ ){
            pq.push(i) ; 
        }

        int result = 0 ; 

        for(int idx = m - 1 ; idx >= 0 ; idx -- ){
            int start = events[idx][0] ; 
            int end = events[idx][1] ; 

            while(!pq.empty() &&  end < pq.top() ) pq.pop() ;

            if(!pq.empty() && (start <= pq.top() && pq.top() <= end)) {
                result ++ ; 
                pq.pop() ; 
            }
            
        }

        return result ; 




    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> events1 = {{1,2},{2,3},{3,4}};
    cout << sol.maxEvents(events1) << endl; // Expected output: 3

    // Example 2
    vector<vector<int>> events2 = {{1,2},{2,3},{3,4},{1,2}};
    cout << sol.maxEvents(events2) << endl; // Expected output: 4

    vector<vector<int>>events3 = {{1,2} , {1,2} , {3,3} , {1,5} , {1,5} } ; 
    cout << sol.maxEvents(events3) << endl; // Expected Output : 5

    return 0;
}

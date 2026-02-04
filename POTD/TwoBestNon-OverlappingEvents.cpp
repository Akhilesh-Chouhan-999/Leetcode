/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        int n = events.size() ;

        int result = INT_MIN ; 
        for(int i = 0 ; i < n ; i ++){
            int start = events[i][0] ; 
            int end = events[i][1] ; 
            int value = events[i][2] ; 

            for(int j = i + 1 ; j < n ; j ++ ){
                int newStart = events[j][0] ; 
                int newEnd = events[j][1] ; 
                int newValue = events[j][2] ; 

                if(newEnd<start || end < newStart){
                    result = max(result , value + newValue) ; 
                }
            }

            result = max(result , value) ; 

        }


        return result ; 
    }
};

int main() {
    Solution sol;

    vector<vector<int>> events1 = {{1,3,2}, {4,5,2}, {2,4,3}};
    vector<vector<int>> events2 = {{1,3,2}, {4,5,2}, {1,5,5}};
    vector<vector<int>> events3 = {{1,5,3}, {1,5,1}, {6,6,5}};

    cout << "Test Case 1 Output: " << sol.maxTwoEvents(events1) << endl;
    cout << "Expected Output: 4\n\n";

    cout << "Test Case 2 Output: " << sol.maxTwoEvents(events2) << endl;
    cout << "Expected Output: 5\n\n";

    cout << "Test Case 3 Output: " << sol.maxTwoEvents(events3) << endl;
    cout << "Expected Output: 8\n\n";

    return 0;
}
Time Complexity : O(n*n)
SpaceComplexity : O(1)
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int binarySearch(vector<vector<int>>&events , int end , int low , int high , vector<int>& maxValueFromRtoL){

        int index = -1 ; 

        while (low <= high){

           int mid = low + (high - low) / 2 ; 

           if(end  <  events[mid][0]) {
            index = mid ; 
            high = mid - 1 ; 
           }
           else{
            low = mid + 1 ; 
           }
        }
        
        if(index == -1 )
        return 0 ; 

        return maxValueFromRtoL[index] ; 
    
    }
    int maxTwoEvents(vector<vector<int>>& events) {

        int n = events.size() ; 
        int result = INT_MIN ; 

        sort(begin(events),end(events)) ; 

        vector<int>maxValueFromRtoL(n,0);

        maxValueFromRtoL[n-1] = events.back()[2] ; 

        for(int i = n - 2 ; i >= 0 ; i --){
            maxValueFromRtoL[i] = max(maxValueFromRtoL[i+1] , events[i][2]) ; 
        }

        for(int i = 0 ; i < n ; i ++ ){
            
            int end = events[i][1] ; 
            int value1 = events[i][2] ;

            int value2 = binarySearch(events , end , i + 1 , n - 1 , maxValueFromRtoL) ;

            result = max(result ,  value1 + value2) ; 
        } 

        return result ; 

    }
};

int main() {
    Solution sol;

    vector<vector<int>> events1 = {{1,3,2}, {4,5,2}, {2,4,3}};
    vector<vector<int>> events2 = {{1,3,2}, {4,5,2}, {1,5,5}};
    vector<vector<int>> events3 = {{1,5,3}, {1,5,1}, {6,6,5}};

    cout << "Test Case 1 Output: " << sol.maxTwoEvents(events1) << endl;
    cout << "Expected Output: 4\n\n";

    cout << "Test Case 2 Output: " << sol.maxTwoEvents(events2) << endl;
    cout << "Expected Output: 5\n\n";

    cout << "Test Case 3 Output: " << sol.maxTwoEvents(events3) << endl;
    cout << "Expected Output: 8\n\n";

    return 0;
}


// Time Complexity : O(n*log(n))
// Space Complexity : O(n)
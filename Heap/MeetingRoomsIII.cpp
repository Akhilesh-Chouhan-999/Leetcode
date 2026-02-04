#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    typedef long long ll;

    int mostBooked(int n, vector<vector<int>> &meetings){

        sort(begin(meetings), end(meetings)); // m*log(m)
        priority_queue<int, vector<int>, greater<int>> freeRooms; // freeRooms index 

        for(int i = 0 ; i < n ; i ++ ){  // n*log(n)
            freeRooms.push(i) ;
        }

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> busyRoom; // endTime , room 
        vector<int>counts(n , 0) ; // space O(n)

        for(vector<int >meeting : meetings ){ // O(m)

            int start = meeting[0] ; 
            int end = meeting[1]  ; 
            int duration = end - start ; 

            while(!busyRoom.empty() && busyRoom.top().first <= start){ //  O(log(n))
                 long long endTime = busyRoom.top().first ; 
                 int room = busyRoom.top().second ; 

                 freeRooms.push(room) ;
                 busyRoom.pop() ; 
            }

            if(!freeRooms.empty()){
               int room = freeRooms.top() ; 
               freeRooms.pop() ; 

               counts[room] ++ ; 

               busyRoom.push({ end , room}) ; 
            }
            else{

                long long endTime = busyRoom.top().first ; 
                int room = busyRoom.top().second ; 

                busyRoom.pop() ; 
                counts[room] ++ ; 

                busyRoom.push({endTime + duration , room }) ;
            }

        }

    
        int  resultIndex = 0 ;
        int maxi = counts[0] ; 

        for(int i = 1 ;i < n ; i ++ ){
           int x = counts[i] ; 

            if(maxi < x){
                resultIndex = i ; 
                maxi  = x ; 
            }
        }

        return resultIndex ; 

    }
};

int main()
{
    Solution sol;

    // ------------------ Test Case 1 (Given Example 1) ------------------
    {
        int n = 2;
        vector<vector<int>> meetings = {
            {0, 10}, {1, 5}, {2, 7}, {3, 4}};
        cout << "Test 1 Output: " << sol.mostBooked(n, meetings) << endl;
    }

    // ------------------ Test Case 2 (Given Example 2) ------------------
    {
        int n = 3;
        vector<vector<int>> meetings = {
            {1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
        cout << "Test 2 Output: " << sol.mostBooked(n, meetings) << endl;
    }

    // ------------------ Hard Test Case 3 (All overlap) ------------------
    {
        int n = 1;
        vector<vector<int>> meetings = {
            {0, 5}, {1, 6}, {2, 7}, {3, 8}};
        // Only one room → everything delayed
        cout << "Test 3 Output: " << sol.mostBooked(n, meetings) << endl;
    }

    // ------------------ Hard Test Case 4 (Same start time) ------------------
    {
        int n = 3;
        vector<vector<int>> meetings = {
            {0, 10}, {0, 5}, {0, 7}, {0, 3}};
        cout << "Test 4 Output: " << sol.mostBooked(n, meetings) << endl;
    }

    // ------------------ Hard Test Case 5 (Chain delays) ------------------
    {
        int n = 2;
        vector<vector<int>> meetings = {
            {1, 4}, {2, 3}, {3, 5}, {4, 6}, {5, 7}};
        cout << "Test 5 Output: " << sol.mostBooked(n, meetings) << endl;
    }

    // ------------------ Edge Case 6 (Single meeting) ------------------
    {
        int n = 5;
        vector<vector<int>> meetings = {
            {10, 20}};
        cout << "Test 6 Output: " << sol.mostBooked(n, meetings) << endl;
    }

    // ------------------ Hard Test Case 7 (Large gaps) ------------------
    {
        int n = 2;
        vector<vector<int>> meetings = {
            {0, 1}, {10, 11}, {20, 21}, {30, 31}};
        cout << "Test 7 Output: " << sol.mostBooked(n, meetings) << endl;
    }

    return 0;
}


// Time Complexity :  O(M*log(n))
// Space Complexity : O( n)


/*
#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    bool isPossible(long long t , long long totalTrips , vector<int>&times){

        long long cntTrips = 0 ; 

        for(int &time : times){
            
            cntTrips += ( t / (long long)time) ;

            if(cntTrips >= totalTrips) return true ; 
        }

        return cntTrips >= totalTrips ; 

    }
public:
    long long minimumTime(vector<int>& time, long long totalTrips) {
     
        int n = time.size() ;
        long long result = 0 ;
        long long size = totalTrips * 1LL * (*max_element(time.begin(), time.end()));  

        for(long long t = 1 ; t <= size ; t ++){

            if(isPossible(t , totalTrips , time)){
                result = t ; 
                break ; 
            }

        }

        
        return result ; 
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> time1 = {1, 2, 3};
    long long trips1 = 5;
    cout << "Test 1 Output: " << sol.minimumTime(time1, trips1) << endl;

    // Test Case 2
    vector<int> time2 = {2};
    long long trips2 = 10;
    cout << "Test 2 Output: " << sol.minimumTime(time2, trips2) << endl;

    // Test Case 3
    vector<int> time3 = {5, 10, 10};
    long long trips3 = 9;
    cout << "Test 3 Output: " << sol.minimumTime(time3, trips3) << endl;

    // Test Case 4
    vector<int> time4 = {3, 3, 3};
    long long trips4 = 7;
    cout << "Test 4 Output: " << sol.minimumTime(time4, trips4) << endl;

    // Test Case 5
    vector<int> time5 = {1, 5, 7, 10};
    long long trips5 = 20;
    cout << "Test 5 Output: " << sol.minimumTime(time5, trips5) << endl;

    return 0;
}
Time complexity : O(n * (range))
 where range is high - low
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    bool isPossible(long long t , long long totalTrips , vector<int>&times){

        long long cntTrips = 0 ; 

        for(int &time : times){
            
            cntTrips += ( t / (long long)time) ;

            if(cntTrips >= totalTrips) return true ; 
        }

        return cntTrips >= totalTrips ; 

    }
public:
    long long minimumTime(vector<int>& time, long long totalTrips) {
     
        long long result = 0 ;
        long long size = totalTrips * 1LL * (*max_element(time.begin(), time.end()));  

        long long low = 0 ; 
        long long high = size ; 
        long long mid = -1 ; 

        while(low <= high){

            mid = low + (high - low) / 2 ; 

            if(isPossible(mid , totalTrips , time)){
                result = mid ; 
                high = mid - 1 ; 
            }
            else{
                low = mid + 1 ; 
            }

        }
        
        return result ; 
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> time1 = {1, 2, 3};
    long long trips1 = 5;
    cout << "Test 1 Output: " << sol.minimumTime(time1, trips1) << endl;

    // Test Case 2
    vector<int> time2 = {2};
    long long trips2 = 10;
    cout << "Test 2 Output: " << sol.minimumTime(time2, trips2) << endl;

    // Test Case 3
    vector<int> time3 = {5, 10, 10};
    long long trips3 = 9;
    cout << "Test 3 Output: " << sol.minimumTime(time3, trips3) << endl;

    // Test Case 4
    vector<int> time4 = {3, 3, 3};
    long long trips4 = 7;
    cout << "Test 4 Output: " << sol.minimumTime(time4, trips4) << endl;

    // Test Case 5
    vector<int> time5 = {1, 5, 7, 10};
    long long trips5 = 20;
    cout << "Test 5 Output: " << sol.minimumTime(time5, trips5) << endl;

    return 0;
}


// Time Complexity : O(n * log(range)) where range = ( high - low)
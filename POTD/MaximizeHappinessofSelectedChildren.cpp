/*
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        priority_queue<int , vector<int> , greater<int> >minHeap ; 
        priority_queue<int>maxHeap ; 

        for(int &x : happiness){

            minHeap.push(x) ; 

            if(minHeap.size() > k ){
                minHeap.pop() ; 
            }

        }


        while(!minHeap.empty()){
            maxHeap.push(minHeap.top()) ; 
            minHeap.pop() ; 
        }


        int dec = 0 ; 
        long long result = 0  ; 

        while(!maxHeap.empty()) {

            int value = maxHeap.top() - dec ; 


            if(value <= 0 )
            break;

            result += value ; 
            dec ++ ; 
            maxHeap.pop() ; 

        }

        return result ;

        
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> happiness1 = {1, 2, 3};
    int k1 = 2;
    cout << "Test Case 1 Output: "
         << sol.maximumHappinessSum(happiness1, k1)
         << " | Expected: 4" << endl;

    // Test Case 2
    vector<int> happiness2 = {1, 1, 1, 1};
    int k2 = 2;
    cout << "Test Case 2 Output: "
         << sol.maximumHappinessSum(happiness2, k2)
         << " | Expected: 1" << endl;

    // Test Case 3
    vector<int> happiness3 = {2, 3, 4, 5};
    int k3 = 1;
    cout << "Test Case 3 Output: "
         << sol.maximumHappinessSum(happiness3, k3)
         << " | Expected: 5" << endl;

    return 0;
}


// Time Complexity : O(n*log(n))
// Space Complexity : O(k)

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

       int n = happiness.size() ; 

       sort(begin(happiness) , end(happiness)  ) ;

       long long result = 0  ; 
       int dec = 0 ; 

       for(int i = n - 1 ; i >= 0 ; i -- ){

        if(happiness[i] - dec <= 0 || k == 0 )
        break ; 

        result += (happiness[i] - dec)  ; 
        k -- ;
        dec ++ ; 

       }


       return result ; 
        
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> happiness1 = {1, 2, 3};
    int k1 = 2;
    cout << "Test Case 1 Output: "
         << sol.maximumHappinessSum(happiness1, k1)
         << " | Expected: 4" << endl;

    // Test Case 2
    vector<int> happiness2 = {1, 1, 1, 1};
    int k2 = 2;
    cout << "Test Case 2 Output: "
         << sol.maximumHappinessSum(happiness2, k2)
         << " | Expected: 1" << endl;

    // Test Case 3
    vector<int> happiness3 = {2, 3, 4, 5};
    int k3 = 1;
    cout << "Test Case 3 Output: "
         << sol.maximumHappinessSum(happiness3, k3)
         << " | Expected: 5" << endl;

    return 0;
}

// Time Complexity : O(n*log(n))
// Space Complexity : O(1)
/*
#include<bits/stdc++.h>
using namespace std ; 
    
class Solution {
public:
    bool checkMinOpeationLessThanK(vector<int>&nums , int k ){
     
          unsigned long long int maxLimit = 1LL* k * k ;
          unsigned long long int opern = 0 ; 

        for(int i = 0 ; i < nums.size() ; i ++){

            opern += ( nums[i] + k - 1 ) / k ; 

            if(opern > maxLimit)
            return false ; 

        }


        return opern > maxLimit ? false : true ; 

    }


    int minimumK(vector<int>& nums) {
       
        int n = nums.size() ;

       long long low = 1 ; 
       long long high = accumulate(begin(nums) , end(nums) , 0LL) ; 
 
 

        int result  = 0 ; 

        for(int idx = low ; idx <= high ; idx ++){
            if(checkMinOpeationLessThanK(nums , idx)){
                result = idx ; 
                break ; 
            }
        }
                        
        
        return result ; 
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {3, 7, 5},
        {1},
        {10, 10, 10},
        {100000}
    };

    for (auto &nums : testCases) {
        cout << "Input: ";
        for (int x : nums) cout << x << " ";
        cout << endl;

        cout << "Minimum k: " << sol.minimumK(nums) << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}

// Time Complexity : O( range(sum(num)*n) )
// Space Complexity : O(1)

*/


#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
bool checkMinOpeationLessThanK(vector<int>&nums , long long k ){

            unsigned long long int maxLimit = 1LL* k * k ;
            unsigned long long int opern = 0 ; 

            for(int i = 0 ; i < nums.size() ; i ++){

            opern += ( nums[i] + k - 1 ) / k ; 

            if(opern > maxLimit)
            return false ; 

            }

            return opern > maxLimit ? false : true ; 

}


int minimumK(vector<int>& nums) {

        int n = nums.size() ;

        int low = 1 ;
        int maxElement = *max_element(begin(nums) , end(nums)) ;  
        long long high = n*maxElement ; 
        int mid ; 

        long long result  = 0 ;


        while(low <= high){

        mid = low + ( high - low) / 2 ; 

        if(checkMinOpeationLessThanK(nums , mid)){
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

    vector<vector<int>> testCases = {
        {3, 7, 5},
        {1},
        {10, 10, 10},
        {100000}
    };

    for (auto &nums : testCases) {
        cout << "Input: ";
        for (int x : nums) cout << x << " ";
        cout << endl;

        cout << "Minimum k: " << sol.minimumK(nums) << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}

// Time Complexity : O( range(sum(num)*n) )
// Space Complexity : O(1)
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result = 0 ; 

    bool checkDivisor(int x ){

        int cnt =  2 ; 
        int sum = 1 + x ; 

        for(int i = 2 ; i < x ; i ++){
            if(x % i == 0){
                sum += i ; 
                cnt ++ ; 
            }
        }

        if(cnt == 4){
            result += sum ; 
            return true ; 
        } 

        return false ; 
    }

    int sumFourDivisors(vector<int>& nums) {

        for(int num : nums){
            checkDivisor(num) ; 
        }

        return result ;  
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {21, 4, 7};
    cout << "Output: " << sol.sumFourDivisors(nums1) << endl;
    
    vector<int> nums2 = {10, 8, 3};
    cout << "Output: " << sol.sumFourDivisors(nums2) << endl;
   

    return 0;
}
Time Complexity : O(n*x) where n is the size and x is the number . 
Space Complexity : O(1)


*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int result = 0 ; 

    void checkDivisor(int &x ){

        int sum = 0 ; 
        int cnt = 0 ; 

        for(int i = 1 ; i*i <= x ; i ++ ){
            
           if(x % i == 0){
             if( i == x / i ){
                sum += i ; 
                cnt += 1 ; 
            }else{
                sum += i + ( x  / i ) ; 
                cnt += 2 ; 
            }
           }

            if(cnt > 4) 
            return ;

        }

        if(cnt == 4)
        result += sum;  

        
    }

    int sumFourDivisors(vector<int>& nums) {

        for(int num : nums){
            checkDivisor(num) ; 
        }

        return result ;  
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {21, 4, 7};
    cout << "Output: " << sol.sumFourDivisors(nums1) << endl;
    
    vector<int> nums2 = {10, 8, 3};
    cout << "Output: " << sol.sumFourDivisors(nums2) << endl;
   

    return 0;
}

// Time Complexity : O( n * ✓x )
// Space Complexity : O(1)
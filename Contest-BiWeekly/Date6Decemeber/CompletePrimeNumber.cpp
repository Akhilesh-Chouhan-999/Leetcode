#include <bits/stdc++.h>
using namespace std;

class Solution {
public : 
    bool checkPrime(int n){

        if(n <= 1 ) return false;

        if(n == 2) return true;

        if(n % 2 == 0) return false;

        for(int i = 3 ; i * i <= n ; i += 2)
            if(n % i == 0)
             return false;
        
        return true;
    }
    
    bool completePrime(int num) {

        vector<int> nums1; 
        vector<int> nums2; 

        while(num){
            nums1.push_back(num % 10);
            nums2.push_back(num % 10);
            num /= 10;
        }

        reverse(nums1.begin(), nums1.end());

        int n = nums1.size();
        int number = 0;

        
        for(int i = 0; i < n; i++){
            number = number * 10 + nums1[i];
            if(checkPrime(number) == false)
                return false;
        }

        number = 0;

        for(int i = 0; i < n; i++){
            number = pow(10, i) * nums2[i] + number;
            if(checkPrime(number) == false)
                return false;
        }

        return true;
    }
};

int main() {
    Solution obj;

    vector<int> tests = {233, 239, 53, 373, 797};

    for(int num : tests) {
        cout << "Number: " << num 
             << " -> Complete Prime? " 
             << (obj.completePrime(num) ? "YES" : "NO") 
             << endl;
    }

    return 0;
}

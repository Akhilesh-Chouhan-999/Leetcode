/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    const int MOD = 100000007 ; 
 
    int solve(int n ){

        if( n == 1)
        return 1 ; 


        int spaces = 2 * n - 1 ; 

        int result = 0  ; 

        result += (solve(n-1) * ((spaces * (spaces +1 )) / 2) ) % MOD ; 

        return  result ; 

    }
    int countOrders(int n){

        return solve(n) ;

    }
};

int main() {

    Solution obj;

    // Hardcoded Test Cases
    int n1 = 1;
    cout << "Input: " << n1 << endl;
    cout << "Output: " << obj.countOrders(n1) << endl;
    cout << endl;

    int n2 = 2;
    cout << "Input: " << n2 << endl;
    cout << "Output: " << obj.countOrders(n2) << endl;
    cout << endl;

    int n3 = 3;
    cout << "Input: " << n3 << endl;
    cout << "Output: " << obj.countOrders(n3) << endl;
    cout << endl;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

   const int MOD = 1000000007 ;
    int countOrders(int n){

        if(n == 1) return 1;

        long long result = 1;

        for(int i = 2; i <= n; i++){

            long long spaces = 2LL * i - 1;

            long long ways = (spaces * (spaces + 1) / 2) % MOD;

            result = (result * ways) % MOD;
        }

        return result;
    }
};

int main() {

    Solution obj;

    // Hardcoded Test Cases
    int n1 = 1;
    cout << "Input: " << n1 << endl;
    cout << "Output: " << obj.countOrders(n1) << endl;
    cout << endl;

    int n2 = 2;
    cout << "Input: " << n2 << endl;
    cout << "Output: " << obj.countOrders(n2) << endl;
    cout << endl;

    int n3 = 3;
    cout << "Input: " << n3 << endl;
    cout << "Output: " << obj.countOrders(n3) << endl;
    cout << endl;

    return 0;
}

// Time Complexity : O(n)
// Space Complexity :: O(1)
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    
    bool solve(int n , bool aliceTurn ){

        if( n <= 1)
        return !aliceTurn ; 

        for(int i = 1 ; i < n ; i ++ ){
           
            if( n % i == 0 ){

                if(aliceTurn){

                    if(solve( n - i , false)){
                        return true ; 
                    }
                }
                else{
                    if(!solve(n - i , true)){
                        return false ; 
                    }
                }
            }
        }

        return !aliceTurn ; 
    }
    
    
    bool divisorGame(int n){
        return solve(n , true) ; 
    }
};


int main() {
    Solution obj;

    cout << boolalpha ;

    cout << "Test Case 1" << endl;
    cout << "Input: 2" << endl;
    cout << "Expected Output: true" << endl;
    cout << "Your Output: " << obj.divisorGame(2) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 2" << endl;
    cout << "Input: 3" << endl;
    cout << "Expected Output: false" << endl;
    cout << "Your Output: " << obj.divisorGame(3) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 3" << endl;
    cout << "Input: 4" << endl;
    cout << "Expected Output: true" << endl;
    cout << "Your Output: " << obj.divisorGame(4) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 4" << endl;
    cout << "Input: 5" << endl;
    cout << "Expected Output: false" << endl;
    cout << "Your Output: " << obj.divisorGame(5) << endl;

    return 0;
}

Time Complexity : O(2 ^ n)
Space Complexity : O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int memo[1001][2] ; 

    bool solve(int n , bool aliceTurn ){

        if( n <= 1)
        return !aliceTurn ; 


        if(memo[n][aliceTurn] != -1)
        return memo[n][aliceTurn] ;

        for(int i = 1 ; i < n ; i ++ ){
           
            if( n % i == 0 ){

                if(aliceTurn){

                    if(solve( n - i , false)){
                        return true ; 
                    }
                }
                else{
                    if(!solve(n - i , true)){
                        return false ; 
                    }
                }
            }
        }

        return memo[n][aliceTurn] = !aliceTurn ; 
    }
    
    
    bool divisorGame(int n){

        memset(memo , -1 , sizeof(memo)) ; 
        return solve(n , true) ; 
    }
};


int main() {
    Solution obj;

    cout << boolalpha ;

    cout << "Test Case 1" << endl;
    cout << "Input: 2" << endl;
    cout << "Expected Output: true" << endl;
    cout << "Your Output: " << obj.divisorGame(2) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 2" << endl;
    cout << "Input: 3" << endl;
    cout << "Expected Output: false" << endl;
    cout << "Your Output: " << obj.divisorGame(3) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 3" << endl;
    cout << "Input: 4" << endl;
    cout << "Expected Output: true" << endl;
    cout << "Your Output: " << obj.divisorGame(4) << endl;
    cout << "-----------------------------" << endl;

    cout << "Test Case 4" << endl;
    cout << "Input: 5" << endl;
    cout << "Expected Output: false" << endl;
    cout << "Your Output: " << obj.divisorGame(5) << endl;

    return 0;
}


// Time Complexity : O(n ^ 2)
// Space Complexity : O(n)
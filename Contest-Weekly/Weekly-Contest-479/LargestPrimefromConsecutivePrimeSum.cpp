#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    vector<bool>SieveofEratosthenes(int n ){
        
        vector<bool>isPrime(n+1 , true) ;
        isPrime[0] = isPrime[1] = false ;
        
        for(int p = 2 ; p*p <= n ; p ++){
          
            if(isPrime[p]){
                for(int i = p*p ; i <= n ; i += p){
                    isPrime[i] = false ; 
                }
            }

        }

        return isPrime ; 

    }
 
    int largestPrime(int n) {

        vector<bool>isPrime = SieveofEratosthenes(n) ; // O(n*log(log(n)))
        vector<int>prime  ; 

        for(int i = 0 ; i <= n ; i ++){ // O(n)
            if(isPrime[i]){
                prime.push_back(i) ; 
            }
        }

        int m = prime.size() ; 

        int sum = 0 ; 
        int result = 0 ; 

        for(int i = 0 ; i < m ; i ++){ // O(m)

            sum += prime[i] ; 
            
            if(sum > n ){
                break ; 
            }


            if(isPrime[sum]){
                result = sum ; 
            }

        }

        return result ; 

    }
};

int main() {
    Solution obj;

    vector<int> testCases = {10, 20, 50, 100};

    for (int n : testCases) {
        cout << "n = " << n << " -> ";
        cout << obj.largestPrime(n) << endl;
    }

    return 0;
}

// Time Complexity : O(n*log(log(n))) + O(n) + O(m)
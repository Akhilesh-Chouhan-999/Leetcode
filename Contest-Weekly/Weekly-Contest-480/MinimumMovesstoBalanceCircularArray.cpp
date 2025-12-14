#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minMoves(vector<int>& balance) {
       
        int n = balance.size() ; 

        int negIndex = -1 ; 
        long long sum = 0 ; 

        for(int i = 0 ; i < n ; i ++){

            if(balance[i] < 0) negIndex = i ; 

            sum += balance[i] ; 
        }

        if(sum < 0)
        return -1 ; 

        if(negIndex == -1)
        return 0 ; 

        int left = (negIndex - 1 + n ) % n ; 
        int right = ( negIndex + 1 ) % n ; 
        

        long long cost = 0 ; 
        long long need = -balance[negIndex] ; 

        long long step = 1 ; 

        while(need > 0 &&  step <= n / 2){

            if(balance[left] > 0 ){

                long long take = min((long long)balance[left] , need) ; 
                need -= take ; 
                cost += take*step  ; 
                balance[left] = 0 ; 
            }

            if(need <= 0 )
            break ; 

            if(balance[right] > 0){

                long long take = min((long long) balance[right] , need) ; 
                need -= take ; 
                cost += take*step ; 
                balance[right] = 0 ; 
            }

            left = (left - 1 + n) % n ; 
            right = ( right + 1) % n ; 
            step ++ ; 
        }

        return cost  ; 



    }
};

int main() {
    Solution obj;

    vector<int> balance1 = {1, -1, 2, -2};
    cout << "Test case 1 output: " << obj.minMoves(balance1) << endl;
    // Expected output: depends on implementation

    vector<int> balance2 = {0, 0, 0};
    cout << "Test case 2 output: " << obj.minMoves(balance2) << endl;

    vector<int> balance3 = {5, -3, -2};
    cout << "Test case 3 output: " << obj.minMoves(balance3) << endl;

    return 0;
}

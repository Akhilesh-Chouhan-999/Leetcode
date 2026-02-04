#include <bits/stdc++.h>
using namespace std;

int pickedNumber; 
int guess(int num) {
    if (num > pickedNumber) return -1;
    if (num < pickedNumber) return 1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        
        int low = 1 ; 
        int high = n ; 

        while(low <= high){

            int mid = low + (high - low) / 2 ; 

            if(guess(mid) == 0) return mid ;

            else if(guess(mid) == -1) high = mid - 1 ; 

            else
            low = mid + 1 ;  


        }

        return -1 ; 
    }
};

int main() {
    int n;
    cin >> n;          // upper bound
    cin >> pickedNumber; // number chosen for testing

    Solution obj;
    cout << obj.guessNumber(n);

    return 0;
}

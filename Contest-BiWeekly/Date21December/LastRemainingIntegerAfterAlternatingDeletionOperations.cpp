#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long lastInteger(long long n) {

        using ll = long long ; 

        ll a = 1 ; 
        ll d = 1 ; 
        ll remaining_element = n ; 
        bool left = true ; 

        while(remaining_element > 1){

            if(!left  && remaining_element % 2 == 0){
                a = a  + d ; 
            }
            
            d = d * 2 ;  
            remaining_element = ( remaining_element + 1 ) / 2 ; 
            left = !left ; 
        }
        
        return a;
    }
};

int main() {
    long long n;
    cin >> n;

    Solution obj;
    cout << obj.lastInteger(n);

    return 0;
}
/*

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {

        int result = 0 ; 

        for(int i = low ; i <= high ; i ++){

            if(i % 2 == 1)
            result ++ ; 
        }
       
        return result ; 
    }
};

int main() {
    Solution obj;

    cout << obj.countOdds(3, 7) << "\n";    // Test 1 → Output: 3 (3,5,7)
    cout << obj.countOdds(8, 10) << "\n";   // Test 2 → Output: 1 (9)
    cout << obj.countOdds(1, 1) << "\n";    // Test 3 → Output: 1
    cout << obj.countOdds(2, 2) << "\n";    // Test 4 → Output: 0
    cout << obj.countOdds(100, 120) << "\n"; // Test 5 → Output: 10

    return 0;
}

Time complexity : O(high - low) 


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {

       
        if(low % 2 == 0)
        low ++ ; 

        if(high % 2 == 0)
        high -- ; 

        int result = (high - low) / 2  + 1 ; 

        return result ; 
       
    }
};

int main() {
    Solution obj;

    cout << obj.countOdds(3, 7) << "\n";    // Test 1 → Output: 3 (3,5,7)
    cout << obj.countOdds(8, 10) << "\n";   // Test 2 → Output: 1 (9)
    cout << obj.countOdds(1,  1) << "\n";    // Test 3 → Output: 1
    cout << obj.countOdds(2, 2)<< "\n";    // Test 4 → Output: 0
    cout << obj.countOdds(100, 120) << "\n"; // Test 5 → Output: 10

    return 0;
}

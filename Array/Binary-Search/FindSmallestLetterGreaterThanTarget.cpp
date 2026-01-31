#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int n = letters.size() ; 

        int start = 0 ; 
        int end = n - 1 ; 
        char result = letters[0];

        while(start <= end){
            int mid = start + ( end - start ) / 2 ; 

            if(letters[mid] > target){
                result = letters[mid] ; 
                end = mid - 1 ;
            }else{
                start = mid  + 1 ; 
            }
        }

        return result ; 
        
    }
};

int main() {
    Solution sol;

    vector<char> letters1 = {'c', 'f', 'j'};
    char target1 = 'a';
    cout << sol.nextGreatestLetter(letters1, target1) << endl;  // c

    vector<char> letters2 = {'c', 'f', 'j'};
    char target2 = 'c';
    cout << sol.nextGreatestLetter(letters2, target2) << endl;  // f

    vector<char> letters3 = {'x', 'x', 'y', 'y'};
    char target3 = 'z';
    cout << sol.nextGreatestLetter(letters3, target3) << endl;  // x

    return 0;
}

// Time Complexity : O(log(n))
// Space Complexity : O(1)


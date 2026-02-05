/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkMonobit(bitset<32>& bits) {
        int flag = bits[0];
        int pos = -1;

        for (int i = 1; i < 32; i++) {
            if (bits[i] != flag) {
                pos = i;
                flag = bits[i];
                break;
            }
        }

        if (pos == -1)
            return true;

        for (int j = pos + 1; j < 32; j++) {
            if (bits[j] != flag)
                return false;
        }

        return true;
    }

    int countMonobit(int n) {
        int result = 0;

        for (int i = 0; i <= n; i++) {
            bitset<32> bits(i);
            if (checkMonobit(bits)) {
                result++;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Hardcoded test cases
    vector<int> tests = {1, 4, 0, 7, 15, 16};

    for (int n : tests) {
        cout << "n = " << n 
             << " -> Monobit count = " 
             << sol.countMonobit(n) << endl;
    }

    return 0;
}


// Time Complexity : O(n * 32)
// Space Complexity : O(1)



*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countMonobit(int n) {
       
        
        int cnt = 1 ; 
    
        int i = 0 ; 
        int num = 0 ; 

        while ( num <= n ){

            num += ( 1 << i ) ; 

            if(num > n )
                break ; 
            
            cnt ++ ;
            i ++ ;
        }

        return cnt ; 
        
    }
};

int main() {
    Solution sol;

    // Hardcoded test cases
    vector<int> tests = {1, 4, 0, 7, 15, 16};

    for (int n : tests) {
        cout << "n = " << n 
             << " -> Monobit count = " 
             << sol.countMonobit(n) << endl;
    }

    return 0;
}


// Time Complexity : O(n * 32)
// Space Complexity : O(1)


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minOperation(int x){

        int opns1 = 0 ; 
        int num = x ; 

        while(true){

            bitset<32>bs(num) ; 

            int i = 0 ; 
            int j = 31 ; 

            while(bs[j] == 0) j -- ; 

            bool flag = false ; 
            while( i <= j){
                if(bs[i] != bs[j]) {
                    flag = true ; 
                    break ;  
                }

                i ++ ; 
                j -- ; 
            }

            if(flag)
            {
                opns1 ++ ; 
                num += 1 ; 
            }
            else
            {
                break ; 
            }

        }
        

        int opns2 = 0 ; 
        num = x ; 

        while(true){

            bitset<32>bs(num) ; 

            int i = 0 ; 
            int j = 31 ; 
            bool flag = false ; 

            while(bs[j] == 0) j -- ; 

            while( i <= j ){

                if(bs[i] != bs[j])
                {
                    flag = true ; 
                    break ; 
                }

                i ++ ; 
                j -- ; 
            }

            if(flag)
            {
                num -= 1 ; 
                opns2 ++ ; 
            }
            else
            {
                break ; 
            }

        }

        return min(opns1 , opns2) ;
    }
    vector<int> minOperations(vector<int>& nums) {

        int n = nums.size() ; 

        vector<int>result(n , 0) ; 

        for(int &num : nums)
        {
            result.push_back(minOperation(num)) ; 
        }

        return result ; 

    }
};

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {1, 2, 4},
        {6, 7, 12},
        {3, 5, 9},
        {8, 15, 16},
        {2, 7, 10, 19},
        {1, 5000}
    };

    for (int t = 0; t < tests.size(); t++) {
        cout << "Testcase " << t + 1 << ": ";
        vector<int> ans = sol.minOperations(tests[t]);

        cout << "[ ";
        for (int x : ans) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}

// Time Complexity O( n * n  ) where n = 5000 (According to constraings)
// In the worst case the distance to the nearest binary palindrome is at most proportional to the maximum possible value we might need to scan.
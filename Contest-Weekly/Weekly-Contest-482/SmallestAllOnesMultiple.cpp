/*

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAllOneMultiple(int k) {

        if( k  % 2 == 0 || k % 5 == 0)
         return -1 ; 

        vector<bool>visited(k , false) ; 
        int rem = 0 ; 
        int length = 1 ; 

        for(int i = 0 ; i <=  k ; i ++ ){

            rem = (rem * 10 + 1) % k;
            
            if(rem == 0) {
                return length ; 
            }

            if(visited[rem]){
                return -1 ; 
            }

            visited[rem] = true ;
            length ++ ; 

        }


        return -1 ; 

        
    }
};

int main() {
    Solution sol;

   
    int k1 = 1;
    cout << "Output 1: " << sol.minAllOneMultiple(k1) << endl;

    int k2 = 3;
    cout << "Output 2: " << sol.minAllOneMultiple(k2) << endl;

    int k3 = 7;
    cout << "Output 3: " << sol.minAllOneMultiple(k3) << endl;

    int k4 = 9;
    cout << "Output 4: " << sol.minAllOneMultiple(k4) << endl;

    return 0;
}


// Time Complexity : O(k)
// Space Complexity : O(k)


*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAllOneMultiple(int k) {

        if( k  % 2 == 0 || k % 5 == 0)
         return -1 ; 

        int rem = 0 ; 
        int length = 1 ; 

        for(int i = 0 ; i <=  k ; i ++ ){

            rem = (rem * 10 + 1) % k;
            
            if(rem == 0) {
                return length ; 
            }

           
            length ++ ; 

        }


        return -1 ; 

        
    }
};

int main() {
    Solution sol;

   
    int k1 = 1;
    cout << "Output 1: " << sol.minAllOneMultiple(k1) << endl;

    int k2 = 3;
    cout << "Output 2: " << sol.minAllOneMultiple(k2) << endl;

    int k3 = 7;
    cout << "Output 3: " << sol.minAllOneMultiple(k3) << endl;

    int k4 = 9;
    cout << "Output 4: " << sol.minAllOneMultiple(k4) << endl;

    return 0;
}


// Time Complexity : O(k)
// Space Complexity : O(1)
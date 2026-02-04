#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        
        int n = damage.size() ; 
        long long points = 0 ;
        
        vector<long long>prefD(n+1 , 0) ; 
        for(int i = 1 ; i <= n ; i ++){
            prefD[i] = prefD[i-1] + damage[i-1] ;
        }


        for(int j = 1 ; j <= n ; j ++){

            long long threshold =  prefD[j] - ( (long long)hp - requirement[j - 1] )  ;
            
            int low = 0 ; 
            int high = j - 1 ; 
            int pos = -1 ; 

            while(low < high){

                int mid = low + ( high - low ) / 2 ; 

                if(prefD[mid] >= threshold){
                    pos = mid ; 
                    high = mid - 1 ; 
                }
                else{
                    low = mid + 1 ; 
                }

            }

            if(pos != -1){
                points += ( j - pos ) ;
            }
        }

        return points ; 


    }
};

int main() {
    Solution obj;

    int hp1 = 10;
    vector<int> damage1 = {2, 3, 5};
    vector<int> requirement1 = {1, 2, 3};

    int hp2 = 15;
    vector<int> damage2 = {4, 6, 2};
    vector<int> requirement2 = {2, 3, 1};

    cout << "Test Case 1 Output: "
         << obj.totalScore(hp1, damage1, requirement1) << endl;

    cout << "Test Case 2 Output: "
         << obj.totalScore(hp2, damage2, requirement2) << endl;

    return 0;
}

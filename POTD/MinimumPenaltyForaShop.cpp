/*
#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.length() ; 
        int minPenalty = INT_MAX ; 
        int minPenaltyIndex = -1 ; 

        for(int i = 0 ; i <= n ; i ++ ){

            int penalty = 0 ;
            
            for(int j = 0 ; j < i ; j ++ ){
                if(customers[j] == 'N') penalty ++ ;
            }

            for(int j = i ; j < n ; j ++ ){
                if(customers[j] == 'Y') penalty ++ ; 
            }

            if(penalty < minPenalty){
                minPenalty = penalty; 
                minPenaltyIndex = i ; 
            }
        }


        return minPenaltyIndex ; 
        
    }
};


int main() {
    Solution sol;

    // Hard-coded test cases
    vector<string> testCases = {
        "YYNY",
        "NNNNN",
        "YYYY"
    };

    for (string customers : testCases) {
        cout << "Input: customers = \"" << customers << "\"\n";
        cout << "Output: " << sol.bestClosingTime(customers) << "\n\n";
    }

    return 0;
}

Time Complexity : O*(n*n)
Space Complexity : O(1)





#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.length() ;
        
        int prevCloseDays = 0 ; 
        vector<int>SeenOpenDays(n , 0) ;
        SeenOpenDays[n-1] = customers[n-1] == 'Y' ? 1 : 0 ; 

        for(int i = n - 2 ; i >= 0 ; i -- ){
            SeenOpenDays[i] = SeenOpenDays[i+1] + ( customers[i] == 'Y' ? 1 : 0) ; 
        }

        int minPenalty = INT_MAX ; 
        int minIndex = -1 ; 

        for(int i = 0 ; i < n ; i ++ ){

            int penalty = SeenOpenDays[i] + prevCloseDays ; 

            if(penalty < minPenalty){
                minPenalty = penalty ; 
                minIndex = i ; 
            }

            prevCloseDays += ( customers[i] == 'N' ? 1 : 0) ;

        }

        if(prevCloseDays < minPenalty){
            minPenalty = prevCloseDays ; 
            minIndex = n  ; 
        }    
        
        return minIndex ; 
        
    }
};


int main() {
    Solution sol;

    vector<string> testCases = {
        "YYNY",
        "NNNNN",
        "YYYY"
    };

    for (string customers : testCases) {
        cout << "Input: customers = \"" << customers << "\"\n";
        cout << "Output: " << sol.bestClosingTime(customers) << "\n\n";
    }

    return 0;
}

Time complexity : O(n+n) : O(n)
Space Complexity : O(`)
*/


#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.length() ;

        int bestHour = 0 ; 
        int minPenalty = INT_MAX; 

        int OpenDays = 0 ; 
        int prevCloseDays = 0 ; 

        for(char customer : customers)
         if(customer == 'Y') 
          OpenDays ++ ;


        for(int i = 0 ; i < n ; i ++ ){

            int penalty = OpenDays + prevCloseDays ;
            
            if(penalty < minPenalty){
                minPenalty = penalty ; 
                bestHour = i ; 
            }

            if(customers[i] == 'N')
            prevCloseDays ++ ;
            else
            OpenDays -- ; 

        }

          if(prevCloseDays < minPenalty){
            minPenalty = prevCloseDays ; 
            bestHour = n  ; 
        }    
        
        return bestHour ; 

      
    }
};


int main() {
    Solution sol;

    vector<string> testCases = {
        "YYNY",
        "NNNNN",
        "YYYY"
    };

    for (string customers : testCases) {
        cout << "Input: customers = \"" << customers << "\"\n";
        cout << "Output: " << sol.bestClosingTime(customers) << "\n\n";
    }

    return 0;
}
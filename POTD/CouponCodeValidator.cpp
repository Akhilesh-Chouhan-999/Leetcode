#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValid(string code){

        if(code.empty()) return false ; 

        for(char &ch : code){

            if(isalnum(ch) || ch == '_' )
             continue;
            else
             return false ; 

        }
        return true ; 

    }
    vector<string> validateCoupons(vector<string>& codes,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {

            int n = codes.size() ; 

            vector<pair<int , string >> vec ; 

            unordered_map<string , int>mpp = {

                {"electronics",1} ,
                {"grocery", 2 },
                {"pharmacy",3 },
                {"restaurant",4}
             } ; 

            for(int i = 0 ; i < n ; i ++){

                string code = codes[i] ; 
                string bsLine = businessLine[i] ; 
                bool flag = isActive[i] ; 

                if(!flag || !checkValid(code) || !mpp.count(bsLine)) continue ;

                vec.push_back({mpp[bsLine] , code}) ; 

            }

            sort(begin(vec) , end(vec)) ; 

            vector<string>result ; 

            for(pair<int , string> p : vec){
                result.push_back(p.second) ; 
            }

            return result ; 
      
    }
};

int main() {
    Solution obj;

    // Hardcoded input
    vector<string> code = {
        "SAVE10",
        "OFF20",
        "WELCOME",
        "DISC30"
    };

    vector<string> businessLine = {
        "FOOD",
        "TRAVEL",
        "FOOD",
        "ELECTRONICS"
    };

    vector<bool> isActive = {
        true,
        false,
        true,
        true
    };

    vector<string> ans = obj.validateCoupons(code, businessLine, isActive);

    // Output
    cout << "Output:\n";
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

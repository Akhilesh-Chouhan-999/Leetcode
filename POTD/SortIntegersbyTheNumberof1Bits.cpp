#include <bits/stdc++.h>
#include <bitset>
using namespace std;

class Solution {
public:

    int countBits(bitset<32>bt ){

        int cntBit = 0 ; 

        for(int i = 0 ; i < 32 ; i ++ ){
            if(bt[i] == 1){
                cntBit ++ ; 
            }
        }

        return cntBit ; 
    }
   vector<int> sortByBits(vector<int>& arr){

        vector<pair<int , int>>temp ; 

        for(int x : arr) {

            int cntBit = countBits(bitset<32>(x));
            temp.push_back({cntBit, x});
        }


        sort(begin(temp) , end(temp)) ; 

        vector<int>result ;

        for(pair<int , int >p : temp){
            int element = p.second ; 

            result.push_back(element) ; 
        }

        return result ;

}
};


void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]";
    cout << endl;
}

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {0,1,2,3,4,5,6,7,8};
    vector<int> res1 = sol.sortByBits(arr1);
    cout << "Output: ";
    printVector(res1);
    cout << " | Expected: [0, 1, 2, 4, 8, 3, 5, 6, 7]" << endl;

    // Example 2
    vector<int> arr2 = {1024,512,256,128,64,32,16,8,4,2,1};
    vector<int> res2 = sol.sortByBits(arr2);
    cout << "Output: ";
    printVector(res2);
    cout << " | Expected: [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024]" << endl;

    return 0;
}
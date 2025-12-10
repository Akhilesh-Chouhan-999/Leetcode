#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {

        
        unordered_set<int>st ; 

        for(int c = 1 ; c <= n ; c ++){
            st.insert(c*c) ;
        }

        int result = 0 ; 

        for(int a = 1 ; a <= n ; a ++){

            for(int b = a + 1  ; b <= n ; b ++){

                if(st.find(a*a + b *b ) != st.end()){
                      result += 2  ; 
                }
            }
        }

        return result ; 

         


        
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    cout << obj.countTriples(n);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<int>> events = {
        {1, 3},
        {2, 5},
        {4, 4}
    };

    
    sort(events.begin(), events.end(),
       // Core logic of lambda : When a comes should first than b in generic . 
        [](const vector<int>& a, const vector<int>& b) {

            // a comes first when its end time is smaller than b's end time
            return a[1] < b[1];
        }
    );

    // for_each loop to print events
    for_each(events.begin(), events.end(),
        [](const vector<int>& e) {
            cout << e[0] << " " << e[1] << endl;
        }
    );

    return 0;
}

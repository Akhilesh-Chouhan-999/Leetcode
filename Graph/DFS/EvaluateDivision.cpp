#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){

        
    }
};

void printVector(const vector<double>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << fixed << setprecision(5) << v[i];
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1
    vector<vector<string>> eq1 = {{"a","b"},{"b","c"}};
    vector<double> val1 = {2.0, 3.0};
    vector<vector<string>> q1 = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};

    vector<double> res1 = sol.calcEquation(eq1, val1, q1);
    cout << "Output: ";
    printVector(res1);
    cout << " | Expected: [6.00000, 0.50000, -1.00000, 1.00000, -1.00000]" << endl;

    // Example 2
    vector<vector<string>> eq2 = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> val2 = {1.5, 2.5, 5.0};
    vector<vector<string>> q2 = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};

    vector<double> res2 = sol.calcEquation(eq2, val2, q2);
    cout << "Output: ";
    printVector(res2);
    cout << " | Expected: [3.75000, 0.40000, 5.00000, 0.20000]" << endl;

    // Example 3
    vector<vector<string>> eq3 = {{"a","b"}};
    vector<double> val3 = {0.5};
    vector<vector<string>> q3 = {{"a","b"},{"b","a"},{"a","c"},{"x","y"}};

    vector<double> res3 = sol.calcEquation(eq3, val3, q3);
    cout << "Output: ";
    printVector(res3);
    cout << " | Expected: [0.50000, 2.00000, -1.00000, -1.00000]" << endl;

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {

        int n = nums.size() ; 

        int result = INT_MIN ;

        for(int i = 0 ; i < n ; i ++){
            for(int j = i + 1 ; j < n ; j ++){
                for(int k = j + 1 ; k < n ; k ++){
                    int sum = nums[i] + nums[j] + nums[k] ; 
                    if(sum % 3 == 0){
                        result = max(result , sum) ; 
                    }
                }
            }
        }

        if(result == INT_MIN) return 0 ; 

        return result ; 
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {4, 2, 3, 1},
        {2, 1, 5}
    };

    vector<int> expectedOutput = {
        9,
        0
    };

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i];
        int result = sol.maximumSum(nums);

        cout << "Test Case " << i + 1 << ": ";
        cout << "Output = " << result;
        cout << ", Expected = " << expectedOutput[i] << endl;
    }

    return 0;
}

Time complexity : O(n*n*n)
Space complexity : O(1)


#include <bits/stdc++.h>
using namespace std;

int calculateSumOfFirstThree(vector<int>&vec){
    if(vec.size() < 3)
    return 0 ; 

    int sum = 0 ; 
    for(int i = 0 ; i < 3 ; i ++){
        sum += vec[i] ; 
    }

    return sum ; 
}
class Solution {
public:
    int maximumSum(vector<int>& nums) {

        int n = nums.size() ; 

        int result = INT_MIN ;

        vector<int>remainderZero ; 
        vector<int>remainderOne ; 
        vector<int>remainderTwo ; 


        for(int &num : nums){
            if(num % 3 == 0) remainderZero.push_back(num) ; 
            if(num % 3 == 1) remainderOne.push_back(num) ; 
            if(num % 3 == 2) remainderTwo.push_back(num) ;  
        }

        sort(begin(remainderOne) , end(remainderOne) , greater<int>()) ; 
        sort(begin(remainderTwo) , end(remainderTwo) , greater<int>()) ; 
        sort(begin(remainderZero) , end(remainderZero) , greater<int>()) ; 

        result = max(result , calculateSumOfFirstThree(remainderZero)) ; 
        result = max(result , calculateSumOfFirstThree(remainderOne)) ; 
        result = max(result , calculateSumOfFirstThree(remainderTwo)) ; 

        if(remainderZero.size() > 0 && remainderOne.size() > 0 && remainderTwo.size() > 0){
            result = max(result , remainderZero[0] + remainderOne[0] + remainderTwo[0]) ; 
        }
        
        return result ; 
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {4, 2, 3, 1},
        {2, 1, 5}
    };

    vector<int> expectedOutput = {
        9,
        0
    };

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i];
        int result = sol.maximumSum(nums);

        cout << "Test Case " << i + 1 << ": ";
        cout << "Output = " << result;
        cout << ", Expected = " << expectedOutput[i] << endl;
    }

    return 0;
}
    Time complexity : O(n*log(n))
    Space Complexity : O(n)

*/


#include <bits/stdc++.h>
using namespace std;

int calculateSumOfFirstThree(vector<int>& vec) {
    if (vec.size() < 3)
        return 0;

    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;

    for (int x : vec) {
        if (x > first) {
            third = second;
            second = first;
            first = x;
        } 
        else if (x > second) {
            third = second;
            second = x;
        } 
        else if (x > third) {
            third = x;
        }
    }

    return first + second + third;
}

class Solution {
public:
    int maximumSum(vector<int>& nums) {

        int n = nums.size() ; 

        int result = INT_MIN ;

        vector<int>remainderZero ; 
        vector<int>remainderOne ; 
        vector<int>remainderTwo ; 


        for(int &num : nums){
            if(num % 3 == 0) remainderZero.push_back(num) ; 
            if(num % 3 == 1) remainderOne.push_back(num) ; 
            if(num % 3 == 2) remainderTwo.push_back(num) ;  
        }

        result = max(result , calculateSumOfFirstThree(remainderZero)) ; 
        result = max(result , calculateSumOfFirstThree(remainderOne)) ; 
        result = max(result , calculateSumOfFirstThree(remainderTwo)) ; 

        if (!remainderZero.empty() && !remainderOne.empty() && !remainderTwo.empty()) {
            int max0 = *max_element(remainderZero.begin(), remainderZero.end());
            int max1 = *max_element(remainderOne.begin(), remainderOne.end());
            int max2 = *max_element(remainderTwo.begin(), remainderTwo.end());
            result = max(result, max0 + max1 + max2);
        }

        
        return result ; 
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {4, 2, 3, 1},
        {2, 1, 5}
    };

    vector<int> expectedOutput = {
        9,
        0
    };

    for (int i = 0; i < testCases.size(); i++) {
        vector<int> nums = testCases[i];
        int result = sol.maximumSum(nums);

        cout << "Test Case " << i + 1 << ": ";
        cout << "Output = " << result;
        cout << ", Expected = " << expectedOutput[i] << endl;
    }

    return 0;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

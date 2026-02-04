/*


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size() ; 

        int index = -1 ; 

        for(int i = 0 ; i < n ; i ++){

            if(nums[i] == target)
            {
                index = i ; 
            }
        }

        return index ; 
        
    }
};

int main() {
    Solution s;

    vector<vector<int>> tests = {
        {4,5,6,7,0,1,2},
        {6,7,0,1,2,4,5},
        {1},
        {1,3},
        {5,1,3}
    };

    vector<int> targets = {0, 7, 1, 3, 5};

    for (int i = 0; i < tests.size(); i++) {
        cout << "Testcase " << i+1 << ": ";
        for (int x : tests[i]) cout << x << " ";
        cout << "\nTarget: " << targets[i];

        int result = s.search(tests[i], targets[i]);
        cout << "\nResult: " << result << "\n\n";
    }

    return 0;
}
Time Complexity : O(n)

*/





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

       int n = nums.size() ; 
       
       int low = 0 ; 
       int high = n - 1 ; 

       int result = -1 ; 

       while(low <= high){

        int mid = low + (high - low) / 2 ; 

        if(nums[mid] == target)
        {
            result = mid ; 
            break ; 
        }

        else if(nums[low] <= nums[mid]){

            if(nums[low] <= target && target <= nums[mid])
            {
                high = mid ; 
            }
            else{
                low = mid + 1 ; 
            }
        }

        else{
              if(nums[mid] <= target && target <= nums[high]){
                low = mid ; 
            }
            else{
                high = mid - 1 ; 
            }
        }

       }

       return result ; 
    }
};

int main() {
    Solution s;

    vector<vector<int>> tests = {
        {4,5,6,7,0,1,2},
        {6,7,0,1,2,4,5},
        {1},
        {1,3},
        {5,1,3}
    };

    vector<int> targets = {0, 7, 1, 3, 5};

    for (int i = 0; i < tests.size(); i++) {
        cout << "Testcase " << i+1 << ": ";
        for (int x : tests[i]) cout << x << " ";
        cout << "\nTarget: " << targets[i];

        int result = s.search(tests[i], targets[i]);
        cout << "\nResult: " << result << "\n\n";
    }

    return 0;
}

// Time Complexity : O(log(n))
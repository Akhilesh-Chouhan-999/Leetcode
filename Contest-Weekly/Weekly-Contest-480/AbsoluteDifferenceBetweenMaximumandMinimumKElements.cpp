

/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int maxSum = 0;
        int minSum = 0;

        for(int i = 0; i < k; i++) minSum += nums[i];
        for(int i = n - 1; i >= n - k; i--) maxSum += nums[i];

        return abs(maxSum - minSum);
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 1, 5, 2, 9};
    int k = 2;

    cout << "Output: " << obj.absDifference(nums, k) << endl;

    return 0;
}

Time Complexity : O(n*log(n))

*/




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {

        int n = nums.size() ; 

        priority_queue<int>maxHeap ; 
        priority_queue<int , vector<int> , greater<int> >minHeap ; 

        for(int &num : nums){

            maxHeap.push(num) ;
            if(maxHeap.size() > k)
            maxHeap.pop() ; 

            minHeap.push(num) ; 
            if(minHeap.size() > k)
            minHeap.pop() ;

        }


        int maxSum = 0 ; 
        int minSum = 0 ; 


        while(!maxHeap.empty() && !minHeap.empty()){

            maxSum += maxHeap.top() ; 
            maxHeap.pop() ; 

            minSum += minHeap.top() ; 
            minHeap.pop() ; 

        }

        return abs(maxSum-minSum) ;

    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 1, 5, 2, 9};
    int k = 2;

    cout << "Output: " << obj.absDifference(nums, k) << endl;

    return 0;
}
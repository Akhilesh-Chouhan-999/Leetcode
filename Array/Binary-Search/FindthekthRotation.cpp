#include<iostream>
#include<vector>
#include<limits.h>
using namespace std ; 

class Solution {
  public:
  int binarySearch(vector<int>&arr){
      
      int n = arr.size() ; 
      
      int low = 0 ; 
      int high = n - 1 ;
      int mini = INT_MAX ; 
      int minIndex = -1 ; 
      
      while(low <= high){
          
          int mid = low + (high - low) / 2 ; 
          
          if(arr[low] <= arr[mid])
          {
              if(mini > arr[low])
              {
                  mini = arr[low] ; 
                  minIndex = low ; 
              }
              
              low = mid + 1 ; 
          }
          else
          {
              if(mini > arr[mid])
              {
                  mini = arr[mid] ; 
                  minIndex = mid ; 
              }
              
              high = mid - 1 ; 
          }
      }
      
      return minIndex ; 
  }
  
  
    int findKRotation(vector<int> &arr) {
      
      int result = binarySearch(arr) ;
      
      return result ; 
    }
};

int main(){

    
    Solution s1 ; 

    vector<int>arr = { 5, 1, 2, 3, 4} ; 
    int result = s1.findKRotation(arr) ; 
    cout << " Result is : " << result << endl; 

    return 0 ; 
}
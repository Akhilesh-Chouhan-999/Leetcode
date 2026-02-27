#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level ){

         int n = watchedVideos.size() ; 

         vector<bool>visited(n , false) ;
         visited[id] = true ; 

         queue<int>que ; 
         que.push(id) ;
         
         int currLevel = 0 ; 

         while(!que.empty() && currLevel < level){

            int size = que.size() ; 

            while(size -- ){

                int u = que.front() ; 
                que.pop() ; 


                for(int v : friends[u]){

                    if(!visited[v]){
                        que.push(v) ;
                        visited[v] = true ;  
                    }

                }
            }

            currLevel ++ ; 

         }

         map<string , int>freq ; 

         while(!que.empty()){

            int u = que.front() ; 
            que.pop() ; 

            for(string video : watchedVideos[u]){
                freq[video] ++ ; 
            }
         }


         vector<pair<string , int>>vec(freq.begin() , freq.end()) ; 


         sort(vec.begin() , vec.end() , [](auto &a , auto &b) {

            if(a.second == b.second){
                return a.first < b.first ; 
            }

            return a.second < b.second ; 
         }) ; 


         vector<string>result ; 


         for(auto v : vec ){
            result.push_back(v.first) ; 
         }

         return result ; 


    }
};

void printVector(const vector<string>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // ---------- Example 1 ----------
    vector<vector<string>> watchedVideos1 = {
        {"A", "B"},
        {"C"},
        {"B", "C"},
        {"D"}
    };
    vector<vector<int>> friends1 = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };
    int id1 = 0, level1 = 1;

    vector<string> result1 =
        sol.watchedVideosByFriends(watchedVideos1, friends1, id1, level1);

    cout << "Output: ";
    printVector(result1);
    cout << " | Expected: [B, C]" << endl;

    // ---------- Example 2 ----------
    int id2 = 0, level2 = 2;

    vector<string> result2 =
        sol.watchedVideosByFriends(watchedVideos1, friends1, id2, level2);

    cout << "Output: ";
    printVector(result2);
    cout << " | Expected: [D]" << endl;

    return 0;
}

/*
Time Complexity : O(n + E + V log U + U log U)
                   where n = number of people 
                   E = total no. of friendship edges
                   V = total no. of videos by people at the target level 
                   U = no. of unique videos at that 
                   level . 

                   O( n ^ 2 + V log(V))

Space Complexity : O( n + U)

*/

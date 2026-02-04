#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
       
        
          map<int , vector<pair<int , int>> > timeMeetings ; 
          vector<int>ans;

          for(vector<int>meeting : meetings){
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2] ; 

            timeMeetings[time].push_back({person1 , person2}) ; 
          }

          vector<int>seenforTimeT(n , false) ; 
          seenforTimeT[0] = true ;
          seenforTimeT[firstPerson] = true ; 

          for(auto meeting : timeMeetings){

            int time = meeting.first ; 
            unordered_map<int , vector<int>>adj ; 
            vector<bool>visited(n , false) ; 
            queue<int>que ; 

            for(pair<int , int>&p : meeting.second){
                int person1 = p.first ; 
                int person2 = p.second ; 

                adj[person1].push_back(person2);
                adj[person2].push_back(person1);

                if(seenforTimeT[person1]){
                    que.push(person1) ;
                    visited[person1] = true;
                }

                if(seenforTimeT[person2]){
                que.push(person2) ;
                visited[person2] = true ; 
                 }

            }


            while(!que.empty()){

                int person = que.front() ; 
                que.pop() ; 

                for(int &nextPerson : adj[person]){
                    if(!visited[nextPerson]){
                        que.push(nextPerson) ; 
                        seenforTimeT[nextPerson] = true ; 
                        visited[nextPerson] = true ; 
                    }
                }
            }

    
          }
       
          for(int i = 0 ; i < n ; i ++){
            if(seenforTimeT[i]){
                ans.push_back(i);
            }
          }

          return ans ; 

        
    }
};

int main() {
    Solution obj;

    int n = 6;
    int firstPerson = 1;

    vector<vector<int>> meetings = {
        {1, 2, 5},
        {2, 3, 8},
        {1, 5, 10}
    };

    vector<int> result = obj.findAllPeople(n, meetings, firstPerson);

    cout << "People who know the secret: ";
    for (int person : result) {
        cout << person << " ";
    }
    cout << endl;

    return 0;
}

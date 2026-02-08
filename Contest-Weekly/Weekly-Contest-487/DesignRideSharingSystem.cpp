/*
#include<bits/stdc++.h>
using namespace std ; 


class RideSharingSystem {
public:

    queue<int>riders ; 
    queue<int>drivers ;
    unordered_set<int>st ; 

    RideSharingSystem() {}

    // Time Complexity : O(1)
    
    void addRider(int riderId) {
        riders.push(riderId) ; 
        st.insert(riderId) ; 
    }
    
    // Time Complexity : O(1)
    void addDriver(int driverId) {
        drivers.push(driverId) ; 
    }
    
    // Time Complexity : O(1)
    vector<int> matchDriverWithRider() {
        
        if(riders.empty() || drivers.empty())
        return { -1 , -1 } ; 
        
        
        int earliestRider = riders.front() ; 
        riders.pop() ;
        
        int earliestDriver = drivers.front() ; 
        drivers.pop() ; 
        
        auto it = st.find(earliestRider) ; 
        st.erase(it) ;
        
        return { earliestDriver , earliestRider} ; 
    }
    
    // Time Complexity : O(n)
    // Space Complexity : O(n)

    
    void cancelRider(int riderId) {

        if(st.find(riderId) == st.end()){
            return ;
        }   

        queue<int>temp ;
        
        while(!riders.empty()){

            if(riders.front() != riderId)
            temp.push(riders.front()) ; 

            riders.pop() ; 
        }

        riders = temp ;
        temp.emplace() ; 

        temp  = queue<int>();   ;

    }
};

int main() {
    cout << "===== Example 1 =====\n";
    RideSharingSystem rs1;

    rs1.addRider(3);
    rs1.addDriver(2);
    rs1.addRider(1);

    auto r1 = rs1.matchDriverWithRider();
    cout << "[" << r1[0] << ", " << r1[1] << "]  Expected: [2, 3]\n";

    rs1.addDriver(5);
    rs1.cancelRider(3);

    auto r2 = rs1.matchDriverWithRider();
    cout << "[" << r2[0] << ", " << r2[1] << "]  Expected: [5, 1]\n";

    auto r3 = rs1.matchDriverWithRider();
    cout << "[" << r3[0] << ", " << r3[1] << "]  Expected: [-1, -1]\n";

    cout << "\n===== Example 2 =====\n";
    RideSharingSystem rs2;

    rs2.addRider(8);
    rs2.addDriver(8);
    rs2.addDriver(6);

    auto r4 = rs2.matchDriverWithRider();
    cout << "[" << r4[0] << ", " << r4[1] << "]  Expected: [8, 8]\n";

    rs2.addRider(2);
    rs2.cancelRider(2);

    auto r5 = rs2.matchDriverWithRider();
    cout << "[" << r5[0] << ", " << r5[1] << "]  Expected: [-1, -1]\n";

    return 0;
}

*/


#include<bits/stdc++.h>
using namespace std ; 


class RideSharingSystem {
public:

    queue<int>riders ; 
    queue<int>drivers ;
    unordered_set<int>st ; 

    RideSharingSystem() {}

    // Time Complexity : O(1)
    void addRider(int riderId) {
        riders.push(riderId) ; 
        st.insert(riderId) ; 
    }
    
    // Time Complexity : O(1)
    void addDriver(int driverId) {
        drivers.push(driverId) ; 
    }
    
    // Time Complexity : Amortized O(1)
    vector<int> matchDriverWithRider() {
        
        while(!riders.empty() && st.find(riders.front()) == st.end()){
            riders.pop() ; 
        }


        if(riders.empty() || drivers.empty())
        return { -1 , -1 } ; 
        
        
        int earliestRider = riders.front() ; 
        riders.pop() ;
        
        int earliestDriver = drivers.front() ; 
        drivers.pop() ; 
        
        auto it = st.find(earliestRider) ; 
        st.erase(it) ;
        
        return { earliestDriver , earliestRider} ; 
    }
    
    // Time Complexity : O(1)

    
    void cancelRider(int riderId) {

        auto it = st.find(riderId) ; 

        if(it  != st.end())
        st.erase(it) ; 

    }
};

int main() {
    cout << "===== Example 1 =====\n";
    RideSharingSystem rs1;

    rs1.addRider(3);
    rs1.addDriver(2);
    rs1.addRider(1);

    auto r1 = rs1.matchDriverWithRider();
    cout << "[" << r1[0] << ", " << r1[1] << "]  Expected: [2, 3]\n";

    rs1.addDriver(5);
    rs1.cancelRider(3);

    auto r2 = rs1.matchDriverWithRider();
    cout << "[" << r2[0] << ", " << r2[1] << "]  Expected: [5, 1]\n";

    auto r3 = rs1.matchDriverWithRider();
    cout << "[" << r3[0] << ", " << r3[1] << "]  Expected: [-1, -1]\n";

    cout << "\n===== Example 2 =====\n";
    RideSharingSystem rs2;

    rs2.addRider(8);
    rs2.addDriver(8);
    rs2.addDriver(6);

    auto r4 = rs2.matchDriverWithRider();
    cout << "[" << r4[0] << ", " << r4[1] << "]  Expected: [8, 8]\n";

    rs2.addRider(2);
    rs2.cancelRider(2);

    auto r5 = rs2.matchDriverWithRider();
    cout << "[" << r5[0] << ", " << r5[1] << "]  Expected: [-1, -1]\n";

    return 0;
}

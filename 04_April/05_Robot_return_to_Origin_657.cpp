// Problem : (LC 657)Robot Return to Origin
// Approach : Simulation
// Time Complexity : O(n)

#include<string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string& moves) {
        int H=0, V=0;
        for(char c: moves){
            H+=(c=='R');
            H-=(c=='L');
            V+=(c=='U');
            V-=(c=='D');
        }
        return (H==0) & (V==0);
    }
};
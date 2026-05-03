// Problem : (LC 796)Rotate String
// Approach : String Matching / Knuth–Morris–Pratt Algorithm
// Time Complexity :  O(n^2)

#include<string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        return (s + s).find(goal) != string::npos;
    }
};
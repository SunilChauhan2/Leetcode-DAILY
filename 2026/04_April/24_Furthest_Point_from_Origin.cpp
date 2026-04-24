// Problem : (LC 2615)Furthest Point from Origin
// Approach : Simulation/ Counting
// Time Complexity : O(N)

#include<iostream>
using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, B = 0;
        for (auto c : moves) {
            if (c == 'L') {
                L++;
            } else if (c == 'R') {
                R++;
            } else {
                B++;
            }
        }
        return abs(L - R) + B;
    }
};
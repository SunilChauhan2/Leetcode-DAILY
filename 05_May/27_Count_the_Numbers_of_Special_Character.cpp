// Problem : (LC 3121)Count the Number of Special Characters II
// Approach : Array / Simulation
// Time Complexity : O(N)

#include<vector>
using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLow(26, -1), firstUp(26, -1);
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (islower(c)) {
                lastLow[c - 'a'] = i;
            } else {
                if (firstUp[c - 'A'] == -1) {
                    firstUp[c - 'A'] = i;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (lastLow[i] != -1 && firstUp[i] != -1 &&
                lastLow[i] < firstUp[i]) {
                ans++;
            }
        }
        return ans;
    }
};
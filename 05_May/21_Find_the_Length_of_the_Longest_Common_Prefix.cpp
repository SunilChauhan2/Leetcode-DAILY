// Problem : (LC 3043) Find the Length of the Longest Common Prefix
// Approach : Prefix Hashing
// Time Complexity : O(D) where, D = total Digits

#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> st;

        for(int x : arr1){

            while(x > 0){
                st.insert(x);
                x /= 10;
            }
        }

        int ans = 0;

        for(int x : arr2){

            while(x > 0){

                if(st.count(x)){
                    ans = max(ans, (int)to_string(x).size());
                    break;
                }

                x /= 10;
            }
        }

        return ans;
    }
};
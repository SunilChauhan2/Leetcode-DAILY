// Problem : (LC 2144)Minimum Cost of buying Candies with Discount
// Approach : Sorting / Greedy
// Time Complexity : O(nlogn)

#include<vector>
using namespace std;

class solution{
public: 
    int minimumCost(vector<int>& cost){
        int n = cost.size();
        sort(cost.begin(), cost.end());
        
        int count = 0;
        int sum = 0;

        for(int i = n - 1; i >= 0; i--){
            if(count < 2){
                sum += cost[i];
                count++;             
            }
            else{
                count = 0;
            }
        }
        return sum;
    }
};
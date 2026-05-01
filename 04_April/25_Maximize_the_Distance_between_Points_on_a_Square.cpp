// Problem : (LC 3464)Maximize the Distance between points on a Square
// Approach : Binary Search / Greedy / Sorting / two pointers
// Time Complexity : O(n^2 . K + n.Klogn)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> arr;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) {
                arr.push_back(y);
            } else if (y == side) {
                arr.push_back(side + x);
            } else if (x == side) {
                arr.push_back(side * 3LL - y);
            } else {
                arr.push_back(side * 4LL - x);
            }
        }
        sort(arr.begin(), arr.end());

        auto check = [&](long long limit) -> bool {
            for (long long start : arr) {
                long long end = start + side * 4LL - limit;
                long long cur = start;
                for (int i = 0; i < k - 1; i++) {
                    auto it = lower_bound(arr.begin(), arr.end(), cur + limit);
                    if (it == arr.end() || *it > end) {
                        cur = -1;
                        break;
                    }
                    cur = *it;
                }
                if (cur != -1) return true;
            }
            return false;
        };

        long long low = 0, high = side * 4LL;
        while (low < high) {
            long long mid = (low + high + 1) / 2;
            if (check(mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};
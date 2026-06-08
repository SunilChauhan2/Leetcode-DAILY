// Problem : (LC 3751)Total Waviness of Numbers in Range I
// Approach : Simulation / Enumeration
// Time Complexity : O((num2−num1)log(num2))

#include<iostream>
using namespace std;

class Solution {
public:

    int getWaviness(int num){

        vector<int> digits;

        while(num > 0){
            digits.push_back(num % 10);
            num /= 10;
        }

        reverse(digits.begin(), digits.end());

        int cnt = 0;

        for(int i = 1; i < digits.size() - 1; i++){

            if(digits[i] > digits[i - 1] &&
               digits[i] > digits[i + 1]){
                cnt++;
            }

            else if(digits[i] < digits[i - 1] &&
                    digits[i] < digits[i + 1]){
                cnt++;
            }
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {

        int ans = 0;

        for(int num = num1; num <= num2; num++){
            ans += getWaviness(num);
        }

        return ans;
    }
};
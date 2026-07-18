//
// Created by ayden on 19/07/2026.
//

#include <vector>
#include <iostream>
using namespace std;

// daily leetcode question, this seems super easy
// however there is an improvement using the euclidean algorithm, gcd(a,b) = gcd(b,amodb)

class Solution {
public:
    int findGCD(vector<int>& nums) {
        // first find min and max
        int min = nums[0];
        int max = nums[0];
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] < min) min = nums[i];
            if (nums[i] > max) max = nums[i];
        }

        // NAIVE APPROACH
        // int gcd = 1;
        // for (int j=max; j > 0; j--) {
        //     if (max % j == 0 && min % j == 0) return j;
        // }
        // return gcd;

        // EUCLIDEAN ALGORITHM APPROACH
        int remainder = 1; //set to some abitrary value to initalise the loop
        // re-initialising variable names to clear up from NAIVE APPROACH
        int a = max;
        int b = min;
        while (remainder != 0) {
            remainder = a%b;
            a = b;
            b = remainder;

        }
        return a;


    }
};


int main() {

    Solution s;

    vector<int> nums = {3,2,4};

    int result = s.findGCD(nums);
    cout << result;
}
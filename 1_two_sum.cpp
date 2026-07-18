//
// Created by ayden on 18/07/2026.
//

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;


/*
 * Option 1: Naive solution
 */


// vector<int> is a dynamically sized array

// vector<int>& nums references the same vector but in a difference name
// this is important as you don't need to copy entire vectors taking O(n), this instead takes O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // OPTION 1: NAIVE SOLUTION
        // const int n = nums.size();
        //
        // for (int i = 0; i < n; i++) {
        //     for (int j = i+1; j < n; j++) {
        //         if (nums[i] + nums[j] == target) {
        //             return {i, j};                }
        //     }
        // }

        // OPTION 2: STORE THE REQUIRED SOLUTION
        // for {2,7,11,15} with target 9, we will compute 9-i and in a hash table
        // for value 9-i, we will store i so when we find the next i we can do a O(1) lookup
        // this approach yields: O(n) in both space and time complexity

        const int n = nums.size();
        unordered_map<int, int> hashtable;

        for (int i = 0; i < n; i++) {
            int result = target - nums[i];

            // check if the result exists in the hashtable
            if (hashtable.find(nums[i]) != hashtable.end()) {
                // we have a solution
                return {i, hashtable[nums[i]]};
            }
            hashtable[result] = i;
        }



    }
};




int main() {

    Solution s;

    vector<int> nums = {3,2,4};
    const int target = 6;

    vector<int> result = s.twoSum(nums, target);
    cout << "[" << result[0] << ", " << result[1] << "]";
}
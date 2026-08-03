// Problem: Single Number I
// https://leetcode.com/problems/single-number/description/

//TC: O(N)  SC: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int num: nums)
        {
            ans ^= num;  // xor accumulates
        }
        return ans;
    }
};



// Problem: Single Number II
// https://leetcode.com/problems/single-number-ii/description/
// Count bits column‑wise across all numbers.
// If a bit’s count is divisible by 3, it belongs to the triplets.
// The remainder (count % 3) marks the unique number’s bit

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int bitCount = 0;
            for (int num : nums) {
                if (num & (1 << i)) bitCount++;
            }
            if (bitCount % 3 != 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};

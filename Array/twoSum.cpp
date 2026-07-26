// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Pattern: Two-pointer
//https://takeuforward.org/data-structure/two-sum-check-if-a-pair-with-given-sum-exists-in-array

//Brute Force Soln: TC: O(n^2) SC: O(1)
//Approch: Nested loop i and j, Do not use the same element twice hence, j starts from i+1

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(nums[i]+nums[j] == target)
                return {i,j};
            }
        }
        return {};
    }
};


//Better Soln: TC: O(n) SC: O(n)
// TC Paradox: if ordered map: O(N*logN) [no collision], if unordered map: O(N*1) [mostly i.e. best and avg TC] but if collision happens [happens once in a blue moon] then O(N*N)
//Approch: Hashmap

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i}; // found the pair
        }
        mp[nums[i]] = i; // store current value with its index
    }
    return {}; // no solution found
}

//Optimized: TC: O(n) & O(nlogn) [if sorting also done]
//Approach: Two Pointer, Greedy way

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i,j,sum;
        int n = numbers.size();
        i = 0;
        j = n-1;
        while(i<j)
        {
            sum = numbers[i] + numbers[j];
            if(sum == target)
            return {i+1 , j+1};
            else if(sum > target)
            j--;
            else
            i++;
        }
        return {0,0};
    }
};


//Counting number of pairs with sum equal to target given sorted array (same complexities as without counting pairs version)
//https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1
// TC: 𝑂(nlogn) if sorting is needed, otherwise O(n), SC: O(1)

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
         int i,j,sum,c;
        int n = arr.size();
        i = 0;
        j = n-1;
        c=0;
        while(i<j)
        {
            sum = arr[i] + arr[j];
            if(sum == target)
            {
                //Case 1 
                if(arr[i] == arr[j])
                {
                    int cnt = j-i+1;
                    c+= (cnt*(cnt-1))/2; //nC2 formula
                    break;
                }
                //Case 2
                int leftCount = 1, rightCount = 1;
                //Duplicates on the left
                while(i+1 < j && arr[i] == arr[i+1])
                {
                    leftCount++;
                    i++;    
                }
                
                //Duplicates on the right
                while(j-1 > i && arr[j] == arr[j-1])
                {
                    rightCount++;
                    j--;
                }
                
                c+= leftCount * rightCount;
                i++;
                j--;
                
            }
            else if(sum > target)
            j--;
            else
            i++;
        }
        return c;
    }
};

// Counting number of pairs when unsorted array given (Hashmap technique)
// TC: O(2n) building map, iterating map. Hashmap operations are O(1), SC: O(n)

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        unordered_map<int,int> freq;
        for (int x : arr) {
            freq[x]++;
        }

        int c = 0;
        for (auto &p : freq) {
            int x = p.first;
            int y = target - x;

            if (freq.find(y) != freq.end()) {
                if (x == y) {
                    // choose 2 out of freq[x]
                    c += (freq[x] * (freq[x] - 1)) / 2;
                } else if(x  < y) {   // else if condition is for skiping to count same pair (x,y) as (y,x).
                    c += freq[x] * freq[y];
                }
            }
        }

        return c; 
    }
};

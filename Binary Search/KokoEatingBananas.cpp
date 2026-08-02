// Problem: Koko Eating Banana
// https://leetcode.com/problems/koko-eating-bananas/
// https://www.youtube.com/watch?v=qyfekrNni90

//BFS: Linear scan of all possible speeds i.e. all possible values of K
// K will be between i=1 to max wale in piles array
// TC: O(maxi * N) SC: O(1)

class Solution {
public:
    long long requiredTime(vector<int>& piles, int k)
    {
        long long time = 0;
        for(int pile: piles)
        {
            time += (pile + k - 1)/k; // ceil(pile/k)
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = *max_element(piles.begin(), piles.end());

        for(int i=1; i<= maxi; i++)  // LINEAR SEARCH 
        {
            long long reqTime = requiredTime(piles, i);
            if(reqTime <= h)
            return i; 
        }
        return maxi;
    }
};

// OS:
// TC: O(NlogN)

class Solution {
public:
    long long requiredTime(vector<int>& piles, int k)
    {
        long long time = 0;
        for(int pile: piles)
        {
            time += (pile + k - 1)/k; // ceil(pile/k)
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxi;

        while(low <= high)
        {
            int mid = (low + high)/2;
            long long reqTime = requiredTime(piles, mid);
            
            if(reqTime <= h)
            high = mid-1;

            else
            low = mid+1;
            
        }
        return low;
    }
};

// Problem: Minimum Window Substring
// https://leetcode.com/problems/minimum-window-substring/


// BFS: TC: O(M^3 + M*N), SC: O(256) constant extra space
// Generate all substrings and compare if substring hasAllChars by comparing the frequency using fixed arrayof 256 size

class Solution {
public:
    bool hasAllChars(string sub, string t)
    {
        vector<int> count(256,0);  // int count[256= = {0};

        // Build frequency counts of t once/first
        for(char ch: t) // O(N)
        count[ch]++;
        // compare counts of sub against counts of t 
        for(char ch: sub) // O(M)
        {
            if(count[ch] > 0)
            count[ch]--;
        }

        for(int i=0; i<256; i++)
        {
            if(count[i] > 0)
            return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        string window = "";
        int minLen = INT_MAX;

        for(int i=0; i<m; i++)  // O(M)
        {
            for(int j=i; j<m; j++)  // O(M)
            {
                string sub = s.substr(i,j-i+1); // s.substr(startIdx, Length) TC: O(M) total

                if(hasAllChars(sub, t)) // Hlper fn: 
                {
                    int currLen = sub.length();
                    if(currLen < minLen)
                    {
                        minLen = currLen;
                        window = sub;
                    }
                }
            }
        }
        return window;
    }
};



 // BS:
 //  - Binary search on answers but not expected
 //  - TC: O(N*logN) SC: O(1)



// OS:  TC: O(2M + N)< SC: O(256) constant space


class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int minLen = INT_MAX;
        int startIdx = -1;
        int count = 0;
        int l=0, r=0;

        // Requirement array
        int freq[256] = {0};
        for(char ch: t) // O(N)
            freq[ch]++;

        while(r < m) // O(M)
        {
            // If already preinserted
            if(freq[s[r]] > 0)
            count++;
            freq[s[r]]--; // always decrement

            while(count == n) // O(N) worst case
            {
                if(r-l+1 < minLen)
                {
                    minLen = r-l+1;
                    startIdx = l;
                } 
                // Shrinking from left
                freq[s[l]]++;
                if(freq[s[l]] > 0)
                count--;
                l++;
            }
            r++;
        }
        return startIdx == -1 ? "" : s.substr(startIdx, minLen);
    }
};

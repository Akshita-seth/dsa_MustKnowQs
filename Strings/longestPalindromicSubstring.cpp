// Problem: Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

// BFS:
// Generate all possible substrings of the given string. For each substring, check if it is a palindrome.
// If it is, update the result if its length is greater than the longest palindrome found so far.
// TC: O(n^3), SC: O(1)

bool checkPal(int start, int end, string s)
    {
        if(start == end)
        return true;
        while(start < end)
        {
            if(s[start] != s[end])
            return false;
            start++, end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string palin;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                int len = checkPal(i,j,s) ? j-i+1 : 0;
                if(len > palin.size())
                  palin = s.substr(i,len);
            }
        }
        return palin;
    }

// BS: Expanding around the centre
// TC: O(n^2), SC: O(1)

string longestPalindrome(string s) {
        int n = s.size();
        int start, maxLen=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=1; j++)
            {
                int low = i;
                int high = i + j;

                while(low >= 0 && high < n && s[low] == s[high])
                {
                    int currLen = high - low + 1;
                    if(currLen > maxLen)
                    {
                        start = low;
                        maxLen = currLen;
                    }
                    low--, high++;
                }
            }
        }
        return s.substr(start,maxLen);
    }

// https://www.geeksforgeeks.org/dsa/longest-palindromic-substring/
// Expand Around Center is the expected optimized solution.
// You can mention DP as an alternative, and Manacher’s as the theoretical optimal [TC: O(n) SC: O(n)], but code the center‑expansion method.
// Complexity: O(n^2 and O(1) — good balance of clarity and efficiency.

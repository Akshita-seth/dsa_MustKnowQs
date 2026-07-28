// Problem: Longest Substring without repeating characters
// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// https://www.geeksforgeeks.org/dsa/length-of-the-longest-substring-without-repeating-characters/

// BFS:
// If constraint mentions: s consists of English letters, digits, symbols and spaces.
// Take freq array of size 256
// If only English lowercase alphabets then 26 size array and use visited[s[j]-'a']
// Generate all substrings → check uniqueness.
// TC: O(n^2), SC: O(1) since fixed size array

int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            // Initially all characters are unvisited
            vector<bool> visited(256, false);
            for (int j = i; j < n; j++) {
                // If already visited character encountered, break
                if (visited[s[j]] == true)
                    break;
                // Else update the result if this window is larger,
                // and mark current character as visited.
                else {
                    ans = max(ans, j - i + 1);
                    visited[s[j]] = true;
                }
            }
        }
        return ans;
    }

// If Asked for the Substring Itself
// Instead of just length, you can store the substring:

string longest;
...
ans = max(ans, j - i + 1);
if(ans == j - i + 1) longest = s.substr(i, ans);


// OS 1:
// TC: O(n) SC: O(1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxWindow = 0;
        int left = 0, right =0;
        // Initially all characters ar unvisited
        vector<bool> visited(256, false);
        while(right < n) {
            while(visited[s[right]] == true)
            {
                visited[s[left]] = false;
                left++;
            }
            visited[s[right]] = true;
            maxWindow = max(maxWindow, right-left+1);
            right++;
        }
        return maxWindow;
    }
};

// OS 2:
// TC: O(n) SC: O(1)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxWindow = 0;
        int start = 0, end =0;
        // Initially all characters ar unvisited
        vector<int> lastIndex(256, -1);
        while(end < n) {
            if(lastIndex[s[end]] != -1)
            {
                if(start <= lastIndex[s[end]])
                start = lastIndex[s[end]] + 1;
            }
            lastIndex[s[end]] = end;
            maxWindow = max(maxWindow, end-start+1);
            end++;
        }
        return maxWindow;
    }
};

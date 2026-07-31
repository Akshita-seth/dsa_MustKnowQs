// Problem: Permutation in string
// 
// A permutation means the arrangement can change, but the multiset of characters must be identical.
// So if two strings have the same length and the same frequency of each character, they are permutations.


// BFS:
// Sort every substring of s2 of length s1.size() and compare with sorted s1.
// TC: O(n. mlogm) where Sorting each substring costs O(len1.loglen1), m=len1 and Doing this for all windows i.e. multiply (len2-len1)=n [heavier than necessary], SC: O(1)
// DND: limit for i is <= len1-len2 otherwise problem: 
// 1st: if not len2 not subtracted then i goes out of bounds
// 2nd: if just < then i misses last pssbl substring hence <=

bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());

        int len1 = s1.size();
        int len2 = s2.size();

        for(int i=0; i <= len2-len1; i++)
        {
            string str = s2.substr(i, len1);
            sort(str.begin(), str.end());
            if(str == s1)
            return true;
        }
        return false;
    }

// OS: Use character frequency arrays + sliding window
// TC: O(len2), each slide is constant work + 26‑char comparison, SC: O(1) since we use two arrays of length 26.
// 1. build freq -> O(len1), 2. Initialize first window of len1 in s2 -> O(len1), Slide the window across s2for len2-len1 windows -> len2-len1
//Hence overall: len1 + len1 + len2-len1 => len2

bool checkInclusion(string s1, string s2) {
        int len1 = s1.size();
        int len2 = s2.size();
        // build freq of s1
        vector<int> freq1(26,0);
        for(char ch:s1)
        freq1[ch - 'a']++;
 
        vector<int> freq2(26,0);
        // initialise window of size len1 in s2
        for(int i=0; i<len2 && i<len1; i++)
            freq2[s2[i] - 'a']++;
        
        // comparing initial window's freq arrays
        if(freq1 == freq2)
        return true;
        
        // sliding the window
        for(int i=len1; i<len2; i++)
        {
            freq2[s2[i]-'a']++; //adding new char
            freq2[s2[i - len1] - 'a']--; //removing leftmost char

            //comparing
            if(freq1 == freq2)
            return true;
        }
        return false;
    }

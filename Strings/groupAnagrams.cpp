// Problem: Group Anagrams
// https://leetcode.com/problems/group-anagrams/description/
// https://www.geeksforgeeks.org/dsa/given-a-sequence-of-words-print-all-anagrams-together/

//BFS:
// TC: O(n^2 * klogk), Sorting each comparison: O(klogk) in helper fn and Comparing all pairs: O(n^2)
// SC: O(n.k), Sorting O(1) or O(k) depending on sorting algo, here assumed O(1), Group stored O(n.k)

vector<vector<string>> anagrams(vector<string> &arr) {
    vector<vector<string>> res;
    int n = arr.size();

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        vector<string> group;
        group.push_back(arr[i]);
        visited[i] = true;

        for (int j = i + 1; j < n; j++) {
            if (!visited[j] && isAnagram(arr[i], arr[j])) {
                group.push_back(arr[j]);
                visited[j] = true;
            }
        }

        res.push_back(group);
    }

    return res;
}



// BS: Sort each word once, use the sorted string as a hash key in a map.
// TC: O(n. klogk) Sorting each word: O(klogk), For n words: O(n. klogk), Hash insertions: O(n)
// SC: O(n.k) Hash map storing groups

 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> anagrams;
        unordered_map<string, int> mpp;
        for(int i=0; i<n; i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());

            if(mpp.find(s) == mpp.end())
            {
                mpp[s] = anagrams.size(); //last index of anagram
                anagrams.push_back({});
            }
            anagrams[mpp[s]].push_back(strs[i]); // don't push bcz it is sorted and not in original form
        }
        return anagrams;
    }

// OS: 

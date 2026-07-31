// Problem: Decode string
// https://leetcode.com/problems/decode-string/

// Solution:
// The stack keeps track of nested contexts.
// Each [ starts a new context, each ] closes it.
// Digits tell you how many times to repeat.

// SC: O(1)
// TC: O(n.k) where n is length of string, k is max repeat count in string.
// But when you expand, you may repeat substrings up to k times.
// If k is large, expansion dominates.
// Example: "100[a]" → output length = 100, so expansion cost is proportional to k.


 string decodeString(string s) {
        string currString;
        stack<pair<string, int>> st; //{previouString, repeatCount}
        int num = 0;

        for(char ch: s)
        {
            if(isdigit(ch))
            // since building multi-digit number ex: 12[a] thus num*10
            num = num*10 + (ch - '0');

            else if(ch == '[')
            {
                // push current context
                st.push({currString, num});
                // for new context
                currString = "";
                num = 0;
            }
            
            else if(isalpha(ch))
            currString.push_back(ch);
            // currString.append(1, ch);


            else if(ch == ']')
            {
                // pop and expand
                auto [prevString, repeatCount] = st.top();
                st.pop();
                string expanded="";

                for(int i=0; i<repeatCount; i++)
                  expanded += currString;

                currString = prevString + expanded;
            }
        }
        return currString;
    }

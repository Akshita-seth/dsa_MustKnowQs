// Problem: Valid Parantheses
// https://leetcode.com/problems/valid-parentheses/description/

// Solution: TC: O(N), SC: O(N)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch: s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
            st.push(ch);

            else 
            {
                if(st.empty()) return false; // no matching closed brackets found

                char c = st.top();
                st.pop();

                if((c == '(' && ch == ')') || (c == '{' && ch == '}') || (c == '[' && ch == ']'))
                continue;
                else 
                return false;
            }
            
        }
        return st.empty();


    }
};

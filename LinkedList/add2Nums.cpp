// Problem: Add two  numbers given in the form of a LL
// https://leetcode.com/problems/add-two-numbers/

//BFS: This version collects digits first (like simulating addition step by step), then builds the linked list
// TC:  O(max(m,n)) , SC:  O(max(m,n))  for the digits vector.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> digits;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            digits.push_back(sum % 10);
            carry = sum / 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        // Build linked list from collected digits
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        for (int d : digits) {
            curr->next = new ListNode(d);
            curr = curr->next;
        }
        return dummy->next;
    }
};


// Optimized:
// TC: O(max(m,n))  where m and n are lengths of the two lists.
// SC: O(1) but if the new created list considered O(max(m,n)), The length of the new LL is at max max(m,n)+1;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;
        while(l1 || l2 || carry)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            curr->next = new ListNode(sum%10);
            curr = curr->next;

            carry =  sum/10;
            
            if(l1) 
            l1 = l1->next;
            if(l2)
            l2 = l2->next;
        }
        return dummy->next;
    }
};

// Problem: Middle of a Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/submissions/2019244814/


//BFS: TC: O(N + N/2)  SC: O(1)

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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int c=0;
        while(temp)
        {
            c++;
            temp = temp->next;
        } 
        int mid = c/2 + 1;
        temp = head;
        while(temp)
        {
            mid--;
            if(mid == 0)
            break;
            temp = temp->next;
        }
        return temp;
    }
};


// Optimized: TC: O(N/2)
// TORTOISE & HARE Algorithm

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL)  //without this also runs
        {
            return head;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};

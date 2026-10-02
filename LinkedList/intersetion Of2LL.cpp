//Problem: find intersection of 2 LL
// 

// DND:
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA && headB)
        {
            if(headA == headB)
            return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

// The issue with your current solution is that it assumes both lists have the same length and advances headA and headB together.
// Why it fails?
// If List A is longer than List B, headA will still have nodes left when headB becomes NULL.
// The loop ends prematurely, and you never check the remaining nodes of the longer list.
// Intersection nodes that exist deeper in the longer list will be missed.
// Example:
// List A: 1 → 2 → 3 → 4 → 5
// List B:       9 → 4 → 5
// Your code compares 1 vs 9, then 2 vs 4, then 3 vs 5.
// When headB reaches NULL, the loop stops.
// But the actual intersection is at node 4, which is missed.



// BFS: check every node in ListA with every node in ListB
// TC: O(N × M), where N is the number of nodes in the first linked list and M is the number of nodes in the second linked list.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;

        while(tempA)
        {
           ListNode* tempB = headB;
           while(tempB)
           {
            if(tempA == tempB)
            return tempA;
            tempB = tempB->next;
           }
           tempA = tempA->next;
        }
        return NULL;
    }
};

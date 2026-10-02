//Problem: find the intersection of 2 LL
//  https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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



// BFS: Compare every node of the first linked list with every node of the second linked list. Since intersection depends on the same node reference, not just equal values, a matching reference identifies the first common physical node.
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


// Better: Store the node references of the first linked list in a hash set. This makes it possible to check whether a node from the second list belongs to the first list in O(1) average time, avoiding repeated comparisons.
// TC: O(M+N), SC: O(M)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mpp;
        ListNode* tempA = headA;
        ListNode* tempB = headB;

        while(tempA)
        {
           mpp[tempA] = 1;
           tempA = tempA->next;
        }
        while(tempB)
        {
            if(mpp.find(tempB) != mpp.end())
            return tempB;
            tempB = tempB->next;a
        }
        return NULL;
    }
};


// OS: Two pointers can automatically balance the different lengths of the two linked lists without calculating their lengths. Each pointer traverses its own list first and then continues through the other list after reaching the end.
// Because both pointers eventually cover the same total distance, any shared suffix causes them to meet at the first common node. If the lists do not intersect, both pointers reach null after covering the same distance.
// TC: O(M+N), SC: O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* first = headA;
        ListNode* second = headB;

        while(first || second)
        {
            if(first == second)
            return first;
            if(!first)
            first = headB;
            else
            first = first->next;
            if(!second)
            second = headA;
            else
            second = second->next;
        }  
        return NULL;
    }
};

// OR  more efficiently coded:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* pA = headA;
    ListNode* pB = headB;

    while(pA != pB) {
        pA = (pA == NULL) ? headB : pA->next;
        pB = (pB == NULL) ? headA : pB->next;
    }
    return pA; // either intersection node or NULL
}


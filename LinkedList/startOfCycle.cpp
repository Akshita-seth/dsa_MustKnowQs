// Problem: Start of Cycle
// https://leetcode.com/problems/linked-list-cycle-ii/


// BFS: Using map 
// TC: O(N) where N is the number of nodes in the linked list. Each node is visited only once during traversal. Hashing allows O(1) lookup to check for previously visited nodes.
// SC: O(N)

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*, int> nodeMap;
        while(temp)
        {
            if(nodeMap.find(temp) != NULL)
            return temp;
            nodeMap[temp] = 1;
            temp = temp->next;
        }
        return NULL;
    }
};


// Optimized: Fast and Slow Pointer
//Distance theory using fast and slow pointer. The first node where fast and slow pointers meet, from there the distance to the starting node of the loop and the distance from the head to the starting of the loop is saem.
// TC: O(N) where N is the number of nodes in the linked list. In the worst case, we traverse the entire list once with the slow and fast pointers, and then again to find the entry point of the loop.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                slow=head;
                while(fast!=slow)
                {
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

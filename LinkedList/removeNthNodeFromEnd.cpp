// Problem: Remove Nth Node from end
// 

// Emphasize that in C++, you pair new with delete.
// In C, you pair malloc with free.
// Never cross them.


// BFS: TC: O(2n) SC: O(1)
// To remove the Nth node from the end, first determine the length of the linked list. 
// Then, delete the (length - N + 1)th node from the front.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int c=0;
        while(temp)
        {
            c++;
            temp = temp->next;
        }
        // handling edge cases when n == c
        if(n == c)
        {
          ListNode* newHead = head->next;
          delete head;
          return newHead;
        }

        temp = head;

        ListNode* prev = NULL;
        int k=0;
        while(temp != NULL)
        {
            k++;
            if(k == c-n+1)
            {
                prev->next = temp->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
            
        }
        return head;
    }
};


// OS:
// TC: O(n), SC: O(1)

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head); // dummy->head
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Moving fast ahead by n+1 guarantees slow stops right before the node to remove
        for(int i=0; i<=n; i++)
        {
        fast = fast->next;
        }

        while(fast !=NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* nodeToDelete = slow->next;
        slow->next = nodeToDelete->next;

        delete nodeToDelete;

        return dummy->next;
    }

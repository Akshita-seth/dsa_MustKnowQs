// Problem: Reorder LL
// https://leetcode.com/problems/reorder-list/

// BFS: TC: O(N^2) SC: O(1)

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* curr = head;

        // Traverse until the second last node
        while (curr && curr->next) {
            // Step 1: Find the last node and its previous
            ListNode* prev = curr;
            ListNode* last = curr->next;
            while (last->next) {
                prev = last;
                last = last->next;
            }

            // Step 2: Disconnect the last node
            prev->next = NULL;

            // Step 3: Place the last node after current
            last->next = curr->next;
            curr->next = last;

            // Step 4: Move current forward
            curr = last->next;
        }
    }
};



// OS:
// TC: O(N) SC: O(1)

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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* prev = NULL, *curr = head, *next = NULL;

        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head;
        // finding mid
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = NULL;

        head2 = reverseList(head2);

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (head1 || head2) {
            if (head1) {
                curr->next = head1;
                head1 = head1->next;
                curr = curr->next;
            }
            if (head2) {
                curr->next = head2;
                head2 = head2->next;
                curr = curr->next;
            }
        }
       
    }
};

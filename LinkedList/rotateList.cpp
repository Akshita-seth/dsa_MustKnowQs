// Problem: Rotate LL Right K times
// https://leetcode.com/problems/rotate-list/


// BFS: 
// A right rotation can be performed by moving the last node of the linked list to the front. Since one such operation rotates the list by one position, repeating it k times gives the required result.
// Before performing rotations, we first count the length of the linked list and reduce k using k % length. This avoids unnecessary full-cycle rotations because rotating a list by its length brings it back to the same order.
// For every effective rotation, we traverse the list until the second last node, detach the last node, place it before the current head, and update the head pointer.
// TC: O(n + (k % n) × n), The list is traversed once to find its length, and each effective rotation takes O(n) time to find the last node. In the worst case, this becomes O(n²).
// SC: O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
        return head;
        ListNode* temp = head;
        int c=0;
        while(temp)
        {
            c++;
            temp = temp->next;
        }
        k = k % c;
        
        while(k)
        {
            temp = head;
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            ListNode* nodeToAddFront = temp->next;
            temp->next = NULL;
            nodeToAddFront->next = head;
            head = nodeToAddFront;
            k--;
        }
        return head;
    }
};


// OS: 
// Instead of rotating the linked list one step at a time, we first connect the tail node to the head node and temporarily convert the list into a circular linked list. 
// This keeps all nodes connected in order and allows us to choose the correct breaking point directly.
//For a right rotation by k, the actual number of rotations is k % length. The new head will be at position length - k + 1 from the beginning, and 
// the node just before it becomes the new tail. After locating the new tail, we break the circular link and return the new head.
// TC: O(n), one traversal counts length and another partial traversal locates the break point.
// SC: O(1)


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
        return head;
        ListNode* temp = head;
        int c=1; // and not zero bcz it is accounting for thr last node count bcz last node doesn't enter the loop
        while(temp->next) // till the last node only since have to connect it to head
        {
            c++;
            temp = temp->next;
        }
        k = k % c;
        temp->next = head; // connecting last node to head for making circular LL temporarily
        temp = head;
        int m=0;
        while(temp)
        {
            m++;
            if(m == c-k) //goes till new tail, and not till new head hence not c-k+1
            break;
            temp = temp->next;
        }
        ListNode* newTail = temp;
        ListNode* newHead = temp->next;
        newTail->next = nullptr;
        
       return newHead;
    }
};

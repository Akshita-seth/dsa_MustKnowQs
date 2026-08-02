// Problem: merge K sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/

// To make mergeKLists standard optimized, you need to change the merging strategy:
//Either use divide-and-conquer (merge pairs recursively until one list remains).
//Or use a min-heap to always pick the smallest head efficiently.

// BFS: Collect all nodes into a vector, sort, rebuild.
//TC: O(N*N), SC: O(N)



// Approach: Sequential Merge
// TC:O(NK) => N is total number of nodes across all lists, K is number of lists SC: O(1) 
// The problem: each time, the merged list grows larger, so later merges are more expensive.
// - Worst case (all lists of equal size, about N/k nodes each):
// - Merge 1: O(2N/k)
// - Merge 2: O(3N/k)
// - Merge 3: O(4N/k)
// - …
// - Merge (k-1): O(N)

// Total cost ≈

// (N/k) * (2 + 3 + 4 + … + k)  
// = (N/k) * (k(k+1)/2)  
// ≈ O(Nk)


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
    ListNode* merge2Lists(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(list1 && list2)
        {
        if(list1->val < list2->val)
        {
            curr->next = list1;
            list1=list1->next;
        }
        else
        {
            curr->next = list2;
            list2=list2->next;
        }
        curr = curr->next;
        }
        if(list1)
        curr->next = list1;
        else
        curr->next = list2;
        
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        return nullptr;

        ListNode* newHead = lists[0];
        for(int i=1; i<lists.size(); i++)
        {
            ListNode* temp = lists[i];
            newHead = merge2Lists(newHead, temp);
        }
        return newHead;
    }
};

// Optimized Approach 1:Pairwise Merge => Divide & Conquer: Merge lists in pairs recursively (like merge sort).
// TC: O(NlogK) where N = total number of nodes across all lists, k = number of lists.
// Each merge operation (merge2Lists) costs O(n) where n is the total number of nodes across the lists being merged.
//The recursion splits the vector of lists in half each time → recursion depth is O(log k). At each level of recursion, all nodes are merged once.
// SC:  O(K) with vector slicing, or O(logK) if you avoid slicing and recurse with indices.
//Recursion stack depth = O(log k).
//Temporary vectors when splitting (leftList, rightList) → each copy costs O(k), but overall bounded by O(k) at each level.

class Solution {
public:
    ListNode* merge2Lists(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(list1 && list2)
        {
        if(list1->val < list2->val)
        {
            curr->next = list1;
            list1=list1->next;
        }
        else
        {
            curr->next = list2;
            list2=list2->next;
        }
        curr = curr->next;
        }
        
        // curr->next = (l1 ? l1 : l2);
        
        if(list1)
        curr->next = list1;
        else
        curr->next = list2;
        
        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
        return NULL;
        if(lists.size() == 1)
        return lists[0];
        
        int mid = lists.size() / 2; 
        //first iterator-> INCLUSIVE & second iterator-> exclusive
        vector<ListNode*> leftList(lists.begin(), lists.begin() + mid);
        vector<ListNode*> rightList(lists.begin() + mid, lists.end());
        ListNode* right = mergeKLists(rightList);
        ListNode* left = mergeKLists(leftList);

        return merge2Lists(left, right);
    }
};


// Complexity of Pairwise Merge (Divide & Conquer)

// - **Time Complexity:** O(N log k)  
//   - Each merge operation (`merge2Lists`) costs O(n), where n is the total number of nodes across the lists being merged.  
//   - The recursion splits the vector of lists in half each time → recursion depth is O(log k).  
//   - At each level of recursion, all nodes are merged once.  
//   - Therefore, total time = O(N log k).

// - **Space Complexity:**  
//   - Recursion stack depth = O(log k).  
//   - Temporary vectors when splitting (`leftList`, `rightList`) → each copy costs O(k), but overall bounded by O(k) at each level.  
//   - So space = O(k) with vector slicing, or O(log k) if you avoid slicing and recurse with indices.

// ### Layman’s Explanation
// Think of it like a **tournament bracket**:
// - You start with k players (lists).
// - In round 1, they play matches in pairs → k/2 winners.
// - In round 2, those winners play again → k/4 winners.
// - This continues until one champion (the final merged list) remains.

// At each round, **every player participates once**, so all N nodes are touched.  
// The number of rounds is about **log₂(k)** (because the group halves each time).  
// So each node gets processed log k times → total work = N × log k.

// ### Summary
// - **TC:** O(N log k)  
// - **SC:** O(k) with slicing, [optimized to O(log k) if using indices +> SEE BELOW]


class Solution {
public:
    // Merge two sorted linked lists
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = (l1 ? l1 : l2);
        return dummy.next;
    }

    // Recursive helper using indices
    ListNode* mergeRange(vector<ListNode*>& lists, int left, int right) {
        if (left > right) return nullptr;
        if (left == right) return lists[left];

        int mid = left + (right - left) / 2;
        ListNode* l1 = mergeRange(lists, left, mid);
        ListNode* l2 = mergeRange(lists, mid + 1, right);

        return merge2Lists(l1, l2);
    }

    // Main function
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return mergeRange(lists, 0, lists.size() - 1);
    }
};


// Optimized Approach 2: Min-Heap (priority queue): Push the head of each list into a min-heap, repeatedly extract the smallest, advance that list.
// TC: O(NlogK) => Each of the 𝑁 nodes is pushed/popped once from the heap.Heap operations cost O(logK)
// SC: O(K) Heap stores at most one node from each list at a time.

// 🔹 Dry run direction (to visualize)
// Suppose lists are:
// L1: [1,4,5]
// L2: [1,3,4]
// L3: [2,6]
// Heap initially: [1(L1), 1(L2), 2(L3)]
// Pop 1(L1) → attach → push 4(L1).
// Heap: [1(L2), 2(L3), 4(L1)]
// Pop 1(L2) → attach → push 3(L2).
// Heap: [2(L3), 3(L2), 4(L1)]
// … continue until heap empty.
// 👉 So the direction is:
// Push all heads → repeatedly pop smallest → attach → push its next → continue.


class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // push the head of each list into the heap
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        // Creates a stack allocated node. dummy is a real ListNode object that lives until the function returns.
        //&dummy gives the address of the stack object. tail is a pointer to that dummy node. At the end, you return dummy.next.
        // Lifetime - Auto‑destroyed when function ends
        // ListNode dummy;
        // ListNode* tail = &dummy;

        // creates a heap‑allocated node. dummy is a pointer to that heap node. tail = dummy; points to the same heap node. 
        // Lifetime - Until manually deleted
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next) {
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
 };


// tail = dummy → correct, both point to the same node.
// tail = &dummy → wrong, makes tail a pointer to a pointer (ListNode**).
// Always use dummy as the fixed anchor, tail as the moving pointer.



// auto &node	-Reference to pointer (ListNode*&)	-Changes affect original vector	-Needed if you want to modify lists
// auto node	-Copy of pointer (ListNode*)	-Changes affect only local copy	-Safe if just reading/pushing


// 1. Matching comparator with heap
// -> Heap declaration:

// cpp
// priority_queue<ListNode*, vector<ListNode*>, customComparator> minHeap;
// ListNode* → type stored in heap

// vector<ListNode*> → underlying container

// customComparator → comparator type

// -> Comparator must accept two ListNode* arguments:

// cpp
// struct customComparator {
//     bool operator()(ListNode* a, ListNode* b) {
//         return a->val > b->val;
//     }
// };
// This matches because the heap stores ListNode*, so the comparator must compare ListNode*.

// 2. Why a->val > b->val gives min‑heap
// Default priority_queue in C++ is a max‑heap (largest element at top).

// Comparator decides ordering:

// If comp(a, b) is true → a is considered “after” b.

// For min‑heap:

// We want smaller values to come out first.

// Writing return a->val > b->val means:

// If a is bigger than b, then a goes after b.

// So smaller values bubble up to the top.

// 3. Quick intuition
// Think of comparator as saying: “Should a go after b?”

// For min‑heap, bigger values should go later → a->val > b->val.

// For max‑heap, smaller values should go later → a->val < b->val.

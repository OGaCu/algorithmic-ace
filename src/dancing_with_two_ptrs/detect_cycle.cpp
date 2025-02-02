
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // two pointers
        // Floyd's algorithm to detect cycle: 
        // https://en.wikipedia.org/wiki/Cycle_detection#:~:text=Floyd's%20cycle%2Dfinding%20algorithm%20is,is%20named%20after%20Robert%20W.
        // fast move two nodes
        // slow move a node
        // if there is a cycle, fast == slow
        // else, fast reach the end (nullptr)
        
        // find where the cycle begins
        // after fast == slow
        // fast = head
        // both poitners increment by one 
        // if meet, that is where the cycle begins
        
        // Time complexity: O(n)
        // Space complexity: O(1)

        bool is_first_cycle = true;
        ListNode *fast = head, *slow = head;

        while (fast != slow || is_first_cycle) {
            if (fast == nullptr || fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
            is_first_cycle = false;
        }
        // find where cycle begins
        fast = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
        
    } // 142
};
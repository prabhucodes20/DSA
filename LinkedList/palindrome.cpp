class Solution {

    public:
        // Helper function to reverse a linked list.
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            while (head) {
                ListNode* nextTemp = head->next; // Save the next node.
                head->next = prev;               // Reverse the link.
                prev = head;                     // Move prev to current node.
                head = nextTemp;                 // Move to next node.
            }
            return prev; // New head of the reversed list.
        }
    
        bool isPalindrome(ListNode* head) {
            if (!head || !head->next)
                return true; // List with 0 or 1 node is always a palindrome.
    
            // Use two pointers: slow and fast.
            // Move fast by 2 steps and slow by 1 step to find the middle.
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // Reverse the second half of the list starting after slow.
            ListNode* secondHalf = reverseList(slow->next);
    
            // Compare first half and reversed second half.
            ListNode* p1 = head;
            ListNode* p2 = secondHalf;
            bool palindrome = true;
            while (p2) { // Only need to check until end of second half.
                if (p1->val != p2->val) {
                    palindrome = false; // Values don't match, not a palindrome.
                    break;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
    
            // Restore the list to its original state by reversing the second half again.
            slow->next = reverseList(secondHalf);
    
            return palindrome;
        }
    };
    
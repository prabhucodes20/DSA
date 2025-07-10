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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            // Create a dummy node to simplify handling the head of the result list
            ListNode dummy;
            // 'curr' will point to the last node in the result list as we build it
            ListNode* curr = &dummy;
            // 'carry' stores carry-over value when sum of two digits >= 10
            int carry = 0;
    
            // Loop until both lists are fully processed, and also handle leftover carry
            while (l1 != NULL || l2 != NULL || carry != 0) {
                // Start with carry from previous iteration
                int sum = carry;
    
                // Add value from l1 if it exists, then move l1 forward
                if (l1 != NULL) {
                    sum += l1->val;
                    l1 = l1->next;
                }
    
                // Add value from l2 if it exists, then move l2 forward
                if (l2 != NULL) {
                    sum += l2->val;
                    l2 = l2->next;
                }
    
                // Update carry for next iteration (e.g., 15/10=1)
                carry = sum / 10;
    
                // Create new node with the digit part (e.g., 15%10=5) and attach to result
                curr->next = new ListNode(sum % 10);
    
                // Move curr to the newly created node
                curr = curr->next;
            }
    
            // Return head of the newly formed list (skipping dummy node)
            return dummy.next;
        }
    };

    

    // You add numbers digit by digit just like on paper, moving left to right.

    // The carry keeps track of overflow from previous sum.
    
    // The dummy node makes it easy to handle the head: you don't need a special case to initialize the result list.
    
    
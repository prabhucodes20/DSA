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
        ListNode* middleNode(ListNode* head) {
            int cnt=0;
            ListNode *temp=head;
            while(temp!=NULL){
                cnt++;
                temp=temp->next;
            }
            cnt/=2;
            while(cnt!=0){
                head=head->next;
                cnt--;
            }
            return head;
        }
    };




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
        ListNode* middleNode(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
    
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // when fast reaches end, slow is at middle
            return slow;
        }
    };
    
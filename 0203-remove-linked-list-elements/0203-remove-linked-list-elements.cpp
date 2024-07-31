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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return nullptr;
        if (head && !head->next && head->val!=val) return head;
        
        while (head && head->val==val) {
            head = head->next;
        }

        ListNode* curr = head;

        while (curr) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
                curr = curr->next;
            }
            else { 
                curr = curr->next;
            }
        }

        return head;
    }
};
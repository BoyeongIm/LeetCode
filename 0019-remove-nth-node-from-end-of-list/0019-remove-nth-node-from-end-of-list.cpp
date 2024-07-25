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
        if (!head->next) {
            delete head;
            return nullptr;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        if (n==1) {
            while (curr->next) {
                prev = curr;
                curr = curr->next;
            } prev->next = nullptr;
            delete curr;
            return head;
        } 
        
        int size = 1;
        while (curr->next) {
            prev = curr;
            curr = curr->next;
            size++;
        } 
        
        if (size == n) return head->next;

        ListNode* curr2 = head;
        ListNode* prev2 = nullptr;

        while (curr2->next) {
            prev2 = curr2;
            curr2 = curr2->next;
            size--;
            if (size == n) {
                prev2->next = curr2->next;
                delete curr2;
                break;
            }
        }

        return head;
    }
};
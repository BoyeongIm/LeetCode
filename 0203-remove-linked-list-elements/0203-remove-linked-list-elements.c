/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head==NULL) return NULL;
    if (head->next==NULL && head->val == val) return NULL;

    while (head && head->val == val) head = head->next;

    struct ListNode* curr = head;
    while (curr && curr->next) {
        if (curr->next->val != val) {
            curr = curr->next;
        }

        else {
            if (curr->next->next) curr->next = curr->next->next;
            else curr->next = NULL;
        }
    }
    return head;
}
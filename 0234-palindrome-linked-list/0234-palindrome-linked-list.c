/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head==NULL || head->next==NULL) return head;

    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head->next == NULL) return true;

    struct ListNode* reversed_head = reverseList(head);

    while (head && reversed_head) {
        if (head->val != reversed_head->val) {
            return false;
        }
        head = head->next;
        reversed_head = reversed_head->next;
    }

    return true;
}
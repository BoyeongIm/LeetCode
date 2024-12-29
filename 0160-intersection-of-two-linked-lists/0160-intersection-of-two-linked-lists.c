/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* la = headA;
    struct ListNode* lb = headB;
    int lenA = 0;
    int lenB = 0;
    while (la) {
        lenA++;
        la = la->next;
    }
    while (lb) {
        lenB++;
        lb = lb->next;
    }

    int diff = 0;
    if (lenA > lenB) {
        diff = lenA-lenB;
        struct ListNode* currA = headA;
        struct ListNode* currB = headB;
        while (diff > 0) {
            currA = currA->next;
            diff--;
        }

        while (currA && currB) {
            if (currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        } 
    }

    else {
        diff = lenB-lenA;
        struct ListNode* currA = headA;
        struct ListNode* currB = headB;
        while (diff > 0) {
            currB = currB->next;
            diff--;
        }

        while (currA && currB) {
            if (currA == currB) return currA;
            currA = currA->next;
            currB = currB->next;
        } 
    }

    return NULL;
}
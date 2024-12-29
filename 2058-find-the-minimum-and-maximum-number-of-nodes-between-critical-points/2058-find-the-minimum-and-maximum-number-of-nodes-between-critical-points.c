/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    *returnSize = 2;
    int* answer = (int*)malloc((*returnSize) * sizeof(int));
    int criticalPoints = 0;
    answer[0] = INT_MAX;
    answer[1] = INT_MIN;
    int first_cp = -1;
    int prev_cp = 0;
    int pos = 2;

    struct ListNode* prv = head;
    struct ListNode* curr = head->next;
    struct ListNode* nxt = head->next->next;
    while (nxt) {
        if ((prv->val < curr->val && curr->val > nxt->val) || (prv->val > curr->val && curr->val < nxt->val)) {
            criticalPoints++;
            if (first_cp < 0) {
                first_cp = pos;
            }
            else {
                if (pos-first_cp > answer[1]) answer[1] = pos - first_cp;
                if (pos-prev_cp < answer[0]) answer[0] = pos - prev_cp;
            }
            prev_cp = pos;
        }
        prv = curr;
        curr = nxt;
        nxt = nxt->next;
        pos++;
    }
    if (criticalPoints < 2) {
        answer[0] = -1;
        answer[1] = -1;
    }

    return answer;
}
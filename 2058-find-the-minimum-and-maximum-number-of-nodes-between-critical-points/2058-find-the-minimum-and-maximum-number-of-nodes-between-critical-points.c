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
    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    struct ListNode* nextt = head->next->next;
    int *ans = (int*) malloc(2*sizeof(int));
    *returnSize = 2;
    int criticalCount = 0;
    int first_cp = -1;
    int prev_cp = -1;
    int idx= 1;
    ans[0] = INT_MAX;
    ans[1] = INT_MIN;
    while (nextt) {
        if (((prev->val < curr->val) && (curr->val > nextt->val)) || 
            ((prev->val > curr->val) && (curr->val < nextt->val))) 
        {
            criticalCount++;
            if (first_cp==-1) first_cp = idx;
            else {
                if (idx - prev_cp < ans[0]) {
                    ans[0] = idx - prev_cp;
                }
                if (idx - first_cp > ans[1]) {
                    ans[1] = idx - first_cp;
                }
            }
            prev_cp = idx;
        }
            prev = curr;
            curr = nextt;
            nextt = nextt->next;
            idx ++;
    }

    if (criticalCount < 2) {
        ans[0] = -1;
        ans[1] = -1;
    }
    return ans;
}
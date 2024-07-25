/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        if (!head->next) return false;
        map<ListNode*, int> linked;
        ListNode* curr = head;
        while (curr->next) {
            if (linked.find(curr) == linked.end()) {
                linked[curr] = 1;
                curr = curr->next;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
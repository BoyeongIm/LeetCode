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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode* curr = head;
        vector<ListNode*> copied;

        while (curr) {
            ListNode* pushed = new ListNode(curr->val);
            copied.push_back(pushed);
            curr = curr->next;
        }

        ListNode* newhead = copied.back();
        copied.pop_back();
        ListNode* tmp = newhead;

        while (!copied.empty()) {
            ListNode* tmp_next = copied.back();
            copied.pop_back();
            tmp->next = tmp_next;
            tmp = tmp_next;
        }

        tmp->next = nullptr;

        return newhead;
    }
};
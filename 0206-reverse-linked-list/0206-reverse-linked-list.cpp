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
        if (!head) return nullptr;
        ListNode* curr = head;
        vector<ListNode*> copied;

        while (curr) {
            ListNode* pushed = new ListNode(curr->val);
            copied.push_back(pushed);
            curr = curr->next;
        }

        //ListNode* tmp = copied.back();
        //ListNode* curr = tmp;
        //copied.pop_back();

        for (int i=copied.size()-1; i>0; i--) {
            copied[i]->next = copied[i-1];
        }      
        return copied.back();
    }
};
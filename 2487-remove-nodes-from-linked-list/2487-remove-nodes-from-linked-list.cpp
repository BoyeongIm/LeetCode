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
    ListNode* removeNodes(ListNode* head) {
        if (!head) return nullptr;

        ListNode* curr = head;
        vector<ListNode*> nodestack;

        while (curr) {
            nodestack.push_back(curr);
            curr = curr->next;
        }

        for (int i=nodestack.size()-1; i>=0; i--) {
            if (i==0) {
                if (nodestack[i]->val < nodestack[i]->next->val) {
                    head = nodestack[i]->next;
                }
            }

            else if (i==1) {
                if (nodestack[i]->val < nodestack[i]->next->val) {
                    nodestack[i-1]->next = nodestack[i+1];
                }
            }
            else {
                ListNode* curr = nodestack[i];
                ListNode* prev = nodestack[i-1];
                if (curr->val > prev->val) {
                    nodestack[i-2]->next = curr;
                }
            }
        }

        return head;
    }
};
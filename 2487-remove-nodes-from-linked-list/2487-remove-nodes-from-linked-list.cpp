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
        if (!head->next) return head;

        ListNode* curr = head;
        vector<ListNode*> nodestack;

        while (curr) {
            nodestack.push_back(curr);
            curr = curr->next;
        }

        ListNode* maxnode = nodestack.back();
        for (int i=nodestack.size()-2; i>=0; i--) {
            if (maxnode->val <= nodestack[i]->val) {
                nodestack[i]->next = maxnode;
                maxnode = nodestack[i];
            }
            else if (maxnode->val > nodestack[i]->val){
                head = maxnode;
            }
        }

        return head;
    }
};
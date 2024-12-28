/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (!list1) return list2;
    else if (!list2) return list1;
    if (!list1) return list2;
    else if (!list2) return list1;
    
    struct ListNode* linking = list1;
    while (linking->next) {
        linking = linking->next;
    } linking->next = list2;
    
    struct ListNode* curr = list1;
    struct ListNode* temp = NULL;

    while (curr) {
        temp = curr->next;
        
        while (temp) 
            {
                if (curr->val > temp->val) {  // to decreasing order
                    int curr_val = curr->val; 
                    curr->val = temp->val;   
                    temp->val = curr_val;     
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
    
    return list1;
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* node = head;
    int size = 0;
    while (node) {
        size++;
        node = node->next;
    }

    if (size==1) return true;

    struct ListNode* temp = head;
    if (size%2 == 0) {
        int mid = size/2;
        int arr[size];
        for (int i=0; i<mid; i++) {
            arr[i] = temp->val;
            temp = temp->next;
        }
        for (int j=mid-1; j>=0; j--) {
            if (arr[j] != temp->val) return false;
            temp = temp->next;
        }
    }

    else if (size%2 == 1) {
        int mid = size/2;
        int arr[size];
        for (int i=0; i<mid; i++) {
            arr[i] = temp->val;
            temp = temp->next;
        }
        temp = temp->next;
        for (int j=mid-1; j>=0; j--) {
            if (arr[j]!=temp->val) return false;
            temp = temp->next;
        }
    }
    return true;
}
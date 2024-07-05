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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> criticalPoints;
        vector<int> result(2,-1);
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int idx = 0;
        while (curr && curr->next) {
            if (prev && curr->next) {
                if ((prev->val < curr->val && curr->val > curr->next->val) ||
                    (prev->val > curr->val && curr->val < curr->next->val)) {
                        criticalPoints.push_back(idx);
                }
            }
            prev = curr;
            curr = curr->next;
            idx++;
        }

        if (criticalPoints.size() < 2) {
            return result;
        }

        result[0] = INT_MAX;  
        result[1] = criticalPoints.back() - criticalPoints.front(); // 값 계산하려면 front/back 사용
        for (size_t i=1; i<criticalPoints.size(); i++) {  // 마지막 인덱스에 도달하면 i+1이 안먹히니까 i=1부터 시작해서 i - (i-1) 로 하기
            int minDist = criticalPoints[i] - criticalPoints[i-1];
            if (minDist < result[0]) {
                result[0] = minDist;
            }
        }
        return result; 
    }
};
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
        
        ListNode *prev = head;
        if(!prev->next) {
            return {-1, -1};
        }
        
        ListNode *mid  = prev->next; 
        if(!mid->next) {
            return {-1, -1};
        }
        
        ListNode *nxt  = mid->next; 
        int index = 1;
        vector<int> res;
        int mn = 1e9;
        while(nxt) {
            int x = prev->val;
            int y = mid->val;
            int z = nxt->val;
            if((y > x and y > z) or (y < x and y < z)) {
                if(res.size()) {
                    mn = min(mn, index - res.back());
                }
                res.push_back(index);
            }
            
            index++;
            prev = mid;
            mid = nxt;
            nxt = nxt->next;
        }
        
        if(mn == 1e9)
            return {-1, -1};
        
        return {mn, res.back() - res.front()};
    }
};
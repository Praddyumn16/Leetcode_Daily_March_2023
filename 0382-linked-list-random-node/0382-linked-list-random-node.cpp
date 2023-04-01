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
    int n = 0;
    ListNode* headnode;

    Solution(ListNode* head) {
        auto temp = head;
        headnode = head;
        while(temp) n++ , temp = temp->next;    
    }
    
    int getRandom() {
        int num = rand() % n;
        auto temp = headnode;
        while(num--)
            temp = temp->next;
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
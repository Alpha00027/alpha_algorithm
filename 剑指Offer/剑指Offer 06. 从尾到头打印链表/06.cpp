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
    vector<int> reversePrint(ListNode* head) {
        vector<int> value;
        ListNode* node = head;
        while(node != nullptr)
        {
            value.push_back(node->val);
            node = node->next;
        }
        vector<int> out(value.size(),0);
        for(int i = 0;i < value.size();i++)
        {
            out[i] = value[value.size()-1-i];
        }
        return out;
    }
};
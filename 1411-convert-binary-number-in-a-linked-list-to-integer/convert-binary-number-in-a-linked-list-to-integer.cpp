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
    int getDecimalValue(ListNode* head) {
        vector<int> v;
        int count = 0;
        while(head){
            int value = head->val;
            v.push_back(value);
            count+=1;
            head = head->next;
        }

        long long int num = 0;

        for (int i=count-1; i>=0; i-=1){
            num+=(v[i]*pow(2, count-1-i));
        }

        return num;
    }
};
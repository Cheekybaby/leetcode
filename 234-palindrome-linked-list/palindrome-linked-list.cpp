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
    bool checkPalindrome(vector<int> &v){
        for (int i=0; i<v.size()/2; i+=1){
            if (v[i] != v[v.size()-i-1]) return false;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr) return true;

        vector<int> v;
        while (head!=nullptr){
            v.push_back(head->val);
            head = head->next;
        }

        return checkPalindrome(v);
    }
};
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
    bool isAPalindrome(vector<int> &v){
        if (v.size() == 1) return true;

        int i=0, j = v.size()-1;

        while (i<=j){
            if (v[i] != v[j]){
                return false;
            }
            i+=1;
            j-=1;
        }

        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> v;

        ListNode *temp = head;

        while (temp != nullptr){
            v.push_back(temp->val);
            temp = temp->next;
        }

        return isAPalindrome(v);
    }
};
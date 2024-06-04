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
    int size;
    ListNode* mid;

    int get_size(ListNode* head) {
        int size{};
        while(head) {
            size++;
            head = head->next;
        }
        return size;
    }
    
    bool rec(ListNode* cur, int i) {
        if(i == size/2) {
            if(size&1)
                mid = cur->next;
            else
                mid = cur;
            return true;
        }
        
        bool is_palindrome = rec(cur->next, i+1);
        
        if(cur->val != mid->val)
            is_palindrome = false;

        mid = mid->next;

        return is_palindrome;
    }


    bool isPalindrome(ListNode* head) {
        if(!head->next) 
            return true;

        size = get_size(head);

        return rec(head, 0);
    }
};

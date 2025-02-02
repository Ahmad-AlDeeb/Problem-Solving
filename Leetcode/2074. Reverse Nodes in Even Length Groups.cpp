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
    int getSize(ListNode* head) {
        int size{};
        ListNode* cur = head;
        while(cur) {
            size++;
            cur = cur->next;
        }
        return size;
    }
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int listSize = getSize(head);
        
        ListNode* cur = head;
        ListNode* prev = nullptr;

        for(int num{1}; cur; ++num) {
            int groupSize = min(listSize, num);
            listSize -= num;
            
            if(groupSize % 2) {
                while(cur && groupSize--) {
                    prev = cur;
                    cur = cur->next;
                }
            }
            else {
                ListNode* groupHead = cur;
                ListNode* groupPrev = nullptr;

                while(cur && groupSize--) {
                    ListNode* next = cur->next;
                    cur->next = groupPrev;
                    groupPrev = cur;
                    cur = next;
                }

                groupHead->next = cur;
                prev->next = groupPrev;
                prev = groupHead;
            }
        }

        return head;
    }
};

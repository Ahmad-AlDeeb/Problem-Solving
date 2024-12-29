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
    vector<ListNode*> getVecNode(ListNode* head) {
        vector<ListNode*> vecNode;
        
        ListNode* current = head;
        while(current) {
            vecNode.push_back(current);
            current = current->next;
        }

        return vecNode;
    }

public:
    void reorderList(ListNode* head) {
        vector<ListNode*> vecNode = getVecNode(head);
        int size = vecNode.size();

        vector<ListNode*> reorderVecNode(size);

        for(int left{}, right{size - 1}, i{}; left <= right; left++, right--, i += 2) {
            if(left == right) {
                reorderVecNode[i] = vecNode[left];
            }
            else {
                reorderVecNode[i] = vecNode[left];
                reorderVecNode[i+1] = vecNode[right];
            }
        }

        for(int i{}; i < size - 1; ++i) {
            cout << i << endl;
            reorderVecNode[i]->next = reorderVecNode[i + 1]; 
        }
        reorderVecNode[size - 1]->next = nullptr;
    }
};

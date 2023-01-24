/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = head;
        ListNode *prev = dummy;
        int i = 1;

        while(current!=NULL){
            if(i%k==0){
                prev = reverse(prev,current->next);
                current = prev -> next;
            }else{
                current = current -> next;
            }
            i++;    
        }
        return dummy->next;
    }

    ListNode *reverse(ListNode *prev,ListNode *end){
        ListNode *last = prev -> next;
        ListNode *temp = last -> next;

        while(temp != end){
            last -> next = temp -> next;
            temp -> next = prev -> next;
            prev -> next = temp;
            temp = last -> next;
        }
        return last;
    }
};
// @lc code=end


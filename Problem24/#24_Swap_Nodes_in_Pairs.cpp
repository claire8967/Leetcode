class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy;
        while(current->next!=NULL && current->next->next!=NULL){
            swap(current);
            current = current->next->next;
        }
        return dummy->next;
        
    }
    void swap(ListNode* current){
        ListNode *t1 = current->next;
        ListNode *t2 = t1->next;
        t1->next = t2->next;
        t2->next = current->next;
        current->next = t2;
    }
};
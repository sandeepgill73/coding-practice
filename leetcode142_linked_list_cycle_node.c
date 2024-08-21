LeetCode 142. Linked List Cycle II 
- Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode *detectCycle(struct ListNode *head) {
    if(!head || !head->next) return NULL;
    struct ListNode *slow = head, *fast = head;
    
    while(fast && fast->next) {
        //slow moves 1 step at a time, fast moves 2 steps at a time.
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break; //when slow and fast meet each other, they must be on the cycle
    }
    
    if(!fast || !fast->next) return NULL;
    
    //so if head and slow start to move at the same time, they will meet at the start of the cycle
    while(head != slow) {
        slow = slow->next;
        head = head->next;
    }
        
    return head;
}

// LeetCode 203. Remove Linked List Elements
// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // 'temp' node serves as a dummy head node to simplify edge cases, especially when the head node itself needs to be removed.
    struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    // next of 'temp' is set to head, effectively inserting the dummy node before the actual head of the list.
    temp->next = head;
    struct ListNode *curr = temp; // 'curr' is a reference that initially points to the same dummy node.
    while(curr->next != NULL) { // loop continues as long as the next node after 'curr' is not null.
        if (curr->next->val == val) {
            curr->next = curr->next->next;
        }
        else {
            curr = curr->next;
        }
    }

    // Since 'temp' is the dummy head node, temp.next is the actual head of the modified list.
    return temp->next; 
}

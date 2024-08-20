/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /*
237. Delete Node in a Linked List
 There is a singly-linked list head and we want to delete a node node in it.
 You are given the node to be deleted. You will not be given access to the first node of head.
 All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
 Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
 */
void deleteNode(struct ListNode* node) {
    
    struct ListNode* nextNode = node->next;
    // Copy the value of the next node to the current node.
    node->val = nextNode->val; 
    // Adjust the next pointer to skip the next node.
    node->next = nextNode->next;
    //free(nextNode)

    // Time complexity O(1) and Space complexity O(n)
}

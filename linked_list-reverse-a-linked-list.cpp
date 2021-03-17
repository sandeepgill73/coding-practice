/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Reverse(Node *head)
{
/* 
   Time Complexity : O(n)
   Space Complexity: O(1)
*/
    if(head != NULL)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *next = NULL;
        
        /* change next to prev, prev to current and current to next */
        while(curr != NULL)
        {
            // Before changing next of current, store next node
            next  = curr->next;  
            // Now change next of current. This is where actual reversing happens
            curr->next = prev;   
            // Move prev and curr one step forward
            prev = curr;
            curr = next;
        }
        
        head = prev;
    }
    
    return head;
}

/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/

/* swap prev and next pointers for all nodes, 
change prev of the head (or start) and 
change the head pointer in the end.*/
Node* Reverse(Node* head)
{
    Node *temp = NULL;  
    Node *current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;              
        current = current->prev;
    }      
    
    if(temp != NULL)
    {
        head = temp->prev;
    }

    return head;
}
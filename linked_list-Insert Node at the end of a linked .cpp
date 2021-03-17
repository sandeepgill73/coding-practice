/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
    Node *new_tail = new Node(); 
    new_tail->data = data;
    new_tail->next = NULL;
    
    if(head == NULL)
    {
        head = new_tail;
    }
    else
    {
        Node *curr_head = head;
        while(curr_head->next != NULL)
        {
            curr_head = curr_head->next;
        }
        curr_head->next = new_tail;
    }
    
    return head;
}
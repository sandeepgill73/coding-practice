/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
    Node *new_pos = new Node(); 
    new_pos->data = data;
    new_pos->next = NULL;

    if(head == NULL)
    {
        return new_pos;
    }
    else if (position == 0)
    {
        new_pos->next = head;
        return new_pos;
    }
    else
    {
        Node *curr_head = head;
            
        while((position - 1 > 0) && 
              (curr_head->next != NULL))
        {
            curr_head = curr_head->next;
            position--;
        }

        new_pos->next = curr_head->next;
        curr_head->next = new_pos;
    }
    
    return head;  
}

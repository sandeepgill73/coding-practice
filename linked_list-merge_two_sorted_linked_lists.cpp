/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
    Node *Merge = new Node();
    Merge->data = 0;
    Merge->next = NULL;
    Node *prev = Merge;
    
    // while both linked lists are not empty
    while((headA != NULL) && (headB != NULL))
    {
        if(headA->data <= headB->data)
        {
            prev->next = headA;
            headA = headA->next;
        }
        else
        {
            prev->next = headB;
            headB = headB->next;
        }

        prev = prev->next;
    }
    
    // once we reach end of a linked list, append the other 
    // list because we know it is already sorted
    if (headA == NULL)
    {
        prev->next = headB;
    }
    else if (headB == NULL)
    {
        prev->next = headA;
    }
    else
    {     
    }
    
    return Merge->next;
   
}
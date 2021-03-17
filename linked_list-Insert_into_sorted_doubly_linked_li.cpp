/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    Node *newNode = new Node();
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = data;
    
    if (head == NULL)
    {
        return newNode;
    }
    else if (data < head->data) 
    { 
        // insert in front of list
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    else
    {
        Node *prevNode = NULL;
        Node *currNode = head;
        
        /* Walk list with 2 pointers */
        while (currNode != NULL && currNode->data < data) 
        {
            prevNode = currNode;
            currNode = currNode->next;
        }
        
        if (currNode == NULL) 
        { 
            // insert at end of list
            prevNode->next = newNode;
            newNode->prev = prevNode;
        } 
        else 
        { 
            // insert in sorted list
            prevNode->next = newNode;
            currNode->prev = newNode;
            
            newNode->prev = prevNode;
            newNode->next = currNode;
        }
        
        return head;
    }
}
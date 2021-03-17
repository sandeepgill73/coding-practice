/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
    if(head == NULL)
    {
        return 0;
    }
    else
    {
        Node *curr_head = head;
        int elements = 0;
        
        // loop to get number of elements in linked list
        while(curr_head != NULL)
        {
            curr_head = curr_head->next;
            elements++;
        }
        
        if(elements > 0)
        {
            int data_arr[elements];
            int i = 0;
            curr_head = head;

            // loop to store data into array
            while(curr_head != NULL)
            {
                data_arr[i] = curr_head->data;
                curr_head = curr_head->next;
                i++;
            }
            
            return data_arr[elements - positionFromTail - 1];
        }
    }
    
    return 0;
}

int GetNode(Node *head,int positionFromTail)
{
    /* To get the nth node from the tail of the linked list, 
       we can calculate the length of the entire list by traversing the list once. 
       Let this length be l. nth node from the tail is the (l-n-1)th node from the start 
      (everything is 0-based) Or we can use two pointers. 
      We can increment one of these to point to the nth node from the start and then 
      increment both of these simultaneously till the first node reaches the end of the list. 
      The second node points to the nth node from the tail. 
      Time Complexity: O(N)
    */
    
    Node *ptr1 = head;
    Node *ptr2 = head;
    int count = 0;
    
    while((ptr1 != NULL) && (count < positionFromTail))
    {
        //Increment ptr1 till it points to Nth node from the head
        ptr1 = ptr1->next;
        count++;
    }
    
    while(ptr1->next != NULL)
    {
        //Increment ptr1 till it points to Nth node from the head
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    //ptr2 points to the Nth node from the tail
    return ptr2->data; 
}
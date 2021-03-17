/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

void ReversePrint(Node *head)
{
    // Using recursion 
    Node *first_head = head;
    
    if(head != NULL)
    {
        ReversePrint(head->next);
        cout<<head->data<<endl;
    }
    else
    {
        return;
    }
}


void ReversePrint(Node *head)
{
    // Without recursion 
    if(head == NULL)
    {
        return;
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

            for (int j = elements - 1; j >= 0; j--)
            {
                cout<<data_arr[j]<<endl;
            }
        }
    }
}


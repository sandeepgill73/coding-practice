/*
Detect a cycle in a linked list. 
Note that the head pointer may be 'NULL' if the list is empty.
*/

struct Node 
{
    int data;
    struct Node* next;
}

bool has_cycle(Node* head) 
{
    // Complete this function
    // Do not write the main method
    if (head == NULL) return false;
    
    Node* present = head;
    Node* future = head->next;
    while (present != future) 
    {
        if (future == NULL || future->next == NULL) return false;
        
        present = present->next;
        future = future->next->next;
    }
    
    return true;
}

/*
To solve this problem, we must traverse the list using two pointers that we'll refer to as slow and fast.
Our slow pointer moves forward 1 node at a time, and our fast pointer moves forward 2 nodes at a time
If at any point in time these pointers refer to the same object, then there is a loop; 
otherwise, the list does not contain a loop. 
*/

bool has_cycle(Node* head) 
{
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && slow != NULL && fast->next) 
	{
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) 
		{
            return 1;
        }
    }
    
    return 0;
}
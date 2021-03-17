/*
Delete Node at a given position in a linked list
Node is defined as
struct Node
{
int data;
struct Node *next;
}
*/
Node* Delete(Node *head, int position)
{
	if (position == 0)
	{
		head = head->next;
	}
	else
	{
		Node *curr_head = head;
		while ((position - 1 > 0) &&
			(curr_head != NULL))
		{
			curr_head = curr_head->next;
			position--;
		}

		curr_head->next = curr_head->next->next;
	}

	return head;
}
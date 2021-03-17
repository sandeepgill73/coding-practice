// http://stackoverflow.com/questions/1801549/reverse-a-singly-linked-list

#include <stdio.h>
#include <assert.h>

typedef struct node Node;
struct node {
    int data;
    Node *next;
};

void spec_reverse();
Node *reverse(Node *head);

int main()
{
    spec_reverse();
    return 0;
}

void print(Node *head) {
    while (head) {
        printf("[%d]->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void spec_reverse() {
    // Create a linked list.
    // [0]->[1]->[2]->NULL
    Node node2 = {2, NULL};
    Node node1 = {1, &node2};
    Node node0 = {0, &node1};
    Node *head = &node0;

    print(head);
    head = reverse(head);
    print(head);

    assert(head == &node2);
    assert(head->next == &node1);
    assert(head->next->next == &node0);

    printf("Passed!");
}

// Step 1:
//
// prev head  next
//   |    |    |
//   v    v    v
// NULL  [0]->[1]->[2]->NULL
//
// Step 2:
//
//      prev head  next
//        |    |    |
//        v    v    v
// NULL<-[0]  [1]->[2]->NULL
//
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *next;

    while (head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

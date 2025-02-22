/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL){ // covers the case of an empty linked list
        return head;
    }
    if(head->next == NULL){ //returns the linked list from the back once it reaches the final node
        return head; 
    }
    struct ListNode *new = reverseList(head->next); //recursive function call that has the last node has the head of the "new" linked list.

    // Note: I say "new" linked list, but we're only changing the pointer direction of the already existing linked list.
  // 
    head->next->next = head; // updates next pointer of current node with head
    head->next = NULL; // goes back to the statement on line 12 to return the REMAINING part of the "new" linked list. Allows our recursion to function.

    return new; // returns our "new" linked list starting from what was previously the final node.


}

// Passed all cases

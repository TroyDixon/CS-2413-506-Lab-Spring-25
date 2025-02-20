/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *p = head;    //initialize 2 traversion nodes to the head
    struct ListNode *prev = head; // prev will follow our p node
    
    if(head!= NULL){ // "Is there stuff in the linked list "
        while(p->next!=NULL){ //standard traversion
            if(p->next->val==val){ // "is node p on the value?"
                p->next = p->next->next; /* pointer assignment skips the node with the value we're looking for, effectively deleting it */
            }else{
                p=p->next; //if p isn't on the value we can advance traversion
            }
        }
        if(prev->val == val){ //covers case that target value is at head
            prev=prev->next; //skips the node simulating deletion
        }
    }
    return prev; //return our output
}

//Passed all cases

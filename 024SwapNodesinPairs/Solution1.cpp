class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode **newHead = &head;
        ListNode **n1 = &head;
        ListNode **n2 = &head->next;
        while (*n1 != NULL && *n2 != NULL)
        {
            ListNode *temp = *n1;
            *n1 = *n2;

            ListNode *temp2 = (*n2)->next;
            (*n2)->next = temp;

            *n2 = temp2;

            n1 = n2;
            if (*n2 == NULL || (*n2)->next == NULL)
                break;
            else
                n2 = &((*n2)->next);
        }
        return *newHead;
    }
};
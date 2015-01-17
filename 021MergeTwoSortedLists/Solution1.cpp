/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head = NULL;
        ListNode **tail = &head;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                *tail = l1;
                tail = &((*tail)->next);
                l1 = l1->next;
            }
            else
            {
                *tail = l2;
                tail = &((*tail)->next);
                l2 = l2->next;
            }
        }
        *tail = l1 != NULL ? l1 : l2;
        return head;
    }
};

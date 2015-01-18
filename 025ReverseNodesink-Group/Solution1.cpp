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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int count = 0;
        stack<ListNode *> s;
        ListNode *l = head;
        while (l != NULL && count < k)
        {
            s.push(l);
            count++;
            l = l->next;
        }
        if (count < k)
            return head;
        ListNode **newHead = &head;
        ListNode **tail = &head;
        while (!s.empty())
        {
            *tail = s.top();
            s.pop();
            tail = &((*tail)->next);
        }
        *tail = reverseKGroup(l, k);
        return *newHead;
    }
};
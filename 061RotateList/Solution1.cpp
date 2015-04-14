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
    ListNode *rotateRight(ListNode *head, int k)
    {
        int size = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            size++;
        }
        if (size == 0)
            return head;
        k %= size;
        if (k == 0)
            return head;
        queue<int> q;
        while (head != NULL)
        {
            q.push(head->val);
            ListNode *temp = head;
            head = head->next;
            delete temp;    // It is quite ugly because the memory might not be in the heap
        }
        queue<int> right;
        while (q.size() > k)
        {
            right.push(q.front());
            q.pop();
        }
        ListNode *newHead = NULL;
        bool newHeadSet = false;
        ListNode *previous = NULL;
        while (!q.empty())
        {
            ListNode *temp = new ListNode(q.front());
            q.pop();
            if (newHead == NULL)
            {
                newHead = temp;
                previous = temp;
            }
            else
            {
                previous->next = temp;
                previous = previous->next;
            }
        }
        while (!right.empty())
        {
            ListNode *temp = new ListNode(right.front());
            right.pop();
            if (newHead == NULL)
            {
                newHead = temp;
                previous = temp;
            }
            else
            {
                previous->next = temp;
                previous = previous->next;
            }
        }
        return newHead;
    }
};

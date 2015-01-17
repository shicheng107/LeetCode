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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        map<int, int> m;
        for (auto l : lists)
        {
            while (l != NULL)
            {
                m[l->val]++;
                l = l->next;
            }
        }
        ListNode *head = NULL;
        ListNode *tail = NULL;
        for (auto p : m)
        {
            for (int i = 0; i < p.second; i++)
            {
                ListNode *node = new ListNode(p.first);
                if (head == NULL)
                    head = node;
                if (tail == NULL)
                    tail = node;
                else
                {
                    tail->next = node;
                    tail = tail->next;
                }
            }
        }
        return head;
    }
};

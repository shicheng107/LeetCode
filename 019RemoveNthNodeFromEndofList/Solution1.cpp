/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

#include <queue>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        queue<ListNode **> q;
        ListNode **p = &head;
        while (*p != NULL)
        {
            q.push(p);
            if (q.size() > n)
                q.pop();
            p = &((*p)->next);
        }

        ListNode **nth = q.front();
        *nth = (*nth)->next;
        return head;
    }
};


int main(int argc, const char** argv)
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode *newHead = s.removeNthFromEnd(head, 1);
    while (newHead != NULL)
    {
        cout << newHead->val << endl;
        newHead = newHead->next;
    }
    cout << "done" << endl;
    cin.get();
    return 0;
}

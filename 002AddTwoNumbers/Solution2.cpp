/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

// Time complexity: O(n+m).
// Space complexity: O(n+m).
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(const ListNode *l1, const ListNode *l2)
    {
        ListNode *l3 = NULL;
        ListNode *previous = NULL;
        uint32_t add = 0;
        while (l1 != NULL || l2 != NULL)
        {
            uint32_t n = 0;
            if (l1 != NULL)
            {
                n += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                n += l2->val;
                l2 = l2->next;
            }
            n += add;
            add = n / 10;
            n %= 10;

            ListNode *newNode = new ListNode(n);
            if (l3 == NULL)
                l3 = newNode;
            if (previous != NULL)
                previous->next = newNode;
            previous = newNode;
        }
        if (add > 0)
        {
            ListNode *newNode = new ListNode(add);
            if (previous != NULL)
                previous->next = newNode;
        }

        return l3;
    }

    ListNode *BuildList(const vector<uint32_t> n)
    {
        ListNode *l = NULL;
        for (auto it = n.rbegin(); it != n.rend(); ++it)
        {
            ListNode *newNode = new ListNode(*it);
            newNode->next = l;
            l = newNode;
        }
        return l;
    }

    void PrintList(const ListNode *l)
    {
        while (l != NULL)
        {
            cout << l->val;
            if (l->next != NULL)
                cout << "->";
            l = l->next;
        }
        cout << endl;
    }

    void DeleteList(ListNode *l)
    {
        while (l != NULL)
        {
            ListNode *temp = l;
            l = l->next;
            delete temp;
        }
    }
};

int main(int argc, const char** argv)
{
    Solution s;
    ListNode *l1 = s.BuildList(vector<uint32_t>({ 2, 4, 3, 5 }));
    ListNode *l2 = s.BuildList(vector<uint32_t>({ 5, 6, 9 }));
    s.PrintList(l1);
    s.PrintList(l2);

    ListNode *l3 = s.addTwoNumbers(l1, l2);
    s.PrintList(l3);

    s.DeleteList(l1);
    s.DeleteList(l2);
    s.DeleteList(l3);

    cin.get();
    return 0;
}

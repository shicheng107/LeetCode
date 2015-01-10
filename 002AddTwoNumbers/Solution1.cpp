/**
* Cheng Shi, shicheng107@hotmail.com
*/

#include <iostream>
#include <stdint.h>
using namespace std;

// Time complexity: O(n+m).
// Space complexity: O(n+m).
// This solution is my first solution because I did not notice that
// the digits are stored in reverse order.
// But this solution cannot deal with digit count more than 20 and runs slower
// than solution 2.
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
        return Number2List(List2Number(l1) + List2Number(l2));
    }

private:
    uint64_t List2Number(const ListNode *l)
    {
        uint64_t n = 0;
        uint64_t factor = 1;
        while (l != NULL)
        {
            n += factor * l->val;
            l = l->next;
            factor *= 10;
        }
        return n;
    }

    // Every node in the return list should be deleted after use.
    ListNode *Number2List(uint64_t n)
    {
        ListNode *l = NULL;
        ListNode *previous = NULL;
        while (n > 0)
        {
            ListNode *newNode = new ListNode(n % 10);
            if (l == NULL)
                l = newNode;
            if (previous != NULL)
                previous->next = newNode;
            previous = newNode;
            n /= 10;
        }
        if (l == NULL)
            l = new ListNode(0);
        return l;
    }

public:
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
    ListNode *l1 = s.BuildList(vector<uint32_t>(1, 9));
    ListNode *l2 = s.BuildList(vector<uint32_t>({ 1, 9, 9, 9, 9, 9, 9, 9, 9, 9 }));
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

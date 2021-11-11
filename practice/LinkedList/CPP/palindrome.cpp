#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *midnode(ListNode *head)
{
    if (head->next == NULL or head == NULL)
        return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *reverse(ListNode *head)
{
    if (head == NULL or head->next == NULL)
        return head;
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return head;
}

bool isPalindrome(ListNode *head)
{
    if (head == NULL or head->next == NULL)
        return true;
    ListNode *mid = midnode(head);
    ListNode *newhead = mid->next;
    mid->next = NULL;
    newhead = reverse(newhead);
    ListNode *curr1 = head;
    ListNode *curr2 = newhead;
    while (curr1 != NULL and curr2 != NULL)
    {
        if (curr1->val != curr2->val)
            return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    cout << (boolalpha) << isPalindrome(dummy->next) << endl;

    return 0;
}
                        
                        
                                
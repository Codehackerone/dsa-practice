#include <iostream>
#include<bits/stdc++.h>
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

ListNode *midNode(ListNode *head)
{
    int len = 0;
    ListNode* temp=head;
    while(head->next != nullptr){
        len++;        
        head=head->next;
    }
    if(len < 1){
        return head;
    }
    else{
        int mid = len/2;
        for(int i=0;i<mid;i++){
            temp=temp->next;
        }
        return temp;
    }
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

    ListNode *head = midNode(dummy->next);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
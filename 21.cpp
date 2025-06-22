#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *create_list(vector<int> &arr)
{

    ListNode *head = new ListNode();
    if (arr.size() == 0)
        return nullptr;

    head->val = arr[0];
    ListNode *follower = head;

    for (int i = 1; i < arr.size(); i++)
    {
        follower->next = new ListNode(arr[i]);
        follower = follower->next;
    }

    return head;
}

void print_list(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head = new ListNode();
    ListNode *follower = head;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val <= list2->val)
        {
            follower->next = list1;
            list1 = list1->next;
        }
        else
        {
            follower->next = list2;
            list2 = list2->next;
        }
        follower = follower->next;
    }

    while (list1 != nullptr)
    {
        follower->next = list1;
        list1 = list1->next;
        follower = follower->next;
    }

    while (list2 != nullptr)
    {
        follower->next = list2;
        list2 = list2->next;
        follower = follower->next;
    }

    follower = head;
    head = head->next;
    delete follower;
    return head;
}

int main()
{
    vector<int> arr1{};
    vector<int> arr2{};

    ListNode *head1 = create_list(arr1);
    ListNode *head2 = create_list(arr2);

    ListNode *head = mergeTwoLists(head1, head2);
    print_list(head);

    return 0;
}

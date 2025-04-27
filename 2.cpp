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

ListNode *createNumber(string number)
{
    ListNode *head = nullptr;

    for (auto x : number)
    {
        int num = x - '0';
        ListNode *newHead = new ListNode();
        newHead->val = num;
        newHead->next = head;
        head = newHead;
    }

    return head;
}

void printNumber(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

string getNumber(ListNode *head)
{
    string number = "";
    while (head != nullptr)
    {
        char valInChar = char(head->val) + '0';
        number = valInChar + number;
        head = head->next;
    }
    return number;
}

string addNumbers(ListNode *num1Head, ListNode *num2Head)
{
    string result = "";

    int carry = 0;
    while (num1Head != nullptr && num2Head != nullptr)
    {
        int addResult = num1Head->val + num2Head->val + carry;

        carry = addResult >= 10;    // if greater than 10, carry is 1
        addResult = addResult % 10; // if greater than 10, then reduce to 1 int

        char valInChar = addResult + '0';
        result = valInChar + result;

        num1Head = num1Head->next;
        num2Head = num2Head->next;
    }

    // reduce the other numbers that are remaining
    {
        while (num1Head != nullptr)
        {
            int addResult = num1Head->val + carry;

            carry = addResult >= 10;
            addResult = addResult % 10;

            char valInChar = addResult + '0';
            result = valInChar + result;

            num1Head = num1Head->next;
        }

        while (num2Head != nullptr)
        {
            int addResult = num2Head->val + carry;

            carry = addResult >= 10;
            addResult = addResult % 10;

            char valInChar = addResult + '0';
            result = valInChar + result;

            num2Head = num2Head->next;
        }
    }

    // if carry remaining
    if (carry == 1)
        result = '1' + result;

    return result;
}

int main()
{
    ListNode *num1 = createNumber("9");
    ListNode *num2 = createNumber("99999999991");

    cout << "Num 1: " << getNumber(num1) << endl;
    cout << "Num 2: " << getNumber(num2) << endl;

    ListNode *addR = createNumber(addNumbers(num1, num2));

    cout << "Add result: " << getNumber(addR) << endl;

    return 0;
}

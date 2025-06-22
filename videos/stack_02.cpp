#include <bits/stdc++.h>

using namespace std;

vector<int> ngr(vector<int> &arr)
{
    stack<int> s;
    vector<int> ngrs;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        if (s.empty())
            ngrs.push_back(-1);
        else
            ngrs.push_back(s.top());

        s.push(arr[i]);
    }

    reverse(ngrs.begin(), ngrs.end());
    return ngrs;
}

vector<int> ngl(vector<int> &arr)
{
    stack<int> s;
    vector<int> ngls;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        if (s.empty())
            ngls.push_back(-1);
        else
            ngls.push_back(s.top());

        s.push(arr[i]);
    }

    return ngls;
}

vector<int> nsr(vector<int> &arr)
{
    stack<int> s;
    vector<int> nsrs;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() >= arr[i])
            s.pop();

        if (s.empty())
            nsrs.push_back(-1);
        else
            nsrs.push_back(s.top());

        s.push(arr[i]);
    }

    reverse(nsrs.begin(), nsrs.end());
    return nsrs;
}

vector<int> nsl(vector<int> &arr)
{
    stack<int> s;
    vector<int> nsls;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && s.top() >= arr[i])
            s.pop();

        if (s.empty())
            nsls.push_back(-1);
        else
            nsls.push_back(s.top());

        s.push(arr[i]);
    }

    return nsls;
}

int main()
{
    vector<int> arr{1, 3, 2, 4};

    for (auto x : ngr(arr))
        cout << x << " ";
    cout << endl;

    for (auto x : ngl(arr))
        cout << x << " ";
    cout << endl;

    for (auto x : nsr(arr))
        cout << x << " ";
    cout << endl;

    for (auto x : nsl(arr))
        cout << x << " ";
    cout << endl;
}
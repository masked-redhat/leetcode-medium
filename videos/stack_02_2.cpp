#include <bits/stdc++.h>

using namespace std;

vector<int> ngr(vector<int> &arr)
{
    vector<int> res;
    stack<int> s;
    int arrSize = arr.size();

    for (int i = arrSize - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        if (s.empty())
            res.push_back(-1);
        else
            res.push_back(s.top());

        s.push(arr[i]);
    }

    reverse(res.begin(), res.end());
    return res;
}

vector<int> ngl(vector<int> &arr)
{
    vector<int> res;
    stack<int> s;
    int arrSize = arr.size();

    for (int i = 0; i <= arrSize - 1; i++)
    {
        while (!s.empty() && s.top() <= arr[i])
            s.pop();

        if (s.empty())
            res.push_back(-1);
        else
            res.push_back(s.top());

        s.push(arr[i]);
    }

    return res;
}

vector<int> nsr(vector<int> &arr)
{
    vector<int> res;
    stack<int> s;
    int arrSize = arr.size();

    for (int i = arrSize - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() >= arr[i])
            s.pop();

        if (s.empty())
            res.push_back(-1);
        else
            res.push_back(s.top());

        s.push(arr[i]);
    }

    reverse(res.begin(), res.end());
    return res;
}

vector<int> nsl(vector<int> &arr)
{
    vector<int> res;
    stack<int> s;
    int arrSize = arr.size();

    for (int i = 0; i <= arrSize - 1; i++)
    {
        while (!s.empty() && s.top() >= arr[i])
            s.pop();

        if (s.empty())
            res.push_back(-1);
        else
            res.push_back(s.top());

        s.push(arr[i]);
    }

    return res;
}

int main()
{
    vector<int> arr{100, 60, 80, 50, 60, 70, 60, 75, 85};

    cout << "NGR : ";
    for (auto x : ngr(arr))
        cout << x << " ";
    cout << endl;

    cout << "NGL : ";
    for (auto x : ngl(arr))
        cout << x << " ";
    cout << endl;

    cout << "NSR : ";
    for (auto x : nsr(arr))
        cout << x << " ";
    cout << endl;

    cout << "NSL : ";
    for (auto x : nsl(arr))
        cout << x << " ";
    cout << endl;

    return 0;
}

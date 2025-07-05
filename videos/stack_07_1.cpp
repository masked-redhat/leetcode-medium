#include <bits/stdc++.h>

using namespace std;

int mah(vector<int> &arr)
{
    int maxArea = 0;

    vector<int> nsr, nsl;
    stack<int> s;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (s.empty())
            nsr.push_back(arr.size() - 1);
        else
            nsr.push_back(s.top() - 1);

        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();

        if (s.empty())
            nsl.push_back(0);
        else
            nsl.push_back(s.top() + 1);

        s.push(i);
    }

    reverse(nsr.begin(), nsr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        int area = (nsr[i] - nsl[i] + 1) * arr[i];
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main()
{
    vector<int> arr{6, 2, 5, 4, 5, 1, 6, 6, 6};

    cout << "MAH : " << mah(arr) << endl;

    return 0;
}

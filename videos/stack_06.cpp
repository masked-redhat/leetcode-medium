// Stock span problem

// Arr: [1,2,3,4,5,6,7]
// Output: [1, 2, 3, 4, 5, 6, 7]
// Why: previous consecutive smaller and equal how many

// Arr: [100, 80, 60, 70, 60, 75, 85]
// Output: [1 1 1 2 1 4 6]

#include <bits/stdc++.h>

using namespace std;

vector<int> ssp(vector<int> &arr)
{
    vector<int> res;
    stack<int> s;
    int arrSize = arr.size();

    for (int i = 0; i <= arrSize - 1; i++)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
            s.pop();

        if (s.empty())
            res.push_back(i + 1);
        else
            res.push_back(i - s.top());

        s.push(i);
    }

    return res;
}

int main()
{
    vector<int> arr{100, 60, 80, 50, 60, 70, 60, 75, 85, 1300};

    cout << "SSP : ";
    for (auto x : ssp(arr))
        cout << x << " ";
    cout << endl;

    return 0;
}

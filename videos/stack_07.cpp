#include <bits/stdc++.h>

using namespace std;

// Binary search for lowest greater than by indices
int greater_bs(vector<int> &org, vector<int> &inds, int val)
{
    int low = 0, high = inds.size() - 1;
    int curr_greatest = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int ch_val = org[inds[mid]];

        if (ch_val >= val)
        {
            high = mid - 1;
            curr_greatest = inds[mid];
        }
        else if (ch_val < val)
            low = mid + 1;
    }

    return curr_greatest;
}

// Farthest greatest to left
vector<int> fgl(vector<int> &arr)
{
    vector<int> res;
    vector<int> lgs;
    int arrSize = arr.size();

    for (int i = 0; i < arrSize; i++)
    {
        int greater = greater_bs(arr, lgs, arr[i]);

        if (greater != -1)
            res.push_back(greater);
        else
        {
            res.push_back(i);
            lgs.push_back(i);
        }
    }

    return res;
}

// Farthest greatest to right
vector<int> fgr(vector<int> &arr)
{
    vector<int> res;
    vector<int> lgs;
    int arrSize = arr.size();

    for (int i = arrSize - 1; i >= 0; i--)
    {
        int greater = greater_bs(arr, lgs, arr[i]);

        if (greater != -1)
            res.push_back(greater);
        else
        {
            res.push_back(i);
            lgs.push_back(i);
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

// Max area
int maxArea(vector<int> &height)
{
    int maximum = 0, hSize = height.size();
    vector<int> lgs;

    for (int i = 0; i < hSize; i++)
    {
        int greater = greater_bs(height, lgs, height[i]);

        if (greater != -1)
            maximum = max(maximum, height[i] * (i - greater));
        else
            lgs.push_back(i);
    }

    lgs.clear();

    for (int i = hSize - 1; i >= 0; i--)
    {
        int greater = greater_bs(height, lgs, height[i]);

        if (greater != -1)
            maximum = max(maximum, height[i] * (greater - i));
        else
            lgs.push_back(i);
    }

    return maximum;
}

int main()
{
    vector<int> arr1{100, 80, 60, 70, 110, 75, 85, 120, 40, 20, 10, 245, 65};
    vector<int> arr2{1, 1};

    cout << maxArea(arr2) << endl;

    return 0;
}

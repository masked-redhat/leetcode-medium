#include <bits/stdc++.h>

using namespace std;

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
    vector<int> heights{4, 4};

    cout << "Max area : " << maxArea(heights) << endl;

    return 0;
}

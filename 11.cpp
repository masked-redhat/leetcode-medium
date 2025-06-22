#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &height)
{
    int maxArea = 0;

    int n = height.size();
    int i = (n / 2) - 1, j = n / 2;

    maxArea = min(height[i], height[j]) * (j - i);

    while (i >= 1 && j < n - 1)
    {

        int e_left = height[i], left = height[i - 1];
        int e_right = height[j], right = height[j + 1];

        int maxArea1 = min(e_right, left) * (j - i + 1);
        int maxArea2 = min(e_left, right) * (j - i + 1);

        int maxArea3 = min(e_left, left);
        int maxArea4 = min(e_right, right);

        if (maxArea1 < maxArea2)
            j++;
        else
            i--;

        maxArea = max(maxArea1, maxArea2);
    }

    while (i >= 1)
    {
        int leftArea = min(height[i - 1], height[j]) * (j - i + 1);
        maxArea = max(maxArea, leftArea);
        i--;
    }

    while (j < n - 1)
    {
        int rightArea = min(height[i], height[j + 1]) * (j - i + 1);
        maxArea = max(maxArea, rightArea);
        j++;
    }

    return maxArea;
}

int main()
{
    vector<int> heights{4, 4};
    // vector<int> heights{1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << "Max area : " << maxArea(heights) << endl;

    return 0;
}

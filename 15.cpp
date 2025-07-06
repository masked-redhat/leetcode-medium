#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    unordered_map<int, vector<pair<int, int>>> values;
    int prev = INT_MIN;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (prev == nums[i])
            continue;
        int prev2 = INT_MIN;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (prev2 == nums[j])
                continue;
            int sum_ij = nums[i] + nums[j];
            pair<int, int> ij{i, j};
            values[sum_ij].push_back(ij);
            prev2 = nums[j];
        }
        prev = nums[i];
    }

    vector<vector<int>> sums;
    unordered_map<string, bool> uniques;

    for (int i = 0; i < nums.size(); i++)
    {
        int n = nums[i], n2 = 0 - nums[i];
        for (auto y : values[n2])
            if (i != y.first && i != y.second)
            {
                vector<int> ijk{n, nums[y.first], nums[y.second]};
                sort(ijk.begin(), ijk.end());
                string s = to_string(ijk[0]) + to_string(ijk[1]) + to_string(ijk[2]);

                if (uniques[s])
                    continue;

                sums.push_back(ijk);

                uniques[s] = true;
            }
    }

    return sums;
}

int main()
{

    vector<int> nums{-1, 0, 1, 1, 2, -1, -4};

    for (auto x : threeSum(nums))
    {
        for (auto y : x)
            cout << y << " ";
        cout << " , ";
    }
    cout << endl;

    return 0;
}

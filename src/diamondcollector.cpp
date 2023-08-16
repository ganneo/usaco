#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int numDiamonds, maxDifference;
    cin >> numDiamonds >> maxDifference;
    vector<int> diamondSizes;
    for (int i = 0; i < numDiamonds; ++i) {
        int diamondSize;
        cin >> diamondSize;
        diamondSizes.emplace_back(diamondSize);
    }

    sort(diamondSizes.begin(), diamondSizes.end());
    int maxDiamonds = 0;
    for (int i = 0; i < numDiamonds; ++i) {
        int currDiamond = 1;
        int smallestSize = diamondSizes[i];
        for (int j = 0; j < numDiamonds; ++j) {
            if (j == i) {
                continue;
            }

            if (abs(diamondSizes[j] - smallestSize) <= maxDifference) {
                ++currDiamond;
                smallestSize = min(diamondSizes[j], smallestSize);
            }
        }

        maxDiamonds = max(maxDiamonds, currDiamond);
    }

    cout << maxDiamonds;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCows;
    vector<long long> allCowMoney;
    cin >> numCows;
    for (int i = 0; i < numCows; ++i) {
        long long cowMoney;
        cin >> cowMoney;
        allCowMoney.emplace_back(cowMoney);
    }
    sort(allCowMoney.begin(), allCowMoney.end());

    long long maxMoney = 0;
    long long maxTuition = 0;
    for (int i = 0; i < numCows; ++i) {
        if (maxMoney < (numCows - i) * allCowMoney[i]) {
            maxMoney = (numCows - i) * allCowMoney[i];
            maxTuition = allCowMoney[i];
        }
    }

    cout << maxMoney << ' ' << maxTuition;
    return 0;
}
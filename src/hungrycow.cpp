#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numDeliveries;
    long long numDays;
    cin >> numDeliveries;
    cin >> numDays;
    vector<pair<long long, long long>> deliveries;
    for (int i = 0; i < numDeliveries; ++i) {
        long long day, amt;
        cin >> day >> amt;
        deliveries.emplace_back(day, amt);
    }
    sort(deliveries.begin(), deliveries.end());

    long long numHaybales = 0;
    long long haybalesEaten = 0;
    long long prevDay = 1;
    for (auto & delivery : deliveries) {
        long long currDay = delivery.first;
        long long haybales = delivery.second;

        if (numHaybales < currDay - prevDay) {
            haybalesEaten += numHaybales;
            numHaybales = haybales;
        } else {
            haybalesEaten += currDay - prevDay;
            numHaybales -= currDay - prevDay;
            numHaybales += haybales;
        }

        prevDay = currDay;
    }

    haybalesEaten += min(numDays - prevDay + 1, numHaybales);

    cout << haybalesEaten;

    return 0;
}

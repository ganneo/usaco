#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int numLawSeg, numBessieSeg;
    cin >> numLawSeg >> numBessieSeg;
    int currDistance = 0;
    map<int, int> lawSegments = {};
    set<int> lawPositions;
    set<int> segPositions;
    for (int i = 0; i < numLawSeg; ++i) {
        int distance, speedLimit;
        cin >> distance >> speedLimit;
        lawSegments[currDistance] = speedLimit;
        lawPositions.emplace(currDistance);
        segPositions.emplace(currDistance);
        currDistance += distance;
    }

    currDistance = 0;
    map<int, int> bessieSegments;
    set<int> bessiePositions;
    for (int i = 0; i < numBessieSeg; ++i) {
        int distance, speed;
        cin >> distance >> speed;
        bessieSegments[currDistance] = speed;
        bessiePositions.emplace(currDistance);
        segPositions.emplace(currDistance);
        currDistance += distance;
    }

    int lawDistance = 0;
    int bessieDistance = 0;
    int maxOverSpeed = 0;
    for (auto position : segPositions) {
        if (lawPositions.find(position) != lawPositions.end()) {
            lawDistance = position;
        }

        if (bessiePositions.find(position) != bessiePositions.end()) {
            bessieDistance = position;
        }

        maxOverSpeed = max(maxOverSpeed, bessieSegments[bessieDistance] - lawSegments[lawDistance]);
    }

    cout << maxOverSpeed;

    return 0;
}

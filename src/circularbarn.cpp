#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int numRooms;
    cin >> numRooms;
    vector<int> numCowInRoom;
    for (int i = 0; i < numRooms; ++i) {
        int numCows;
        cin >> numCows;
        numCowInRoom.emplace_back(numCows);
    }

    int maxNumMoves = INT_MAX;
    for (int i = 0; i < numRooms; ++i) {
        int numMoves = 0;
        for (int j = 0; j < numRooms - i; ++j) {
            numMoves += numCowInRoom[i + j] * j;
        }

        for (int j = 0; j < i; ++j) {
            numMoves += numCowInRoom[j] * (numRooms - i + j);
        }

        maxNumMoves = min(maxNumMoves, numMoves);
    }

    cout << maxNumMoves;

    return 0;
}
/**
 * @file 20_k-closest-points-origin.cpp
 * @author Anikthe_27 (aniket.kumar.giri2707@gmail.com)
 * @brief K Closest Points To Origin using Heaps(priority queues)
 * @date 2022-08-11
 *
 * @copyright Copyright @ani, 2022
 *
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> ppi;

// max heap
vector<vector<int>> KnearestPoints(int n, int k, vector<vector<int>> &points) {
    priority_queue<ppi> pq;
    for (int i = 0; i < n; i++) {
        int x = points[i][0];
        int y = points[i][1];
        int dist = x * x + y * y;

        pq.push({{dist}, {x, y}});
        if (pq.size() > k) {
            pq.pop();
        }
    }

    vector<vector<int>> ans;
    while (!pq.empty()) {
        vector<int> temp;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        temp.push_back(x);
        temp.push_back(y);
        ans.push_back(temp);
    }

    return ans;
}

int main() {
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int n = points.size();

    int k = 2;
    // cin >> k;

    vector<vector<int>> ans = KnearestPoints(n, k, points);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

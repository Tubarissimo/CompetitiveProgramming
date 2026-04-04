// https://cses.fi/problemset/task/1620

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int check(vector<long long int> req_time, long long int products, long long int time) {
    long long int total_products {0};
    for (auto machine : req_time) {
        total_products += time/machine;
        if (total_products >= products) return total_products;
    }

    return total_products;
}

long long int time_needed(vector<long long int> req_time, long long int products) {
    long long int left = 1, right = req_time.back()*products;
    long long int time = -1;

    while (left <= right)
    {
        long long int mid = left + (right - left)/2;

        if (check(req_time,products,mid) >= products) {
            time = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return time;
}

int main() {
    long long int n, products;
    vector<long long int> req_time;

    cin >> n >> products;
    for (long long int i = 0; i < n; i++)
    {
        long long int time;
        cin >> time;
        req_time.push_back(time);
    }

    sort(req_time.begin(),req_time.end());

    cout << time_needed(req_time,products);

    return 0;
}
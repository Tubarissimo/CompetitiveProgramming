// https://cses.fi/problemset/task/1085

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long check(vector<long long> arr, long long k, long long max_sum) {
    long long n_sub_arr {1}, current_sum {0};

    for (auto elem : arr) {
        if (current_sum + elem > max_sum) {
            n_sub_arr++;
            current_sum = elem;
        } else {
            current_sum += elem;
        }
    }

    return n_sub_arr <= k;
}

long long min_sum(vector<long long>& arr, long long k) {
    long long sum {0};
    long long l {*max_element(arr.begin(),arr.end())};
    long long r {accumulate(arr.begin(),arr.end(),0LL)};

    while (l <= r)
    {
        long long mid = l + (r - l)/2;

        if (check(arr, k, mid)) {
            sum = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return sum;
}

int main() {
    long long n, k;
    vector<long long> arr;

    cin >> n >> k;
    for (long long i {0}; i < n; i++)
    {
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    cout << min_sum(arr,k);
    
    return 0;
}
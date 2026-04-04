// https://cses.fi/problemset/task/1084/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int got_apartment(vector<int>& des_ap_size, vector<int>& ap_size, int k) {
    int got_ap {0};
    int i {0}, j {0};

    sort(des_ap_size.begin(),des_ap_size.end());
    sort(ap_size.begin(),ap_size.end());

    while (i < des_ap_size.size() && j < ap_size.size()) {
        if (ap_size[j] < des_ap_size[i]-k) {
            j++;
        } else if (ap_size[j] > des_ap_size[i]+k) {
            i++;
        } else {
            got_ap++;
            i++;
            j++;
        }
    }

    return got_ap;
}

int main() {
    int n, m, k;
    vector<int> des_ap_size;
    vector<int> ap_size;

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        des_ap_size.push_back(num);
    }
    
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        ap_size.push_back(num);
    }

    cout << got_apartment(des_ap_size,ap_size,k);

    return 0;
}

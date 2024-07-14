#include <bits/stdc++.h>
using namespace std;

int main() {
    // Example 1: Basic Operations and Resizing
    vector<int> v1;
    v1.push_back(40);
    v1.push_back(50);
    v1.resize(2);
    v1.resize(7, 100);
    cout << "Vector v1 size: " << v1.size() << endl;
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;

    // Example 2: Erasing Elements
    vector<int> v2 = {1, 2, 3, 4, 5};
    v2.erase(v2.begin() + 1, v2.end() - 1);
    for (int x : v2) {
        cout << x << " ";
    }
    cout << endl;

    // Example 3: Different Ways to Initialize Vectors
    vector<int> v3 = {2, 10, 3};
    for (int i = 0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }
    cout << endl;
    cout << "Vector v3 size: " << v3.size() << endl;

    // Example 4: Input and Output of Vectors
    int n;
    cin >> n;
    vector<int> v4(n);
    for (int i = 0; i < n; i++) {
        cin >> v4[i];
    }
    for (int val : v4) {
        cout << val << " ";
    }
    cout << endl;

    // Example 5: Inserting Elements from Another Vector
    vector<int> v5 = {1, 2, 3, 4, 5};
    vector<int> v5_2 = {100, 101, 102, 103};
    v5.insert(v5.begin() + 2, v5_2.begin(), v5_2.end());
    for (int x : v5) {
        cout << x << " ";
    }
    cout << endl;

    // Example 6: Popping Elements
    vector<int> v6 = {10, 20, 30, 40};
    v6.pop_back();
    v6.pop_back();
    for (int i = 0; i < v6.size(); i++) {
        cout << v6[i] << " ";
    }
    cout << endl;

    // Example 7: Inserting Elements (Duplicate Example)
    vector<int> v7 = {1, 2, 3, 4, 5};
    vector<int> v7_2 = {100, 101, 102, 103};
    v7.insert(v7.begin() + 2, v7_2.begin(), v7_2.end());
    for (int x : v7) {
        cout << x << " ";
    }
    cout << endl;

    // Example 8: Vector of Strings (Individual Input)
    cin >> n;
    vector<string> v8;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v8.push_back(s);
    }
    for (string val : v8) {
        cout << val << endl;
    }

    // Example 9: Vector of Strings (Line Input)
    cin >> n;
    cin.ignore();
    vector<string> v9(n);
    for (int i = 0; i < n; i++) {
        getline(cin, v9[i]);
    }
    for (string val : v9) {
        cout << val << endl;
    }

    // Example 10: Replace and Find Elements
    vector<int> v10 = {1, 2, 2, 4, 3, 5, 1, 2, 4, 5, 3, 2};
    replace(v10.begin(), v10.end(), 2, 100);
    for (int x : v10) {
        cout << x << " ";
    }
    cout << endl;

    auto it = find(v10.begin(), v10.end(), 100);
    if (it == v10.end()) {
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }

    return 0;
}

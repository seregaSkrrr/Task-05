#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<int> findMinInWindow(const vector<int>& nums, int n) {
    vector<int> res;
    if (nums.empty() || n > nums.size()) return res;

    multiset<int> window(nums.begin(), nums.begin() + n);
    res.push_back(*window.begin());

    for (int i = n; i < nums.size(); i++) {
        window.erase(window.find(nums[i - n]));
        window.insert(nums[i]);
        res.push_back(*window.begin());
    }

    return res;
}

int main() {
    setlocale(LC_ALL, "");
    
    vector<int> nums;
    int n, k;
    cout << "Input K and size of window N: ";
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        int num;
        cout << "Enter the number: ";
        cin >> num;
        nums.push_back(num);
    }
    
    vector<int> res = findMinInWindow(nums, n);
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
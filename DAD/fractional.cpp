#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    int value, weight;
    Item(int x, int y) : value(x), weight(y) {}
};

struct ItemComparator {
    bool operator()(const Item& a, const Item& b) {
        double r1 = static_cast<double>(a.value) / static_cast<double>(a.weight);
        double r2 = static_cast<double>(b.value) / static_cast<double>(b.weight);
        return r1 > r2; // Reverse order to sort in descending order
    }
};

double fractionalKnapsack(int W, vector<Item>& arr) {
    sort(arr.begin(), arr.end(), ItemComparator());

    int curWeight = 0;
    double finalValue = 0.0;

    for (const Item& item : arr) {
        if (curWeight + item.weight <= W) {
            curWeight += item.weight;
            finalValue += item.value;
        } else {
            int remain = W - curWeight;
            finalValue += (static_cast<double>(item.value) / static_cast<double>(item.weight)) * static_cast<double>(remain);
            break;
        }
    }

    return finalValue;
}

int main() {
    int n = 3, weight = 50;
    vector<Item> arr;
    arr.push_back(Item(100, 20));
    arr.push_back(Item(60, 10));
    arr.push_back(Item(120, 30));

    double ans = fractionalKnapsack(weight, arr);
    cout << "The maximum value is " << ans << endl;

    return 0;
}

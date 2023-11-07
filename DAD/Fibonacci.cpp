#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of Fibonacci terms to generate: ";
    cin >> n;

    int n1 = 0;
    int n2 = 1;

    cout << n1 << " " << n2 << " ";
    int steps = 2;

    for (int i = 2; i < n; i++) {
        int n3 = n1 + n2;
        cout << n3 << " ";
        n1 = n2;
        n2 = n3;
        steps++;
    }

    cout << "\nNumber of step count is: " << steps << endl;

    return 0;
}

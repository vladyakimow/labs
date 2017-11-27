#include <iostream>

using namespace std;

int main() {
    double a[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    double pr = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            pr = pr * a[i];
        }
    }
    cout << pr << endl;
    double min = 10000000.0;
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            index = i;
        }
    }
    double sum = 0.0;
    for (int i = 0; i < index; i++)
        sum = sum + a[i];
    cout << sum;
    return 0;
}

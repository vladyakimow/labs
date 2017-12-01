#include <iostream>

using namespace std;

int main() {
    int a[100][100];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++) {
            int kolvo = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) {
                for (int k = 0; k < m; k++) {
                    if (a[i][k] < 0) {
                        kolvo++;
                    }
                }
                break;
            }
        }
        cout << kolvo << endl;
    }
    int mini[100];
    for (int i = 0; i < n; i++)
        mini[i] = 10000000;
    int maxj[100];
    for (int i = 0; i < n; i++)
        maxj[i] = -10000000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] < mini[i])
                mini[i] = a[i][j];
            if (a[i][j] > maxj[j])
                maxj[j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            if ((a[i][j] == mini[i]) && (a[i][j] == maxj[j])) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}

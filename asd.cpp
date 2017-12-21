#include <iostream>
#include <limits.h>

using namespace std;

struct Point {
    int x,y,z;
};

struct Vector {
    int x,y,z;
};

int main() {
    int n;
    cin >> n;
    int a[100], b[100], c[100];
    for (int i = 0; i < n; ++i) {
        Point m1,m2,m3;
        cin >> m1.x >> m1.y >> m1.z;
        cin >> m2.x >> m2.y >> m2.z;
        cin >> m3.x >> m3.y >> m3.z;
        Vector v1,v2;
        v1.x = m2.x - m1.x;
        v1.y = m2.y - m1.y;
        v1.z = m2.z - m1.z;
        v2.x = m3.x - m1.x;
        v2.y = m3.y - m1.y;
        v2.z = m3.z - m1.z;
        int m[2][3] = {{v1.x, v1.y, v1.z}, {v2.x, v2.y, v2.z}};
        /*for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }*/
        a[i] = m[0][1] * m[1][2] - m[1][1] * m[0][2];
        b[i] = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]);
        c[i] = m[0][0] * m[1][1] - m[1][0] * m[0][1];
    }
    /*cout << endl << endl;
    int maxn = 0, maxa, maxb, maxc;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " " << b[i] << " " << c[i] << endl;
    }
    cout << endl << endl;*/
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j)
                if ((a[i] == a[j]) && (b[i] == b[j]) && (c[i] == c[j]))
                    a[j] = b[j] = c[j] = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (a[i] != INT_MAX) {
            cout << a[i] << " " << b[i] << " " << c[i] << endl;
        }
    }
    return 0;
}

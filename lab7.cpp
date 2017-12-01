#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {
    ifstream file("file.dat");
    int maxProbelov = 0;
    while (file) {
        char str[70];
        file.getline(str, 70, '\n');
        int len = strlen(str);
        int probelov = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == ' ') {
                probelov++;
            }
            else {
                if (maxProbelov < probelov)
                    maxProbelov = probelov;
                probelov = 0;
            }
        }

        if (maxProbelov < probelov)
            maxProbelov = probelov;
    }

    cout << maxProbelov << endl;
    file.close();
    file.open("file.dat");
    while (file) {
        char str[70];
        file.getline(str, 70, '\n');
        int len = strlen(str);
        int probelov = 0;
        for (int i = 0; i < len; ++i) {
            if (str[i] == ' ') {
                probelov++;
            }
            else {
                if (probelov == maxProbelov) {
                    for (int j = 0; j < maxProbelov; ++j) {
                        cout << "_";
                    }
                }
                else {
                    for (int j = 0; j < probelov; ++j) {
                        cout << " ";
                    }
                }
                probelov = 0;
                cout << str[i];
            }
        }
        if (probelov == maxProbelov) {
            for (int j = 0; j < maxProbelov; ++j) {
                cout << "_";
            }
        }
        else {
            for (int j = 0; j < probelov; ++j) {
                cout << " ";
            }
        }
        cout << endl;
    }
    file.close();
    return 0;
}

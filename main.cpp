#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <locale>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Notebook {
    struct DisplayResolution {
        int x, y;
    } disp_res;
    int f;
    float d;
    float hdd;
    char model[21];
    int price;
    float weight;
    struct Dimensions {
        float x, y, z;
    } dims;
    int frequency;
    int ram;
};

bool f (Notebook a, Notebook b) {
    return a.frequency < b.frequency;
}

int main() {
    setlocale(0, "");
    ifstream file("note.txt");
    Notebook note[18];
    int index = 0;
    while (file) {
        char s[76];
        file.getline(s, 76, '\n');
        //cout << (string)s << endl;
        for (int i = 0; i < 19; ++i) {
            note[index].model[i] = s[i];
        }
        note[index].model[19] = '\0';
        note[index].price = atoi(&s[19]);
        //cout << note[index].price << endl;
        note[index].weight = (float)atoi(&s[24]) + ((float)atoi(&s[26]) / 10);
        note[index].dims.x = (float)atoi(&s[28]) + ((float)atoi(&s[31]) / 10);
        note[index].dims.y = (float)atoi(&s[33]) + ((float)atoi(&s[36]) / 10);
        note[index].dims.z = (float)atoi(&s[38]) + ((float)atoi(&s[41]) / 10);
        note[index].frequency = atoi(&s[42]);
        note[index].ram = atoi(&s[47]);
        note[index].d = (float)atoi(&s[50]) + ((float)atoi(&s[53]) / 10);
        note[index].disp_res.x = atoi(&s[55]);
        note[index].disp_res.y = atoi(&s[60]);
        note[index].f = atoi(&s[65]);
        note[index].hdd = (float)atoi(&s[68]) + ((float)atoi(&s[70]) / 10);
        index++;
    }
    file.close();
    sort(note, note + index, f);
    ofstream output("note2.txt");
    output << setprecision(1) << fixed;
    for (int i = 0; i < index; ++i)
        if (note[i].price > 3500)
            output << (string)note[i].model << " " << note[i].price << " " << note[i].weight << " " << note[i].dims.x << " " << note[i].dims.y
            << " " << note[i].dims.z << " " << note[i].frequency << " " << note[i].ram << " " << note[i].d << " " <<
            note[i].disp_res.x << " " << note[i].disp_res.y << " " << note[i].f << " " << note[i].hdd << endl;
    output.close();
    return 0;
}

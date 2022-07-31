#include <bits/stdc++.h>
using namespace std;

int calcTotalMarks(vector<int> m) {
    return m[0] + m[1] + m[2];
};
bool compare(pair<string, vector<int>> s1, pair<string, vector<int>> s2) {
    vector<int> m1 = s1.second;
    vector<int> m2 = s2.second;
    return calcTotalMarks(m1) > calcTotalMarks(m2);
}
int main() {
    vector<pair<string, vector<int>>> student_marks = {
        {"Pilton", {99, 98, 99}},
        {"Swrang", {61, 72, 77}},
        {"Brahma", {48, 61, 67}},
        {"Noob", {9, 8, 19}},
    };

    sort(student_marks.begin(), student_marks.end(), compare);
    for (auto x : student_marks) {
        string name = x.first;
        vector<int> marks = x.second;
        cout << "Name : " << name << " ";
        for (int no : marks) {
            cout << no << " ";
        }
        cout << "\tTotal : " << calcTotalMarks(marks);
        cout << endl;
    }
    return 0;
}
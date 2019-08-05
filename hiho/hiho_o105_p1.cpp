#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int M;
    cin >> M;

    vector<int> nums(M);
    for (int i = 0; i < M; i++) {
        cin >> nums[i];
    }

    unordered_map<string, int> topic;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < nums[i]; j++) {
            string s;
            cin >> s;

            topic[s] = i;
        }
    }

    vector<string> paragraph;
    string s;
    while (cin >> s) {
        paragraph.push_back(s);
    }

    vector<int> score(M, 0);
    for (int i = 0; i < paragraph.size(); i++) {
        if (topic.find(paragraph[i]) == topic.end()) continue;

        score[topic[paragraph[i]]]++;
    }

    for (int v : score) {
        cout << v << endl;
    }

    return 0;
}


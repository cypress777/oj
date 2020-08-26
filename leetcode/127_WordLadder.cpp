class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> dict;
        bool has_end = false;
        for (int i = 0; i < wordList.size(); i++) {
            dict[wordList[i]] = i;
            if (wordList[i] == endWord) has_end = true;
        }
        if (!has_end) return 0;

        vector<int> vst(wordList.size(), -1);

        vector<string> queue = { beginWord };
        vector<int> steps = { 1 };
        int f = 0, r = 0;

        while (f <= r) {
            string cur = queue[f];
            int cur_step = steps[f];
            f++;

            if (cur == endWord) {
                return cur_step;
                break;
            }

            for (int i = 0; i < cur.size(); i++) {
                string new_string = cur;
                for (int j = 0; j < 26; j++) {
                    new_string[i] = 'a' + j;

                    if (new_string == cur) continue;
                    if (dict.find(new_string) == dict.end()) continue;

                    int id = dict[new_string];
                    if (vst[id] != -1) continue;

                    if (r + 1 >= queue.size()) {
                        queue.push_back("");
                        steps.push_back(-1);
                    }

                    queue[r + 1] = new_string;
                    steps[r + 1] = cur_step + 1;
                    vst[id] = 1;
                    r++;
                }
            }
        }

        return 0;
    }
};

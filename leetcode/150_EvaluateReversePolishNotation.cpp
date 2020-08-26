class Solution {
public:
    struct Node {
        string symbol;
        Node *left, *right;

        Node(string sym) : symbol(sym), left(NULL), right(NULL) {}
    };

    bool is_op(const string &s) {
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }

    int to_int(const string &s) {
        int start = (s[0] == '-' ? 1 : 0);
        int sign = (s[0] == '-' ? -1 : 1);

        int res = 0;
        for (int i = start; i < s.size(); i++) res = res * 10 + (s[i] - '0');
        return sign * res;
    }

    int cal (Node *head) {
        int res = 0;
        string sym = head->symbol;
        // cout << "---- " << sym << endl;

        if (sym == "+") {
            res = cal(head->left) + cal(head->right);
            // cout << "+= " << res << " --- " << sym << endl;
        } else if (sym == "-") {
            res = cal(head->left) - cal(head->right);
            // cout << "-= " << res << " --- " << sym << endl;
        } else if (sym == "*") {
            res = cal(head->left) * cal(head->right);
            // cout << "*= " << res << " --- " << sym << endl;
        } else if (sym == "/") {
            res = cal(head->left) / cal(head->right);
            // cout << "/= " << res << " --- " << sym << endl;
        } else {
            res = to_int(sym);
            // cout << "= " << res << " --- " << sym << endl;
        }

        return res;
    }

    int evalRPN(vector<string>& tokens) {
        vector<Node*> stack;
        int r = -1;
        Node *head = NULL;

        for (int i = 0; i < tokens.size(); i++) {
            string sym = tokens[i];
            Node *p = new Node(sym);

            if (is_op(sym)) {
                p->left = stack[r - 1];
                p->right = stack[r];

                r--;
                if (r >= 0) stack[r] = p;
            } else {
                r++;
                if (r >= stack.size()) stack.push_back(p);
                else stack[r] = p;
            }

            if (i == tokens.size() - 1) {
                head = p;
                break;
            }
        }

        int res = 0;
        res = cal(head);

        return res;
    }
};

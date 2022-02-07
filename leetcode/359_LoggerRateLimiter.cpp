class Logger {
private:
    map<int, unordered_set<string>> _log;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        // cout << "=======  " << timestamp << endl;
        bool res = true;
        
        for (auto log : this->_log) {
            if (log.first <= timestamp - 10) {
                this->_log.erase(log.first);
            } else {
                if (log.second.find(message) != log.second.end()) {
                    res = false;
                }
            }
            // cout << "- " << log.first << " " << res << endl;
        }

        if (res) {
            if (this->_log.find(timestamp) == this->_log.end()) {
                this->_log[timestamp] = unordered_set<string>{};
            }
            this->_log[timestamp].insert(message);
        }
        return res;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
class Solution {
  public:
    string s;
    deque<char>dq;
    void append(char x) {
        // append x into document
        s.push_back(x);
        
    }

    void undo() {
        // undo last change
        dq.push_front(s.back());
        s.pop_back();
        
    }

    void redo() {
        // redo changes
        s.push_back(dq.front());
        dq.pop_front();
    }

    string read() {
        // read the document
        return s;
    }
};
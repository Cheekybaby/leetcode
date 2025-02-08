class NumberContainers {
public:
    unordered_map<int,int> m;
    unordered_map<int,set<int>> s;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(m.find(index) != m.end()){
            int prev = m[index];
            s[prev].erase(index);
            if(s[prev].empty()){
                s.erase(prev);
            }
        }
        m[index] = number;
        s[number].insert(index);
    }
    
    int find(int number) {
        if(s.find(number) != s.end()){
            return *s[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
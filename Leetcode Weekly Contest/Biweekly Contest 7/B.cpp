
class FileSystem {
public:
    map<string,int>ma;
    FileSystem() {
        ma.clear();
    }

    bool create(string path, int value) {
        if(ma.find(path)!=ma.end()) return false;
        int idx=path.rfind('/');
        cout<<idx<<endl;
        if(idx==0) {
            ma[path]=value;
            return 1;
        }
        string fa=path.substr(0, idx);
        cout<<fa<<endl;
        if(ma.find(fa)==ma.end()) return false;
        ma[path]=value;
        return true;
    }

    int get(string path) {
        if(ma.find(path)==ma.end()) return -1;
        else return ma[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->create(path,value);
 * int param_2 = obj->get(path);
 */
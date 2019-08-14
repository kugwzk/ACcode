class SnapshotArray {
public:
    vector<map<int,int> > vec;
    int id=0;
    SnapshotArray(int length) {
        map<int,int>ma;
        ma[0]=0;
        for(int i=0;i<length;i++)
            vec.push_back(ma);
    }

    void set(int index, int val) {
        vec[index][id] = val;
    }

    int snap() {
        //snap_id += 1;

        id += 1;
        return id-1;
    }

    int get(int index, int snap_id) {
        // cout<<id<<endl;
        auto tmp = vec[index].upper_bound(snap_id);
        // cout<<snap_id<<endl;
        tmp--;
        return tmp->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
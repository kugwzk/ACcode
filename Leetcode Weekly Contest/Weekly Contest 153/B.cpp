string res[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

class Solution {
public:

    string dayOfTheWeek(int day, int month, int year) {
        //res = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
        int ans = 0;
        if(month==1 || month == 2){
            year -- ;
            if(month==1) month=13;
            else month=14;
        }
        ans = (((year%100) + (year%100/4) + (year/100/4) - year/100*2 + 26*(month+1)/10 + day - 1)%7 + 7 ) % 7;
        cout<<ans<<endl;
        return res[ans];
    }
};
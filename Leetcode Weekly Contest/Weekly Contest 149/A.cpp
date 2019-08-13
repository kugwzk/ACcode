class Solution {
public:

    int check(int year) {
        if ((year%4==0 && year%100!=0) || (year%400 == 0)) return 1;
        else return 0;
    }

    int dayOfYear(string date) {
        int year = (date[0]-'0') * 1000 + (date[1] - '0') * 100 + (date[2] - '0') * 10 + (date[3] - '0');
        int month = (date[5] - '0') * 10 + (date[6] - '0');
        int day = (date[8] - '0') * 10 + (date[9] - '0');
        int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int tot = 0;
        if(check(year)) {

            for(int i=1;i<month;i++) tot += days[i];
            if (month > 2) tot += 1;
            tot += day;
        }
        else {
            for(int i=1;i<month;i++) tot += days[i];
            tot += day;
        }
        return tot;
    }
};
class Solution {
    unordered_map<int, int> monthToDays;
    
    vector<int> convertDateToInt(string date) {
        string yearString, monthString, dayString;
        for(int i{}; i < 4; ++i) {
            yearString += date[i];
        }
        monthString += date[5];
        monthString += date[6];
        dayString += date[8];
        dayString += date[9];


        vector<int> intDate {stoi(yearString), stoi(monthString), stoi(dayString)};
        return intDate;
    }
    
    bool isLeapYear(int year) {
        if((year % 4 == 0 && year % 100) || (year % 400 == 0)) {
            return true;
        }
        return false;
    }

    void init() {
        monthToDays[1] = 31;
        monthToDays[2] = 28;
        monthToDays[3] = 31;
        monthToDays[4] = 30;
        monthToDays[5] = 31;
        monthToDays[6] = 30;
        monthToDays[7] = 31;
        monthToDays[8] = 31;
        monthToDays[9] = 30;
        monthToDays[10] = 31;
        monthToDays[11] = 30;
        monthToDays[12] = 31;
    }

public:
    int daysBetweenDates(string date1, string date2) {
        init();
        if(date1 > date2) {
            swap(date1, date2);
        }
        
        vector<int> intDate = convertDateToInt(date1);
        int year1 = intDate[0];
        int month1 = intDate[1];
        int day1 = intDate[2];

        intDate = convertDateToInt(date2);
        int year2 = intDate[0];
        int month2 = intDate[1];
        int day2 = intDate[2];

        // Calculate days directlly if they are same year and month 
        if(year1 == year2 && month1 == month2) {
            return day2 - day1;
        }

        // Calculate remainder days for month1 to complete
        int days{};
        if(month1 == 2 && isLeapYear(year1)) {
            days += 29 - day1;
        }
        else days += monthToDays[month1] - day1;

        // Calculate all days by incremeting from month1 to month2
        for(int curMonth{month1 + 1}, curYear{year1};;) {
            if(curMonth == 13) {
                curMonth = 1;
                curYear++;
            }
            if(curYear == year2 && curMonth == month2) {
                break;
            }

            if(curMonth == 2 && isLeapYear(curYear)) {
                days += 29;
            }
            else {
                days += monthToDays[curMonth];
            }

            curMonth++;
        }
        // Get remainder days for month2
        days += day2;

        cout << year1 << " " << month1 << " " << day1;
        cout << endl;
        cout << year2 << " " << month2 << " " << day2;

        return days;
    }
};

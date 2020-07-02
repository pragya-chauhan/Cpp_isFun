//Pragya Chauhan
//Time calculation from https://stackoverflow.com/questions/8034469/c-how-to-get-the-actual-time-with-time-and-localtime
//thanks to Prof Kruger for help

#include <iostream>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

class JulianDate {
private:

	double jday;
	static int EPOCH;//2000
    const static int daysPerMonth[12];
    const static string monNames[12];
    const static int cumulativeDaysPerMonth[12];
    JulianDate(double jday): jday(jday){}
    int leapYear =0, leapMonth=0;
public:
JulianDate(int year, int mon, int day, int hour, int min, int second){
    int dy = year - EPOCH;
    int days = 365 * dy + dy/4 - dy/100 +dy /400;
    days += cumulativeDaysPerMonth[mon-1];

    double seconds = (hour * 60.0 * 60.0 + min * 60.0 + second) / 86400.0;  //misnamed variable
    jday = days + day + seconds;        //off by one check in the end
for(int i = EPOCH; i < year; i++){
        if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0){
        leapYear ++;                                                        //extra
    leapMonth ++;
                days ++;
    }
    }
if ((year%4 == 0 && year %100 != 0) || year % 400 ==0){         //leapYear =
        if(mon >= 3){
                days ++;leapYear ++;

}
}
}




static JulianDate now (){
       int year, mon,day,hour, min, second;
        time_t curr_time;
    curr_time = time(NULL);
    struct tm *time_ptr = localtime( &curr_time);
   year = time_ptr->tm_year + 1900;						//The tm_year field is relative to 1900
   mon = time_ptr->tm_mon +1;
   day = time_ptr->tm_mday;
   hour = time_ptr->tm_hour;			//access members of local time
   min = time_ptr->tm_min;
   second = time_ptr->tm_sec;               //
    return JulianDate( year, mon,day,hour, min, second);
     }





        int getYear() const{
        int i = jday;
        int j = (i - leapYear)/ 365;
        return j + EPOCH;
    }



    string getMonth() const{
        int i = jday;
        int j = 0;
        int dy = getYear()-EPOCH;
        j = jday-dy*365-leapMonth;

        if ((getYear()%4 == 0 && getYear() %100 != 0) || getYear() % 400 ==0){
            for (int k = 0; k < 12; k++) {
                if(j >= cumulativeDaysPerMonth[k]&& j < cumulativeDaysPerMonth[k+1]){
                    return monNames[k];
      }
    }
}
        else{
        for (int k = 0; k < 12; k++) {
    if(j >= cumulativeDaysPerMonth[k] && j < cumulativeDaysPerMonth[k+1]){
    return monNames[k];
            }
        }
    }
        return "";
    }

    int getDay() const{
        int i = jday;
        int j = 0;
        int dy = getYear()-EPOCH;
        j = jday - dy*365 - leapYear;
        if ((getYear()%4==0 && getYear() %100 != 0)|| getYear() % 400 ==0){
            for (int k = 0; k < 12; ++k) {
                if (getMonth() == monNames[k]){
                    return j-cumulativeDaysPerMonth[k]+1;
   }
 }
}
        else{
            for (int k = 0; k < 12; ++k) {
            if (getMonth() == monNames[k]){
                return j -cumulativeDaysPerMonth[k]+1;
            }
            }
    }
        return 0;
    }

    int getHour() const{
        double i = jday;
        int j = i;
        int temp = round((i - j)*86400);
        return temp / 3600;
    }

	int getMin() const{
        double i = jday;
        int j = i;
        int temp =round((i - j)*86400) - getHour()*3600;		//60*60*24 = 86400
        return temp / 60;
    }

    int getSec() const{
        double i = jday;
        int j = i;
        int temp = round((i - j)*86400) - getHour()*3600 - getMin()*60;
        return temp;
    }


    friend double operator -(JulianDate a, JulianDate b) {
		return a.jday - b.jday;

    }

	friend JulianDate operator +(JulianDate a, double b) {
	JulianDate sum(a.jday + b);
        sum.leapYear=a.leapYear;
        sum.leapMonth=a.leapMonth;
        return sum  ;
    }


    friend ostream& operator <<(ostream& s, const JulianDate& j) {
    return    s << j.getYear() << ' ' << j.getMonth() << ' ' << j.getDay() << ' ' << j.getHour() << ' ' <<
		j.getMin() << ' ' << j.getSec();

    }





};



const int JulianDate::daysPerMonth[12] =
        {31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};
const int JulianDate::cumulativeDaysPerMonth[12] =
        { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

const string JulianDate::monNames[12] =
        {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int JulianDate::EPOCH = 2000;

int main() {
	JulianDate newyear(2018, 1, 1, 0,0,0);
	JulianDate valentine(2018, 2, 14, 12,0,0); // 0.5
	JulianDate today = JulianDate::now(); // get it from the system time: time(nullptr)
	                  // localtime

	double days = valentine - newyear;
	JulianDate due = today + 7;
	cout << due << '\n';

	cout << "\nyear: " << newyear.getYear()
			 << "\nmonth: " << newyear.getMonth()
			 << "\nday: " << newyear.getDay()
			 << "\nhour: " << newyear.getHour()
			 << "\nmin: " << newyear.getMin()
			 << "\nsec: " << newyear.getSec() << '\n';
	JulianDate d1(2019, 1, 1, 0,0,0);
	for (int i = 0; i < 100; i++)
		cout << d1 + i;



}

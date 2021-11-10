#ifndef DATE_COMPLEX_NUMBER_H
#define DATE_COMPLEX_NUMBER_H
#include <iostream>
#include <istream>
#include <ostream>

namespace solve {
    struct Date {
        int day;
        int month;
        int year;
        Date(int d = 0, int m = 0, int y = 0) {
            day = d;
            month = m;
            year = y;
        }
    };
    // struct Complex {
    //     int real;
    //     int imaginary;
    //     Complex(int r, int i);
    // };

    // data member
    inline bool operator==(Date a, Date b) { return a.day == b.day && a.month == b.month && a.year == b.year; }  // equility
    // inline bool operator!=(Date a, Date b);  // ineqaulity
    // inline bool operator<(Date a, Date b);   // less than
    // inline bool operator<=(Date a, Date b);  // less than or equal to
    // inline bool operator>(Date a, Date b);   // greater than
    // inline bool operator>=(Date a, Date b);  // greator than or equal to
    // constexpr Date& operator++(Date d);
    // constexpr Date& operator--(Date d);
    Date& operator+(Date a) {
        Date temp;
        temp.day = this->day + a.day;
    }
    // constexpr Date& operator-(Date a, Date b);
    // constexpr Date& operator+=(Date d);
    // constexpr Date& operator-=(Date d);
    // constexpr Date& operator+(Date d, int day);
    // constexpr Date& operator+(Date d, int month);
    // constexpr Date& operator+(Date d, int year);
    // constexpr Date& operator-(Date d, int day);
    // constexpr Date& operator-(Date d, int month);
    // constexpr Date& operator-(Date d, int year);

    std::ostream& operator<<(std::ostream&, Date d) { std::cout << d.day << "/" << d.month << "/" << d.year; }
    std::istream& operator>>(std::istream&, Date& d) { std::cin >> d.day >> d.month >> d.year; }

    // complex member

}  // namespace solve

#endif
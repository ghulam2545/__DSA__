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
struct Complex {
    int real;
    int imaginary;
    Complex(int r = 0, int i = 0) {
        real = r;
        imaginary = i;
    }
};

// date member
inline bool operator==(Date a, Date b) { return a.day == b.day && a.month == b.month && a.year == b.year; }  // equility
inline bool operator!=(Date a, Date b) { return a.day != b.day || a.month != b.month || a.year != b.year; }  // ineqaulity
inline bool operator<(Date a, Date b) { return a.day < b.day || a.month < b.month || a.year < b.year; }      // less than
inline bool operator<=(Date a, Date b) { return a.day <= b.day && a.month <= b.month && a.year <= b.year; }  // less than or equal to
inline bool operator>(Date a, Date b) { return a.day > b.day || a.month > b.month || a.year > b.year; }      // greater than
inline bool operator>=(Date a, Date b) { return a.day >= b.day && a.month >= b.month && a.year >= b.year; }  // greator than or equal to
Date& operator++(Date& d) {
    ++d.day;
    return d;
}
Date& operator--(Date& d) {
    --d.day;
    return d;
}
Date& operator+(Date a, Date b) {
    // ......
    static Date d;
    d.day = a.day + b.day;
    d.month = a.month + b.month;
    d.year = a.year + b.year;
    return d;
}
Date& operator-(Date a, Date b) {
    // ......
    static Date d;
    d.day = a.day - b.day;
    d.month = a.month - b.month;
    d.year = a.year - b.year;
    return d;
}
Date& operator+=(Date& a, Date b) {
    // ......
    a.day += b.day;
    a.month += b.month;
    a.year += b.year;
    return a;
}
Date& operator-=(Date& a, Date b) {
    // ......
    a.day -= b.day;
    a.month -= b.month;
    a.year -= b.year;
    return a;
}
std::ostream& operator<<(std::ostream&, Date d) { std::cout << d.day << "/" << d.month << "/" << d.year; }
std::istream& operator>>(std::istream&, Date& d) { std::cin >> d.day >> d.month >> d.year; }

// complex member
// ......
inline bool operator==(Complex a, Complex b) { return a.real == b.real && a.imaginary == b.imaginary; }
inline bool operator!=(Complex a, Complex b) { return a.real != b.real || a.imaginary != b.imaginary; }
inline bool operator<(Complex a, Complex b) { return a.real < b.real || a.imaginary < b.imaginary; }
inline bool operator<=(Complex a, Complex b) { return a.real <= b.real && a.imaginary <= b.imaginary; }
inline bool operator>(Complex a, Complex b) { return a.real > b.real || a.imaginary > b.imaginary; }
inline bool operator>=(Complex a, Complex b) { return a.real >= b.real && a.imaginary >= b.imaginary; }

std::ostream& operator<<(std::ostream&, Complex c) { std::cout << c.real << "+" << c.imaginary << "i"; }
std::istream& operator>>(std::istream&, Complex c) { std::cin >> c.real >> c.imaginary; }

}  // namespace solve

#endif
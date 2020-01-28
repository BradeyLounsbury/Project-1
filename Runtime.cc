// The implementation file for the Runtime class
#include "Runtime.h"
#include "MyTime.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Constructor
Runtime::Runtime() {
    distance = 0.0;
}


//operators
Runtime Runtime::operator + (const Runtime& r1) const {
    Runtime tmp;
    tmp.rtime = rtime + r1.rtime;
    tmp.distance = distance + r1.distance;
    return tmp;
}

Runtime Runtime::operator - (const Runtime& r1) const {
    Runtime tmp;
    tmp.rtime = rtime - r1.rtime;
    tmp.distance = abs(distance - r1.distance);
    return tmp;
}

Runtime Runtime::operator * (const double& x) const {
    Runtime tmp;
    tmp.rtime = rtime * x;
    tmp.distance = distance * x;
    return tmp;
}

// Runtime operator * (const double& x, const Runtime& r1) {
//     Runtime tmp;
//     tmp
// }

Runtime Runtime::operator / (const double& x) const {
    Runtime tmp;
    tmp.rtime = rtime / x;
    tmp.distance = distance / x;
    return tmp;
}

bool Runtime::operator == (const Runtime& r1) const {
    return (rtime == r1.rtime && distance == r1.distance);
}

bool Runtime::operator != (const Runtime& r1) const {
    return (rtime.get_hours() != r1.rtime.get_hours() ||
            rtime.get_minutes() != r1.rtime.get_minutes() ||
            rtime.get_seconds() != r1.rtime.get_seconds() ||
            distance != r1.distance);
}


//helper
bool Runtime::distance_equal(double d) const {
    if (0 <= abs(distance - d) && 0.11 > abs(distance - d))
    {
        return true;
    }
    return false;
    
}


//stream functions
void Runtime::input(istream& ins) {
    char junk;
    ins >> rtime;
    ins.get(junk);
    ins >> distance;
}

void Runtime::output(ostream& outs) const {
    outs << "\nTime: ";
    rtime.output(outs);
    outs << "\nDistance: " << distance << " miles";
}

istream& operator >>(istream& ins, Runtime& r1) {
    r1.input(ins);
    return ins;
}

ostream& operator <<(ostream& outs, const Runtime& r1) {
    r1.output(outs);
    return outs;
}
/**
 *      Name: Bradey Lounsbury
 *      Date: January 27, 2020
 *      Email: bl396918@ohio.edu
 *      Desc: Implementation file of "Runtime.h" 
 */
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
//adds two runtimes
Runtime Runtime::operator + (const Runtime& rhs) const {
    Runtime tmp;
    tmp.rtime = rtime + rhs.rtime;
    tmp.distance = distance + rhs.distance;
    return tmp;
}

//subtracts two runtimes
Runtime Runtime::operator - (const Runtime& rhs) const {
    Runtime tmp;
    tmp.rtime = rtime - rhs.rtime;
    tmp.distance = abs(distance - rhs.distance);
    return tmp;
}

//multiplies a runtime and double (if in "Runtime * double" format)
Runtime Runtime::operator * (const double& x) const {
    Runtime tmp;
    tmp.rtime = rtime * x;
    tmp.distance = distance * x;
    return tmp;
}

//divides a runtime by a double
Runtime Runtime::operator / (const double& x) const {
    Runtime tmp;
    tmp.rtime = rtime / x;
    tmp.distance = distance / x;
    return tmp;
}

//compares two runtimes for equality
bool Runtime::operator == (const Runtime& rhs) const {
    return (rtime == rhs.rtime && distance == rhs.distance);
}

//compares two runtimes for inequality
bool Runtime::operator != (const Runtime& rhs) const {
    return (rtime.get_hours() != rhs.rtime.get_hours() ||
            rtime.get_minutes() != rhs.rtime.get_minutes() ||
            rtime.get_seconds() != rhs.rtime.get_seconds() ||
            distance != rhs.distance);
}


//helper
//returns true if distance of runtime is within a tenth of d
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
    outs << "\nDistance: " << fixed << setprecision(2) << distance << " miles";
}


//non-member functions
//multiplies runtime and double (if in "double * runtime" format)
Runtime operator *(const double& lhs, const Runtime& rhs) {
    Runtime tmp;
    tmp = rhs * lhs;
    return tmp;
}

istream& operator >>(istream& ins, Runtime& rhs) {
    rhs.input(ins);
    return ins;
}

ostream& operator <<(ostream& outs, const Runtime& rhs) {
    rhs.output(outs);
    return outs;
}
// #include <cmath>
// #include <fstream>
// #include <iomanip>
// #include <iostream>

// #include "APC_Const.h"
// #include "APC_Mat3D.h"
// #include "APC_Planets.h"
// #include "APC_Spheric.h"
// #include "APC_Sun.h"
// #include "APC_Time.h"
// #include "APC_VecMat3D.h"

#include <cmath>
#include <iomanip>

#include "APC_Const.h"
#include "APC_Spheric.h"
#include "APC_VecMat3D.h"
#include "APC_Math.h"
#include "APC_PrecNut.h"
#include "APC_Sun.h"
#include "APC_Time.h"
# define M_PI           3.14159265358979323846  /* pi */

using namespace std;

// Degrees to radians
double Radd(double Deg) {
    return Deg * M_PI / 180.0;
}

// Radians to degrees
double Degg(double Rad) {
    return Rad * 180.0 / M_PI;
}
/*
// Simple date/time formatter
char* DateTime(double MJD, TimeFormat fmt) {
    // Implementation depends on your existing libraries
    // Should return formatted date/time string
    static char buf[50];
    // ... implementation ...
    return buf;
}
*/
//-------------------------------------------------------------------------
//
// Main program
//
//-------------------------------------------------------------------------
int main()
{
    //
    // Constants
    //
    const double JD_J2000 = 2451545.0;
    const double c_light = 173.14;       // Speed of light [AU/day]

    //
    // Variables
    //
    int year, month, day;
    double hour, MJD, T;
    double lon_deg, lat_deg;
    double Az_deg, Alt_deg;
    Vec3D sunEcl, sunEqu;
    Mat3D ecl2equ;
    double ra, dec, gmst, lst, tau;
    double dist, fac;
    Vec3D r_geoc;
    
    // Title
    cout << endl
         << "   SUNAZALT: Azimuth and altitude of the Sun " << endl
         << endl;

    // Input
    cout << " Date (yyyy mm dd hh.hhh) ... "; 
    cin >> year >> month >> day >> hour; 
    cin.ignore(81,'\n');
    
    cout << " Observer longitude [deg] ... ";
    cin >> lon_deg;
    
    cout << " Observer latitude [deg] ... ";
    cin >> lat_deg;
    cin.ignore(81,'\n');
    
    // Convert to radians
    double lon_rad = Radd(lon_deg);
    double lat_rad = Radd(lat_deg);
    
    // Calculate MJD and T
    int h = static_cast<int>(hour);
    int m = static_cast<int>((hour - h) * 60);
    double s = ((hour - h) * 60 - m) * 60;
    MJD = Mjd(year, month, day, h, m, s);
    T = (MJD + 2400000.5 - JD_J2000) / 36525.0;
    
    // Calculate Sun position
    sunEcl = SunPos(T);
    
    // Transformation matrix
    ecl2equ = Ecl2EquMatrix(T);
    
    // Convert to equatorial coordinates
    sunEqu = ecl2equ * sunEcl;
    
    // Calculate RA and Dec
    ra = atan2(sunEqu[y], sunEqu[x]);
    double r_xy = sqrt(sunEqu[x]*sunEqu[x] + sunEqu[y]*sunEqu[y]);
    dec = atan2(sunEqu[z], r_xy);
    
    // Calculate sidereal time
    gmst = GMST(MJD);
    lst = Modulo(gmst + lon_rad, 2*M_PI);
    tau = Modulo(lst - ra + 5*M_PI, 2*M_PI) - M_PI; // [-π, π]
    
    // Calculate altitude and azimuth
    double h_rad, Az_rad;
    Equ2Hor(dec, tau, lat_rad, h_rad, Az_rad);
    
    // Convert to degrees
    Az_deg = Degg(Modulo(Az_rad, 2*M_PI));
    Alt_deg = Degg(h_rad);
    
    // Output results
    cout << endl << endl
         << " Date:  " << DateTime(MJD+hour/24.0, HHh) << " UT" << endl
         << " Position: " << fixed << setprecision(6) << lon_deg << " E, "
         << lat_deg << " N" << endl << endl;
    
    cout << " Sun position:" << endl
         << "   Azimuth:  " << setprecision(3) << setw(8) << Az_deg << " deg" << endl
         << "   Altitude: " << setprecision(3) << setw(8) << Alt_deg << " deg" << endl
         << endl;
    
    return 0;
}
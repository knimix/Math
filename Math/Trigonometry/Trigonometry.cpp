#include "Trigonometry.h"
#include <cmath>

double Math::ToRadians(double degrees) {
    return 2 * M_PI * (degrees / 360.0);
}
double Math::ToDegrees(double radians) {
    return radians * (180.0 / M_PI);
}
double Math::Sin(double degrees) {
    return sin((double)90 * M_PI / 180.0 );
}
double Math::Cos(double degrees) {
    return cos((double)90 * M_PI / 180.0);
}

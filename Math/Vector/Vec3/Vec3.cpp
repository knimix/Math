#include "Vec3.h"
#include <cmath>

bool Math::Vec3::operator ==(const Math::Vec3& vec) const {
    return vec.x == x && vec.y == y && vec.z == z;
}
bool Math::Vec3::operator !=(const Math::Vec3& vec) const {
    return vec.x != x || vec.y != y || vec.z != z;
}
Math::Vec3 Math::Vec3::operator +(const Math::Vec3& vec) const{
    return {x + vec.x, y + vec.y, z + vec.z};
}
Math::Vec3 Math::Vec3::operator -(const Math::Vec3& vec) const{
    return {x - vec.x, y - vec.y, z - vec.z};
}
Math::Vec3 Math::Add(const Vec3& vec1, const Vec3& vec2) {
    return {vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z};
}
Math::Vec3 Math::Subtract(const Vec3& vec1, const Vec3& vec2) {
    return {vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z};
}
Math::Vec3 Math::Multiply(const Vec3& vec1, const Vec3& vec2) {
    return {vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z};
}
Math::Vec3 Math::Normalize(const Vec3& vec) {
    auto length = static_cast<float>(Length(vec));
    length = static_cast<float>(1.0 / length);
    return {length * vec.x, length * vec.y, length * vec.z};
}
float Math::Length(const Vec3& vec) {
    return static_cast<float>(std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2) + std::pow(vec.z, 2)));
}
float Math::Dot(const Vec3& vec1, const Vec3& vec2) {
    return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

#include "Vec4.h"
#include <cmath>

bool Math::Vec4::operator ==(const Math::Vec4& vec) const {
    return vec.x == x && vec.y == y && vec.z == z && vec.w == w;
}
bool Math::Vec4::operator !=(const Math::Vec4& vec) const {
    return vec.x != x || vec.y != y || vec.z != z || vec.w != w;
}
Math::Vec4 Math::Vec4::operator +(const Math::Vec4& vec) const{
    return {x + vec.x, y + vec.y, z + vec.z, w + vec.w};
}
Math::Vec4 Math::Vec4::operator -(const Math::Vec4& vec) const{
    return {x - vec.x, y - vec.y, z - vec.z, w - vec.w};
}
Math::Vec4 Math::Add(const Vec4& vec1, const Vec4& vec2) {
    return {vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z, vec1.w + vec2.w};
}
Math::Vec4 Math::Subtract(const Vec4& vec1, const Vec4& vec2) {
    return {vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z, vec1.w - vec2.w};
}
Math::Vec4 Math::Multiply(const Vec4& vec1, const Vec4& vec2) {
    return {vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z, vec1.w * vec2.w};
}
Math::Vec4 Math::Normalize(const Vec4& vec) {
    auto length = static_cast<float>(Length(vec));
    length = static_cast<float>(1.0 / length);
    return {length * vec.x, length * vec.y, length * vec.z, length * vec.w};
}
float Math::Length(const Vec4& vec) {
    return static_cast<float>(std::sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2) + std::pow(vec.z, 2) + std::pow(vec.w, 2)));
}
float Math::Dot(const Vec4& vec1, const Vec4& vec2) {
    return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
}

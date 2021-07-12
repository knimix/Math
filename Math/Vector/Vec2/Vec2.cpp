#include "Vec2.h"
#include <cmath>
bool Math::Vec2::operator ==(const Math::Vec2& vec) const {
    return vec.x == x && vec.y == y;
}
bool Math::Vec2::operator !=(const Math::Vec2& vec) const {
    return vec.x != x || vec.y != y;
}
Math::Vec2 Math::Vec2::operator + (const Math::Vec2& vec) const {
    return {x + vec.x, y + vec.y};
}
Math::Vec2 Math::Vec2::operator -(const Math::Vec2& vec) const {
    return {x - vec.x, y - vec.y};
}
Math::Vec2 Math::Add(const Vec2 &vec1, const Vec2 &vec2) {
    return {vec1.x + vec2.x, vec1.y + vec2.y};
}
Math::Vec2 Math::Subtract(const Vec2 &vec1, const Vec2 &vec2){
    return {vec1.x - vec2.x, vec1.y - vec2.y};
}
Math::Vec2 Math::Multiply(const Vec2 &vec1, const Vec2 &vec2) {
    return {vec1.x * vec2.x, vec1.y *vec2.y};
}
Math::Vec2 Math::Normalize(const Vec2 &vec) {
    auto length = static_cast<float>(Length(vec));
    length = static_cast<float>(1.0/length);
    return {length * vec.x,length * vec.y};
}
float Math::Length(const Vec2 &vec) {
    return static_cast<float>(std::sqrt(std::pow(vec.x,2) + std::pow(vec.y,2)));
}
float Math::Dot(const Vec2 &vec1, const Vec2 &vec2) {
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

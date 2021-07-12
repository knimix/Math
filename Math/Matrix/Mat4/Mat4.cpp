#include "Mat4.h"
#include <cmath>

Math::Mat4 Math::Identity(float scala) {
    return {{scala,0,0,0},{0,scala,0,0},{0,0,scala,0},{0,0,0,scala}};
}
Math::Mat4 Math::Multiply(const Mat4& mat1, const Mat4& mat2) {
    Mat4 out = {};
    out.C0.x = (mat1.C0.x * mat2.C0.x) + (mat1.C1.x * mat2.C0.y) + (mat1.C2.x * mat2.C0.z) + (mat1.C3.x * mat2.C0.w);
    out.C0.y = (mat1.C0.y * mat2.C0.x) + (mat1.C1.y * mat2.C0.y) + (mat1.C2.y * mat2.C0.z) + (mat1.C3.y * mat2.C0.w);
    out.C0.z = (mat1.C0.z * mat2.C0.x) + (mat1.C1.z * mat2.C0.y) + (mat1.C2.z * mat2.C0.z) + (mat1.C3.z * mat2.C0.w);
    out.C0.w = (mat1.C0.w * mat2.C0.x) + (mat1.C1.w * mat2.C0.y) + (mat1.C2.w * mat2.C0.z) + (mat1.C3.w * mat2.C0.w);
    out.C1.x = (mat1.C0.x * mat2.C1.x) + (mat1.C1.x * mat2.C1.y) + (mat1.C2.x * mat2.C1.z) + (mat1.C3.x * mat2.C1.w);
    out.C1.y = (mat1.C0.y * mat2.C1.x) + (mat1.C1.y * mat2.C1.y) + (mat1.C2.y * mat2.C1.z) + (mat1.C3.y * mat2.C1.w);
    out.C1.z = (mat1.C0.z * mat2.C1.x) + (mat1.C1.z * mat2.C1.y) + (mat1.C2.z * mat2.C1.z) + (mat1.C3.z * mat2.C1.w);
    out.C1.w = (mat1.C0.w * mat2.C1.x) + (mat1.C1.w * mat2.C1.y) + (mat1.C2.w * mat2.C1.z) + (mat1.C3.w * mat2.C1.w);
    out.C2.x = (mat1.C0.x * mat2.C2.x) + (mat1.C1.x * mat2.C2.y) + (mat1.C2.x * mat2.C2.z) + (mat1.C3.x * mat2.C2.w);
    out.C2.y = (mat1.C0.y * mat2.C2.x) + (mat1.C1.y * mat2.C2.y) + (mat1.C2.y * mat2.C2.z) + (mat1.C3.y * mat2.C2.w);
    out.C2.z = (mat1.C0.z * mat2.C2.x) + (mat1.C1.z * mat2.C2.y) + (mat1.C2.z * mat2.C2.z) + (mat1.C3.z * mat2.C2.w);
    out.C2.w = (mat1.C0.w * mat2.C2.x) + (mat1.C1.w * mat2.C2.y) + (mat1.C2.w * mat2.C2.z) + (mat1.C3.w * mat2.C2.w);
    out.C3.x = (mat1.C0.x * mat2.C3.x) + (mat1.C1.x * mat2.C3.y) + (mat1.C2.x * mat2.C3.z) + (mat1.C3.x * mat2.C3.w);
    out.C3.y = (mat1.C0.y * mat2.C3.x) + (mat1.C1.y * mat2.C3.y) + (mat1.C2.y * mat2.C3.z) + (mat1.C3.y * mat2.C3.w);
    out.C3.z = (mat1.C0.z * mat2.C3.x) + (mat1.C1.z * mat2.C3.y) + (mat1.C2.z * mat2.C3.z) + (mat1.C3.z * mat2.C3.w);
    out.C3.w = (mat1.C0.w * mat2.C3.x) + (mat1.C1.w * mat2.C3.y) + (mat1.C2.w * mat2.C3.z) + (mat1.C3.w * mat2.C3.w);
    return out;
}
Math::Vec4 Math::Multiply(const Vec4& vec, const Mat4& mat) {
    Vec4 out = {0, 0, 0};
    out.x = (mat.C0.x * vec.x) + (mat.C1.x * vec.y) + (mat.C2.x * vec.z) + (mat.C3.x * vec.w);
    out.y = (mat.C0.y * vec.x) + (mat.C1.y * vec.y) + (mat.C2.y * vec.z) + (mat.C3.y * vec.w);
    out.z = (mat.C0.z * vec.x) + (mat.C1.z * vec.y) + (mat.C2.z * vec.z) + (mat.C3.z * vec.w);
    out.w = (mat.C0.w * vec.x) + (mat.C1.w * vec.y) + (mat.C2.w * vec.z) + (mat.C3.w * vec.w);
    return out;
}
Math::Mat4 Math::Ortho(float left, float right, float bottom, float top, float zNear, float zFar) {
    Mat4 out = Identity(1.0);
    out.C0.x = 2 / (right - left);
    out.C0.y = 0;
    out.C0.z = 0;
    out.C0.w = 0;
    out.C1.x = 0;
    out.C1.y = 2 / (top - bottom);
    out.C1.z = 0;
    out.C1.w = 0;
    out.C2.x = 0;
    out.C2.y = 0;
    out.C2.z = -2 / (zFar - zNear);
    out.C2.w = 0;
    out.C3.x = -((right + left) / (right - left));
    out.C3.y = -((top + bottom) / (top - bottom));
    out.C3.z = -((zFar + zNear) / (zFar - zNear));
    out.C3.w = 1;
    return out;
}
Math::Mat4 Math::Perspective(float fov, float aspect, float zNear, float zFar) {
    Mat4 out = Identity(1.0);
    out.C0.x = 1 / aspect * std::tan(fov / 2);
    out.C0.y = 0;
    out.C0.z = 0;
    out.C0.w = 0;
    out.C1.x = 0;
    out.C1.y = 1 / tan(fov / 2);
    out.C1.z = 0;
    out.C1.w = 0;
    out.C2.x = 0;
    out.C2.y = 0;
    out.C2.z = -((zFar + zNear) / (zFar - zNear));
    out.C2.w = -1;
    out.C3.x = 0;
    out.C3.y = 0;
    out.C3.z = -((2 * zFar * zNear) / (zFar - zNear));
    out.C3.w = 0;
    return out;
}
Math::Mat4 Math::Translate(const Mat4& mat,const Math::Vec3& translate) {
    Mat4 out = {};
    out.C0.x = 1;
    out.C0.y = 0;
    out.C0.z = 0;
    out.C0.w = 0;
    out.C1.x = 0;
    out.C1.y = 1;
    out.C1.z = 0;
    out.C1.w = 0;
    out.C2.x = 0;
    out.C2.y = 0;
    out.C2.z = 1;
    out.C2.w = 0;
    out.C3.x = translate.x;
    out.C3.y = translate.y;
    out.C3.z = translate.z;
    out.C3.w = 1;
    return Multiply(mat,out);
}
Math::Mat4 Math::Scale(const Mat4& mat,const Math::Vec3& scale) {
    Mat4 out = Identity(1.0);
    out.C0.x = scale.x;
    out.C0.y = 0;
    out.C0.z = 0;
    out.C0.w = 0;
    out.C1.x = 0;
    out.C1.y = scale.y;
    out.C1.z = 0;
    out.C1.w = 0;
    out.C2.x = 0;
    out.C2.y = 0;
    out.C2.z = scale.z;
    out.C2.w = 0;
    out.C3.x = 0;
    out.C3.y = 0;
    out.C3.z = 0;
    out.C3.w = 1;
    return Multiply(mat,out);
}
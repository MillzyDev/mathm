#pragma once

#include <cmath>

namespace mathm {
    struct Vector2 {
        double x;
        double y;

        Vector2 inline operator +() {
            ++x;
            ++y;
            return *this;
        }

        Vector2 inline operator -() {
            --x;
            --y;
            return *this;
        }

        inline Vector2 operator +(Vector2 rhs) {
            auto ret = *this;
            ret.x += rhs.x;
            ret.y += rhs.y;
            return ret;
        }

        inline Vector2 operator -(Vector2 rhs) {
            auto ret = *this;
            ret.x -= rhs.x;
            ret.y -= rhs.y;
            return ret;
        }

        inline Vector2 operator *(double rhs) {
            auto ret = *this;
            ret.x *= rhs;
            ret.y *= rhs;
            return ret;
        }

        inline friend Vector2 operator *(double lhs, Vector2 rhs) {
            Vector2 ret = rhs;
            ret.x *= lhs;
            ret.y *= lhs;
            return ret;
        }

        inline double magnitude() {
            return sqrt(x*x + y*y);
        }
    };

    struct RowVector2;

    struct ColumnVector2 : Vector2 {
        inline RowVector2 transpose();
    };

    struct RowVector2 : Vector2 {
        inline ColumnVector2 transpose();
    };

    inline RowVector2 ColumnVector2::transpose() {
        return (RowVector2)*this;
    }

    inline ColumnVector2 RowVector2::transpose() {
        return (ColumnVector2)*this;
    }

    struct Vector3 {
        double x;
        double y;
        double z;

        Vector3 inline operator +() {
            ++x;
            ++y;
            ++z;
            return *this;
        }

        Vector3 inline operator -() {
            --x;
            --y;
            --z;
            return *this;
        }

        inline Vector3 operator +(Vector3 rhs) {
            Vector3 ret = *this;
            ret.x += rhs.x;
            ret.y += rhs.y;
            ret.z += rhs.z;
            return ret;
        }

        inline Vector3 operator -(Vector3 rhs) {
            Vector3 ret = *this;
            ret.x -= rhs.x;
            ret.y -= rhs.y;
            ret.z -= rhs.z;
            return ret;
        }

        inline Vector3 operator *(double rhs) {
            Vector3 ret = *this;
            ret.x *= rhs;
            ret.y *= rhs;
            ret.z *= rhs;
            return ret;
        }

        inline friend Vector3 operator *(double lhs, Vector3 rhs) {
            Vector3 ret = rhs;
            ret.x *= lhs;
            ret.y *= lhs;
            ret.z *= lhs;
            return ret;
        }

        inline double magnitude() {
            return sqrt(x*x + y*y + z*z);
        }
    };

    struct RowVector3;

    struct ColumnVector3 : Vector3 {
        inline RowVector3 transpose();
    };

    struct RowVector3 : Vector3 {
        inline ColumnVector3 transpose();
    };

    inline RowVector3 ColumnVector3::transpose() {
        return (RowVector3)*this;
    }

    inline ColumnVector3 RowVector3::transpose() {
        return (ColumnVector3)*this;
    }

    struct Vector {
        inline static double dot(Vector2 a, Vector2 b) {
            return a.x*b.x + a.y*b.y;
        }

        inline static double dot(Vector3 a, Vector3 b) {
            return a.x*b.x + a.y*b.y + a.z*b.z;
        }

        inline static Vector3 cross(Vector3 a, Vector3 b) {
            return {
                a.y*b.z - a.z*b.y,
                a.z*b.x - a.x*b.z,
                a.x*b.y - a.y*b.x
            };
        }
    };
}
#pragma once

namespace mathm {
    struct Vector2 {
        double x;
        double y;

        inline operator +() {
            ++x;
            ++y;
        }

        inline operator -() {
            --x;
            --y;
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
            ret.y *= rhs;
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
        return *this;
    }

    inline ColumnVector2 RowVector2::transpose() {
        return *this;
    }
}
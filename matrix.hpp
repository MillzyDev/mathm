#pragma once

namespace mathm {

    struct Matrix2x2 {
        double m11;
        double m12;
        double m21;
        double m22;

        inline operator +() {
            ++m11;
            ++m12;
            ++m21;
            ++m22;
        }

        inline operator -() {
            --m11;
            --m12;
            --m21;
            --m22;
        }

        inline Matrix2x2 operator +(Matrix2x2 rhs) {
            Matrix2x2 ret = *this;
            ret.m11 += rhs.m11;
            ret.m12 += rhs.m12;
            ret.m21 += rhs.m21;
            ret.m22 += rhs.m22;
            return ret;
        }

        inline Matrix2x2 operator -(Matrix2x2 rhs) {
            Matrix2x2 ret = *this;
            ret.m11 -= rhs.m11;
            ret.m12 -= rhs.m12;
            ret.m21 -= rhs.m21;
            ret.m22 -= rhs.m22;
            return ret;
        }

        inline Matrix2x2 operator *(double rhs) {
            Matrix2x2 ret = *this;
            ret.m11 += rhs;
            ret.m12 *= rhs;
            ret.m21 *= rhs;
            ret.m22 *= rhs;
            return ret;
        }

        inline friend Matrix2x2 operator *(double lhs, Matrix2x2 rhs) {
            Matrix2x2 ret = rhs;
            ret.m11 *= lhs;
            ret.m12 *= lhs;
            ret.m21 *= lhs;
            ret.m22 *= lhs;
            return ret;
        }

        inline Matrix2x2 operator *(Matrix2x2 rhs) {
            return {
                m11*rhs.m11 + m12*rhs.m21, m11*rhs.m12 + m12*rhs.m22,
                m21*rhs.m11 + m22*rhs.m21, m21*rhs.m12 + m22*rhs.m22
            };
        }

        inline Matrix2x2 transpose() {
            return {
                m11, m21,
                m12, m22
            };
        }
    };

    struct Matrix3x3 {
        double m11;
        double m12;
        double m13;
        double m21;
        double m22;
        double m23;
        double m31;
        double m32;
        double m33;

        inline operator +() {
            ++m11;
            ++m12;
            ++m13;
            ++m21;
            ++m22;
            ++m23;
            ++m31;
            ++m32;
            ++m33;
        }

        inline operator -() {
            --m11;
            --m12;
            --m13;
            --m21;
            --m22;
            --m23;
            --m31;
            --m32;
            --m33;
        }
    };
}
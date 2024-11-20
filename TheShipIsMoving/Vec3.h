#pragma once
#include <iostream>
#include "raylib.h"

struct Vec3 {
    float x, y, z;

    Vector3 GetRayVec(){
        return Vector3{ x, y, z };
    }

    // Addition with another Vec3
    Vec3& operator+=(const Vec3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    // Addition with a scalar
    Vec3& operator+=(float scalar) {
        x += scalar;
        y += scalar;
        z += scalar;
        return *this;
    }

    // Subtraction with another Vec3
    Vec3& operator-=(const Vec3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    // Subtraction with a scalar
    Vec3& operator-=(float scalar) {
        x -= scalar;
        y -= scalar;
        z -= scalar;
        return *this;
    }

    // Multiplication with another Vec3
    Vec3& operator*=(const Vec3& other) {
        x *= other.x;
        y *= other.y;
        z *= other.z;
        return *this;
    }

    // Multiplication with a scalar
    Vec3& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    // Division with another Vec3
    Vec3& operator/=(const Vec3& other) {
        x /= other.x;
        y /= other.y;
        z /= other.z;
        return *this;
    }

    // Division with a scalar
    Vec3& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    // Friend function to allow Vec3 + Vec3
    friend Vec3 operator+(Vec3 left, const Vec3& right) {
        return left += right;
    }

    // Friend function to allow Vec3 + scalar
    friend Vec3 operator+(Vec3 left, float scalar) {
        return left += scalar;
    }

    // Friend function to allow Vec3 - Vec3
    friend Vec3 operator-(Vec3 left, const Vec3& right) {
        return left -= right;
    }

    // Friend function to allow Vec3 - scalar
    friend Vec3 operator-(Vec3 left, float scalar) {
        return left -= scalar;
    }

    // Friend function to allow scalar - Vec3
    friend Vec3 operator-(float scalar, Vec3 left) {
        return left -= scalar;
    }

    // Friend function to allow Vec3 * Vec3
    friend Vec3 operator*(Vec3 left, const Vec3& right) {
        return left *= right;
    }

    // Friend function to allow Vec3 * scalar
    friend Vec3 operator*(Vec3 left, float scalar) {
        return left *= scalar;
    }

    // Friend function to allow scalar * Vec3
    friend Vec3 operator*(float scalar, Vec3 left) {
        return left *= scalar;
    }

    // Friend function to allow Vec3 / Vec3
    friend Vec3 operator/(Vec3 left, const Vec3& right) {
        return left /= right;
    }

    // Friend function to allow Vec3 / scalar
    friend Vec3 operator/(Vec3 left, float scalar) {
        return left /= scalar;
    }

    // Output stream operator for debugging
    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
        os << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }

    // Normalized function (returns a normalized vector without modifying the current vector)
    Vec3 normalized() const {
        float magnitude = std::sqrt(x * x + y * y + z * z);
        if (magnitude == 0.0f) {
            return Vec3{ 0.0f, 0.0f, 0.0f }; // Return zero vector if the magnitude is zero
        }
        return Vec3{ x / magnitude, y / magnitude, z / magnitude };
    }

    // Cross product (returns a new Vec3 that is the cross product of this and another Vec3)
    Vec3 cross(const Vec3& other) const {
        return Vec3{
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        };
    }
};
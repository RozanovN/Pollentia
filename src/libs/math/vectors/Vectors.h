#pragma once
#include <Eigen/Dense>
#include "../CommonMathHeader.h"

namespace Pollentia::Math {
    using f32Vector2 = Eigen::Vector2f;
    using f64Vector2 = Eigen::Vector2d;
    using f32Vector3 = Eigen::Vector3f;
    using f64Vector3 = Eigen::Vector3d;
    using f32Vector4 = Eigen::Vector4f;
    using f64Vector4 = Eigen::Vector3d;
    using ui32Vector2 = Eigen::Vector2<unsigned32int>;
    using i32Vector2 = Eigen::Vector2<int32>;
    using ui32Vector3 = Eigen::Vector3<unsigned32int>;
    using i32Vector3 = Eigen::Vector3<int32>;
    using ui32Vector4 = Eigen::Vector4<unsigned32int>;
    using i32Vector4 = Eigen::Vector4<int32>;
    using ui64Vector2 = Eigen::Vector2<unsigned64int>;
    using i64Vector2 = Eigen::Vector2<int64>;
    using ui64Vector3 = Eigen::Vector3<unsigned64int>;
    using i64Vector3 = Eigen::Vector3<int64>;
    using ui64Vector4 = Eigen::Vector4<unsigned64int>;
    using i64Vector4 = Eigen::Vector4<int64>;
    using f32Matrix3x3 = Eigen::Matrix3f;
    using f64Matrix3x3 =  Eigen::Matrix3d;
    using f32Matrix4x4 = Eigen::Matrix4f;
    using f64Matrix4x4 =  Eigen::Matrix4d;
}
#include "stdafx.h"
#include "Transform.h"

Vector3 Transform::Up()
{
	glm::detail::compute_quat_mul_vec4<double, glm::qualifier::defaultp, false> a;
	return a.call(rotation, Vector4(0,1,0,0));
}

Vector3 Transform::Right()
{
	glm::detail::compute_quat_mul_vec4<double, glm::qualifier::defaultp, false> a;
	return a.call(rotation, Vector4(1, 0, 0, 0));
}

Vector3 Transform::Forward()
{
	glm::detail::compute_quat_mul_vec4<double, glm::qualifier::defaultp, false> a;
	return a.call(rotation, Vector4(0, 0, 1, 0));
}

Matrix4x4 Transform::GetTransformMatrix()
{
}

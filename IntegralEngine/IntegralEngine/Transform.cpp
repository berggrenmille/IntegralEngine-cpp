#include "stdafx.h"
#include "Transform.h"

Vector3 Transform::Up() const
{
	return VectorExtensions::Up() * rotation;
}

Vector3 Transform::Right() const
{
	return VectorExtensions::Right() * rotation;
}

Vector3 Transform::Forward() const
{
	return VectorExtensions::Forward() * rotation;
}

Matrix4x4 Transform::GetTransformMatrix()
{
	Matrix4x4 positionMatrix = MatrixExtensions::Identity();
	Matrix4x4 rotationMatrix = glm::toMat4(rotation);;
	Matrix4x4 scaleMatrix = MatrixExtensions::Identity();

	glm::translate(positionMatrix, position);
	glm::scale(scaleMatrix, scale);

	return positionMatrix * rotationMatrix * scaleMatrix;
}

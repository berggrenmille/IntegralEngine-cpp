#include "stdafx.h"
#include "Transform.h"

Vector3 Transform::Up()
{
	return VectorExtensions::Up() * rotation;
}

Vector3 Transform::Right()
{
	return VectorExtensions::Right() * rotation;
}

Vector3 Transform::Forward()
{
	return VectorExtensions::Forward() * rotation;
}

Matrix4x4 Transform::GetTransformMatrix()
{
	Matrix4x4 positionMatrix = MatrixExtensions::Identity();
	Matrix4x4 rotationMatrix;
	Matrix4x4 scaleMatrix = MatrixExtensions::Identity();

	glm::translate(positionMatrix, position);
	rotationMatrix = glm::toMat4(rotation);
	glm::scale(scaleMatrix, scale);

	return positionMatrix * rotationMatrix * scaleMatrix;
}

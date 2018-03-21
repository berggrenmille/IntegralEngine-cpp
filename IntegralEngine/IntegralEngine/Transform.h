#pragma once

class Transform
{
public:
	Vector3 position = VectorExtensions::Zero();
	Vector3 eulerRotation = VectorExtensions::Zero();
	Quaternion rotation = MatrixExtensions::Identity();
	Vector3 scale = VectorExtensions::Zero();

	Vector3 Up() const;
	Vector3 Right() const;
	Vector3 Forward() const;

	Matrix4x4 GetTransformMatrix();
private:
	Matrix4x4 transformationMatrix;
};

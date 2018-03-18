#pragma once

class Transform
{
public:
	Vector3 position = Zero();
	Vector3 eulerRotation = Zero();
	Quaternion rotation = MatrixExtensions::Identity();
	Vector3 scale = Zero();

	Vector3 Up();
	Vector3 Right();
	Vector3 Forward();

	Matrix4x4 GetTransformMatrix();
private:
	Matrix4x4 transformationMatrix;
};

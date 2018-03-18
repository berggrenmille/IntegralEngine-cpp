#pragma once

class Transform
{
public:
	Vector3 position = VectorExtensions::zero;
	Vector3 eulerRotation = VectorExtensions::zero;
	Quaternion rotation = QuaternionExtensions::identity;
	Vector3 scale = VectorExtensions::zero;

	Vector3 Up();
	Vector3 Right();
	Vector3 Forward();

	Matrix4x4 GetTransformMatrix();
private:
	Matrix4x4 transformationMatrix;
};

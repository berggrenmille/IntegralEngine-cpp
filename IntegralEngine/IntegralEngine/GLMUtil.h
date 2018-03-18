#pragma once

    typedef glm::vec4 Vector4;
	typedef glm::vec2 Vector2;
	typedef glm::vec3 Vector3;
	
	typedef glm::dquat Quaternion;

	typedef glm::mat4x4 Matrix4x4;
	
	namespace VectorExtensions
	{
		Vector3 zero = Vector3(0, 0, 0);
		Vector3 one = Vector3(0, 0, 0);
		Vector3 up = Vector3(0, 1, 0);
		Vector3 right = Vector3(1, 0, 0);
		Vector3 forward = Vector3(0, 0, 1);
	}
	namespace QuaternionExtensions
	{
		Quaternion identity = Quaternion(0, 0, 0, 1);
	}
	namespace MatrixExtensions
	{
		Matrix4x4 identity = Matrix4x4(
		{1,0,0,0},
		{0,1,0,0},
		{0,0,1,0},
		{0,0,0,1});
	}
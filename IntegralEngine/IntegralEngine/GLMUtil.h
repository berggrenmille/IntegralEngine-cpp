#pragma once
#include <../glm/glm.hpp>
#include <../glm/gtc/quaternion.hpp>

	typedef glm::vec4 Vector4;
	typedef glm::vec2 Vector2;
	typedef glm::vec3 Vector3;
	
	typedef glm::dquat Quaternion;

	typedef glm::mat4x4 Matrix4x4;
	
	namespace VectorExtensions
	{
		inline Vector3 Zero() { return Vector3(0, 0, 0); }
		inline Vector3 One() { return Vector3(1, 1, 1); }
		inline Vector3 Up() { return Vector3(0, 1, 0); }
		inline Vector3 Right() { return Vector3(1, 0, 0); }
		inline Vector3 Forward() { return Vector3(0, 0, 1); }
		inline Vector3 operator* (Vector3 vec, Quaternion quat) {
			float num = quat.x * 2.0f;
			float num2 = quat.y * 2.0f;
			float num3 = quat.z * 2.0f;
			float num4 = quat.x * num;
			float num5 = quat.y * num2;
			float num6 = quat.z * num3;
			float num7 = quat.x * num2;
			float num8 = quat.x * num3;
			float num9 = quat.y * num3;
			float num10 = quat.w * num;
			float num11 = quat.w * num2;
			float num12 = quat.w * num3;
			Vector3 result;
			result.x = (1.0f - (num5 + num6)) * vec.x + (num7 - num12) * vec.y + (num8 + num11) * vec.z;
			result.y = (num7 + num12) * vec.x + (1.0f - (num4 + num6)) * vec.y + (num9 - num10) * vec.z;
			result.z = (num8 - num11) * vec.x + (num9 + num10) * vec.y + (1.0f - (num4 + num5)) * vec.z;
			return result;
		}
	}
	namespace QuaternionExtensions
	{
		inline Quaternion Identity()
		{
			return Quaternion(0.0, 0.0, 0.0, 1.0);
		}
		
	}
	namespace MatrixExtensions
	{
		inline Matrix4x4 Identity()
		{
			return Matrix4x4(
			{ 1,0,0,0 },
			{ 0,1,0,0 },
			{ 0,0,1,0 },
			{ 0,0,0,1 });
		}
	}
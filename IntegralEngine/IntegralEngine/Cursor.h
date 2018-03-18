#pragma once
namespace Application
{
	class Cursor
	{
	public:
		static bool IsLocked();
		static bool IsSecured();
		static void ToggleLockCursor();
		static void ToggleSecureCursor();
		static void FreeCursor();
		static void ToggleCursor();
	private:
		static bool m_locked;
		static bool m_secured;

	};
}

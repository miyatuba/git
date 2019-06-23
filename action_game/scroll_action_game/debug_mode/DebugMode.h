#pragma once

class DebugMode
{
private:
	static bool is_debug_mode;
public:
	static void OnDebugMode();
	static void OffDebugMode();
	static bool isDebugMode();

	static float floatVariable;
};
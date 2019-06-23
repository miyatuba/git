#include "DebugMode.h"

bool DebugMode::is_debug_mode = false;
float DebugMode::floatVariable = 0.0f;

void DebugMode::OnDebugMode()
{
	DebugMode::is_debug_mode = true;
}

bool DebugMode::isDebugMode()
{
	return DebugMode::is_debug_mode;
}
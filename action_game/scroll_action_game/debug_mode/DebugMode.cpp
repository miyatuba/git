#include "DebugMode.h"

bool DebugMode::is_debug_mode = false;

void DebugMode::OnDebugMode()
{
	DebugMode::is_debug_mode = true;
}

bool DebugMode::isDebugMode()
{
	return DebugMode::is_debug_mode;
}
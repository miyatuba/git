#include "Audio.h"

void Audio::PlayBGM(int sound_handle)
{
	int result = PlaySoundMem(sound_handle, DX_PLAYTYPE_LOOP, true);

	if (result == -1) {
		std::string message = "BGM�̍Đ����s";
		throw message;
	}
}

void Audio::PlaySE(int sound_handle)
{
	int result = PlaySoundMem(sound_handle, DX_PLAYTYPE_BACK, true);
	if (result == -1) {
		std::string message = "SE�̍Đ����s";
		throw message;
	}
}
#include <bass.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "defines.h"

#define SPECWIDTH NUM_FREQS // display width (should be multiple of 4)
#define SPECHEIGHT 100  // height (changing requires palette adjustments too)
#define FILE "music.mp3"

DWORD chan;

void setup_bass()
{
	// initialize BASS
	if (!BASS_Init(-1,44100,0,NULL,NULL)) {
		printf("Can't initialize device\n");
	}
}

void teardown_bass()
{
	BASS_Free();
}

void play_file()
{
	if (!(chan=BASS_StreamCreateFile(FALSE,FILE,0,0,BASS_SAMPLE_LOOP))
		&& !(chan=BASS_MusicLoad(FALSE,FILE,0,0,BASS_MUSIC_RAMP|BASS_SAMPLE_LOOP,1))) {
		printf("Can't play file");
	} else {
		BASS_ChannelPlay(chan,FALSE);
	}
}

bool bass_playing()
{
	return BASS_StreamGetFilePosition(chan, BASS_FILEPOS_CURRENT) == BASS_StreamGetFilePosition(chan, BASS_FILEPOS_SIZE);
}

void get_bass_transform(uint8_t* spec_buffer)
{
	float fft[1024];
	int y1, y, x;
	BASS_ChannelGetData(chan,fft,BASS_DATA_FFT2048); // get the FFT data
	for (x=0;x<SPECWIDTH;x+=2)
	{
		// y=sqrt(fft[x*2 + 1])*3*SPECHEIGHT-4; // scale it (sqrt to make low values more visible)
		y=fft[x+1]*10*SPECHEIGHT;
		y1 = (y1+y)/2;
		spec_buffer[x] = y1;
		y1 = y;
		if (y>SPECHEIGHT) y=SPECHEIGHT; // cap it
		spec_buffer[x+1] = y;
	}
}
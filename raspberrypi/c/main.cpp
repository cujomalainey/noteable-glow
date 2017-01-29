#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include "serial.h"
#include "proto_packer.h"
#include "bass_handler.h"
#include "defines.h"

#define BUFFER_SIZE 256

#define REFRESH_RATE 15
// ~15 is ideal

#define DELAY 1.0/REFRESH_RATE

static uint8_t buffer[BUFFER_SIZE];
uint8_t spec[NUM_FREQS];

int main()
{
	setup_serial();
	setup_bass();
	clock_t t = clock();
	audioMessage msg = audioMessage_init_default;
	msg.data_count = NUM_FREQS;
	play_file();
	while (!bass_playing())
	{
		get_bass_transform(spec);
		for (uint8_t i = 0; i < NUM_FREQS; i++)
		{
			msg.data[i] = spec[i];
		}
		size_t bytes = encode_proto(buffer, BUFFER_SIZE, &msg);
		send_bytes(buffer, bytes);
		usleep((uint32_t)((DELAY - ((double)t)/CLOCKS_PER_SEC)*1000*1000));
	}
	teardown_bass();
}
#include <math.h>
#include <bass.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "serial.h"
#include "proto_packer.h"

#define BUFFER_SIZE 256

static uint8_t buffer[BUFFER_SIZE];

int main()
{
	setup_serial();
	configure_buffer(buffer, BUFFER_SIZE);
	uint8_t data = 1;
	send_bytes(&data, 1);
	sleep(1);
}
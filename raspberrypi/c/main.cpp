#include <math.h>
#include <bass.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "serial.h"

int main()
{
	setup_serial();
	uint8_t data = 1;
	send_bytes(&data, 1);
	sleep(1);
}
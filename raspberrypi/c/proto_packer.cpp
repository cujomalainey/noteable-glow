#include <stdio.h>
#include <pb_encode.h>
#include "proto_packer.h"

static pb_ostream_t buffer;

void configure_buffer(uint8_t* inc_buffer, uint16_t inc_buffer_size)
{
	buffer = pb_ostream_from_buffer(inc_buffer, inc_buffer_size);
}

size_t encode_proto(audioMessage* data)
{
	if (!pb_encode(&buffer, audioMessage_fields, data))
	{
	    printf("Decode failed: %s\n", PB_GET_ERROR(&buffer));
	}
	size_t size;
	if (!pb_get_encoded_size(&size, audioMessage_fields, data))
	{
		printf("Sizing failed");
	}
	return size;
}
#include <stdio.h>
#include <pb_encode.h>
#include "proto_packer.h"

size_t encode_proto(uint8_t* inc_buffer, uint16_t inc_buffer_size, audioMessage* data)
{
	pb_ostream_t buffer = pb_ostream_from_buffer(inc_buffer, inc_buffer_size);
	if (!pb_encode(&buffer, audioMessage_fields, data))
	{
	    printf("Encode failed: %s\n", PB_GET_ERROR(&buffer));
	}
	size_t size;
	if (!pb_get_encoded_size(&size, audioMessage_fields, data))
	{
		printf("Sizing failed");
	}
	return size;
}
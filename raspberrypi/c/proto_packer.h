#include "audio.pb.h"
#include <pb.h>

void configure_buffer(uint8_t* inc_buffer, uint16_t inc_buffer_size);

size_t encode_proto(audioMessage* data);
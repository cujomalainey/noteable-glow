#include "audio.pb.h"
#include <pb.h>

size_t encode_proto(uint8_t* inc_buffer, uint16_t inc_buffer_size, audioMessage* data);
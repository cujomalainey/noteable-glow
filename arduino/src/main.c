#include <Arduino.h>

void setup()
{

}

void loop()
{

}

    //         pb_istream_t stream = pb_istream_from_buffer(zrr.getData(), zrr.getDataLength());
    //         if (pb_decode(&stream, ChannelConfig_fields, &message))
    //         {
    //             ant_configure_radio(&message);
    //         }
    //         else
    //         {
    //             debug_pb_input_error(&stream);
    //         }
    //             for (uint8_t i = 0; i < config->channel_serial_number_count; i++) {
    //     if (config->channel_serial_number[i] != 0)
    //     {
    //         ant_setup_channel(i, config->channel_serial_number[i], (ant_device_type)config->channel_type[i]);
    //     }
    // }
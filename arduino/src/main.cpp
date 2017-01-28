#include <Arduino.h>
#include "HSLtoRGB.h"

#define BAUD_RATE 9600

void setup()
{
	Serial.begin(BAUD_RATE);
	RGB_point rgb = HSL_2_RGB( {200, 100, 75} );
	delay(5000);
	Serial.print("R: ");
	Serial.println(rgb.r);
	Serial.print("G: ");
	Serial.println(rgb.g);
	Serial.print("B: ");
	Serial.println(rgb.b);
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
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "HSLtoRGB.h"

#define LED_PIN   0
#define BAUD_RATE 9600
#define SATURATION 100
#define NUMPIXELS 60

#define INTENSITY_TO_HUE (360.0/100)

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

void set_pixel(uint8_t i, uint8_t intensity);

void setup()
{
	Serial.begin(BAUD_RATE);
    pixels.begin();
}

void loop()
{
        for (uint8_t i = 0; i < NUMPIXELS; i++)
        {
            set_pixel(i, i);
        }
        pixels.show();
        delay(50);
}

void set_pixel(uint8_t i, uint8_t intensity)
{
    uint16_t v1 = (uint16_t)(((double)intensity) * INTENSITY_TO_HUE);
    RGB_point rgb = HSL_2_RGB( {v1, SATURATION, intensity} );
    pixels.setPixelColor(i,pixels.Color(rgb.r, rgb.g, rgb.b));
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
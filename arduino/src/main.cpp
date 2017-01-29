#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <pb.h>
#include <pb_decode.h>
#include "HSLtoRGB.h"
#include "mduino.h"
#include "audio.pb.h"

#define LED_PIN   0
#define BAUD_RATE 115200
#define SATURATION 100
#define NUMPIXELS 60
#define ERROR_PIN 13

#define INTENSITY_TO_HUE (360.0/100)

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);
uint8_t messageBuffer[256];
mduino m = mduino();
OutgoingMessage om = OutgoingMessage();
audioMessage msg;

void set_pixel(uint8_t i, uint8_t intensity);

void setup()
{
	Serial.begin(BAUD_RATE);
    m.setSerial(Serial);
    pinMode(ERROR_PIN, OUTPUT);
    pixels.begin();
}

void loop()
{
    m.readPacket();
    if (m.getResponse().isAvailable())
    {
        pb_istream_t stream = pb_istream_from_buffer(m.getResponse().getFrameData(), m.getResponse().getFrameLength());
        if (!pb_decode(&stream, audioMessage_fields, &msg))
        {
            // Serial.print("Decode failed: ");
            // Serial.println(PB_GET_ERROR(&stream));
            digitalWrite(ERROR_PIN, HIGH);
        }
        else
        {
            for (int i = 0; i < NUMPIXELS; i++)
            {
                set_pixel(i, msg.data[i]);
            }
            pixels.show();
        }
    }
    else if (m.getResponse().isError())
    {
        digitalWrite(ERROR_PIN, HIGH);
    }
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
#include <Arduino.h>

#define H_MAX 360.0
#define S_MAX 100.0
#define L_MAX 100.0


typedef struct RGB_point {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGB_point;

typedef struct HSL_point {
    uint16_t h;
    uint8_t s;
    uint8_t l;
} HSL_point;

RGB_point HSL_2_RGB( HSL_point point );
#ifndef UTILS_H
#define UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

uint8_t* convert_number_to_string(int32_t value);

void writef(const char *fmt, ...);

#ifdef __cplusplus
}
#endif


#endif
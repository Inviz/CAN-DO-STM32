#ifndef INC_DEV_BLANK
#define INC_DEV_BLANK

#ifdef __cplusplus
extern "C" {
#endif

#include "core/device.h"

/* Start of autogenerated OD types */
/* 0x6100: Module Timer 1
   ADC Unit used for high-volume sampling of analog signals */
typedef struct {
    int16_t disabled;
    uint8_t prescaler;
    uint8_t source;
} module_timer_config_t;
/* End of autogenerated OD types */

typedef struct {
    device_t *device;
    module_timer_config_t *config;
} module_timer_t;


extern device_callbacks_t module_timer_callbacks;

/* Start of autogenerated OD accessors */
#define SUBIDX_TIMER_DISABLED 0x1
#define SUBIDX_TIMER_PRESCALER 0x2
#define SUBIDX_TIMER_SOURCE 0x3

/* End of autogenerated OD accessors */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
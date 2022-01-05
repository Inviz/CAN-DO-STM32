#include "i2c.h"
#include "helpers/dma.h"

/* Start of autogenerated OD accessors */

/* End of autogenerated OD accessors */

static ODR_t OD_write_transport_i2c_property(OD_stream_t *stream, const void *buf, OD_size_t count,
                                            OD_size_t *countWritten) {
    transport_i2c_t *i2c = stream->object;
    (void)i2c;
    ODR_t result = OD_writeOriginal(stream, buf, count, countWritten);
    return result;
}

static int transport_i2c_validate(OD_entry_t *config_entry) {
    transport_i2c_config_t *config = (transport_i2c_config_t *)OD_getPtr(config_entry, 0x01, 0, NULL);
    (void)config;
    if (false) {
        return CO_ERROR_OD_PARAMETERS;
    }
    return 0;
}

static void transport_i2c_tx_dma_start(transport_i2c_t *i2c, uint8_t *data, uint16_t size) {
    transport_i2c_tx_dma_stop(i2c);
    dma_periphery_tx_start((uint32_t) & (I2C_DR(i2c->address)), i2c->config->dma_tx_unit, i2c->config->dma_tx_stream, i2c->config->dma_tx_channel, data, size);
    i2c_enable_txdma(i2c->address);
}

static int transport_i2c_construct(transport_i2c_t *i2c, device_t *device) {
    i2c->device = device;
    i2c->config = (transport_i2c_config_t *)OD_getPtr(device->config, 0x01, 0, NULL);
    return i2c->config->disabled;
}

static int transport_i2c_start(transport_i2c_t *i2c) {
    (void)i2c;
    return 0;
}

static int transport_i2c_stop(transport_i2c_t *i2c) {
    (void)i2c;
    return 0;
}

static int transport_i2c_pause(transport_i2c_t *i2c) {
    (void)i2c;
    return 0;
}

static int transport_i2c_resume(transport_i2c_t *i2c) {
    (void)i2c;
    return 0;
}

static int transport_i2c_tick(transport_i2c_t *i2c, uint32_t time_passed, uint32_t *next_tick) {
    (void)i2c;
    (void)time_passed;
    (void)next_tick;
    return 0;
}

static int transport_i2c_link(transport_i2c_t *i2c) {
    (void)i2c;
    return 0;
}

static int transport_i2c_phase(transport_i2c_t *i2c, device_phase_t phase) {
    (void)i2c;
    (void)phase;
    return 0;
}

device_callbacks_t transport_i2c_callbacks = {.validate = transport_i2c_validate,
                                             .construct = (int (*)(void *, device_t *))transport_i2c_construct,
                                             .link = (int (*)(void *))transport_i2c_link,
                                             .start = (int (*)(void *))transport_i2c_start,
                                             .stop = (int (*)(void *))transport_i2c_stop,
                                             .pause = (int (*)(void *))transport_i2c_pause,
                                             .resume = (int (*)(void *))transport_i2c_resume,
                                             .tick = (int (*)(void *, uint32_t time_passed, uint32_t *next_tick))transport_i2c_tick,
                                             //.accept = (int (*)(void *, device_t *device, void *channel))transport_i2c_accept,
                                             .phase = (int (*)(void *, device_phase_t phase))transport_i2c_phase,
                                             .write_values = OD_write_transport_i2c_property};
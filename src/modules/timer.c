#include "timer.h"

/* Start of autogenerated OD accessors */

/* End of autogenerated OD accessors */

static ODR_t OD_write_module_timer_property(OD_stream_t *stream, const void *buf, OD_size_t count,
                                            OD_size_t *countWritten) {
    module_timer_t *blank = stream->object;
    (void)blank;
    ODR_t result = OD_writeOriginal(stream, buf, count, countWritten);
    return result;
}

static int module_timer_validate(OD_entry_t *config_entry) {
    module_timer_config_t *config = (module_timer_config_t *)OD_getPtr(config_entry, 0x01, 0, NULL);
    (void)config;
    if (false) {
        return CO_ERROR_OD_PARAMETERS;
    }
    return 0;
}

static int module_timer_construct(module_timer_t *blank, device_t *device) {
    blank->device = device;
    blank->config = (module_timer_config_t *)OD_getPtr(device->config, 0x01, 0, NULL);
    return blank->config->disabled;
}

static int module_timer_start(module_timer_t *blank) {
    (void)blank;
    return 0;
}

static int module_timer_stop(module_timer_t *blank) {
    (void)blank;
    return 0;
}

static int module_timer_pause(module_timer_t *blank) {
    (void)blank;
    return 0;
}

static int module_timer_resume(module_timer_t *blank) {
    (void)blank;
    return 0;
}

static int module_timer_tick(module_timer_t *blank, uint32_t time_passed, uint32_t *next_tick) {
    (void)blank;
    (void)time_passed;
    (void)next_tick;
    return 0;
}

static int module_timer_link(module_timer_t *blank) {
    (void)blank;
    return 0;
}

static int module_timer_phase(module_timer_t *blank, device_phase_t phase) {
    (void)blank;
    (void)phase;
    return 0;
}


//static int device_mcu_timeout(device_mcu_t *mcu) {
//
//	/* Enable TIM2 clock. */
//	rcc_periph_clock_enable(RCC_TIM2);
//
//	/* Enable TIM2 interrupt. */
//	nvic_enable_irq(NVIC_TIM2_IRQ);
//
//	/* Reset TIM2 peripheral to defaults. */
//	rcc_periph_reset_pulse(RST_TIM2);
//
//	/* Timer global mode:
//	 * - No divider
//	 * - Alignment edge
//	 * - Direction up
//	 * (These are actually default values after reset above, so this call
//	 * is strictly unnecessary, but demos the api for alternative settings)
//	 */
//	timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT,
//		TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP);
//
//	/*
//	 * Please take note that the clock source for STM32 timers
//	 * might not be the raw APB1/APB2 clocks.  In various conditions they
//	 * are doubled.  See the Reference Manual for full details!
//	 * In our case, TIM2 on APB1 is running at double frequency, so this
//	 * sets the prescaler to have the timer run at 5kHz
//	 */
//	timer_set_prescaler(TIM2, ((rcc_apb1_frequency * 2) / 5000));
//
//	/* Disable preload. */
//	timer_disable_preload(TIM2);
//	timer_continuous_mode(TIM2);
//
//	/* count full range, as we'll update compare value continuously */
//	timer_set_period(TIM2, 65535);
//
//	/* Set the initual output compare value for OC1. */
//	timer_set_oc_value(TIM2, TIM_OC1, frequency_sequence[frequency_sel++]);
//
//	/* Counter enable. */
//	timer_enable_counter(TIM2);
//
//	/* Enable Channel 1 compare interrupt to recalculate compare values */
//	timer_enable_irq(TIM2, TIM_DIER_CC1IE);
//}

device_callbacks_t module_timer_callbacks = {.validate = module_timer_validate,
                                             .construct = (int (*)(void *, device_t *))module_timer_construct,
                                             .link = (int (*)(void *))module_timer_link,
                                             .start = (int (*)(void *))module_timer_start,
                                             .stop = (int (*)(void *))module_timer_stop,
                                             .pause = (int (*)(void *))module_timer_pause,
                                             .resume = (int (*)(void *))module_timer_resume,
                                             .tick = (int (*)(void *, uint32_t time_passed, uint32_t *next_tick))module_timer_tick,
                                             //.accept = (int (*)(void *, device_t *device, void *channel))module_timer_accept,
                                             .phase = (int (*)(void *, device_phase_t phase))module_timer_phase,
                                             .write_values = OD_write_module_timer_property};
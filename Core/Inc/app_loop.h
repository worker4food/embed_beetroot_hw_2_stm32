#pragma once

#include "stm32f4xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} pin_config_t;

typedef struct {
    GPIO_PinState btn_state;
    uint32_t debounce_till_ms;
    uint32_t last_toggle_ms;
} app_state_t;

void app_setup(const pin_config_t led_pin, const pin_config_t btn_pin, app_state_t *);
void app_loop(app_state_t *);

#ifdef __cplusplus
}
#endif
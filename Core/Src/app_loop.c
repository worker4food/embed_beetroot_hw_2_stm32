
#include "app_loop.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#define DEBOUNCE_DELAY_MS 50
#define BLINK_DELAY_MS 100

static pin_config_t s_led_pin;
static pin_config_t s_btn_pin;

void app_setup(const pin_config_t led_pin, const pin_config_t btn_pin, app_state_t *p_state) {
    s_led_pin = led_pin;
    s_btn_pin = btn_pin;

    p_state->btn_state = HAL_GPIO_ReadPin(s_btn_pin.port, s_btn_pin.pin);
    p_state->debounce_till_ms = HAL_GetTick();
    p_state->last_toggle_ms = 0;
}

void app_loop(app_state_t *p_state) {
    GPIO_PinState btn_curr = HAL_GPIO_ReadPin(s_btn_pin.port, s_btn_pin.pin);
    uint32_t current_ms = HAL_GetTick();

    if (current_ms >= p_state->debounce_till_ms) {
      p_state->btn_state = btn_curr;
      p_state->debounce_till_ms = current_ms + DEBOUNCE_DELAY_MS;
    }

    if (current_ms - p_state->last_toggle_ms > BLINK_DELAY_MS) {
      if (p_state->btn_state == GPIO_PIN_RESET) { // blink
        HAL_GPIO_TogglePin(s_led_pin.port, s_led_pin.pin);
      } else { // turn off
        HAL_GPIO_WritePin(s_led_pin.port, s_led_pin.pin, GPIO_PIN_SET);
      }
      p_state->last_toggle_ms = current_ms;
    }
}
/* ***************************************************************************
 *
 * Copyright 2019 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/


//#define CONFIG_TARGET_WEMOS_D1_R32
#ifdef CONFIG_TARGET_WEMOS_D1_R32

#define GPIO_INPUT_BUTTON 18

#define GPIO_OUTPUT_MAINLED 16
#define GPIO_OUTPUT_MAINLED_0 26 /* use as ground */


#define GPIO_OUTPUT_NOUSE1 17
#define GPIO_OUTPUT_NOUSE2 25
#else // ESP32_DEVKITC_V4

#define GPIO_INPUT_BUTTON 0

#define GPIO_OUTPUT_MAINLED 12

#define GPIO_OUTPUT_RELAY 14

#endif

enum switch_led_onoff_state {
    LED_SWITCH_OFF = 1,
    LED_SWITCH_ON = 0,
};

enum switch_relay_onoff_state {
    RELAY_SWITCH_OFF = 0,
    RELAY_SWITCH_ON = 1,
};

enum main_led_gpio_state {
    MAINLED_GPIO_ON = 0,
    MAINLED_GPIO_OFF = 1,
};

enum main_relay_gpio_state {
    MAINRELAY_GPIO_ON = 1,
    MAINRELAY_GPIO_OFF = 0,
};

enum led_animation_mode_list {
    LED_ANIMATION_MODE_IDLE = 0,
    LED_ANIMATION_MODE_FAST,
    LED_ANIMATION_MODE_SLOW,
};

enum button_gpio_state {
    BUTTON_GPIO_RELEASED = 1,
    BUTTON_GPIO_PRESSED = 0,
};

#define BUTTON_DEBOUNCE_TIME_MS 20
#define BUTTON_LONG_THRESHOLD_MS 5000
#define BUTTON_DELAY_MS 300

enum button_event_type {
    BUTTON_LONG_PRESS = 0,
    BUTTON_SHORT_PRESS = 1,
};

void change_led_switch_state(int switch_state);
void change_relay_switch_state(int switch_state);
void button_isr_handler(void *arg);
int get_button_event(int* button_event_type, int* button_event_count);
void led_blink(int switch_state, int delay, int count);
void change_led_mode(int noti_led_mode);
void iot_gpio_init(void);

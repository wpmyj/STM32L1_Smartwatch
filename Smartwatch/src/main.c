#include "main.h"

// All queues
QueueHandle_t ISR_batteryQ;
QueueHandle_t battery_displayQ;
QueueHandle_t sensors_displayQ;
QueueHandle_t ISR_buttonQ;
QueueHandle_t button_displayQ;
QueueHandle_t sensor_displayQ;

void main(void){

    /* SCB configuration */

    // Set AIRCR register(
    SCB->AIRCR = (VECTKEY_VALUE << VECTKEY_OFFSET) | (PRIGROUP_VALUE << PRIGROUP_OFFSET);


    // Initialize all queues
    ISR_batteryQ = xQueueCreate(3, sizeof(short));
    battery_displayQ = xQueueCreate(3, sizeof(uint8_t));
    ISR_buttonQ = xQueueCreate(3, sizeof(uint8_t));
    button_displayQ = xQueueCreate(3, sizeof(uint8_t));
    sensor_displayQ = xQueueCreate(3, sizeof(Sensor *));
    

    // Create battery_t task
    xTaskCreate(battery_t, "Battery task", 1000, NULL, tskIDLE_PRIORITY + 2, NULL);

    // Create button_t task
    xTaskCreate(button_t, "Button task", 1000, NULL, tskIDLE_PRIORITY + 2, NULL);

    // Create sensor_t task
    xTaskCreate(sensors_t, "Sensor task", 1000, NULL, tskIDLE_PRIORITY + 2, NULL);

    // Create display_t task
    xTaskCreate(display_t, "Display 500", 1000, NULL, tskIDLE_PRIORITY + 1, NULL);

    // Start scheduler
    vTaskStartScheduler();
    for(;;);

}

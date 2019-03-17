/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
			

#include "FreeRTOS.h"  // must be included 1st
#include "task.h"


TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;

// task function prototype.
void vTask1_handler (void *params);
void vTask2_handler (void *params);


int main(void)
{
	//1. Reset the RCC clock configuration to the default reset state.
	//HSI ON, PLL OFF, HSE OFF, system clock = 16MHz, cpu_clock = 16MHz
	RCC_DeInit();

	//2. update the SystemCoreclock variable
	SystemCoreClockUpdate();

	//3. lets create 2 tasks, task 1 and task 2

	// 		vTask1_handler is the function name of the task
	xTaskCreate(vTask1_handler,
			"Task-1",
			configMINIMAL_STACK_SIZE,  // 130 word x 4 byte = number of bytes is allocated to the stack for this task
			NULL,   //void * const pvParameters,
			2,  	// UBaseType_t uxPriority,
			&xTaskHandle1		//	TaskHandle_t * const pxCreatedTask )
			);

	// 		vTask1_handler is the function name of the task
		xTaskCreate(vTask2_handler,
				"Task-2",
				configMINIMAL_STACK_SIZE,  // number of bytes is allocated to the stack for this task
				NULL,   //void * const pvParameters,
				2,  	// UBaseType_t uxPriority,
				&xTaskHandle2		//	TaskHandle_t * const pxCreatedTask )
				);



	for(;;);
}

// handler of the task 1
void vTask1_handler (void *params)
{
	while(1);  // the task handler should never return so we have a while(1) here.
}

// handler of the task 2
void vTask2_handler (void *params)
{
	while(1);
}

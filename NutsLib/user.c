#include "user.h"

/*		Command Function Template
 *

 NutStatus_e FunctionName(uint8_t *received_data_ptr, uint32_t received_data_length, uint8_t *result_buffer_ptr, uint32_t *result_length,
 uint32_t result_buffer_MAX_size) {
 *result_length = 0;		// length of responding payload


 // return run result: NUT_OK, NUT_WARNING, NUT_ERROR
 return NUT_OK;
 }

 */

NutStatus_e Echo(uint8_t *received_data_ptr, uint32_t received_data_length, uint8_t *result_buffer_ptr, uint32_t *result_length,
		uint32_t result_buffer_MAX_size) {
	uint32_t i;
	uint8_t tempu8;
	*result_length = received_data_length;
	for (i = 0; i < received_data_length; i++) {
		tempu8 = received_data_ptr[i];
		result_buffer_ptr[i] = tempu8;
	}
	return NUT_OK;
}

/* Enter sleep mode on demand */

static void set_all_pins_pullup(void) {
	GPIO_InitTypeDef GPIO_InitStruct = {
			0 };
	HAL_GPIO_DeInit(NUT_LED_PORT, NUT_LED_PIN);
	HAL_GPIO_DeInit(NUT_IO_USER_PORT, NUT_IO_USER_PIN);
	HAL_GPIO_DeInit(NUT_IO1_PORT, NUT_IO1_PIN);
	HAL_GPIO_DeInit(NUT_IO2_PORT, NUT_IO2_PIN);
	HAL_GPIO_DeInit(NUT_IO3_PORT, NUT_IO3_PIN);
	HAL_GPIO_DeInit(NUT_SPI_CS_PORT, NUT_SPI_CS_PIN);

	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Pin = NUT_LED_PIN;
	HAL_GPIO_Init(NUT_LED_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = NUT_IO_USER_PIN;
	HAL_GPIO_Init(NUT_IO_USER_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = NUT_IO1_PIN;
	HAL_GPIO_Init(NUT_IO1_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = NUT_IO2_PIN;
	HAL_GPIO_Init(NUT_IO2_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = NUT_IO3_PIN;
	HAL_GPIO_Init(NUT_IO3_PORT, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = NUT_SPI_CS_PIN;
	HAL_GPIO_Init(NUT_SPI_CS_PORT, &GPIO_InitStruct);
}

NutStatus_e EnterSleep_NoWake_MainReg(uint8_t *received_data_ptr, uint32_t received_data_length, uint8_t *result_buffer_ptr, uint32_t *result_length,
		uint32_t result_buffer_MAX_size) {
	*result_length = 0;
	Nut_LED(1);
	HAL_Delay(100);
	Nut_LED(0);
	set_all_pins_pullup();
	HAL_SuspendTick();	// disable SysTick
	HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);	// enter sleep mode
	return NUT_OK;
}

NutStatus_e EnterSleep_NoWake_LPReg(uint8_t *received_data_ptr, uint32_t received_data_length, uint8_t *result_buffer_ptr, uint32_t *result_length,
		uint32_t result_buffer_MAX_size) {
	*result_length = 0;
	Nut_LED(1);
	HAL_Delay(1000);
	Nut_LED(0);
	set_all_pins_pullup();
	HAL_SuspendTick();	// disable SysTick
	HAL_PWR_EnterSLEEPMode(PWR_LOWPOWERREGULATOR_ON, PWR_SLEEPENTRY_WFI);	// enter sleep mode
	return NUT_OK;
}

NutStatus_e EnterStop_NoWake_MainReg(uint8_t *received_data_ptr, uint32_t received_data_length, uint8_t *result_buffer_ptr, uint32_t *result_length,
		uint32_t result_buffer_MAX_size) {
	*result_length = 0;
	Nut_LED(1);
	HAL_Delay(100);
	Nut_LED(0);
	HAL_Delay(100);
	Nut_LED(1);
	HAL_Delay(100);
	Nut_LED(0);
	HAL_Delay(100);
	Nut_LED(1);
	HAL_Delay(100);
	Nut_LED(0);
	set_all_pins_pullup();
	HAL_SuspendTick();	// disable SysTick
	HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON, PWR_STOPENTRY_WFI);	// enter stop mode
	return NUT_OK;
}

NutStatus_e EnterStop_NoWake_LPReg(uint8_t *received_data_ptr, uint32_t received_data_length, uint8_t *result_buffer_ptr, uint32_t *result_length,
		uint32_t result_buffer_MAX_size) {
	*result_length = 0;
	Nut_LED(1);
	HAL_Delay(1000);
	Nut_LED(0);
	HAL_Delay(1000);
	Nut_LED(1);
	HAL_Delay(1000);
	Nut_LED(0);
	HAL_Delay(1000);
	Nut_LED(1);
	HAL_Delay(1000);
	Nut_LED(0);
	set_all_pins_pullup();
	HAL_SuspendTick();	// disable SysTick
	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);	// enter stop mode
	return NUT_OK;
}

NutStatus_e EnterStandby_NoWake(uint8_t *received_data_ptr, uint32_t received_data_length, uint8_t *result_buffer_ptr, uint32_t *result_length,
		uint32_t result_buffer_MAX_size) {
	*result_length = 0;
	Nut_LED(1);
	HAL_Delay(100);
	Nut_LED(0);
	HAL_Delay(1000);
	Nut_LED(1);
	HAL_Delay(100);
	Nut_LED(0);
	HAL_Delay(1000);
	Nut_LED(1);
	HAL_Delay(100);
	Nut_LED(0);
	set_all_pins_pullup();
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);		// clear wake-up flag
	HAL_SuspendTick();	// disable SysTick
	HAL_PWR_EnterSTANDBYMode();	// enter standby mode
	return NUT_OK;
}

/* User command */
// @formatter:off
NutAction_t command_list[] = {
		{.command=0x0001, .function=Echo},
		{.command=0x0501, .function=EnterSleep_NoWake_MainReg},
		{.command=0x0502, .function=EnterSleep_NoWake_LPReg},
		{.command=0x0503, .function=EnterStop_NoWake_MainReg},
		{.command=0x0504, .function=EnterStop_NoWake_LPReg},
		{.command=0x0505, .function=EnterStandby_NoWake},
};
// @formatter:on
uint16_t command_count = sizeof(command_list) / sizeof(command_list[0]);

void User_Init() {
	Nut_LED(1);
	HAL_Delay(200);
	Nut_LED(0);
}

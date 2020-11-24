/*******************************************************************************
 * COPYRIGHT (C) VITESCO TECHNOLOGIES
 * ALL RIGHTS RESERVED.
 *
 * The reproduction, transmission or use of this document or its
 * contents is not permitted without express written authority.
 * Offenders will be liable for damages. All rights, including rights
 * created by patent grant or registration of a utility model or design,
 * are reserved.
 *******************************************************************************/

#include "BSW/MCAL/ADC/adc.h"

#include "driver/adc.h"

static const char *TAG = "MCAL ADC";

void ADC_vInit(void)
{
	adc_config_t adc_config =
	{ .mode = ADC_READ_TOUT_MODE, .clk_div = 20 };

	ESP_ERROR_CHECK(adc_init(&adc_config));
}

uint16_t ADC_u16Read(void)
{
	uint16_t u16Data = 0;

	ESP_ERROR_CHECK(adc_read(&u16Data));

	return u16Data;
}

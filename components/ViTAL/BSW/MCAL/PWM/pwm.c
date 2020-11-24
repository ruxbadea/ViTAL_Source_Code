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

#include "BSW/MCAL/PWM/pwm.h"

#include "driver/pwm.h"

static const char *TAG = "MCAL PWM";

/* Default duty-cycles for each channel */
uint32_t g_u32Duties[PWM_CHANNELS] =
{ 1500, 0, 0 };

/* Pin numbers on board for each channel */
uint32_t g_u32PinNum[PWM_CHANNELS] =
{ SERVO_MOTOR_PWM_PIN, DC_MOTOR_PWM_PIN, BUZZER_PWM_PIN };

void PWM_vInit(void)
{
	/* Configure PWM with initial settings */
	ESP_ERROR_CHECK(
			pwm_init(PWM_PERIOD, g_u32Duties, PWM_CHANNELS, g_u32PinNum));

	/* Start the PWM */
	ESP_ERROR_CHECK(pwm_start());

	/* Configure DC motor PWM phase */
	ESP_ERROR_CHECK(pwm_set_phase(DC_MOTOR_PWM_CHANNEL, 0));

	/* Apply settings */
	ESP_ERROR_CHECK(pwm_start());

	/* Configure SERVO motor PWM phase */
	ESP_ERROR_CHECK(pwm_set_phase(SERVO_MOTOR_PWM_CHANNEL, 0));

	/* Apply settings */
	ESP_ERROR_CHECK(pwm_start());

	/* Configure SERVO motor PWM phase */
	ESP_ERROR_CHECK(pwm_set_phase(BUZZER_PWM_CHANNEL, 0));

	/* Apply settings */
	ESP_ERROR_CHECK(pwm_start());
}

void PWM_vSetDutyCycle(uint8_t u8Channel, uint32_t u32DutyCycle)
{
	/* Set duty cycle for this channel */
	ESP_ERROR_CHECK(pwm_set_duty(u8Channel, u32DutyCycle));

	/* Apply settings */
	ESP_ERROR_CHECK(pwm_start());
}

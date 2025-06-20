/*
 * infrarot.c
 *
 *  Created on: Jun 20, 2025
 *      Author: jelly
 */

#include "adc.h"
#include "infrarot.h"

float InfrarotSensorRead(uint32_t sensorfr)
{

		uint32_t sensor[4];
	    HAL_ADC_Start(&hadc);

	    for (int i = 0; i < 4; i++) {
	        HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);
	        sensor[i] = HAL_ADC_GetValue(&hadc);
	    }
	    HAL_ADC_Stop(&hadc);


	    if (sensorfr==1){
    return sensor[0];}

	    else if (sensorfr==2){
    return sensor[1];}

	    else if (sensorfr==3){
    return sensor[2];}

	    else if (sensorfr==4){
    return sensor[3];}

}

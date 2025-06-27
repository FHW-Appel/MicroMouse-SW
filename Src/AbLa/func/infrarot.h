/*
 * infrarot.h
 *
 *  Created on: Jun 13, 2025
 *      Author: Phivo
 */

#ifndef SRC_ABLA_FUNC_INFRAROT_H_
#define SRC_ABLA_FUNC_INFRAROT_H_


uint32_t sensorValue;
float InfrarotSensorRead()
{
    HAL_ADC_Start(&hadc);
    HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);
    uint32_t sensorValue = HAL_ADC_GetValue(&hadc);
    HAL_ADC_Stop(&hadc);
    return sensorValue;
}



#endif /* SRC_ABLA_FUNC_INFRAROT_H_ */

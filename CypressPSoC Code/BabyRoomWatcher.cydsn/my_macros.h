/* 
 Project:    Baby Room Wtcher
 By:         Raymond Alavo
*/
    
#include <project.h>
    
#define FILTER_COEFFICIENT_ALS			        (10)


#define ALS_CURRENT_SCALE_FACTOR_NUMERATOR		(-26633)
#define ALS_CURRENT_SCALE_FACTOR_DENOMINATOR	(10000)

/#define ALS_LIGHT_SCALE_FACTOR_NUMERATOR		(3333)
#define ALS_LIGHT_SCALE_FACTOR_DENOMINATOR		(1000)

#define LED_ON                      (0u)
#define LED_OFF                     (1u)
#define MOTION_DETECTED             (1u)
#define MOTION_NOT_DETECTED         (0u)
#define THREE_FEET                  (3u)
#define TEN_FEET                    (10u)
#define TWENTY_FEET                 (20u)
#define ADC_CHANNEL_PIR             (0u)
#define ADC_CHANNEL_VREF            (1u)
#define ADC_CHANNEL_VTH             (2u)
#define ADC_CHANNEL_ALS             (3u)
#define SENSOR_RAW_INITIAL          (0)
/* EzI2C Read/Write Boundary */
#define READ_WRITE_BOUNDARY         (1u)


#define PIR_WINDOW_HIGH_3FT         (1200)
/* Low Threshold for 3 feet detection (80% of negative peak count) */
#define PIR_WINDOW_LOW_3FT          (-1200)   
/* High Threshold for 10 feet detection (80% of positive peak count) */
#define PIR_WINDOW_HIGH_10FT        (600)
/* Low Threshold for 10 feet detection (80% of negative peak count) */
#define PIR_WINDOW_LOW_10FT         (-600)
/* High Threshold for 20 feet detection (80% of positive peak count) */    
#define PIR_WINDOW_HIGH_20FT        (1200)
/* Low Threshold for 20 feet detection (80% of negative peak count) */   
#define PIR_WINDOW_LOW_20FT         (-1200)
	
#define FILTER_COEFFICIENT_TEMPERATURE	(32u)
    
/* Constants used to calculate humidity */
/* This is the capacitance of the sensor at 55% RH with 0.1pF resolution */
#define CAPACITANCE_AT_55_RH        (1800)
/* Sensitivity numerator and denominator indicate sensitivity of the sensor */
#define SENSITIVITY_NUMERATOR       (31)
#define SENSITIVITY_DENOMINATOR     (100)
/* Value of reference capacitor.  Note that this value includes the pin capacitance
    and the physical 180pF reference capacitor */
#define CREF                        (1930)
/* Offset Capacitance */
#define COFFSET                     (150)
/* This is raw count equivalent to trace capacitance */
#define OFFSETCOUNT                 (1536)
#define BUFFERSIZE                  (8)

/* Nominal humidity 55% */
#define NOMINAL_HUMIDITY            (550)
#define HUMIDITY_0_PERCENT          (0)
#define HUMIDITY_100_PERCENT        (1000)
#define HUMIDITY_50                 (500)   


//Reduced Size to 14bytes
typedef struct __attribute__((packed)) /* Structure that holds the sensor values                                        */
{
    
    uint8 detectionDistance;      	/* PIR detection distance */
	int16 sensorRawValue;        	/* ADC result */
	int16 highThreshold;		    /* High threshold for motion detection */
	int16 lowThreshold;			    /* Low threshold for motion detection */
    uint8 motionDetected;		    /* Motion detection flag */
    
	int16 temperature;			/* Measured temperature */
    
	uint16 illuminance; 		/* Ambient light illuminance */	
    
	uint16 humidity;			/* Measured humidity */
}psoc_data;


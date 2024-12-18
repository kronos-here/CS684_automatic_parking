/*
 * eBot_Sim_Predef.h
 *
 *  Created on: 11-Jan-2021
 *      Author: TAs of CS 684 Spring 2020
 */

#ifndef EBOT_SIM_PREDEF_H_
#define EBOT_SIM_PREDEF_H_


//---------------------------------- INCLUDES ----------------------------------

#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>

extern "C" {
	#include "extApi.h"
}


//---------------------------------- CONSTANTS ----------------------------------


#define LINEAR_VELOCITY_MAX			10

#define VIS_SEN_INITIAL_VAL			100

#define FRONT_IR_PROX_NUMBER 		4

#define LEFT_WL_SENS_NUMBER			0
#define CENTER_WL_SENS_NUMBER		3
#define RIGHT_WL_SENS_NUMBER		6

#define left_wl_sensor_channel		1
#define center_wl_sensor_channel	2
#define right_wl_sensor_channel		3
#define left_ir_sensor_channel	    4
#define center_ir_sensor_channel	5
#define right_ir_sensor_channel	    6

//---------------------------------- FUNCTIONS ----------------------------------

void init_remote_api_server(void);
void get_object_handles(void);
void start_simulation(void);
void get_white_line_sensor_data(void);
void init_vision_sensors(void);
unsigned char get_front_prox_sensor_distance(unsigned char);
void init_prox_sensors(void);
void init_sensors(void);
int init_setup(void);
unsigned char read_px(int,int);
unsigned char convert_analog_channel_data(int, unsigned char);
int print_ir_prox_5_data(unsigned char, unsigned char, unsigned char);
void set_motor_velocities(void);
void rob_forward(int);
void back(int);
void left(int);
void right(int);
void soft_left(int);
void soft_right(int);
void stop(int);
void velocity(int,int, int);
void thread_calls(void);
void _delay_ms(unsigned int);
void stop_simulation(void);
void exit_remote_api_server(void);
void clean_up(void);


#endif /* EBOT_SIM_PREDEF_H_ */

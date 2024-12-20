/*
 * eBot_Sandbox.cpp
 *
 *  Created on: 11-Jan-2021
 *      Author: TAs of CS 684 Spring 2020
 */

#include "eBot_Sandbox.h"
#include "controller.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "server.h"
using namespace std;
Controller__main_mem mem;

//------------------------------ GLOBAL VARIABLES -------------------------------
// To store 8-bit data of left, center and right white line sensors
// unsigned char left_wl_sensor_data, center_wl_sensor_data, right_wl_sensor_data;
unsigned int left_wl_sensor_data, center_wl_sensor_data, right_wl_sensor_data;

// To store 8-bit data of 5th IR proximity sensors
unsigned char left_ir_sensor_data, center_ir_sensor_data, right_ir_sensor_data;

//---------------------------------- INCLUDES -----------------------------------


unsigned char Velocity_max = 250;
float Kp2 = 1;
float Ki2 = 0.0000;
float Kd2 = 0.217;


int diff, error, difference_error,integration_error[5] = {0,0,0,0,0}, prev_error[5] = {0,0,0,0,0}, speed, flag = 0;
// To store 8-bit data of 5th IR proximity sensors
unsigned char ir_prox_5_sensor_data;
void traverse_line_ta(int rob_num)
{
	if (center_wl_sensor_data == 0)
    	error = 0;
    else
	error = 120*(right_wl_sensor_data - left_wl_sensor_data);

	difference_error = error - prev_error[rob_num];
	integration_error[rob_num] += error/50;
	if(error == 0 && center_wl_sensor_data == 1)
		error = -(1 * prev_error[rob_num]);

	speed = Kp2 * error + Kd2 * difference_error + Ki2 * integration_error[rob_num];
	prev_error[rob_num] = error;

	if (speed > Velocity_max)
		speed = Velocity_max;
	if (speed < -Velocity_max)
		speed = -Velocity_max;

	if(speed > 0)
		velocity(rob_num,Velocity_max - speed, Velocity_max);
	else
	{
		speed = abs(speed);
		velocity(rob_num,Velocity_max, Velocity_max - speed);
	}
	
}


int my_speed = 200;
int er_norm_factor = 100;

float Kp = 1;
float Ki = 0.08;
float Kd = 0.01;
float s[5] = {0,0,0,0,0}, e_prev[5] = {0,0,0,0,0};



void traverse_line(int rob_num)
{
        
	rob_forward(rob_num);
	
	// Calculating error
	// er_norm_factor currently at 80
	float er = er_norm_factor*((0.0 + center_wl_sensor_data + 2.0*right_wl_sensor_data)/(left_wl_sensor_data + center_wl_sensor_data + right_wl_sensor_data) - 1);
	
	// Integral error for indexed robot
	s[rob_num] = (0.5)*s[rob_num] + er;
	
	// difference error
	float d = er - e_prev[rob_num];
	e_prev[rob_num] = er;
	
	// The net actuation
	int c = (unsigned int)(Kp*er + Ki*s[rob_num] + Kd*d);
	if (c < 0) velocity(rob_num,my_speed - c, my_speed);
	else velocity(rob_num,my_speed, my_speed + c);
	
	set_motor_velocities();
}



void turn_left(int rob_num){
        printf("\n left turn ");
	int t = 0;
	rob_forward(rob_num);
	while(true){
		if (t > 5){
		    velocity(rob_num,50, 50);
		    set_motor_velocities();
	    	break;
	                   }
	        else{
	    	    velocity(rob_num, 100, 200);
	    	    set_motor_velocities();
	                   }
	    t++;
	    _delay_ms(100);
	}

}

void turn_right(int rob_num){
	printf("\n right turn ");
	int t = 0;
	rob_forward(rob_num);
	while(true){
		if (t > 5){
		    velocity(rob_num,50, 50);
		    set_motor_velocities();
	    	break;
	                   }
	        else{
	    	    velocity(rob_num, 200, 100);
	    	    set_motor_velocities();
	                   }
	    t++;
	    _delay_ms(100);
	    }
}

void swivel_left_90(int rob_num){
	printf("\n left swivel ");
	int t = 0;
	rob_forward(rob_num);
	while(true){
		if (t > 6){
		    velocity(rob_num,50, 50);
		    set_motor_velocities();
	    	break;
	                   }
	        else{
	    	    velocity(rob_num, 0, 200);
	    	    set_motor_velocities();
	                   }
	    t++;
	    _delay_ms(100);
	    }
}

void swivel_right_90(int rob_num){
	printf("\n right swivel ");
	int t = 0;
	rob_forward(rob_num);
	while(true){
		if (t > 6){
		    velocity(rob_num,50, 50);
		    set_motor_velocities();
	    	break;
	                   }
	        else{
	    	    velocity(rob_num, 200, 0);
	    	    set_motor_velocities();
	                   }
	    t++;
	    _delay_ms(100);
	    }
}

void park_robot(int rob_num){
	printf("\n park ");
	int t = 0;
	rob_forward(rob_num);
	while(true){
		if (t > 2){
		    velocity(rob_num,0, 0);
		    set_motor_velocities();
	    	break;
	                   }
	        else{
	    	    velocity(rob_num, 100, 100);
	    	    set_motor_velocities();
	                   }
	    t++;
	    _delay_ms(100);
         }
}

void double_swivel(int rob_num){
	float t = 0;
		left(rob_num);
		while(true){
			if (t > 10.0){
				velocity(rob_num,0, 0);
				set_motor_velocities();
		    	break;
		    }
		    else{
		    	velocity(rob_num, 200, 200);
		    	set_motor_velocities();
		    }
		    printf("\n Time (sec) : %f",t);
		    t++;
		    _delay_ms(100);
		    }
   }



int dir[number_of_robots][30];
int rob_path[number_of_robots][30];
char name[number_of_robots];
int entry_time[number_of_robots];
int exit_time[number_of_robots];
int deadline[number_of_robots];
int gate[number_of_robots];

void send_sensor_data(void)
{
	start_webserver();


	FILE *file_obs;
	if ((file_obs = fopen("obstacles.txt","w")) == NULL){
	fprintf(stderr,"Input File error\n");
	exit(-1);
	}

	for (int j = 0; j<40; j++){
		int sensor_distance = read_px(j,2);
		printf("\n%hhu %hhu",j+1,sensor_distance);
		if (sensor_distance < 50){
			fprintf(file_obs,"%d\n",95-j);
			reserved.push_back(95-j);
		}
		else if (sensor_distance < 100){
			fprintf(file_obs,"%d\n",54-j-2*(j/5));
			reserved.push_back(54-j-2*(j/5));
		}
	}
	fclose(file_obs);

	int system(const char* command);
	char arr[30] = "python3 src/scheduler.py";
	system (arr);
	
	
	FILE *file;
	if ((file = fopen("schedule.txt","r")) == NULL){
	fprintf(stderr,"Input File error\n");
	exit(-1);
	}
	
	// Instructions set from python
	for (int i = 0; i < number_of_robots; i++){
		int x;
		int count = 0;
		char c;
		fscanf(file,"%c",&c);
		fscanf(file,"%d",&entry_time[i]);
		fscanf(file,"%d",&exit_time[i]);
		fscanf(file,"%d",&deadline[i]);
		fscanf(file,"%d",&gate[i]);
		cout << endl << "Cars " << i << " " << c << ", " << entry_time[i] << " " << exit_time[i] << ", " << deadline[i] << " " << gate[i] << endl;
		while (count < 30){
			fscanf(file,"%d",&x);
			if (x == -1) break;
			rob_path[i][count] = x;
			count++;
		}
		count = 0;
		while (count < 30){
			fscanf(file,"%d",&x);
			dir[i][count] = x;
			if (x == 0) break;
			count++;
		}

		cars.push_back(SelfParkingCar(string(1, c), entry_time[i], deadline[i], exit_time[i], gate[i]+95, i));
		fscanf(file,"%c",&c);
	}

	printf("\n\tPress any key to start ");
	char input_cmd = getchar();
	input_cmd = getchar();

	t_start = std::chrono::high_resolution_clock::now();
	t_end = std::chrono::high_resolution_clock::now();
	global_clock = std::chrono::duration<double, std::milli>(t_end-t_start).count()/1000.0;


//	for (int i = 0; i < number_of_robots; i++){
//
//	}


}

void* actuate_robot(void* rob_address)
{
	//Controller__main_out _res;
        //Controller__main_reset(&mem);
        
	int count = 1;
		
	bool node = false,in_node = false;
	int comms = 0;
	int i = *(int*)rob_address;
	_delay_ms(1000*entry_time[i]);
	while (true)
	{    
	        
		// Taking the sensor data for line
		left_wl_sensor_data = convert_analog_channel_data(i, left_wl_sensor_channel);
		center_wl_sensor_data = convert_analog_channel_data(i, center_wl_sensor_channel);
		right_wl_sensor_data = convert_analog_channel_data(i, right_wl_sensor_channel);
					
		// Is node or not? == 1
		node =  ((left_wl_sensor_data == 0)&&(center_wl_sensor_data == 0)&&(right_wl_sensor_data == 0));
					
		left_ir_sensor_data	= convert_analog_channel_data(i, left_ir_sensor_channel);
		center_ir_sensor_data = convert_analog_channel_data(i, center_ir_sensor_channel);
		right_ir_sensor_data = convert_analog_channel_data(i, right_ir_sensor_channel);

                //if ((node == true) && (in_node == false)){
                //Controller__main_step(left_wl_reading, center_wl_reading, right_wl_reading, comms, &_res, &mem);
		//forward();
		//velocity(_res.v_l, _res.v_r);
		//set_motor_velocities();
		//}
		//Decision section
		printf("\nDetected %d %d %d %d",i,left_wl_sensor_data, center_wl_sensor_data, right_wl_sensor_data);
		comms = dir[i][count];
		
		if ((node == true) && (in_node == false)){
			printf("\nRobot %d Comms %d %d",i,comms, count);
			if (comms == 1){
				rob_forward(i);
				velocity(i,my_speed,my_speed);
				set_motor_velocities();
			}
			else if (comms == 2) {
				turn_left(i);
			}
			else if (comms == 3) {
				turn_right(i);
			}
			else if (comms == 4) {
				swivel_left_90(i);
			} 
			else if (comms == 5) {
				swivel_right_90(i);
			}
			else {
				park_robot(i);
			}
			in_node = true;
			s[i] = 0; e_prev[i] = 0;
			
			_delay_ms(100);
			t_end = std::chrono::high_resolution_clock::now();
			global_clock = std::chrono::duration<double, std::milli>(t_end-t_start).count()/1000.0;
			cars[i].update_position(global_clock, rob_path[i][count]);
//			cout << "Clock is " << global_clock << endl;
		}
		else if ((node == true) && (in_node == true)){
			rob_forward(i);
			velocity(i,20,20);
			set_motor_velocities();
			_delay_ms(20);
		}
		else {
		if (in_node == true) count++;
			in_node = false;
			traverse_line(i);	
			_delay_ms(1);

		}

		t_end = std::chrono::high_resolution_clock::now();
		global_clock = std::chrono::duration<double, std::milli>(t_end-t_start).count()/1000.0;

	}
}

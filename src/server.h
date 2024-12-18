/*
 * server.h
 *
 *  Created on: 28-Apr-2022
 *      Author: priyesh
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <stdlib.h>

#include <bits/stdc++.h>
#include <httpserver.hpp>

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include<bits/stdc++.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>
#include <chrono>

#include "json.cpp"

using namespace httpserver;



class SelfParkingCar {
public:
	std::string id;
	float in_time;
	float out_time;
	float parking_deadline;
	float park_in;
	float park_out;
	float leaving_deadline;
	int position;
	float arrival_tt;
	float departure_tt;
	int index;
	std::string state;


	SelfParkingCar();
	SelfParkingCar(std::string id, float start, float deadline, float endtime, int gate, int i);

	void update_position(float clock, int new_position);

	nlohmann::json to_json();

	bool is_at_gate(int);
	bool is_in_transit(int);
	bool is_parked(int);

};


using namespace httpserver;

class api_response: public http_resource {
public:
	const std::shared_ptr<http_response> render(const http_request&);
};



void start_webserver(void);


extern std::chrono::high_resolution_clock::time_point t_start, t_end;
extern double global_clock;
extern double parking_clock;
extern std::vector<SelfParkingCar> cars;
extern std::vector<int> reserved;



#endif /* SERVER_H_ */

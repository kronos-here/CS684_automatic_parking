/*
 * server.cpp
 *
 *  Created on: 28-Apr-2022
 *      Author: priyesh
 */

#include "server.h"

using namespace std;
using json = nlohmann::json;
using namespace httpserver;

std::chrono::high_resolution_clock::time_point t_start, t_end;
double global_clock = 0.0;
vector<SelfParkingCar> cars;
vector<int> reserved;

SelfParkingCar::SelfParkingCar() {
}

bool SelfParkingCar::is_at_gate(int pos) {
	return pos >= 96 and pos <= 99;
}

bool SelfParkingCar::is_in_transit(int pos) {
	return pos >= 0 and pos <= 55;
}

bool SelfParkingCar::is_parked(int pos) {
	return pos >= 56 and pos <= 95;
}




SelfParkingCar::SelfParkingCar(string id, float start, float deadline,
		float endtime, int gate, int i) {
	cout << "New car " << id << endl;
	this->id = id;
	in_time = start;
	out_time = -1;
	parking_deadline = deadline;
	park_in = park_out = -1;
	leaving_deadline = endtime;
	position = gate;
	arrival_tt = departure_tt = -1;
	index = i;
}

void SelfParkingCar::update_position(float clock, int new_position) {
	/**
	 * State transitions
	 * Entry Gate
	 * Parking target path
	 * Parked
	 * Exit gate path
	 * Exit Gate
	 *
	 */

	if (is_at_gate(position) and is_in_transit(new_position)) {
		// Started moving towards parking spot
	} else if (is_in_transit(position) and is_parked(new_position)) {
		// Just now parked
		park_in = clock;
		arrival_tt = (park_in-in_time)/2.0;
	} else if (is_parked(position) and is_in_transit(new_position)) {
		// Moving towards exit
		park_out = clock;
	} else if (is_in_transit(position) and is_at_gate(new_position)) {
		// At exit gate
		out_time = clock;
		departure_tt = (out_time-park_out)/2.0;
	} else if (is_in_transit(position) and is_in_transit(new_position)) {
		// Moving path
	} else {
		// Don't know
	}

	position = new_position;
}

json SelfParkingCar::to_json() {
	json j;
	j["id"] = id;
	j["in_time"] = in_time;
	j["out_time"] = out_time;
	j["parking_deadlne"] = parking_deadline;
	j["park_in"] = park_in;
	j["park_out"] = park_out;
	j["leaving_deadline"] = leaving_deadline;
	j["last_position"] = position;
	j["arrival_tt"] = arrival_tt;
	j["dearture_tt"] = departure_tt;
	j["overall_tt"] = (arrival_tt + departure_tt) / 2.0;

	return j;

}

const std::shared_ptr<http_response> api_response::render(const http_request&) {
	json res;
	json c;
	res["clock"] = global_clock;

	for (auto x : cars) {
//		cout << x.id << " " << x.in_time << endl;
		c[x.id] = x.to_json();
	}

	// TODO: Add available/not available parking details
	res["cars"] = c;
	res["reserved"] = reserved;
;
//	res['obstacle'] = {};
	return std::shared_ptr<http_response>(new string_response(res.dump()));
}

void* run(void*) {
	cout << "Creating webserver" << endl;
	webserver ws = create_webserver(8080);
	api_response hwr;
	ws.register_resource("/", &hwr);
	ws.start(true);
	return NULL;
}

void start_webserver(void) {

	pthread_t server;
	pthread_attr_t attr;
	// pthread_attr_t initialization
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	pthread_create(&server,&attr,run,NULL);

}



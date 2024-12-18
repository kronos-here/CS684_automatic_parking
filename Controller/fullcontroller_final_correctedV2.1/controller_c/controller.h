/* --- Generated the 24/4/2022 at 0:26 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. jan. 31 15:41:33 CET 2022) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts Controller.ept --- */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "controller_types.h"
typedef struct Controller__find_velocities_out {
  int v_l;
  int v_r;
} Controller__find_velocities_out;

void Controller__find_velocities_step(int speed,
                                      Controller__find_velocities_out* _out);

typedef struct Controller__adacrus_mem {
  Controller__st ck;
  int v_62;
  int v_60;
  int v_58;
  int v_56;
  int v_67;
  int v_65;
  int v_72;
  int v_70;
  int v_77;
  int v_75;
  int v_82;
  int v_80;
  int v_32;
  int v_30;
  int v_29;
  int v_27;
  int v_26;
  int v_19;
  int v_18;
  int v_12;
  int pnr;
} Controller__adacrus_mem;

typedef struct Controller__adacrus_out {
  int v_l;
  int v_r;
  int nod;
} Controller__adacrus_out;

void Controller__adacrus_reset(Controller__adacrus_mem* self);

void Controller__adacrus_step(int left_wl, int center_wl, int right_wl,
                              int comms, Controller__adacrus_out* _out,
                              Controller__adacrus_mem* self);

typedef struct Controller__main_mem {
  Controller__adacrus_mem adacrus;
} Controller__main_mem;

typedef struct Controller__main_out {
  int v_l;
  int v_r;
  int nod;
} Controller__main_out;

void Controller__main_reset(Controller__main_mem* self);

void Controller__main_step(int left_wl, int center_wl, int right_wl,
                           int comms, Controller__main_out* _out,
                           Controller__main_mem* self);

#endif // CONTROLLER_H

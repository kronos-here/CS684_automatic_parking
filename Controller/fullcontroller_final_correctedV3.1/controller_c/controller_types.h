/* --- Generated the 27/4/2022 at 3:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. jan. 31 15:41:33 CET 2022) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts Controller.ept --- */

#ifndef CONTROLLER_TYPES_H
#define CONTROLLER_TYPES_H

#include "stdbool.h"
#include "assert.h"
#include "pervasives.h"
typedef enum {
  Controller__St_RTurn,
  Controller__St_RSwi,
  Controller__St_Order,
  Controller__St_LTurn,
  Controller__St_LSwi,
  Controller__St_Fwdimpulse,
  Controller__St_Forward,
  Controller__St_DoubleSwi
} Controller__st;

Controller__st Controller__st_of_string(char* s);

char* string_of_Controller__st(Controller__st x, char* buf);

static const float Controller__kp = 0.120000;

static const float Controller__ki = 0.080000;

static const float Controller__kd = 0.010000;

static const float Controller__max_velocity = 200.000000;

static const int Controller__turntime = 2;

static const int Controller__swiveltime = 2;

#endif // CONTROLLER_TYPES_H

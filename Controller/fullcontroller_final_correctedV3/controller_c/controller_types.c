/* --- Generated the 24/4/2022 at 1:39 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. jan. 31 15:41:33 CET 2022) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts Controller.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "controller_types.h"

Controller__st Controller__st_of_string(char* s) {
  if ((strcmp(s, "St_RTurn")==0)) {
    return Controller__St_RTurn;
  };
  if ((strcmp(s, "St_RSwi")==0)) {
    return Controller__St_RSwi;
  };
  if ((strcmp(s, "St_Order")==0)) {
    return Controller__St_Order;
  };
  if ((strcmp(s, "St_LTurn")==0)) {
    return Controller__St_LTurn;
  };
  if ((strcmp(s, "St_LSwi")==0)) {
    return Controller__St_LSwi;
  };
  if ((strcmp(s, "St_Fwdimpulse")==0)) {
    return Controller__St_Fwdimpulse;
  };
  if ((strcmp(s, "St_Forward")==0)) {
    return Controller__St_Forward;
  };
}

char* string_of_Controller__st(Controller__st x, char* buf) {
  switch (x) {
    case Controller__St_RTurn:
      strcpy(buf, "St_RTurn");
      break;
    case Controller__St_RSwi:
      strcpy(buf, "St_RSwi");
      break;
    case Controller__St_Order:
      strcpy(buf, "St_Order");
      break;
    case Controller__St_LTurn:
      strcpy(buf, "St_LTurn");
      break;
    case Controller__St_LSwi:
      strcpy(buf, "St_LSwi");
      break;
    case Controller__St_Fwdimpulse:
      strcpy(buf, "St_Fwdimpulse");
      break;
    case Controller__St_Forward:
      strcpy(buf, "St_Forward");
      break;
    default:
      break;
  };
  return buf;
}


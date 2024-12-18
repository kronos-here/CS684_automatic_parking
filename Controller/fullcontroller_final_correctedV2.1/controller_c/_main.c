/* --- Generated the 24/4/2022 at 0:26 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. jan. 31 15:41:33 CET 2022) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts Controller.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

Controller__main_mem mem;
int main(int argc, char** argv) {
  int step_c;
  int step_max;
  int left_wl;
  int center_wl;
  int right_wl;
  int comms;
  Controller__main_out _res;
  step_c = 0;
  step_max = 0;
  if ((argc==2)) {
    step_max = atoi(argv[1]);
  };
  Controller__main_reset(&mem);
  while ((!(step_max)||(step_c<step_max))) {
    step_c = (step_c+1);
    
    if ((scanf("%d", &left_wl)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &center_wl)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &right_wl)==EOF)) {
      return 0;
    };;
    
    if ((scanf("%d", &comms)==EOF)) {
      return 0;
    };;
    Controller__main_step(left_wl, center_wl, right_wl, comms, &_res, &mem);
    printf("%d\n", _res.v_l);
    printf("%d\n", _res.v_r);
    printf("%d\n", _res.nod);
    fflush(stdout);
  };
  return 0;
}


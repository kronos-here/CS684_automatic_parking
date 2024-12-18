/* --- Generated the 22/4/2022 at 3:11 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. jan. 31 15:41:33 CET 2022) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts Controller.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "controller.h"

void Controller__find_velocities_step(int speed,
                                      Controller__find_velocities_out* _out) {
  
  int v_9;
  int v_8;
  int v_7;
  int v_6;
  int v_5;
  int v_4;
  int v_3;
  int v_2;
  int v_1;
  int v;
  v_4 = -(speed);
  v_5 = (200-v_4);
  v_3 = (200-speed);
  v_2 = (speed>0);
  if (v_2) {
    v_7 = 200;
    v_6 = v_3;
  } else {
    v_7 = v_5;
    v_6 = 200;
  };
  v_1 = (speed<-200);
  if (v_1) {
    v_9 = 0;
    v_8 = 200;
  } else {
    v_9 = v_7;
    v_8 = v_6;
  };
  v = (speed>200);
  if (v) {
    _out->v_r = 200;
    _out->v_l = 0;
  } else {
    _out->v_r = v_9;
    _out->v_l = v_8;
  };;
}

void Controller__adacrus_reset(Controller__adacrus_mem* self) {
  self->v_59 = true;
  self->v_54 = true;
  self->v_49 = true;
  self->v_44 = true;
  self->v_39 = true;
  self->v_37 = true;
  self->v_35 = true;
  self->pnr = false;
  self->ck = Controller__St_Order;
  self->v_33 = true;
  self->v_26 = true;
  self->v_23 = true;
  self->v_15 = true;
  self->v = true;
}

void Controller__adacrus_step(int left_wl, int center_wl, int right_wl,
                              int comms, Controller__adacrus_out* _out,
                              Controller__adacrus_mem* self) {
  Controller__find_velocities_out Controller__find_velocities_out_st;
  
  int v_42;
  int v_40;
  int v_38;
  int v_36;
  int t_4;
  int v_47;
  int v_45;
  int v_43;
  int t_3;
  int v_52;
  int v_50;
  int v_48;
  int t_2;
  int v_57;
  int v_55;
  int v_53;
  int t_1;
  int v_62;
  int v_60;
  int v_58;
  int t;
  int v_84;
  Controller__st v_83;
  int v_82;
  Controller__st v_81;
  int v_80;
  Controller__st v_79;
  int v_78;
  Controller__st v_77;
  int v_76;
  Controller__st v_75;
  int v_74;
  int v_73;
  int v_72;
  int v_71;
  int v_70;
  int v_69;
  int v_68;
  int v_67;
  int v_66;
  int v_65;
  int v_64;
  int v_63;
  int nr_St_Fwdimpulse;
  Controller__st ns_St_Fwdimpulse;
  int v_r_St_Fwdimpulse;
  int v_l_St_Fwdimpulse;
  int nr_St_RSwi;
  Controller__st ns_St_RSwi;
  int v_r_St_RSwi;
  int v_l_St_RSwi;
  int nr_St_LSwi;
  Controller__st ns_St_LSwi;
  int v_r_St_LSwi;
  int v_l_St_LSwi;
  int nr_St_RTurn;
  Controller__st ns_St_RTurn;
  int v_r_St_RTurn;
  int v_l_St_RTurn;
  int nr_St_LTurn;
  Controller__st ns_St_LTurn;
  int v_r_St_LTurn;
  int v_l_St_LTurn;
  int nr_St_Forward;
  Controller__st ns_St_Forward;
  int v_r_St_Forward;
  int v_l_St_Forward;
  int nr_St_Order;
  Controller__st ns_St_Order;
  int v_r_St_Order;
  int v_l_St_Order;
  int v_34;
  int v_32;
  int v_31;
  int v_30;
  int v_29;
  int v_28;
  int v_25;
  int v_22;
  int v_21;
  int v_20;
  int v_19;
  int v_18;
  int v_17;
  int v_14;
  int v_13;
  int v_12;
  int v_11;
  int v_10;
  Controller__st ns;
  int r;
  int nr;
  int error;
  int difference_error;
  int integration_error;
  int speed;
  r = self->pnr;
  v_32 = (left_wl==1);
  v_30 = (center_wl==1);
  v_29 = (right_wl==1);
  v_31 = (v_29&&v_30);
  _out->nod = (v_31&&v_32);
  v_19 = (right_wl-left_wl);
  v_20 = (100*v_19);
  v_17 = -(self->v_16);
  if (self->v_15) {
    v_18 = 0;
  } else {
    v_18 = v_17;
  };
  v_13 = (center_wl==1);
  v_11 = (right_wl-left_wl);
  v_12 = (v_11==0);
  v_14 = (v_12&&v_13);
  if (v_14) {
    v_21 = v_18;
  } else {
    v_21 = v_20;
  };
  v_10 = (center_wl==0);
  if (v_10) {
    v_22 = 0;
  } else {
    v_22 = v_21;
  };
  if (self->v) {
    error = 0;
  } else {
    error = v_22;
  };
  v_34 = (1*error);
  if (self->v_33) {
    speed = 0;
  } else {
    speed = v_34;
  };
  v_28 = (self->v_27+error);
  if (self->v_26) {
    integration_error = 0;
  } else {
    integration_error = v_28;
  };
  v_25 = (error-self->v_24);
  if (self->v_23) {
    difference_error = error;
  } else {
    difference_error = v_25;
  };
  switch (self->ck) {
    case Controller__St_Order:
      v_r_St_Order = 0;
      v_l_St_Order = 0;
      v_73 = (comms==6);
      v_74 = (_out->nod&&v_73);
      if (v_74) {
        v_76 = true;
        v_75 = Controller__St_Fwdimpulse;
      } else {
        v_76 = false;
        v_75 = Controller__St_Order;
      };
      v_71 = (comms==5);
      v_72 = (_out->nod&&v_71);
      if (v_72) {
        v_78 = true;
        v_77 = Controller__St_RSwi;
      } else {
        v_78 = v_76;
        v_77 = v_75;
      };
      v_69 = (comms==4);
      v_70 = (_out->nod&&v_69);
      if (v_70) {
        v_80 = true;
        v_79 = Controller__St_LSwi;
      } else {
        v_80 = v_78;
        v_79 = v_77;
      };
      v_67 = (comms==3);
      v_68 = (_out->nod&&v_67);
      if (v_68) {
        v_82 = true;
        v_81 = Controller__St_RTurn;
      } else {
        v_82 = v_80;
        v_81 = v_79;
      };
      v_65 = (comms==2);
      v_66 = (_out->nod&&v_65);
      if (v_66) {
        v_84 = true;
        v_83 = Controller__St_LTurn;
      } else {
        v_84 = v_82;
        v_83 = v_81;
      };
      v_63 = (comms==1);
      v_64 = (_out->nod&&v_63);
      if (v_64) {
        nr_St_Order = true;
        ns_St_Order = Controller__St_Forward;
      } else {
        nr_St_Order = v_84;
        ns_St_Order = v_83;
      };
      _out->v_l = v_l_St_Order;
      _out->v_r = v_r_St_Order;
      ns = ns_St_Order;
      nr = nr_St_Order;
      break;
    case Controller__St_Forward:
      Controller__find_velocities_step(speed,
                                       &Controller__find_velocities_out_st);
      v_l_St_Forward = Controller__find_velocities_out_st.v_l;
      v_r_St_Forward = Controller__find_velocities_out_st.v_r;
      if (_out->nod) {
        nr_St_Forward = true;
        ns_St_Forward = Controller__St_Order;
      } else {
        nr_St_Forward = false;
        ns_St_Forward = Controller__St_Forward;
      };
      _out->v_l = v_l_St_Forward;
      _out->v_r = v_r_St_Forward;
      ns = ns_St_Forward;
      nr = nr_St_Forward;
      break;
    case Controller__St_LTurn:
      v_62 = (self->v_61+1);
      if (self->v_59) {
        v_60 = true;
      } else {
        v_60 = r;
      };
      if (v_60) {
        t = 0;
      } else {
        t = v_62;
      };
      v_r_St_LTurn = 200;
      v_l_St_LTurn = 50;
      v_58 = (t==Controller__turntime);
      if (v_58) {
        nr_St_LTurn = true;
        ns_St_LTurn = Controller__St_Forward;
      } else {
        nr_St_LTurn = false;
        ns_St_LTurn = Controller__St_LTurn;
      };
      _out->v_l = v_l_St_LTurn;
      _out->v_r = v_r_St_LTurn;
      ns = ns_St_LTurn;
      nr = nr_St_LTurn;
      self->v_61 = t;
      self->v_59 = false;
      break;
    case Controller__St_RTurn:
      v_57 = (self->v_56+1);
      if (self->v_54) {
        v_55 = true;
      } else {
        v_55 = r;
      };
      if (v_55) {
        t_1 = 0;
      } else {
        t_1 = v_57;
      };
      v_r_St_RTurn = 50;
      v_l_St_RTurn = 200;
      v_53 = (t_1==Controller__turntime);
      if (v_53) {
        nr_St_RTurn = true;
        ns_St_RTurn = Controller__St_Forward;
      } else {
        nr_St_RTurn = false;
        ns_St_RTurn = Controller__St_RTurn;
      };
      _out->v_l = v_l_St_RTurn;
      _out->v_r = v_r_St_RTurn;
      ns = ns_St_RTurn;
      nr = nr_St_RTurn;
      self->v_56 = t_1;
      self->v_54 = false;
      break;
    case Controller__St_LSwi:
      v_52 = (self->v_51+1);
      if (self->v_49) {
        v_50 = true;
      } else {
        v_50 = r;
      };
      if (v_50) {
        t_2 = 0;
      } else {
        t_2 = v_52;
      };
      v_r_St_LSwi = 200;
      v_l_St_LSwi = -200;
      v_48 = (t_2==Controller__swiveltime);
      if (v_48) {
        nr_St_LSwi = true;
        ns_St_LSwi = Controller__St_Fwdimpulse;
      } else {
        nr_St_LSwi = false;
        ns_St_LSwi = Controller__St_LSwi;
      };
      _out->v_l = v_l_St_LSwi;
      _out->v_r = v_r_St_LSwi;
      ns = ns_St_LSwi;
      nr = nr_St_LSwi;
      self->v_51 = t_2;
      self->v_49 = false;
      break;
    case Controller__St_RSwi:
      v_47 = (self->v_46+1);
      if (self->v_44) {
        v_45 = true;
      } else {
        v_45 = r;
      };
      if (v_45) {
        t_3 = 0;
      } else {
        t_3 = v_47;
      };
      v_r_St_RSwi = -200;
      v_l_St_RSwi = 200;
      v_43 = (t_3==Controller__swiveltime);
      if (v_43) {
        nr_St_RSwi = true;
        ns_St_RSwi = Controller__St_Fwdimpulse;
      } else {
        nr_St_RSwi = false;
        ns_St_RSwi = Controller__St_RSwi;
      };
      _out->v_l = v_l_St_RSwi;
      _out->v_r = v_r_St_RSwi;
      ns = ns_St_RSwi;
      nr = nr_St_RSwi;
      self->v_46 = t_3;
      self->v_44 = false;
      break;
    case Controller__St_Fwdimpulse:
      v_42 = (self->v_41+1);
      if (self->v_39) {
        v_40 = true;
      } else {
        v_40 = r;
      };
      if (v_40) {
        t_4 = 0;
      } else {
        t_4 = v_42;
      };
      if (self->v_37) {
        v_38 = true;
      } else {
        v_38 = r;
      };
      if (v_38) {
        v_r_St_Fwdimpulse = 200;
      } else {
        v_r_St_Fwdimpulse = 0;
      };
      if (self->v_35) {
        v_36 = true;
      } else {
        v_36 = r;
      };
      if (v_36) {
        v_l_St_Fwdimpulse = 200;
      } else {
        v_l_St_Fwdimpulse = 0;
      };
      if (_out->nod) {
        nr_St_Fwdimpulse = true;
        ns_St_Fwdimpulse = Controller__St_Order;
      } else {
        nr_St_Fwdimpulse = false;
        ns_St_Fwdimpulse = Controller__St_Fwdimpulse;
      };
      _out->v_l = v_l_St_Fwdimpulse;
      _out->v_r = v_r_St_Fwdimpulse;
      ns = ns_St_Fwdimpulse;
      nr = nr_St_Fwdimpulse;
      self->v_41 = t_4;
      self->v_39 = false;
      self->v_37 = false;
      self->v_35 = false;
      break;
    default:
      break;
  };
  self->pnr = nr;
  self->ck = ns;
  self->v_33 = false;
  self->v_27 = integration_error;
  self->v_26 = false;
  self->v_24 = error;
  self->v_23 = false;
  self->v_16 = error;
  self->v_15 = false;
  self->v = false;;
}

void Controller__main_reset(Controller__main_mem* self) {
  Controller__adacrus_reset(&self->adacrus);
}

void Controller__main_step(int left_wl, int center_wl, int right_wl,
                           int comms, Controller__main_out* _out,
                           Controller__main_mem* self) {
  Controller__adacrus_out Controller__adacrus_out_st;
  Controller__adacrus_step(left_wl, center_wl, right_wl, comms,
                           &Controller__adacrus_out_st, &self->adacrus);
  _out->v_l = Controller__adacrus_out_st.v_l;
  _out->v_r = Controller__adacrus_out_st.v_r;
  _out->nod = Controller__adacrus_out_st.nod;
}


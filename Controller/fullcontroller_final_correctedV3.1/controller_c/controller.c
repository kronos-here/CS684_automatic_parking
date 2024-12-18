/* --- Generated the 27/4/2022 at 3:25 --- */
/* --- heptagon compiler, version 1.05.00 (compiled mon. jan. 31 15:41:33 CET 2022) --- */
/* --- Command line: /usr/local/bin/heptc -target c -s main -hepts Controller.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "controller.h"

void Controller__find_velocities_step(int speed,
                                      Controller__find_velocities_out* _out) {
  
  int v_8;
  int v_7;
  int v_6;
  int v_5;
  int v_4;
  int v_3;
  int v_2;
  int v_1;
  int v;
  v_4 = (250-speed);
  v_3 = (250+speed);
  v_2 = (speed<0);
  if (v_2) {
    v_6 = v_3;
    v_5 = 250;
  } else {
    v_6 = 250;
    v_5 = v_4;
  };
  v_1 = (speed<-250);
  if (v_1) {
    v_8 = 0;
    v_7 = 250;
  } else {
    v_8 = v_6;
    v_7 = v_5;
  };
  v = (speed>250);
  if (v) {
    _out->v_r = 250;
    _out->v_l = 0;
  } else {
    _out->v_r = v_8;
    _out->v_l = v_7;
  };;
}

void Controller__adacrus_reset(Controller__adacrus_mem* self) {
  self->v_83 = true;
  self->v_78 = true;
  self->v_73 = true;
  self->v_68 = true;
  self->v_63 = true;
  self->v_61 = true;
  self->v_59 = true;
  self->v_54 = true;
  self->pnr = false;
  self->ck = Controller__St_Forward;
  self->v_32 = true;
  self->v_29 = true;
  self->v_26 = true;
  self->v_18 = true;
  self->v_12 = true;
}

void Controller__adacrus_step(int left_wl, int center_wl, int right_wl,
                              int comms, Controller__adacrus_out* _out,
                              Controller__adacrus_mem* self) {
  Controller__find_velocities_out Controller__find_velocities_out_st;
  
  int v_52;
  Controller__st v_51;
  int v_50;
  Controller__st v_49;
  int v_48;
  Controller__st v_47;
  int v_46;
  Controller__st v_45;
  int v_44;
  Controller__st v_43;
  int v_42;
  Controller__st v_41;
  int v_40;
  int v_39;
  int v_38;
  int v_37;
  int v_36;
  int v_35;
  int v_34;
  int r_St_DoubleSwi;
  Controller__st s_St_DoubleSwi;
  int r_St_Fwdimpulse;
  Controller__st s_St_Fwdimpulse;
  int r_St_RSwi;
  Controller__st s_St_RSwi;
  int r_St_LSwi;
  Controller__st s_St_LSwi;
  int r_St_RTurn;
  Controller__st s_St_RTurn;
  int r_St_LTurn;
  Controller__st s_St_LTurn;
  int r_St_Order;
  Controller__st s_St_Order;
  int r_St_Forward;
  Controller__st s_St_Forward;
  int v_57;
  int v_55;
  int v_53;
  int t_5;
  int t2;
  int v_66;
  int v_64;
  int v_62;
  int v_60;
  int v_58;
  int t_4;
  int v_71;
  int v_69;
  int v_67;
  int t_3;
  int v_76;
  int v_74;
  int v_72;
  int t_2;
  int v_81;
  int v_79;
  int v_77;
  int t_1;
  int v_86;
  int v_84;
  int v_82;
  int t;
  int nr_St_DoubleSwi;
  Controller__st ns_St_DoubleSwi;
  int v_r_St_DoubleSwi;
  int v_l_St_DoubleSwi;
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
  int nr_St_Order;
  Controller__st ns_St_Order;
  int v_r_St_Order;
  int v_l_St_Order;
  int nr_St_Forward;
  Controller__st ns_St_Forward;
  int v_r_St_Forward;
  int v_l_St_Forward;
  Controller__st ck_1;
  int v_33;
  int v_31;
  int v_28;
  int v_25;
  int v_24;
  int v_23;
  int v_22;
  int v_21;
  int v_20;
  int v_17;
  int v_16;
  int v_15;
  int v_14;
  int v_13;
  int v_11;
  int v_10;
  int v_9;
  int v;
  Controller__st s;
  Controller__st ns;
  int r;
  int nr;
  int error;
  int difference_error;
  int integration_error;
  int speed;
  v_22 = (right_wl-left_wl);
  v_23 = (150*v_22);
  v_20 = -(self->v_19);
  if (self->v_18) {
    v_21 = 0;
  } else {
    v_21 = v_20;
  };
  v_16 = (center_wl==1);
  v_14 = (right_wl-left_wl);
  v_15 = (v_14==0);
  v_17 = (v_15&&v_16);
  if (v_17) {
    v_24 = v_21;
  } else {
    v_24 = v_23;
  };
  v_13 = (center_wl==0);
  if (v_13) {
    v_25 = 0;
  } else {
    v_25 = v_24;
  };
  if (self->v_12) {
    error = 0;
  } else {
    error = v_25;
  };
  v_33 = (1*error);
  if (self->v_32) {
    speed = 0;
  } else {
    speed = v_33;
  };
  v_31 = (self->v_30+error);
  if (self->v_29) {
    integration_error = 0;
  } else {
    integration_error = v_31;
  };
  v_28 = (error-self->v_27);
  if (self->v_26) {
    difference_error = error;
  } else {
    difference_error = v_28;
  };
  v_11 = (left_wl==0);
  v_9 = (center_wl==0);
  v = (right_wl==0);
  v_10 = (v&&v_9);
  _out->nod = (v_10&&v_11);
  switch (self->ck) {
    case Controller__St_Forward:
      if (_out->nod) {
        r_St_Forward = true;
        s_St_Forward = Controller__St_Order;
      } else {
        r_St_Forward = self->pnr;
        s_St_Forward = Controller__St_Forward;
      };
      s = s_St_Forward;
      r = r_St_Forward;
      break;
    case Controller__St_Order:
      v_40 = (comms==7);
      if (v_40) {
        v_42 = true;
        v_41 = Controller__St_DoubleSwi;
      } else {
        v_42 = self->pnr;
        v_41 = Controller__St_Order;
      };
      v_39 = (comms==6);
      if (v_39) {
        v_44 = true;
        v_43 = Controller__St_Fwdimpulse;
      } else {
        v_44 = v_42;
        v_43 = v_41;
      };
      v_38 = (comms==5);
      if (v_38) {
        v_46 = true;
        v_45 = Controller__St_RSwi;
      } else {
        v_46 = v_44;
        v_45 = v_43;
      };
      v_37 = (comms==4);
      if (v_37) {
        v_48 = true;
        v_47 = Controller__St_LSwi;
      } else {
        v_48 = v_46;
        v_47 = v_45;
      };
      v_36 = (comms==3);
      if (v_36) {
        v_50 = true;
        v_49 = Controller__St_RTurn;
      } else {
        v_50 = v_48;
        v_49 = v_47;
      };
      v_35 = (comms==2);
      if (v_35) {
        v_52 = true;
        v_51 = Controller__St_LTurn;
      } else {
        v_52 = v_50;
        v_51 = v_49;
      };
      v_34 = (comms==1);
      if (v_34) {
        r_St_Order = true;
        s_St_Order = Controller__St_Forward;
      } else {
        r_St_Order = v_52;
        s_St_Order = v_51;
      };
      s = s_St_Order;
      r = r_St_Order;
      break;
    case Controller__St_LTurn:
      r_St_LTurn = self->pnr;
      s_St_LTurn = Controller__St_LTurn;
      s = s_St_LTurn;
      r = r_St_LTurn;
      break;
    case Controller__St_RTurn:
      r_St_RTurn = self->pnr;
      s_St_RTurn = Controller__St_RTurn;
      s = s_St_RTurn;
      r = r_St_RTurn;
      break;
    case Controller__St_LSwi:
      r_St_LSwi = self->pnr;
      s_St_LSwi = Controller__St_LSwi;
      s = s_St_LSwi;
      r = r_St_LSwi;
      break;
    case Controller__St_RSwi:
      r_St_RSwi = self->pnr;
      s_St_RSwi = Controller__St_RSwi;
      s = s_St_RSwi;
      r = r_St_RSwi;
      break;
    case Controller__St_Fwdimpulse:
      r_St_Fwdimpulse = self->pnr;
      s_St_Fwdimpulse = Controller__St_Fwdimpulse;
      s = s_St_Fwdimpulse;
      r = r_St_Fwdimpulse;
      break;
    case Controller__St_DoubleSwi:
      r_St_DoubleSwi = self->pnr;
      s_St_DoubleSwi = Controller__St_DoubleSwi;
      s = s_St_DoubleSwi;
      r = r_St_DoubleSwi;
      break;
    default:
      break;
  };
  ck_1 = s;
  switch (ck_1) {
    case Controller__St_Forward:
      Controller__find_velocities_step(speed,
                                       &Controller__find_velocities_out_st);
      v_l_St_Forward = Controller__find_velocities_out_st.v_l;
      v_r_St_Forward = Controller__find_velocities_out_st.v_r;
      nr_St_Forward = false;
      ns_St_Forward = Controller__St_Forward;
      _out->v_l = v_l_St_Forward;
      _out->v_r = v_r_St_Forward;
      ns = ns_St_Forward;
      nr = nr_St_Forward;
      break;
    case Controller__St_Order:
      v_r_St_Order = 0;
      v_l_St_Order = 0;
      nr_St_Order = false;
      ns_St_Order = Controller__St_Order;
      _out->v_l = v_l_St_Order;
      _out->v_r = v_r_St_Order;
      ns = ns_St_Order;
      nr = nr_St_Order;
      break;
    case Controller__St_LTurn:
      v_86 = (self->v_85+1);
      if (self->v_83) {
        v_84 = true;
      } else {
        v_84 = r;
      };
      if (v_84) {
        t = 0;
      } else {
        t = v_86;
      };
      v_r_St_LTurn = 200;
      v_l_St_LTurn = 50;
      v_82 = (t==Controller__turntime);
      if (v_82) {
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
      self->v_85 = t;
      self->v_83 = false;
      break;
    case Controller__St_RTurn:
      v_81 = (self->v_80+1);
      if (self->v_78) {
        v_79 = true;
      } else {
        v_79 = r;
      };
      if (v_79) {
        t_1 = 0;
      } else {
        t_1 = v_81;
      };
      v_r_St_RTurn = 50;
      v_l_St_RTurn = 200;
      v_77 = (t_1==Controller__turntime);
      if (v_77) {
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
      self->v_80 = t_1;
      self->v_78 = false;
      break;
    case Controller__St_LSwi:
      v_76 = (self->v_75+1);
      if (self->v_73) {
        v_74 = true;
      } else {
        v_74 = r;
      };
      if (v_74) {
        t_2 = 0;
      } else {
        t_2 = v_76;
      };
      v_r_St_LSwi = 200;
      v_l_St_LSwi = -200;
      v_72 = (t_2==Controller__swiveltime);
      if (v_72) {
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
      self->v_75 = t_2;
      self->v_73 = false;
      break;
    case Controller__St_RSwi:
      v_71 = (self->v_70+1);
      if (self->v_68) {
        v_69 = true;
      } else {
        v_69 = r;
      };
      if (v_69) {
        t_3 = 0;
      } else {
        t_3 = v_71;
      };
      v_r_St_RSwi = -200;
      v_l_St_RSwi = 200;
      v_67 = (t_3==Controller__swiveltime);
      if (v_67) {
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
      self->v_70 = t_3;
      self->v_68 = false;
      break;
    case Controller__St_Fwdimpulse:
      v_66 = (self->v_65+1);
      if (self->v_63) {
        v_64 = true;
      } else {
        v_64 = r;
      };
      if (v_64) {
        t_4 = 0;
      } else {
        t_4 = v_66;
      };
      if (self->v_61) {
        v_62 = true;
      } else {
        v_62 = r;
      };
      if (v_62) {
        v_r_St_Fwdimpulse = 200;
      } else {
        v_r_St_Fwdimpulse = 0;
      };
      if (self->v_59) {
        v_60 = true;
      } else {
        v_60 = r;
      };
      if (v_60) {
        v_l_St_Fwdimpulse = 200;
      } else {
        v_l_St_Fwdimpulse = 0;
      };
      v_58 = (t_4==1);
      if (v_58) {
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
      self->v_65 = t_4;
      self->v_63 = false;
      self->v_61 = false;
      self->v_59 = false;
      break;
    case Controller__St_DoubleSwi:
      v_57 = (self->v_56+1);
      if (self->v_54) {
        v_55 = true;
      } else {
        v_55 = r;
      };
      if (v_55) {
        t_5 = 0;
      } else {
        t_5 = v_57;
      };
      v_r_St_DoubleSwi = -200;
      v_l_St_DoubleSwi = 200;
      t2 = 4;
      v_53 = (t_5==t2);
      if (v_53) {
        nr_St_DoubleSwi = true;
        ns_St_DoubleSwi = Controller__St_Forward;
      } else {
        nr_St_DoubleSwi = false;
        ns_St_DoubleSwi = Controller__St_DoubleSwi;
      };
      _out->v_l = v_l_St_DoubleSwi;
      _out->v_r = v_r_St_DoubleSwi;
      ns = ns_St_DoubleSwi;
      nr = nr_St_DoubleSwi;
      self->v_56 = t_5;
      self->v_54 = false;
      break;
    default:
      break;
  };
  self->pnr = nr;
  self->ck = ns;
  self->v_32 = false;
  self->v_30 = integration_error;
  self->v_29 = false;
  self->v_27 = error;
  self->v_26 = false;
  self->v_19 = error;
  self->v_18 = false;
  self->v_12 = false;;
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


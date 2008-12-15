/*
 * Copyright (c) 2003, 2007-8 Matteo Frigo
 * Copyright (c) 2003, 2007-8 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Mon Nov 10 20:44:15 EST 2008 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_twidsq_c -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 4 -dif -name q1bv_4 -include q1b.h -sign 1 */

/*
 * This function contains 44 FP additions, 32 FP multiplications,
 * (or, 36 additions, 24 multiplications, 8 fused multiply/add),
 * 38 stack variables, 0 constants, and 32 memory accesses
 */
#include "q1b.h"

static void q1bv_4(R *ri, R *ii, const R *W, stride rs, stride vs, INT mb, INT me, INT ms)
{
     INT m;
     R *x;
     x = ii;
     for (m = mb, W = W + (mb * ((TWVL / VL) * 6)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(rs), MAKE_VOLATILE_STRIDE(vs)) {
	  V Tb, Tm, Tx, TI;
	  {
	       V Tc, T9, T3, TG, TA, TH, TD, Ta, T6, Td, Tn, To, Tq, Tr, Tf;
	       V Tg;
	       {
		    V T1, T2, Ty, Tz, TB, TC, T4, T5;
		    T1 = LD(&(x[0]), ms, &(x[0]));
		    T2 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
		    Ty = LD(&(x[WS(vs, 3)]), ms, &(x[WS(vs, 3)]));
		    Tz = LD(&(x[WS(vs, 3) + WS(rs, 2)]), ms, &(x[WS(vs, 3)]));
		    TB = LD(&(x[WS(vs, 3) + WS(rs, 1)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
		    TC = LD(&(x[WS(vs, 3) + WS(rs, 3)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
		    T4 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
		    T5 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
		    Tc = LD(&(x[WS(vs, 1)]), ms, &(x[WS(vs, 1)]));
		    T9 = VADD(T1, T2);
		    T3 = VSUB(T1, T2);
		    TG = VADD(Ty, Tz);
		    TA = VSUB(Ty, Tz);
		    TH = VADD(TB, TC);
		    TD = VSUB(TB, TC);
		    Ta = VADD(T4, T5);
		    T6 = VSUB(T4, T5);
		    Td = LD(&(x[WS(vs, 1) + WS(rs, 2)]), ms, &(x[WS(vs, 1)]));
		    Tn = LD(&(x[WS(vs, 2)]), ms, &(x[WS(vs, 2)]));
		    To = LD(&(x[WS(vs, 2) + WS(rs, 2)]), ms, &(x[WS(vs, 2)]));
		    Tq = LD(&(x[WS(vs, 2) + WS(rs, 1)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
		    Tr = LD(&(x[WS(vs, 2) + WS(rs, 3)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
		    Tf = LD(&(x[WS(vs, 1) + WS(rs, 1)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
		    Tg = LD(&(x[WS(vs, 1) + WS(rs, 3)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	       }
	       {
		    V Tk, Te, Tv, Tp, Tw, Ts, Tl, Th, T7, TE, Tu, TF;
		    ST(&(x[0]), VADD(T9, Ta), ms, &(x[0]));
		    Tk = VADD(Tc, Td);
		    Te = VSUB(Tc, Td);
		    Tv = VADD(Tn, To);
		    Tp = VSUB(Tn, To);
		    Tw = VADD(Tq, Tr);
		    Ts = VSUB(Tq, Tr);
		    Tl = VADD(Tf, Tg);
		    Th = VSUB(Tf, Tg);
		    ST(&(x[WS(rs, 3)]), VADD(TG, TH), ms, &(x[WS(rs, 1)]));
		    T7 = BYTW(&(W[TWVL * 4]), VFNMSI(T6, T3));
		    TE = BYTW(&(W[TWVL * 4]), VFNMSI(TD, TA));
		    {
			 V Tt, Ti, Tj, T8;
			 T8 = BYTW(&(W[0]), VFMAI(T6, T3));
			 ST(&(x[WS(rs, 2)]), VADD(Tv, Tw), ms, &(x[0]));
			 Tt = BYTW(&(W[TWVL * 4]), VFNMSI(Ts, Tp));
			 ST(&(x[WS(rs, 1)]), VADD(Tk, Tl), ms, &(x[WS(rs, 1)]));
			 Ti = BYTW(&(W[TWVL * 4]), VFNMSI(Th, Te));
			 Tj = BYTW(&(W[0]), VFMAI(Th, Te));
			 ST(&(x[WS(vs, 3)]), T7, ms, &(x[WS(vs, 3)]));
			 ST(&(x[WS(vs, 3) + WS(rs, 3)]), TE, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
			 ST(&(x[WS(vs, 1)]), T8, ms, &(x[WS(vs, 1)]));
			 Tu = BYTW(&(W[0]), VFMAI(Ts, Tp));
			 ST(&(x[WS(vs, 3) + WS(rs, 2)]), Tt, ms, &(x[WS(vs, 3)]));
			 TF = BYTW(&(W[0]), VFMAI(TD, TA));
			 ST(&(x[WS(vs, 3) + WS(rs, 1)]), Ti, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
			 ST(&(x[WS(vs, 1) + WS(rs, 1)]), Tj, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
		    }
		    Tb = BYTW(&(W[TWVL * 2]), VSUB(T9, Ta));
		    Tm = BYTW(&(W[TWVL * 2]), VSUB(Tk, Tl));
		    Tx = BYTW(&(W[TWVL * 2]), VSUB(Tv, Tw));
		    ST(&(x[WS(vs, 1) + WS(rs, 2)]), Tu, ms, &(x[WS(vs, 1)]));
		    TI = BYTW(&(W[TWVL * 2]), VSUB(TG, TH));
		    ST(&(x[WS(vs, 1) + WS(rs, 3)]), TF, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	       }
	  }
	  ST(&(x[WS(vs, 2)]), Tb, ms, &(x[WS(vs, 2)]));
	  ST(&(x[WS(vs, 2) + WS(rs, 1)]), Tm, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
	  ST(&(x[WS(vs, 2) + WS(rs, 2)]), Tx, ms, &(x[WS(vs, 2)]));
	  ST(&(x[WS(vs, 2) + WS(rs, 3)]), TI, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
     }
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 4, "q1bv_4", twinstr, &GENUS, {36, 24, 8, 0}, 0, 0, 0 };

void X(codelet_q1bv_4) (planner *p) {
     X(kdft_difsq_register) (p, q1bv_4, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_twidsq_c -simd -compact -variables 4 -pipeline-latency 8 -n 4 -dif -name q1bv_4 -include q1b.h -sign 1 */

/*
 * This function contains 44 FP additions, 24 FP multiplications,
 * (or, 44 additions, 24 multiplications, 0 fused multiply/add),
 * 22 stack variables, 0 constants, and 32 memory accesses
 */
#include "q1b.h"

static void q1bv_4(R *ri, R *ii, const R *W, stride rs, stride vs, INT mb, INT me, INT ms)
{
     INT m;
     R *x;
     x = ii;
     for (m = mb, W = W + (mb * ((TWVL / VL) * 6)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 6), MAKE_VOLATILE_STRIDE(rs), MAKE_VOLATILE_STRIDE(vs)) {
	  V T3, T9, TA, TG, TD, TH, T6, Ta, Te, Tk, Tp, Tv, Ts, Tw, Th;
	  V Tl;
	  {
	       V T1, T2, Ty, Tz;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T2 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
	       T3 = VSUB(T1, T2);
	       T9 = VADD(T1, T2);
	       Ty = LD(&(x[WS(vs, 3)]), ms, &(x[WS(vs, 3)]));
	       Tz = LD(&(x[WS(vs, 3) + WS(rs, 2)]), ms, &(x[WS(vs, 3)]));
	       TA = VSUB(Ty, Tz);
	       TG = VADD(Ty, Tz);
	  }
	  {
	       V TB, TC, T4, T5;
	       TB = LD(&(x[WS(vs, 3) + WS(rs, 1)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
	       TC = LD(&(x[WS(vs, 3) + WS(rs, 3)]), ms, &(x[WS(vs, 3) + WS(rs, 1)]));
	       TD = VBYI(VSUB(TB, TC));
	       TH = VADD(TB, TC);
	       T4 = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
	       T5 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
	       T6 = VBYI(VSUB(T4, T5));
	       Ta = VADD(T4, T5);
	  }
	  {
	       V Tc, Td, Tn, To;
	       Tc = LD(&(x[WS(vs, 1)]), ms, &(x[WS(vs, 1)]));
	       Td = LD(&(x[WS(vs, 1) + WS(rs, 2)]), ms, &(x[WS(vs, 1)]));
	       Te = VSUB(Tc, Td);
	       Tk = VADD(Tc, Td);
	       Tn = LD(&(x[WS(vs, 2)]), ms, &(x[WS(vs, 2)]));
	       To = LD(&(x[WS(vs, 2) + WS(rs, 2)]), ms, &(x[WS(vs, 2)]));
	       Tp = VSUB(Tn, To);
	       Tv = VADD(Tn, To);
	  }
	  {
	       V Tq, Tr, Tf, Tg;
	       Tq = LD(&(x[WS(vs, 2) + WS(rs, 1)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
	       Tr = LD(&(x[WS(vs, 2) + WS(rs, 3)]), ms, &(x[WS(vs, 2) + WS(rs, 1)]));
	       Ts = VBYI(VSUB(Tq, Tr));
	       Tw = VADD(Tq, Tr);
	       Tf = LD(&(x[WS(vs, 1) + WS(rs, 1)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	       Tg = LD(&(x[WS(vs, 1) + WS(rs, 3)]), ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	       Th = VBYI(VSUB(Tf, Tg));
	       Tl = VADD(Tf, Tg);
	  }
	  ST(&(x[0]), VADD(T9, Ta), ms, &(x[0]));
	  ST(&(x[WS(rs, 1)]), VADD(Tk, Tl), ms, &(x[WS(rs, 1)]));
	  ST(&(x[WS(rs, 2)]), VADD(Tv, Tw), ms, &(x[0]));
	  ST(&(x[WS(rs, 3)]), VADD(TG, TH), ms, &(x[WS(rs, 1)]));
	  {
	       V T7, Ti, Tt, TE;
	       T7 = BYTW(&(W[TWVL * 4]), VSUB(T3, T6));
	       ST(&(x[WS(vs, 3)]), T7, ms, &(x[WS(vs, 3)]));
	       Ti = BYTW(&(W[TWVL * 4]), VSUB(Te, Th));
	       ST(&(x[WS(vs, 3) + WS(rs, 1)]), Ti, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
	       Tt = BYTW(&(W[TWVL * 4]), VSUB(Tp, Ts));
	       ST(&(x[WS(vs, 3) + WS(rs, 2)]), Tt, ms, &(x[WS(vs, 3)]));
	       TE = BYTW(&(W[TWVL * 4]), VSUB(TA, TD));
	       ST(&(x[WS(vs, 3) + WS(rs, 3)]), TE, ms, &(x[WS(vs, 3) + WS(rs, 1)]));
	  }
	  {
	       V T8, Tj, Tu, TF;
	       T8 = BYTW(&(W[0]), VADD(T3, T6));
	       ST(&(x[WS(vs, 1)]), T8, ms, &(x[WS(vs, 1)]));
	       Tj = BYTW(&(W[0]), VADD(Te, Th));
	       ST(&(x[WS(vs, 1) + WS(rs, 1)]), Tj, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	       Tu = BYTW(&(W[0]), VADD(Tp, Ts));
	       ST(&(x[WS(vs, 1) + WS(rs, 2)]), Tu, ms, &(x[WS(vs, 1)]));
	       TF = BYTW(&(W[0]), VADD(TA, TD));
	       ST(&(x[WS(vs, 1) + WS(rs, 3)]), TF, ms, &(x[WS(vs, 1) + WS(rs, 1)]));
	  }
	  {
	       V Tb, Tm, Tx, TI;
	       Tb = BYTW(&(W[TWVL * 2]), VSUB(T9, Ta));
	       ST(&(x[WS(vs, 2)]), Tb, ms, &(x[WS(vs, 2)]));
	       Tm = BYTW(&(W[TWVL * 2]), VSUB(Tk, Tl));
	       ST(&(x[WS(vs, 2) + WS(rs, 1)]), Tm, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
	       Tx = BYTW(&(W[TWVL * 2]), VSUB(Tv, Tw));
	       ST(&(x[WS(vs, 2) + WS(rs, 2)]), Tx, ms, &(x[WS(vs, 2)]));
	       TI = BYTW(&(W[TWVL * 2]), VSUB(TG, TH));
	       ST(&(x[WS(vs, 2) + WS(rs, 3)]), TI, ms, &(x[WS(vs, 2) + WS(rs, 1)]));
	  }
     }
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 4, "q1bv_4", twinstr, &GENUS, {44, 24, 0, 0}, 0, 0, 0 };

void X(codelet_q1bv_4) (planner *p) {
     X(kdft_difsq_register) (p, q1bv_4, &desc);
}
#endif				/* HAVE_FMA */

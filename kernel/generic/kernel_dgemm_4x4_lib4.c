/**************************************************************************************************
*                                                                                                 *
* This file is part of BLASFEO.                                                                   *
*                                                                                                 *
* BLASFEO -- BLAS For Embedded Optimization.                                                      *
* Copyright (C) 2016-2018 by Gianluca Frison.                                                     *
* Developed at IMTEK (University of Freiburg) under the supervision of Moritz Diehl.              *
* All rights reserved.                                                                            *
*                                                                                                 *
* This program is free software: you can redistribute it and/or modify                            *
* it under the terms of the GNU General Public License as published by                            *
* the Free Software Foundation, either version 3 of the License, or                               *
* (at your option) any later version                                                              *.
*                                                                                                 *
* This program is distributed in the hope that it will be useful,                                 *
* but WITHOUT ANY WARRANTY; without even the implied warranty of                                  *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                                   *
* GNU General Public License for more details.                                                    *
*                                                                                                 *
* You should have received a copy of the GNU General Public License                               *
* along with this program.  If not, see <https://www.gnu.org/licenses/>.                          *
*                                                                                                 *
* The authors designate this particular file as subject to the "Classpath" exception              *
* as provided by the authors in the LICENSE file that accompained this code.                      *
*                                                                                                 *
* Author: Gianluca Frison, gianluca.frison (at) imtek.uni-freiburg.de                             *
*                                                                                                 *
**************************************************************************************************/



#include <math.h>

#include "../../include/blasfeo_d_kernel.h"



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA)
void kernel_dgemm_nt_4x4_lib4(int kmax, double *alpha, double *A, double *B, double *beta, double *C, double *D)
	{

	const int bs = 4;

#if defined(TARGET_X86_AMD_BARCELONA)

	kernel_dgemm_nt_4x2_lib4(kmax, alpha, A, B, beta, C, D);
	kernel_dgemm_nt_4x2_lib4(kmax, alpha, A, B+2, beta, C+2*bs, D+2*bs);

	return;

#endif

	double
		a_0, a_1, a_2, a_3,
		b_0, b_1, b_2, b_3;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	int k;

	for(k=0; k<kmax-3; k+=4)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		b_1 = B[1];
		b_2 = B[2];
		b_3 = B[3];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;


		// k = 1

		a_0 = A[4];
		a_1 = A[5];
		a_2 = A[6];
		a_3 = A[7];

		b_0 = B[4];
		b_1 = B[5];
		b_2 = B[6];
		b_3 = B[7];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;


		// k = 2

		a_0 = A[8];
		a_1 = A[9];
		a_2 = A[10];
		a_3 = A[11];

		b_0 = B[8];
		b_1 = B[9];
		b_2 = B[10];
		b_3 = B[11];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;


		// k = 3

		a_0 = A[12];
		a_1 = A[13];
		a_2 = A[14];
		a_3 = A[15];

		b_0 = B[12];
		b_1 = B[13];
		b_2 = B[14];
		b_3 = B[15];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 16;
		B += 16;

		}
	
	for(; k<kmax; k++)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		b_1 = B[1];
		b_2 = B[2];
		b_3 = B[3];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 4;

		}
	
	D[0+bs*0] = beta[0]*C[0+bs*0] + alpha[0]*CC[0+bs*0];
	D[1+bs*0] = beta[0]*C[1+bs*0] + alpha[0]*CC[1+bs*0];
	D[2+bs*0] = beta[0]*C[2+bs*0] + alpha[0]*CC[2+bs*0];
	D[3+bs*0] = beta[0]*C[3+bs*0] + alpha[0]*CC[3+bs*0];

	D[0+bs*1] = beta[0]*C[0+bs*1] + alpha[0]*CC[0+bs*1];
	D[1+bs*1] = beta[0]*C[1+bs*1] + alpha[0]*CC[1+bs*1];
	D[2+bs*1] = beta[0]*C[2+bs*1] + alpha[0]*CC[2+bs*1];
	D[3+bs*1] = beta[0]*C[3+bs*1] + alpha[0]*CC[3+bs*1];

	D[0+bs*2] = beta[0]*C[0+bs*2] + alpha[0]*CC[0+bs*2];
	D[1+bs*2] = beta[0]*C[1+bs*2] + alpha[0]*CC[1+bs*2];
	D[2+bs*2] = beta[0]*C[2+bs*2] + alpha[0]*CC[2+bs*2];
	D[3+bs*2] = beta[0]*C[3+bs*2] + alpha[0]*CC[3+bs*2];

	D[0+bs*3] = beta[0]*C[0+bs*3] + alpha[0]*CC[0+bs*3];
	D[1+bs*3] = beta[0]*C[1+bs*3] + alpha[0]*CC[1+bs*3];
	D[2+bs*3] = beta[0]*C[2+bs*3] + alpha[0]*CC[2+bs*3];
	D[3+bs*3] = beta[0]*C[3+bs*3] + alpha[0]*CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7)
void kernel_dgemm_nt_4x4_vs_lib4(int kmax, double *alpha, double *A, double *B, double *beta, double *C, double *D, int km, int kn)
	{

	const int bs = 4;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	kernel_dgemm_nt_4x4_lib4(kmax, alpha, A, B, beta, C, CC);

	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dgemm_nt_4x4_gen_lib4(int kmax, double *alpha, double *A, double *B, double *beta, int offsetC, double *C0, int sdc, int offsetD, double *D0, int sdd, int m0, int m1, int n0, int n1)
	{

	const int bs = 4;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double
		*C1, *D1;
	
	int k;

	if(offsetC==0)
		{
		CC[0+bs*0] = beta[0]*C0[0+bs*0];
		CC[1+bs*0] = beta[0]*C0[1+bs*0];
		CC[2+bs*0] = beta[0]*C0[2+bs*0];
		CC[3+bs*0] = beta[0]*C0[3+bs*0];

		CC[0+bs*1] = beta[0]*C0[0+bs*1];
		CC[1+bs*1] = beta[0]*C0[1+bs*1];
		CC[2+bs*1] = beta[0]*C0[2+bs*1];
		CC[3+bs*1] = beta[0]*C0[3+bs*1];

		CC[0+bs*2] = beta[0]*C0[0+bs*2];
		CC[1+bs*2] = beta[0]*C0[1+bs*2];
		CC[2+bs*2] = beta[0]*C0[2+bs*2];
		CC[3+bs*2] = beta[0]*C0[3+bs*2];

		CC[0+bs*3] = beta[0]*C0[0+bs*3];
		CC[1+bs*3] = beta[0]*C0[1+bs*3];
		CC[2+bs*3] = beta[0]*C0[2+bs*3];
		CC[3+bs*3] = beta[0]*C0[3+bs*3];
		}
	else if(offsetC==1)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[1+bs*0];
		CC[1+bs*0] = beta[0]*C0[2+bs*0];
		CC[2+bs*0] = beta[0]*C0[3+bs*0];
		CC[3+bs*0] = beta[0]*C1[0+bs*0];

		CC[0+bs*1] = beta[0]*C0[1+bs*1];
		CC[1+bs*1] = beta[0]*C0[2+bs*1];
		CC[2+bs*1] = beta[0]*C0[3+bs*1];
		CC[3+bs*1] = beta[0]*C1[0+bs*1];

		CC[0+bs*2] = beta[0]*C0[1+bs*2];
		CC[1+bs*2] = beta[0]*C0[2+bs*2];
		CC[2+bs*2] = beta[0]*C0[3+bs*2];
		CC[3+bs*2] = beta[0]*C1[0+bs*2];

		CC[0+bs*3] = beta[0]*C0[1+bs*3];
		CC[1+bs*3] = beta[0]*C0[2+bs*3];
		CC[2+bs*3] = beta[0]*C0[3+bs*3];
		CC[3+bs*3] = beta[0]*C1[0+bs*3];
		}
	else if(offsetC==2)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[2+bs*0];
		CC[1+bs*0] = beta[0]*C0[3+bs*0];
		CC[2+bs*0] = beta[0]*C1[0+bs*0];
		CC[3+bs*0] = beta[0]*C1[1+bs*0];

		CC[0+bs*1] = beta[0]*C0[2+bs*1];
		CC[1+bs*1] = beta[0]*C0[3+bs*1];
		CC[2+bs*1] = beta[0]*C1[0+bs*1];
		CC[3+bs*1] = beta[0]*C1[1+bs*1];

		CC[0+bs*2] = beta[0]*C0[2+bs*2];
		CC[1+bs*2] = beta[0]*C0[3+bs*2];
		CC[2+bs*2] = beta[0]*C1[0+bs*2];
		CC[3+bs*2] = beta[0]*C1[1+bs*2];

		CC[0+bs*3] = beta[0]*C0[2+bs*3];
		CC[1+bs*3] = beta[0]*C0[3+bs*3];
		CC[2+bs*3] = beta[0]*C1[0+bs*3];
		CC[3+bs*3] = beta[0]*C1[1+bs*3];
		}
	else //if(offsetC==3)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[3+bs*0];
		CC[1+bs*0] = beta[0]*C1[0+bs*0];
		CC[2+bs*0] = beta[0]*C1[1+bs*0];
		CC[3+bs*0] = beta[0]*C1[2+bs*0];

		CC[0+bs*1] = beta[0]*C0[3+bs*1];
		CC[1+bs*1] = beta[0]*C1[0+bs*1];
		CC[2+bs*1] = beta[0]*C1[1+bs*1];
		CC[3+bs*1] = beta[0]*C1[2+bs*1];

		CC[0+bs*2] = beta[0]*C0[3+bs*2];
		CC[1+bs*2] = beta[0]*C1[0+bs*2];
		CC[2+bs*2] = beta[0]*C1[1+bs*2];
		CC[3+bs*2] = beta[0]*C1[2+bs*2];

		CC[0+bs*3] = beta[0]*C0[3+bs*3];
		CC[1+bs*3] = beta[0]*C1[0+bs*3];
		CC[2+bs*3] = beta[0]*C1[1+bs*3];
		CC[3+bs*3] = beta[0]*C1[2+bs*3];
		}
	
	double beta1 = 1.0;

	kernel_dgemm_nt_4x4_lib4(kmax, alpha, A, B, &beta1, CC, CC);

	// shift sol for cols
	if(n0>0)
		{
		if(n0==1)
			{
			CC[0+bs*0] = CC[0+bs*1];
			CC[1+bs*0] = CC[1+bs*1];
			CC[2+bs*0] = CC[2+bs*1];
			CC[3+bs*0] = CC[3+bs*1];

			CC[0+bs*1] = CC[0+bs*2];
			CC[1+bs*1] = CC[1+bs*2];
			CC[2+bs*1] = CC[2+bs*2];
			CC[3+bs*1] = CC[3+bs*2];

			CC[0+bs*2] = CC[0+bs*3];
			CC[1+bs*2] = CC[1+bs*3];
			CC[2+bs*2] = CC[2+bs*3];
			CC[3+bs*2] = CC[3+bs*3];

			D0 += 1*bs;
			}
		else if(n0==2)
			{
			CC[0+bs*0] = CC[0+bs*2];
			CC[1+bs*0] = CC[1+bs*2];
			CC[2+bs*0] = CC[2+bs*2];
			CC[3+bs*0] = CC[3+bs*2];

			CC[0+bs*1] = CC[0+bs*3];
			CC[1+bs*1] = CC[1+bs*3];
			CC[2+bs*1] = CC[2+bs*3];
			CC[3+bs*1] = CC[3+bs*3];

			D0 += 2*bs;
			}
		else //if(n0==3)
			{
			CC[0+bs*0] = CC[0+bs*3];
			CC[1+bs*0] = CC[1+bs*3];
			CC[2+bs*0] = CC[2+bs*3];
			CC[3+bs*0] = CC[3+bs*3];

			D0 += 3*bs;
			}
		}

	n1 = 4<n1 ? 4 : n1;
	int kn = n1 - n0;

	if(offsetD==0)
		{
		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[0+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D0[1+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D0[2+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D0[3+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[0+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[1+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D0[2+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D0[3+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[0+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[1+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D0[2+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D0[3+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[0+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[1+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D0[2+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D0[3+bs*3] = CC[3+bs*3];
		}
	else if(offsetD==1)
		{
		D1 = D0 + sdd*bs;

		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[1+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D0[2+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D0[3+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D1[0+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[1+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[2+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D0[3+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D1[0+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[1+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[2+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D0[3+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D1[0+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[1+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[2+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D0[3+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[0+bs*3] = CC[3+bs*3];
		}
	else if(offsetD==2)
		{
		D1 = D0 + sdd*bs;

		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[2+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D0[3+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D1[0+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D1[1+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[2+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[3+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D1[0+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D1[1+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[2+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[3+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D1[0+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D1[1+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[2+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[3+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D1[0+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[1+bs*3] = CC[3+bs*3];
		}
	else //if(offsetD==3)
		{
		D1 = D0 + sdd*bs;

		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[3+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D1[0+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D1[1+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D1[2+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[3+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D1[0+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D1[1+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D1[2+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[3+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D1[0+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D1[1+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D1[2+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[3+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D1[0+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D1[1+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[2+bs*3] = CC[3+bs*3];
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X64_AMD_BULLDOZER)
void kernel_dgemm_nn_4x4_lib4(int kmax, double *alpha, double *A, int offsetB, double *B, int sdb, double *beta, double *C, double *D)
	{

	const int bs = 4;

#if defined(TARGET_X86_AMD_BARCELONA)

	kernel_dgemm_nn_4x2_lib4(kmax, alpha, A, offsetB, B, sdb, beta, C, D);
	kernel_dgemm_nn_4x2_lib4(kmax, alpha, A, offsetB, B+2*bs, sdb, beta, C+2*bs, D+2*bs);

	return;

#endif

	double
		a_0, a_1, a_2, a_3,
		b_0, b_1, b_2, b_3;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double
		*C1, *D1;
	
	int k;

	k = 0;
	if(offsetB!=0)
		{
		if(offsetB==1)
			{

			B += 1;

			a_0 = A[0];
			a_1 = A[1];
			a_2 = A[2];
			a_3 = A[3];

			b_0 = B[0];
			b_1 = B[4];
			b_2 = B[8];
			b_3 = B[12];

			CC[0+bs*0] += a_0 * b_0;
			CC[1+bs*0] += a_1 * b_0;
			CC[2+bs*0] += a_2 * b_0;
			CC[3+bs*0] += a_3 * b_0;

			CC[0+bs*1] += a_0 * b_1;
			CC[1+bs*1] += a_1 * b_1;
			CC[2+bs*1] += a_2 * b_1;
			CC[3+bs*1] += a_3 * b_1;

			CC[0+bs*2] += a_0 * b_2;
			CC[1+bs*2] += a_1 * b_2;
			CC[2+bs*2] += a_2 * b_2;
			CC[3+bs*2] += a_3 * b_2;

			CC[0+bs*3] += a_0 * b_3;
			CC[1+bs*3] += a_1 * b_3;
			CC[2+bs*3] += a_2 * b_3;
			CC[3+bs*3] += a_3 * b_3;

			A += 4;
			B += 1;
			k += 1;

			if(k>=kmax)
				goto scale;

			a_0 = A[0];
			a_1 = A[1];
			a_2 = A[2];
			a_3 = A[3];

			b_0 = B[0];
			b_1 = B[4];
			b_2 = B[8];
			b_3 = B[12];

			CC[0+bs*0] += a_0 * b_0;
			CC[1+bs*0] += a_1 * b_0;
			CC[2+bs*0] += a_2 * b_0;
			CC[3+bs*0] += a_3 * b_0;

			CC[0+bs*1] += a_0 * b_1;
			CC[1+bs*1] += a_1 * b_1;
			CC[2+bs*1] += a_2 * b_1;
			CC[3+bs*1] += a_3 * b_1;

			CC[0+bs*2] += a_0 * b_2;
			CC[1+bs*2] += a_1 * b_2;
			CC[2+bs*2] += a_2 * b_2;
			CC[3+bs*2] += a_3 * b_2;

			CC[0+bs*3] += a_0 * b_3;
			CC[1+bs*3] += a_1 * b_3;
			CC[2+bs*3] += a_2 * b_3;
			CC[3+bs*3] += a_3 * b_3;

			A += 4;
			B += 1;
			k += 1;

			if(k>=kmax)
				goto scale;

			a_0 = A[0];
			a_1 = A[1];
			a_2 = A[2];
			a_3 = A[3];

			b_0 = B[0];
			b_1 = B[4];
			b_2 = B[8];
			b_3 = B[12];

			CC[0+bs*0] += a_0 * b_0;
			CC[1+bs*0] += a_1 * b_0;
			CC[2+bs*0] += a_2 * b_0;
			CC[3+bs*0] += a_3 * b_0;

			CC[0+bs*1] += a_0 * b_1;
			CC[1+bs*1] += a_1 * b_1;
			CC[2+bs*1] += a_2 * b_1;
			CC[3+bs*1] += a_3 * b_1;

			CC[0+bs*2] += a_0 * b_2;
			CC[1+bs*2] += a_1 * b_2;
			CC[2+bs*2] += a_2 * b_2;
			CC[3+bs*2] += a_3 * b_2;

			CC[0+bs*3] += a_0 * b_3;
			CC[1+bs*3] += a_1 * b_3;
			CC[2+bs*3] += a_2 * b_3;
			CC[3+bs*3] += a_3 * b_3;

			A += 4;
			B += 1;
			B += bs*(sdb-1);
			k += 1;

			}
		else if(offsetB==2)
			{

			B += 2;

			a_0 = A[0];
			a_1 = A[1];
			a_2 = A[2];
			a_3 = A[3];

			b_0 = B[0];
			b_1 = B[4];
			b_2 = B[8];
			b_3 = B[12];

			CC[0+bs*0] += a_0 * b_0;
			CC[1+bs*0] += a_1 * b_0;
			CC[2+bs*0] += a_2 * b_0;
			CC[3+bs*0] += a_3 * b_0;

			CC[0+bs*1] += a_0 * b_1;
			CC[1+bs*1] += a_1 * b_1;
			CC[2+bs*1] += a_2 * b_1;
			CC[3+bs*1] += a_3 * b_1;

			CC[0+bs*2] += a_0 * b_2;
			CC[1+bs*2] += a_1 * b_2;
			CC[2+bs*2] += a_2 * b_2;
			CC[3+bs*2] += a_3 * b_2;

			CC[0+bs*3] += a_0 * b_3;
			CC[1+bs*3] += a_1 * b_3;
			CC[2+bs*3] += a_2 * b_3;
			CC[3+bs*3] += a_3 * b_3;

			A += 4;
			B += 1;
			k += 1;

			if(k>=kmax)
				goto scale;

			a_0 = A[0];
			a_1 = A[1];
			a_2 = A[2];
			a_3 = A[3];

			b_0 = B[0];
			b_1 = B[4];
			b_2 = B[8];
			b_3 = B[12];

			CC[0+bs*0] += a_0 * b_0;
			CC[1+bs*0] += a_1 * b_0;
			CC[2+bs*0] += a_2 * b_0;
			CC[3+bs*0] += a_3 * b_0;

			CC[0+bs*1] += a_0 * b_1;
			CC[1+bs*1] += a_1 * b_1;
			CC[2+bs*1] += a_2 * b_1;
			CC[3+bs*1] += a_3 * b_1;

			CC[0+bs*2] += a_0 * b_2;
			CC[1+bs*2] += a_1 * b_2;
			CC[2+bs*2] += a_2 * b_2;
			CC[3+bs*2] += a_3 * b_2;

			CC[0+bs*3] += a_0 * b_3;
			CC[1+bs*3] += a_1 * b_3;
			CC[2+bs*3] += a_2 * b_3;
			CC[3+bs*3] += a_3 * b_3;

			A += 4;
			B += 1;
			B += bs*(sdb-1);
			k += 1;

			}
		else // if(offsetB==3)
			{

			B += 3;

			a_0 = A[0];
			a_1 = A[1];
			a_2 = A[2];
			a_3 = A[3];

			b_0 = B[0];
			b_1 = B[4];
			b_2 = B[8];
			b_3 = B[12];

			CC[0+bs*0] += a_0 * b_0;
			CC[1+bs*0] += a_1 * b_0;
			CC[2+bs*0] += a_2 * b_0;
			CC[3+bs*0] += a_3 * b_0;

			CC[0+bs*1] += a_0 * b_1;
			CC[1+bs*1] += a_1 * b_1;
			CC[2+bs*1] += a_2 * b_1;
			CC[3+bs*1] += a_3 * b_1;

			CC[0+bs*2] += a_0 * b_2;
			CC[1+bs*2] += a_1 * b_2;
			CC[2+bs*2] += a_2 * b_2;
			CC[3+bs*2] += a_3 * b_2;

			CC[0+bs*3] += a_0 * b_3;
			CC[1+bs*3] += a_1 * b_3;
			CC[2+bs*3] += a_2 * b_3;
			CC[3+bs*3] += a_3 * b_3;

			A += 4;
			B += 1;
			B += bs*(sdb-1);
			k += 1;

			}
		}
	for(; k<kmax-3; k+=4)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		b_1 = B[4];
		b_2 = B[8];
		b_3 = B[12];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;


		// k = 1

		a_0 = A[4];
		a_1 = A[5];
		a_2 = A[6];
		a_3 = A[7];

		b_0 = B[1];
		b_1 = B[5];
		b_2 = B[9];
		b_3 = B[13];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;


		// k = 2

		a_0 = A[8];
		a_1 = A[9];
		a_2 = A[10];
		a_3 = A[11];

		b_0 = B[2];
		b_1 = B[6];
		b_2 = B[10];
		b_3 = B[14];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;


		// k = 3

		a_0 = A[12];
		a_1 = A[13];
		a_2 = A[14];
		a_3 = A[15];

		b_0 = B[3];
		b_1 = B[7];
		b_2 = B[11];
		b_3 = B[15];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 16;
		B += 4*sdb;

		}
	for(; k<kmax; k++)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		b_1 = B[4];
		b_2 = B[8];
		b_3 = B[12];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 1;

		}	
	
	scale:

	D[0+bs*0] = beta[0]*C[0+bs*0] + alpha[0]*CC[0+bs*0];
	D[1+bs*0] = beta[0]*C[1+bs*0] + alpha[0]*CC[1+bs*0];
	D[2+bs*0] = beta[0]*C[2+bs*0] + alpha[0]*CC[2+bs*0];
	D[3+bs*0] = beta[0]*C[3+bs*0] + alpha[0]*CC[3+bs*0];

	D[0+bs*1] = beta[0]*C[0+bs*1] + alpha[0]*CC[0+bs*1];
	D[1+bs*1] = beta[0]*C[1+bs*1] + alpha[0]*CC[1+bs*1];
	D[2+bs*1] = beta[0]*C[2+bs*1] + alpha[0]*CC[2+bs*1];
	D[3+bs*1] = beta[0]*C[3+bs*1] + alpha[0]*CC[3+bs*1];

	D[0+bs*2] = beta[0]*C[0+bs*2] + alpha[0]*CC[0+bs*2];
	D[1+bs*2] = beta[0]*C[1+bs*2] + alpha[0]*CC[1+bs*2];
	D[2+bs*2] = beta[0]*C[2+bs*2] + alpha[0]*CC[2+bs*2];
	D[3+bs*2] = beta[0]*C[3+bs*2] + alpha[0]*CC[3+bs*2];

	D[0+bs*3] = beta[0]*C[0+bs*3] + alpha[0]*CC[0+bs*3];
	D[1+bs*3] = beta[0]*C[1+bs*3] + alpha[0]*CC[1+bs*3];
	D[2+bs*3] = beta[0]*C[2+bs*3] + alpha[0]*CC[2+bs*3];
	D[3+bs*3] = beta[0]*C[3+bs*3] + alpha[0]*CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7)
void kernel_dgemm_nn_4x4_vs_lib4(int kmax, double *alpha, double *A, int offsetB, double *B, int sdb, double *beta, double *C, double *D, int km, int kn)
	{

	const int bs = 4;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	kernel_dgemm_nn_4x4_lib4(kmax, alpha, A, offsetB, B, sdb, beta, C, CC);
	
	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dgemm_nn_4x4_gen_lib4(int kmax, double *alpha, double *A, int offsetB, double *B, int sdb, double *beta, int offsetC, double *C0, int sdc, int offsetD, double *D0, int sdd, int m0, int m1, int n0, int n1)
	{

	const int bs = 4;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double
		*C1, *D1;
	
	if(offsetC==0)
		{
		CC[0+bs*0] = beta[0]*C0[0+bs*0];
		CC[1+bs*0] = beta[0]*C0[1+bs*0];
		CC[2+bs*0] = beta[0]*C0[2+bs*0];
		CC[3+bs*0] = beta[0]*C0[3+bs*0];

		CC[0+bs*1] = beta[0]*C0[0+bs*1];
		CC[1+bs*1] = beta[0]*C0[1+bs*1];
		CC[2+bs*1] = beta[0]*C0[2+bs*1];
		CC[3+bs*1] = beta[0]*C0[3+bs*1];

		CC[0+bs*2] = beta[0]*C0[0+bs*2];
		CC[1+bs*2] = beta[0]*C0[1+bs*2];
		CC[2+bs*2] = beta[0]*C0[2+bs*2];
		CC[3+bs*2] = beta[0]*C0[3+bs*2];

		CC[0+bs*3] = beta[0]*C0[0+bs*3];
		CC[1+bs*3] = beta[0]*C0[1+bs*3];
		CC[2+bs*3] = beta[0]*C0[2+bs*3];
		CC[3+bs*3] = beta[0]*C0[3+bs*3];
		}
	else if(offsetC==1)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[1+bs*0];
		CC[1+bs*0] = beta[0]*C0[2+bs*0];
		CC[2+bs*0] = beta[0]*C0[3+bs*0];
		CC[3+bs*0] = beta[0]*C1[0+bs*0];

		CC[0+bs*1] = beta[0]*C0[1+bs*1];
		CC[1+bs*1] = beta[0]*C0[2+bs*1];
		CC[2+bs*1] = beta[0]*C0[3+bs*1];
		CC[3+bs*1] = beta[0]*C1[0+bs*1];

		CC[0+bs*2] = beta[0]*C0[1+bs*2];
		CC[1+bs*2] = beta[0]*C0[2+bs*2];
		CC[2+bs*2] = beta[0]*C0[3+bs*2];
		CC[3+bs*2] = beta[0]*C1[0+bs*2];

		CC[0+bs*3] = beta[0]*C0[1+bs*3];
		CC[1+bs*3] = beta[0]*C0[2+bs*3];
		CC[2+bs*3] = beta[0]*C0[3+bs*3];
		CC[3+bs*3] = beta[0]*C1[0+bs*3];
		}
	else if(offsetC==2)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[2+bs*0];
		CC[1+bs*0] = beta[0]*C0[3+bs*0];
		CC[2+bs*0] = beta[0]*C1[0+bs*0];
		CC[3+bs*0] = beta[0]*C1[1+bs*0];

		CC[0+bs*1] = beta[0]*C0[2+bs*1];
		CC[1+bs*1] = beta[0]*C0[3+bs*1];
		CC[2+bs*1] = beta[0]*C1[0+bs*1];
		CC[3+bs*1] = beta[0]*C1[1+bs*1];

		CC[0+bs*2] = beta[0]*C0[2+bs*2];
		CC[1+bs*2] = beta[0]*C0[3+bs*2];
		CC[2+bs*2] = beta[0]*C1[0+bs*2];
		CC[3+bs*2] = beta[0]*C1[1+bs*2];

		CC[0+bs*3] = beta[0]*C0[2+bs*3];
		CC[1+bs*3] = beta[0]*C0[3+bs*3];
		CC[2+bs*3] = beta[0]*C1[0+bs*3];
		CC[3+bs*3] = beta[0]*C1[1+bs*3];
		}
	else //if(offsetC==3)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[3+bs*0];
		CC[1+bs*0] = beta[0]*C1[0+bs*0];
		CC[2+bs*0] = beta[0]*C1[1+bs*0];
		CC[3+bs*0] = beta[0]*C1[2+bs*0];

		CC[0+bs*1] = beta[0]*C0[3+bs*1];
		CC[1+bs*1] = beta[0]*C1[0+bs*1];
		CC[2+bs*1] = beta[0]*C1[1+bs*1];
		CC[3+bs*1] = beta[0]*C1[2+bs*1];

		CC[0+bs*2] = beta[0]*C0[3+bs*2];
		CC[1+bs*2] = beta[0]*C1[0+bs*2];
		CC[2+bs*2] = beta[0]*C1[1+bs*2];
		CC[3+bs*2] = beta[0]*C1[2+bs*2];

		CC[0+bs*3] = beta[0]*C0[3+bs*3];
		CC[1+bs*3] = beta[0]*C1[0+bs*3];
		CC[2+bs*3] = beta[0]*C1[1+bs*3];
		CC[3+bs*3] = beta[0]*C1[2+bs*3];
		}
	
	double beta1 = 1.0;

	kernel_dgemm_nn_4x4_lib4(kmax, alpha, A, offsetB, B, sdb, &beta1, CC, CC);

	// shift sol for cols
	if(n0>0)
		{
		if(n0==1)
			{
			CC[0+bs*0] = CC[0+bs*1];
			CC[1+bs*0] = CC[1+bs*1];
			CC[2+bs*0] = CC[2+bs*1];
			CC[3+bs*0] = CC[3+bs*1];

			CC[0+bs*1] = CC[0+bs*2];
			CC[1+bs*1] = CC[1+bs*2];
			CC[2+bs*1] = CC[2+bs*2];
			CC[3+bs*1] = CC[3+bs*2];

			CC[0+bs*2] = CC[0+bs*3];
			CC[1+bs*2] = CC[1+bs*3];
			CC[2+bs*2] = CC[2+bs*3];
			CC[3+bs*2] = CC[3+bs*3];

			D0 += 1*bs;
			}
		else if(n0==2)
			{
			CC[0+bs*0] = CC[0+bs*2];
			CC[1+bs*0] = CC[1+bs*2];
			CC[2+bs*0] = CC[2+bs*2];
			CC[3+bs*0] = CC[3+bs*2];

			CC[0+bs*1] = CC[0+bs*3];
			CC[1+bs*1] = CC[1+bs*3];
			CC[2+bs*1] = CC[2+bs*3];
			CC[3+bs*1] = CC[3+bs*3];

			D0 += 2*bs;
			}
		else //if(n0==3)
			{
			CC[0+bs*0] = CC[0+bs*3];
			CC[1+bs*0] = CC[1+bs*3];
			CC[2+bs*0] = CC[2+bs*3];
			CC[3+bs*0] = CC[3+bs*3];

			D0 += 3*bs;
			}
		}

	n1 = 4<n1 ? 4 : n1;
	int kn = n1 - n0;

	if(offsetD==0)
		{
		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[0+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D0[1+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D0[2+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D0[3+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[0+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[1+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D0[2+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D0[3+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[0+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[1+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D0[2+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D0[3+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[0+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[1+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D0[2+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D0[3+bs*3] = CC[3+bs*3];
		}
	else if(offsetD==1)
		{
		D1 = D0 + sdd*bs;

		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[1+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D0[2+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D0[3+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D1[0+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[1+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[2+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D0[3+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D1[0+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[1+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[2+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D0[3+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D1[0+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[1+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[2+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D0[3+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[0+bs*3] = CC[3+bs*3];
		}
	else if(offsetD==2)
		{
		D1 = D0 + sdd*bs;

		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[2+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D0[3+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D1[0+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D1[1+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[2+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[3+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D1[0+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D1[1+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[2+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[3+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D1[0+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D1[1+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[2+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[3+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D1[0+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[1+bs*3] = CC[3+bs*3];
		}
	else //if(offsetD==3)
		{
		D1 = D0 + sdd*bs;

		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[3+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D1[0+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D1[1+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D1[2+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[3+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D1[0+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D1[1+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D1[2+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[3+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D1[0+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D1[1+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D1[2+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[3+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D1[0+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D1[1+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[2+bs*3] = CC[3+bs*3];
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR)
void kernel_dsyrk_nt_l_4x4_lib4(int kmax, double *alpha, double *A, double *B, double *beta, double *C, double *D)
	{

	const int bs = 4;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	kernel_dgemm_nt_4x4_lib4(kmax, alpha, A, B, beta, C, CC);
	
	D[0+bs*0] = CC[0+bs*0];
	D[1+bs*0] = CC[1+bs*0];
	D[2+bs*0] = CC[2+bs*0];
	D[3+bs*0] = CC[3+bs*0];

	D[1+bs*1] = CC[1+bs*1];
	D[2+bs*1] = CC[2+bs*1];
	D[3+bs*1] = CC[3+bs*1];

	D[2+bs*2] = CC[2+bs*2];
	D[3+bs*2] = CC[3+bs*2];

	D[3+bs*3] = CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7)
void kernel_dsyrk_nt_l_4x4_vs_lib4(int kmax, double *alpha, double *A, double *B, double *beta, double *C, double *D, int km, int kn)
	{

	const int bs = 4;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	kernel_dgemm_nt_4x4_lib4(kmax, alpha, A, B, beta, C, CC);
	
	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[2+bs*2] = CC[2+bs*2];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[1+bs*1] = CC[1+bs*1];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];
		}
	
	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dsyrk_nt_l_4x4_gen_lib4(int kmax, double *alpha, double *A, double *B, double *beta, int offsetC, double *C0, int sdc, int offsetD, double *D0, int sdd, int m0, int m1, int n0, int n1)
	{

	const int bs = 4;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double
		*C1, *D1;

	if(offsetC==0)
		{
		CC[0+bs*0] = beta[0]*C0[0+bs*0];
		CC[1+bs*0] = beta[0]*C0[1+bs*0];
		CC[2+bs*0] = beta[0]*C0[2+bs*0];
		CC[3+bs*0] = beta[0]*C0[3+bs*0];

		CC[1+bs*1] = beta[0]*C0[1+bs*1];
		CC[2+bs*1] = beta[0]*C0[2+bs*1];
		CC[3+bs*1] = beta[0]*C0[3+bs*1];

		CC[2+bs*2] = beta[0]*C0[2+bs*2];
		CC[3+bs*2] = beta[0]*C0[3+bs*2];

		CC[3+bs*3] = beta[0]*C0[3+bs*3];
		}
	else if(offsetC==1)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[1+bs*0];
		CC[1+bs*0] = beta[0]*C0[2+bs*0];
		CC[2+bs*0] = beta[0]*C0[3+bs*0];
		CC[3+bs*0] = beta[0]*C1[0+bs*0];

		CC[1+bs*1] = beta[0]*C0[2+bs*1];
		CC[2+bs*1] = beta[0]*C0[3+bs*1];
		CC[3+bs*1] = beta[0]*C1[0+bs*1];

		CC[2+bs*2] = beta[0]*C0[3+bs*2];
		CC[3+bs*2] = beta[0]*C1[0+bs*2];

		CC[3+bs*3] = beta[0]*C1[0+bs*3];
		}
	else if(offsetC==2)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[2+bs*0];
		CC[1+bs*0] = beta[0]*C0[3+bs*0];
		CC[2+bs*0] = beta[0]*C1[0+bs*0];
		CC[3+bs*0] = beta[0]*C1[1+bs*0];

		CC[1+bs*1] = beta[0]*C0[3+bs*1];
		CC[2+bs*1] = beta[0]*C1[0+bs*1];
		CC[3+bs*1] = beta[0]*C1[1+bs*1];

		CC[2+bs*2] = beta[0]*C1[0+bs*2];
		CC[3+bs*2] = beta[0]*C1[1+bs*2];

		CC[3+bs*3] = beta[0]*C1[1+bs*3];
		}
	else //if(offsetC==3)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[3+bs*0];
		CC[1+bs*0] = beta[0]*C1[0+bs*0];
		CC[2+bs*0] = beta[0]*C1[1+bs*0];
		CC[3+bs*0] = beta[0]*C1[2+bs*0];

		CC[1+bs*1] = beta[0]*C1[0+bs*1];
		CC[2+bs*1] = beta[0]*C1[1+bs*1];
		CC[3+bs*1] = beta[0]*C1[2+bs*1];

		CC[2+bs*2] = beta[0]*C1[1+bs*2];
		CC[3+bs*2] = beta[0]*C1[2+bs*2];

		CC[3+bs*3] = beta[0]*C1[2+bs*3];
		}
	
	double beta1 = 1.0;

	kernel_dgemm_nt_4x4_lib4(kmax, alpha, A, B, &beta1, CC, CC);

	// shift sol for cols
	if(n0>0)
		{
		if(n0==1)
			{
			CC[0+bs*0] = CC[0+bs*1];
			CC[1+bs*0] = CC[1+bs*1];
			CC[2+bs*0] = CC[2+bs*1];
			CC[3+bs*0] = CC[3+bs*1];

			CC[0+bs*1] = CC[0+bs*2];
			CC[1+bs*1] = CC[1+bs*2];
			CC[2+bs*1] = CC[2+bs*2];
			CC[3+bs*1] = CC[3+bs*2];

			CC[0+bs*2] = CC[0+bs*3];
			CC[1+bs*2] = CC[1+bs*3];
			CC[2+bs*2] = CC[2+bs*3];
			CC[3+bs*2] = CC[3+bs*3];

			D0 += 1*bs;
			}
		else if(n0==2)
			{
			CC[0+bs*0] = CC[0+bs*2];
			CC[1+bs*0] = CC[1+bs*2];
			CC[2+bs*0] = CC[2+bs*2];
			CC[3+bs*0] = CC[3+bs*2];

			CC[0+bs*1] = CC[0+bs*3];
			CC[1+bs*1] = CC[1+bs*3];
			CC[2+bs*1] = CC[2+bs*3];
			CC[3+bs*1] = CC[3+bs*3];

			D0 += 2*bs;
			}
		else //if(n0==3)
			{
			CC[0+bs*0] = CC[0+bs*3];
			CC[1+bs*0] = CC[1+bs*3];
			CC[2+bs*0] = CC[2+bs*3];
			CC[3+bs*0] = CC[3+bs*3];

			D0 += 3*bs;
			}
		}

	n1 = 4<n1 ? 4 : n1;
	int kn = n1 - n0;

	if(offsetD==0)
		{
		if(m0<=0)
			{
			if(kn<=0)
				return;

			if(m1>0) D0[0+bs*0] = CC[0+bs*0];
			if(m1>1) D0[1+bs*0] = CC[1+bs*0];
			if(m1>2) D0[2+bs*0] = CC[2+bs*0];
			if(m1>3) D0[3+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>1) D0[1+bs*1] = CC[1+bs*1];
			if(m1>2) D0[2+bs*1] = CC[2+bs*1];
			if(m1>3) D0[3+bs*1] = CC[3+bs*1];

			if(kn<=2)
				return;

			if(m1>2) D0[2+bs*2] = CC[2+bs*2];
			if(m1>3) D0[3+bs*2] = CC[3+bs*2];

			if(kn<=3)
				return;

			if(m1>3) D0[3+bs*3] = CC[3+bs*3];
			}
		else if(m0<=1)
			{
			if(kn<=0)
				return;

			if(m1>1) D0[1+bs*0] = CC[1+bs*0];
			if(m1>2) D0[2+bs*0] = CC[2+bs*0];
			if(m1>3) D0[3+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>2) D0[2+bs*1] = CC[2+bs*1];
			if(m1>3) D0[3+bs*1] = CC[3+bs*1];

			if(kn<=2)
				return;

			if(m1>3) D0[3+bs*2] = CC[3+bs*2];
			}
		else if(m0<=2)
			{
			if(kn<=0)
				return;

			if(m1>2) D0[2+bs*0] = CC[2+bs*0];
			if(m1>3) D0[3+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>3) D0[3+bs*1] = CC[3+bs*1];
			}
		else if(m0<=3)
			{
			if(kn<=0)
				return;

			if(m1>3) D0[3+bs*0] = CC[3+bs*0];
			}
		}
	else if(offsetD==1)
		{
		D1 = D0 + sdd*bs;
		if(m0<=0)
			{
			if(kn<=0)
				return;

			if(m1>0) D0[1+bs*0] = CC[0+bs*0];
			if(m1>1) D0[2+bs*0] = CC[1+bs*0];
			if(m1>2) D0[3+bs*0] = CC[2+bs*0];
			if(m1>3) D1[0+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>1) D0[2+bs*1] = CC[1+bs*1];
			if(m1>2) D0[3+bs*1] = CC[2+bs*1];
			if(m1>3) D1[0+bs*1] = CC[3+bs*1];

			if(kn<=2)
				return;

			if(m1>2) D0[3+bs*2] = CC[2+bs*2];
			if(m1>3) D1[0+bs*2] = CC[3+bs*2];

			if(kn<=3)
				return;

			if(m1>3) D1[0+bs*3] = CC[3+bs*3];
			}
		else if(m0<=1)
			{
			if(kn<=0)
				return;

			if(m1>1) D0[2+bs*0] = CC[1+bs*0];
			if(m1>2) D0[3+bs*0] = CC[2+bs*0];
			if(m1>3) D1[0+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>2) D0[3+bs*1] = CC[2+bs*1];
			if(m1>3) D1[0+bs*1] = CC[3+bs*1];

			if(kn<=2)
				return;

			if(m1>3) D1[0+bs*2] = CC[3+bs*2];
			}
		else if(m0<=2)
			{
			if(kn<=0)
				return;

			if(m1>2) D0[3+bs*0] = CC[2+bs*0];
			if(m1>3) D1[0+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>3) D1[0+bs*1] = CC[3+bs*1];
			}
		else if(m0<=3)
			{
			if(kn<=0)
				return;

			if(m1>3) D1[0+bs*0] = CC[3+bs*0];
			}
		}
	else if(offsetD==2)
		{
		D1 = D0 + sdd*bs;
		if(m0<=0)
			{
			if(kn<=0)
				return;

			if(m1>0) D0[2+bs*0] = CC[0+bs*0];
			if(m1>1) D0[3+bs*0] = CC[1+bs*0];
			if(m1>2) D1[0+bs*0] = CC[2+bs*0];
			if(m1>3) D1[1+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>1) D0[3+bs*1] = CC[1+bs*1];
			if(m1>2) D1[0+bs*1] = CC[2+bs*1];
			if(m1>3) D1[1+bs*1] = CC[3+bs*1];

			if(kn<=2)
				return;

			if(m1>2) D1[0+bs*2] = CC[2+bs*2];
			if(m1>3) D1[1+bs*2] = CC[3+bs*2];

			if(kn<=3)
				return;

			if(m1>3) D1[1+bs*3] = CC[3+bs*3];
			}
		else if(m0<=1)
			{
			if(kn<=0)
				return;

			if(m1>1) D0[3+bs*0] = CC[1+bs*0];
			if(m1>2) D1[0+bs*0] = CC[2+bs*0];
			if(m1>3) D1[1+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>2) D1[0+bs*1] = CC[2+bs*1];
			if(m1>3) D1[1+bs*1] = CC[3+bs*1];

			if(kn<=2)
				return;

			if(m1>3) D1[1+bs*2] = CC[3+bs*2];
			}
		else if(m0<=2)
			{
			if(kn<=0)
				return;

			if(m1>2) D1[0+bs*0] = CC[2+bs*0];
			if(m1>3) D1[1+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>3) D1[1+bs*1] = CC[3+bs*1];
			}
		else if(m0<=3)
			{
			if(kn<=0)
				return;

			if(m1>3) D1[1+bs*0] = CC[3+bs*0];
			}
		}
	else //if(offsetD==3)
		{
		D1 = D0 + sdd*bs;
		if(m0<=0)
			{
			if(kn<=0)
				return;

			if(m1>0) D0[3+bs*0] = CC[0+bs*0];
			if(m1>1) D1[0+bs*0] = CC[1+bs*0];
			if(m1>2) D1[1+bs*0] = CC[2+bs*0];
			if(m1>3) D1[2+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>1) D1[0+bs*1] = CC[1+bs*1];
			if(m1>2) D1[1+bs*1] = CC[2+bs*1];
			if(m1>3) D1[2+bs*1] = CC[3+bs*1];

			if(kn<=2)
				return;

			if(m1>2) D1[1+bs*2] = CC[2+bs*2];
			if(m1>3) D1[2+bs*2] = CC[3+bs*2];

			if(kn<=3)
				return;

			if(m1>3) D1[2+bs*3] = CC[3+bs*3];
			}
		else if(m0<=1)
			{
			if(kn<=0)
				return;

			if(m1>1) D1[0+bs*0] = CC[1+bs*0];
			if(m1>2) D1[1+bs*0] = CC[2+bs*0];
			if(m1>3) D1[2+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>2) D1[1+bs*1] = CC[2+bs*1];
			if(m1>3) D1[2+bs*1] = CC[3+bs*1];

			if(kn<=2)
				return;

			if(m1>3) D1[2+bs*2] = CC[3+bs*2];
			}
		else if(m0<=2)
			{
			if(kn<=0)
				return;

			if(m1>2) D1[1+bs*0] = CC[2+bs*0];
			if(m1>3) D1[2+bs*0] = CC[3+bs*0];

			if(kn<=1)
				return;

			if(m1>3) D1[2+bs*1] = CC[3+bs*1];
			}
		else if(m0<=3)
			{
			if(kn<=0)
				return;

			if(m1>3) D1[2+bs*0] = CC[3+bs*0];
			}
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dsyrk_nt_u_4x4_lib4(int kmax, double *alpha, double *A, double *B, double *beta, double *C, double *D)
	{

	const int bs = 4;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	kernel_dgemm_nt_4x4_lib4(kmax, alpha, A, B, beta, C, CC);
	
	D[0+bs*0] = CC[0+bs*0];

	D[0+bs*1] = CC[0+bs*1];
	D[1+bs*1] = CC[1+bs*1];

	D[0+bs*2] = CC[0+bs*2];
	D[1+bs*2] = CC[1+bs*2];
	D[2+bs*2] = CC[2+bs*2];

	D[0+bs*3] = CC[0+bs*3];
	D[1+bs*3] = CC[1+bs*3];
	D[2+bs*3] = CC[2+bs*3];
	D[3+bs*3] = CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dsyrk_nt_u_4x4_vs_lib4(int kmax, double *alpha, double *A, double *B, double *beta, double *C, double *D, int km, int kn)
	{

	const int bs = 4;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	kernel_dgemm_nt_4x4_lib4(kmax, alpha, A, B, beta, C, CC);
	
	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}
	
	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dsyrk_nt_u_4x4_gen_lib4(int kmax, double *alpha, double *A, double *B, double *beta, int offsetC, double *C0, int sdc, int offsetD, double *D0, int sdd, int m0, int m1, int n0, int n1)
	{

	const int bs = 4;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double
		*C1, *D1;

	if(offsetC==0)
		{
		CC[0+bs*0] = beta[0]*C0[0+bs*0];

		CC[0+bs*1] = beta[0]*C0[0+bs*1];
		CC[1+bs*1] = beta[0]*C0[1+bs*1];

		CC[0+bs*2] = beta[0]*C0[0+bs*2];
		CC[1+bs*2] = beta[0]*C0[1+bs*2];
		CC[2+bs*2] = beta[0]*C0[2+bs*2];

		CC[0+bs*3] = beta[0]*C0[0+bs*3];
		CC[1+bs*3] = beta[0]*C0[1+bs*3];
		CC[2+bs*3] = beta[0]*C0[2+bs*3];
		CC[3+bs*3] = beta[0]*C0[3+bs*3];
		}
	else if(offsetC==1)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[0+bs*0];

		CC[0+bs*1] = beta[0]*C0[0+bs*1];
		CC[1+bs*1] = beta[0]*C0[1+bs*1];

		CC[0+bs*2] = beta[0]*C0[0+bs*2];
		CC[1+bs*2] = beta[0]*C0[1+bs*2];
		CC[2+bs*2] = beta[0]*C0[2+bs*2];

		CC[0+bs*3] = beta[0]*C0[0+bs*3];
		CC[1+bs*3] = beta[0]*C0[1+bs*3];
		CC[2+bs*3] = beta[0]*C0[2+bs*3];
		CC[3+bs*3] = beta[0]*C1[3+bs*3];
		}
	else if(offsetC==2)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[0+bs*0];

		CC[0+bs*1] = beta[0]*C0[0+bs*1];
		CC[1+bs*1] = beta[0]*C0[1+bs*1];

		CC[0+bs*2] = beta[0]*C0[0+bs*2];
		CC[1+bs*2] = beta[0]*C0[1+bs*2];
		CC[2+bs*2] = beta[0]*C1[2+bs*2];

		CC[0+bs*3] = beta[0]*C0[0+bs*3];
		CC[1+bs*3] = beta[0]*C0[1+bs*3];
		CC[2+bs*3] = beta[0]*C1[2+bs*3];
		CC[3+bs*3] = beta[0]*C1[3+bs*3];
		}
	else //if(offsetC==3)
		{
		C1 = C0 + sdc*bs;

		CC[0+bs*0] = beta[0]*C0[0+bs*0];

		CC[0+bs*1] = beta[0]*C0[0+bs*1];
		CC[1+bs*1] = beta[0]*C1[1+bs*1];

		CC[0+bs*2] = beta[0]*C0[0+bs*2];
		CC[1+bs*2] = beta[0]*C1[1+bs*2];
		CC[2+bs*2] = beta[0]*C1[2+bs*2];

		CC[0+bs*3] = beta[0]*C0[0+bs*3];
		CC[1+bs*3] = beta[0]*C1[1+bs*3];
		CC[2+bs*3] = beta[0]*C1[2+bs*3];
		CC[3+bs*3] = beta[0]*C1[3+bs*3];
		}
	
	double beta1 = 1.0;

	kernel_dgemm_nt_4x4_lib4(kmax, alpha, A, B, &beta1, CC, CC);

	// TODO fix below !!!!!!!!!!!!

	if(offsetD==0)
		{
		if(n0==0)
			goto l_00;
		else if(n0==1)
			goto l_01;
		else if(n0==2)
			goto l_02;
		else if(n0==3)
			goto l_03;
		else
			return;

l_00:
		if(n1<=0)
			return;

		if(m0<=0 & m1>0) D0[0+bs*0] = CC[0+bs*0];

l_01:
		if(n1<=1)
			return;

		if(m0<=0 & m1>0) D0[0+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[1+bs*1] = CC[1+bs*1];

l_02:
		if(n1<=2)
			return;

		if(m0<=0 & m1>0) D0[0+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[1+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D0[2+bs*2] = CC[2+bs*2];

l_03:
		if(n1<=3)
			return;

		if(m0<=0 & m1>0) D0[0+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[1+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D0[2+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D0[3+bs*3] = CC[3+bs*3];
		}
	else if(offsetD==1)
		{
		D1 = D0 + sdd*bs;

		if(n0==0)
			goto l_10;
		else if(n0==1)
			goto l_11;
		else if(n0==2)
			goto l_12;
		else if(n0==3)
			goto l_13;
		else
			return;

l_10:
		if(n1<=0)
			return;

		if(m0<=0 & m1>0) D0[0+bs*0] = CC[0+bs*0];

l_11:
		if(n1<=1)
			return;

		if(m0<=0 & m1>0) D0[0+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[1+bs*1] = CC[1+bs*1];

l_12:
		if(n1<=2)
			return;

		if(m0<=0 & m1>0) D0[0+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[1+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D0[2+bs*2] = CC[2+bs*2];

l_13:
		if(n1<=3)
			return;

		if(m0<=0 & m1>0) D0[0+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[1+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D0[2+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[3+bs*3] = CC[3+bs*3];
		}
	else if(offsetD==2)
		{
		D1 = D0 + sdd*bs;

		if(n0==0)
			goto l_20;
		else if(n0==1)
			goto l_21;
		else if(n0==2)
			goto l_22;
		else if(n0==3)
			goto l_23;
		else
			return;

l_20:
		if(n1<=0)
			return;

		if(m0<=0 & m1>0) D0[0+bs*0] = CC[0+bs*0];

l_21:
		if(n1<=1)
			return;

		if(m0<=0 & m1>0) D0[0+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[1+bs*1] = CC[1+bs*1];

l_22:
		if(n1<=2)
			return;

		if(m0<=0 & m1>0) D0[0+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[1+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D1[2+bs*2] = CC[2+bs*2];

l_23:
		if(n1<=3)
			return;

		if(m0<=0 & m1>0) D0[0+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[1+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D1[2+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[3+bs*3] = CC[3+bs*3];
		}
	else //if(offsetD==3)
		{
		D1 = D0 + sdd*bs;

		if(n0==0)
			goto l_30;
		else if(n0==1)
			goto l_31;
		else if(n0==2)
			goto l_32;
		else if(n0==3)
			goto l_33;
		else
			return;

l_30:
		if(n1<=0)
			return;

		if(m0<=0 & m1>0) D0[0+bs*0] = CC[0+bs*0];

l_31:
		if(n1<=1)
			return;

		if(m0<=0 & m1>0) D0[0+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D1[1+bs*1] = CC[1+bs*1];

l_32:
		if(n1<=2)
			return;

		if(m0<=0 & m1>0) D0[0+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D1[1+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D1[2+bs*2] = CC[2+bs*2];

l_33:
		if(n1<=3)
			return;

		if(m0<=0 & m1>0) D0[0+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D1[1+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D1[2+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[3+bs*3] = CC[3+bs*3];
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrmm_nt_ru_4x4_lib4(int kmax, double *alpha, double *A, double *B, double *D)
	{

	const int bs = 4;

	double
		a_0, a_1, a_2, a_3,
		b_0, b_1, b_2, b_3;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	int k;

	k = 0;

	// k = 0
	if(kmax>0)
		{
		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 4;
		k++;
		}

	// k = 1
	if(kmax>1)
		{
		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		b_1 = B[1];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 4;
		k++;
		}

	// k = 2
	if(kmax>2)
		{
		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		b_1 = B[1];
		b_2 = B[2];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 4;
		k++;
		}
	
	kernel_dgemm_nt_4x4_lib4(kmax-k, alpha, A, B, alpha, CC, D);

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrmm_nt_ru_4x4_vs_lib4(int kmax, double *alpha, double *A, double *B, double *D, int km, int kn)
	{

	const int bs = 4;

	double
		a_0, a_1, a_2, a_3,
		b_0, b_1, b_2, b_3;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	int k;

	k = 0;

	// k = 0
	if(kmax>0)
		{
		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 4;
		k++;
		}

	// k = 1
	if(kmax>1)
		{
		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		b_1 = B[1];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 4;
		k++;
		}

	// k = 2
	if(kmax>2)
		{
		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		b_1 = B[1];
		b_2 = B[2];

		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 4;
		k++;
		}
	
	kernel_dgemm_nt_4x4_lib4(kmax-k, alpha, A, B, alpha, CC, CC);

	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}

	return;

	}
#endif




#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR)  || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrmm_nn_rl_4x4_lib4(int kmax, double *alpha, double *A, int offsetB, double *B, int sdb, double *D)
	{

	const int bs = 4;

	double
		a_0, a_1, a_2, a_3,
		b_0, b_1, b_2, b_3;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double *D1;
	
	int k;

	B += offsetB;

	k = 0;

	if(offsetB==0)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 3

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	else if(offsetB==1)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	else if(offsetB==2)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 3

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 4

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 5

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	else // if(offetB==3)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 3

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 4

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	
	store:
	
	CC[0+bs*0] = alpha[0]*CC[0+bs*0];
	CC[1+bs*0] = alpha[0]*CC[1+bs*0];
	CC[2+bs*0] = alpha[0]*CC[2+bs*0];
	CC[3+bs*0] = alpha[0]*CC[3+bs*0];

	CC[0+bs*1] = alpha[0]*CC[0+bs*1];
	CC[1+bs*1] = alpha[0]*CC[1+bs*1];
	CC[2+bs*1] = alpha[0]*CC[2+bs*1];
	CC[3+bs*1] = alpha[0]*CC[3+bs*1];

	CC[0+bs*2] = alpha[0]*CC[0+bs*2];
	CC[1+bs*2] = alpha[0]*CC[1+bs*2];
	CC[2+bs*2] = alpha[0]*CC[2+bs*2];
	CC[3+bs*2] = alpha[0]*CC[3+bs*2];

	CC[0+bs*3] = alpha[0]*CC[0+bs*3];
	CC[1+bs*3] = alpha[0]*CC[1+bs*3];
	CC[2+bs*3] = alpha[0]*CC[2+bs*3];
	CC[3+bs*3] = alpha[0]*CC[3+bs*3];

	double beta1 = 1.0;

	kernel_dgemm_nn_4x4_lib4(kmax-k, alpha, A, 0, B, sdb, &beta1, CC, D);

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR)  || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrmm_nn_rl_4x4_vs_lib4(int kmax, double *alpha, double *A, int offsetB, double *B, int sdb, double *D, int m1, int n1)
	{

	const int bs = 4;

	double
		a_0, a_1, a_2, a_3,
		b_0, b_1, b_2, b_3;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double *D1;
	
	int k;

	B += offsetB;

	k = 0;

	if(offsetB==0)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 3

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	else if(offsetB==1)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	else if(offsetB==2)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 3

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 4

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 5

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	else // if(offetB==3)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 3

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 4

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	
	store:
	
	CC[0+bs*0] = alpha[0]*CC[0+bs*0];
	CC[1+bs*0] = alpha[0]*CC[1+bs*0];
	CC[2+bs*0] = alpha[0]*CC[2+bs*0];
	CC[3+bs*0] = alpha[0]*CC[3+bs*0];

	CC[0+bs*1] = alpha[0]*CC[0+bs*1];
	CC[1+bs*1] = alpha[0]*CC[1+bs*1];
	CC[2+bs*1] = alpha[0]*CC[2+bs*1];
	CC[3+bs*1] = alpha[0]*CC[3+bs*1];

	CC[0+bs*2] = alpha[0]*CC[0+bs*2];
	CC[1+bs*2] = alpha[0]*CC[1+bs*2];
	CC[2+bs*2] = alpha[0]*CC[2+bs*2];
	CC[3+bs*2] = alpha[0]*CC[3+bs*2];

	CC[0+bs*3] = alpha[0]*CC[0+bs*3];
	CC[1+bs*3] = alpha[0]*CC[1+bs*3];
	CC[2+bs*3] = alpha[0]*CC[2+bs*3];
	CC[3+bs*3] = alpha[0]*CC[3+bs*3];

	double beta1 = 1.0;

	kernel_dgemm_nn_4x4_lib4(kmax-k, alpha, A, 0, B, sdb, &beta1, CC, CC);

	if(m1>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(n1==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(n1==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(n1==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(m1>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(n1==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(n1==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(n1==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(m1>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(n1==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(n1==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(n1==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(m1>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(n1==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(n1==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(n1==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrmm_nn_rl_4x4_gen_lib4(int kmax, double *alpha, double *A, int offsetB, double *B, int sdb, int offsetD, double *D0, int sdd, int m0, int m1, int n0, int n1)
	{

	const int bs = 4;

	double
		a_0, a_1, a_2, a_3,
		b_0, b_1, b_2, b_3;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double *D1;
	
	int k;

	B += offsetB;

	k = 0;

	if(offsetB==0)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 3

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	else if(offsetB==1)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	else if(offsetB==2)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 3

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 4

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 5

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	else // if(offetB==3)
		{

		// k = 0

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 1

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 2

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 3

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 1;
		k += 1;

		if(k>=kmax)
			goto store;

		// k = 4

		a_0 = A[0];
		a_1 = A[1];
		a_2 = A[2];
		a_3 = A[3];

		b_0 = B[0];
		CC[0+bs*0] += a_0 * b_0;
		CC[1+bs*0] += a_1 * b_0;
		CC[2+bs*0] += a_2 * b_0;
		CC[3+bs*0] += a_3 * b_0;

		b_1 = B[4];
		CC[0+bs*1] += a_0 * b_1;
		CC[1+bs*1] += a_1 * b_1;
		CC[2+bs*1] += a_2 * b_1;
		CC[3+bs*1] += a_3 * b_1;

		b_2 = B[8];
		CC[0+bs*2] += a_0 * b_2;
		CC[1+bs*2] += a_1 * b_2;
		CC[2+bs*2] += a_2 * b_2;
		CC[3+bs*2] += a_3 * b_2;

		b_3 = B[12];
		CC[0+bs*3] += a_0 * b_3;
		CC[1+bs*3] += a_1 * b_3;
		CC[2+bs*3] += a_2 * b_3;
		CC[3+bs*3] += a_3 * b_3;

		A += 4;
		B += 4*sdb-3;
		k += 1;

		}
	
	store:
	
	CC[0+bs*0] = alpha[0]*CC[0+bs*0];
	CC[1+bs*0] = alpha[0]*CC[1+bs*0];
	CC[2+bs*0] = alpha[0]*CC[2+bs*0];
	CC[3+bs*0] = alpha[0]*CC[3+bs*0];

	CC[0+bs*1] = alpha[0]*CC[0+bs*1];
	CC[1+bs*1] = alpha[0]*CC[1+bs*1];
	CC[2+bs*1] = alpha[0]*CC[2+bs*1];
	CC[3+bs*1] = alpha[0]*CC[3+bs*1];

	CC[0+bs*2] = alpha[0]*CC[0+bs*2];
	CC[1+bs*2] = alpha[0]*CC[1+bs*2];
	CC[2+bs*2] = alpha[0]*CC[2+bs*2];
	CC[3+bs*2] = alpha[0]*CC[3+bs*2];

	CC[0+bs*3] = alpha[0]*CC[0+bs*3];
	CC[1+bs*3] = alpha[0]*CC[1+bs*3];
	CC[2+bs*3] = alpha[0]*CC[2+bs*3];
	CC[3+bs*3] = alpha[0]*CC[3+bs*3];

	double beta1 = 1.0;

	kernel_dgemm_nn_4x4_lib4(kmax-k, alpha, A, 0, B, sdb, &beta1, CC, CC);

	// shift sol for cols
	if(n0>0)
		{
		if(n0==1)
			{
			CC[0+bs*0] = CC[0+bs*1];
			CC[1+bs*0] = CC[1+bs*1];
			CC[2+bs*0] = CC[2+bs*1];
			CC[3+bs*0] = CC[3+bs*1];

			CC[0+bs*1] = CC[0+bs*2];
			CC[1+bs*1] = CC[1+bs*2];
			CC[2+bs*1] = CC[2+bs*2];
			CC[3+bs*1] = CC[3+bs*2];

			CC[0+bs*2] = CC[0+bs*3];
			CC[1+bs*2] = CC[1+bs*3];
			CC[2+bs*2] = CC[2+bs*3];
			CC[3+bs*2] = CC[3+bs*3];

			D0 += 1*bs;
			}
		else if(n0==2)
			{
			CC[0+bs*0] = CC[0+bs*2];
			CC[1+bs*0] = CC[1+bs*2];
			CC[2+bs*0] = CC[2+bs*2];
			CC[3+bs*0] = CC[3+bs*2];

			CC[0+bs*1] = CC[0+bs*3];
			CC[1+bs*1] = CC[1+bs*3];
			CC[2+bs*1] = CC[2+bs*3];
			CC[3+bs*1] = CC[3+bs*3];

			D0 += 2*bs;
			}
		else //if(n0==3)
			{
			CC[0+bs*0] = CC[0+bs*3];
			CC[1+bs*0] = CC[1+bs*3];
			CC[2+bs*0] = CC[2+bs*3];
			CC[3+bs*0] = CC[3+bs*3];

			D0 += 3*bs;
			}
		}

	n1 = 4<n1 ? 4 : n1;
	int kn = n1 - n0;

	if(offsetD==0)
		{
		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[0+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D0[1+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D0[2+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D0[3+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[0+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[1+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D0[2+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D0[3+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[0+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[1+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D0[2+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D0[3+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[0+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[1+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D0[2+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D0[3+bs*3] = CC[3+bs*3];
		}
	else if(offsetD==1)
		{
		D1 = D0 + sdd*bs;

		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[1+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D0[2+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D0[3+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D1[0+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[1+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[2+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D0[3+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D1[0+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[1+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[2+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D0[3+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D1[0+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[1+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[2+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D0[3+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[0+bs*3] = CC[3+bs*3];
		}
	else if(offsetD==2)
		{
		D1 = D0 + sdd*bs;

		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[2+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D0[3+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D1[0+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D1[1+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[2+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D0[3+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D1[0+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D1[1+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[2+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D0[3+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D1[0+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D1[1+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[2+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D0[3+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D1[0+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[1+bs*3] = CC[3+bs*3];
		}
	else //if(offsetD==3)
		{
		D1 = D0 + sdd*bs;

		if(kn<=0)
			return;

		if(m0<=0 & m1>0) D0[3+bs*0] = CC[0+bs*0];
		if(m0<=1 & m1>1) D1[0+bs*0] = CC[1+bs*0];
		if(m0<=2 & m1>2) D1[1+bs*0] = CC[2+bs*0];
		if(m0<=3 & m1>3) D1[2+bs*0] = CC[3+bs*0];

		if(kn<=1)
			return;

		if(m0<=0 & m1>0) D0[3+bs*1] = CC[0+bs*1];
		if(m0<=1 & m1>1) D1[0+bs*1] = CC[1+bs*1];
		if(m0<=2 & m1>2) D1[1+bs*1] = CC[2+bs*1];
		if(m0<=3 & m1>3) D1[2+bs*1] = CC[3+bs*1];

		if(kn<=2)
			return;

		if(m0<=0 & m1>0) D0[3+bs*2] = CC[0+bs*2];
		if(m0<=1 & m1>1) D1[0+bs*2] = CC[1+bs*2];
		if(m0<=2 & m1>2) D1[1+bs*2] = CC[2+bs*2];
		if(m0<=3 & m1>3) D1[2+bs*2] = CC[3+bs*2];

		if(kn<=3)
			return;

		if(m0<=0 & m1>0) D0[3+bs*3] = CC[0+bs*3];
		if(m0<=1 & m1>1) D1[0+bs*3] = CC[1+bs*3];
		if(m0<=2 & m1>2) D1[1+bs*3] = CC[2+bs*3];
		if(m0<=3 & m1>3) D1[2+bs*3] = CC[3+bs*3];
		}
	
	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR)
void kernel_dpotrf_nt_l_4x4_lib4(int kmax, double *A, double *B, double *C, double *D, double *inv_diag_D)
	{

	const int bs = 4;

	double
		a_0, a_1, a_2, a_3,
		b_0, b_1, b_2, b_3,
		tmp;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	int k;

	double alpha1 = -1.0;
	double beta1  = 1.0;

	kernel_dgemm_nt_4x4_lib4(kmax, &alpha1, A, B, &beta1, C, CC);

	if(CC[0+bs*0]>0)
		{
		CC[0+bs*0] = sqrt(CC[0+bs*0]);
		tmp = 1.0/CC[0+bs*0];
		}
	else
		{
		CC[0+bs*0] = 0.0;
		tmp = 0.0;
		}
	CC[1+bs*0] *= tmp;
	CC[2+bs*0] *= tmp;
	CC[3+bs*0] *= tmp;
	inv_diag_D[0] = tmp;

	CC[1+bs*1] -= CC[1+bs*0] * CC[1+bs*0];
	CC[2+bs*1] -= CC[2+bs*0] * CC[1+bs*0];
	CC[3+bs*1] -= CC[3+bs*0] * CC[1+bs*0];
	if(CC[1+bs*1]>0)
		{
		CC[1+bs*1] = sqrt(CC[1+bs*1]);
		tmp = 1.0/CC[1+bs*1];
		}
	else
		{
		CC[1+bs*1] = 0.0;
		tmp = 0.0;
		}
	CC[2+bs*1] *= tmp;
	CC[3+bs*1] *= tmp;
	inv_diag_D[1] = tmp;

	CC[2+bs*2] -= CC[2+bs*0] * CC[2+bs*0];
	CC[3+bs*2] -= CC[3+bs*0] * CC[2+bs*0];
	CC[2+bs*2] -= CC[2+bs*1] * CC[2+bs*1];
	CC[3+bs*2] -= CC[3+bs*1] * CC[2+bs*1];
	if(CC[2+bs*2]>0)
		{
		CC[2+bs*2] = sqrt(CC[2+bs*2]);
		tmp = 1.0/CC[2+bs*2];
		}
	else
		{
		CC[2+bs*2] = 0.0;
		tmp = 0.0;
		}
	CC[3+bs*2] *= tmp;
	inv_diag_D[2] = tmp;

	CC[3+bs*3] -= CC[3+bs*0] * CC[3+bs*0];
	CC[3+bs*3] -= CC[3+bs*1] * CC[3+bs*1];
	CC[3+bs*3] -= CC[3+bs*2] * CC[3+bs*2];
	if(CC[3+bs*3]>0)
		{
		CC[3+bs*3] = sqrt(CC[3+bs*3]);
		tmp = 1.0/CC[3+bs*3];
		}
	else
		{
		CC[3+bs*3] = 0.0;
		tmp = 0.0;
		}
	inv_diag_D[3] = tmp;

	D[0+bs*0] = CC[0+bs*0];
	D[1+bs*0] = CC[1+bs*0];
	D[2+bs*0] = CC[2+bs*0];
	D[3+bs*0] = CC[3+bs*0];

	D[1+bs*1] = CC[1+bs*1];
	D[2+bs*1] = CC[2+bs*1];
	D[3+bs*1] = CC[3+bs*1];

	D[2+bs*2] = CC[2+bs*2];
	D[3+bs*2] = CC[3+bs*2];

	D[3+bs*3] = CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7)
void kernel_dpotrf_nt_l_4x4_vs_lib4(int kmax, double *A, double *B, double *C, double *D, double *inv_diag_D, int km, int kn)
	{

	const int bs = 4;

	double tmp;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double alpha1 = -1.0;
	double beta1  = 1.0;

	kernel_dgemm_nt_4x4_lib4(kmax, &alpha1, A, B, &beta1, C, CC);

	if(CC[0+bs*0]>0)
		{
		CC[0+bs*0] = sqrt(CC[0+bs*0]);
		tmp = 1.0/CC[0+bs*0];
		}
	else
		{
		CC[0+bs*0] = 0.0;
		tmp = 0.0;
		}
	CC[1+bs*0] *= tmp;
	CC[2+bs*0] *= tmp;
	CC[3+bs*0] *= tmp;
	inv_diag_D[0] = tmp;

	if(kn==1)
		goto store;
	
	CC[1+bs*1] -= CC[1+bs*0] * CC[1+bs*0];
	CC[2+bs*1] -= CC[2+bs*0] * CC[1+bs*0];
	CC[3+bs*1] -= CC[3+bs*0] * CC[1+bs*0];
	if(CC[1+bs*1]>0)
		{
		CC[1+bs*1] = sqrt(CC[1+bs*1]);
		tmp = 1.0/CC[1+bs*1];
		}
	else
		{
		CC[1+bs*1] = 0.0;
		tmp = 0.0;
		}
	CC[2+bs*1] *= tmp;
	CC[3+bs*1] *= tmp;
	inv_diag_D[1] = tmp;

	if(kn==2)
		goto store;
	
	CC[2+bs*2] -= CC[2+bs*0] * CC[2+bs*0];
	CC[3+bs*2] -= CC[3+bs*0] * CC[2+bs*0];
	CC[2+bs*2] -= CC[2+bs*1] * CC[2+bs*1];
	CC[3+bs*2] -= CC[3+bs*1] * CC[2+bs*1];
	if(CC[2+bs*2]>0)
		{
		CC[2+bs*2] = sqrt(CC[2+bs*2]);
		tmp = 1.0/CC[2+bs*2];
		}
	else
		{
		CC[2+bs*2] = 0.0;
		tmp = 0.0;
		}
	CC[3+bs*2] *= tmp;
	inv_diag_D[2] = tmp;

	if(kn==3)
		goto store;
	
	CC[3+bs*3] -= CC[3+bs*0] * CC[3+bs*0];
	CC[3+bs*3] -= CC[3+bs*1] * CC[3+bs*1];
	CC[3+bs*3] -= CC[3+bs*2] * CC[3+bs*2];
	if(CC[3+bs*3]>0)
		{
		CC[3+bs*3] = sqrt(CC[3+bs*3]);
		tmp = 1.0/CC[3+bs*3];
		}
	else
		{
		CC[3+bs*3] = 0.0;
		tmp = 0.0;
		}
	inv_diag_D[3] = tmp;


	store:

	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[2+bs*2] = CC[2+bs*2];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[1+bs*1] = CC[1+bs*1];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];
		}
	
	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dsyrk_dpotrf_nt_l_4x4_lib4(int kp, double *Ap, double *Bp, int km_, double *Am, double *Bm, double *C, double *D, double *inv_diag_D)
	{
	double alpha = 1.0;
	double beta = 1.0;
	kernel_dsyrk_nt_l_4x4_lib4(kp, &alpha, Ap, Bp, &beta, C, D);
	kernel_dpotrf_nt_l_4x4_lib4(km_, Am, Bm, D, D, inv_diag_D);
	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dsyrk_dpotrf_nt_l_4x4_vs_lib4(int kp, double *Ap, double *Bp, int km_, double *Am, double *Bm, double *C, double *D, double *inv_diag_D, int km, int kn)
	{
	double alpha = 1.0;
	double beta = 1.0;
	kernel_dsyrk_nt_l_4x4_vs_lib4(kp, &alpha, Ap, Bp, &beta, C, D, km, kn);
	kernel_dpotrf_nt_l_4x4_vs_lib4(km_, Am, Bm, D, D, inv_diag_D, km, kn);
	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA)
void kernel_dtrsm_nt_rl_inv_4x4_lib4(int kmax, double *A, double *B, double *beta, double *C, double *D, double *E, double *inv_diag_E)
	{

	const int bs = 4;

	double tmp;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double alpha1 = -1.0;

	kernel_dgemm_nt_4x4_lib4(kmax, &alpha1, A, B, beta, C, CC);

	tmp = inv_diag_E[0];
	CC[0+bs*0] *= tmp;
	CC[1+bs*0] *= tmp;
	CC[2+bs*0] *= tmp;
	CC[3+bs*0] *= tmp;

	tmp = E[1+bs*0];
	CC[0+bs*1] -= CC[0+bs*0] * tmp;
	CC[1+bs*1] -= CC[1+bs*0] * tmp;
	CC[2+bs*1] -= CC[2+bs*0] * tmp;
	CC[3+bs*1] -= CC[3+bs*0] * tmp;
	tmp = inv_diag_E[1];
	CC[0+bs*1] *= tmp;
	CC[1+bs*1] *= tmp;
	CC[2+bs*1] *= tmp;
	CC[3+bs*1] *= tmp;

	tmp = E[2+bs*0];
	CC[0+bs*2] -= CC[0+bs*0] * tmp;
	CC[1+bs*2] -= CC[1+bs*0] * tmp;
	CC[2+bs*2] -= CC[2+bs*0] * tmp;
	CC[3+bs*2] -= CC[3+bs*0] * tmp;
	tmp = E[2+bs*1];
	CC[0+bs*2] -= CC[0+bs*1] * tmp;
	CC[1+bs*2] -= CC[1+bs*1] * tmp;
	CC[2+bs*2] -= CC[2+bs*1] * tmp;
	CC[3+bs*2] -= CC[3+bs*1] * tmp;
	tmp = inv_diag_E[2];
	CC[0+bs*2] *= tmp;
	CC[1+bs*2] *= tmp;
	CC[2+bs*2] *= tmp;
	CC[3+bs*2] *= tmp;

	tmp = E[3+bs*0];
	CC[0+bs*3] -= CC[0+bs*0] * tmp;
	CC[1+bs*3] -= CC[1+bs*0] * tmp;
	CC[2+bs*3] -= CC[2+bs*0] * tmp;
	CC[3+bs*3] -= CC[3+bs*0] * tmp;
	tmp = E[3+bs*1];
	CC[0+bs*3] -= CC[0+bs*1] * tmp;
	CC[1+bs*3] -= CC[1+bs*1] * tmp;
	CC[2+bs*3] -= CC[2+bs*1] * tmp;
	CC[3+bs*3] -= CC[3+bs*1] * tmp;
	tmp = E[3+bs*2];
	CC[0+bs*3] -= CC[0+bs*2] * tmp;
	CC[1+bs*3] -= CC[1+bs*2] * tmp;
	CC[2+bs*3] -= CC[2+bs*2] * tmp;
	CC[3+bs*3] -= CC[3+bs*2] * tmp;
	tmp = inv_diag_E[3];
	CC[0+bs*3] *= tmp;
	CC[1+bs*3] *= tmp;
	CC[2+bs*3] *= tmp;
	CC[3+bs*3] *= tmp;

	D[0+bs*0] = CC[0+bs*0];
	D[1+bs*0] = CC[1+bs*0];
	D[2+bs*0] = CC[2+bs*0];
	D[3+bs*0] = CC[3+bs*0];

	D[0+bs*1] = CC[0+bs*1];
	D[1+bs*1] = CC[1+bs*1];
	D[2+bs*1] = CC[2+bs*1];
	D[3+bs*1] = CC[3+bs*1];

	D[0+bs*2] = CC[0+bs*2];
	D[1+bs*2] = CC[1+bs*2];
	D[2+bs*2] = CC[2+bs*2];
	D[3+bs*2] = CC[3+bs*2];

	D[0+bs*3] = CC[0+bs*3];
	D[1+bs*3] = CC[1+bs*3];
	D[2+bs*3] = CC[2+bs*3];
	D[3+bs*3] = CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7)
void kernel_dtrsm_nt_rl_inv_4x4_vs_lib4(int kmax, double *A, double *B, double *beta, double *C, double *D, double *E, double *inv_diag_E, int km, int kn)
	{

	const int bs = 4;

	double tmp;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double alpha1 = -1.0;

	kernel_dgemm_nt_4x4_lib4(kmax, &alpha1, A, B, beta, C, CC);

	tmp = inv_diag_E[0];
	CC[0+bs*0] *= tmp;
	CC[1+bs*0] *= tmp;
	CC[2+bs*0] *= tmp;
	CC[3+bs*0] *= tmp;

	if(kn==1)
		goto store;
	
	tmp = E[1+bs*0];
	CC[0+bs*1] -= CC[0+bs*0] * tmp;
	CC[1+bs*1] -= CC[1+bs*0] * tmp;
	CC[2+bs*1] -= CC[2+bs*0] * tmp;
	CC[3+bs*1] -= CC[3+bs*0] * tmp;
	tmp = inv_diag_E[1];
	CC[0+bs*1] *= tmp;
	CC[1+bs*1] *= tmp;
	CC[2+bs*1] *= tmp;
	CC[3+bs*1] *= tmp;

	if(kn==2)
		goto store;
	
	tmp = E[2+bs*0];
	CC[0+bs*2] -= CC[0+bs*0] * tmp;
	CC[1+bs*2] -= CC[1+bs*0] * tmp;
	CC[2+bs*2] -= CC[2+bs*0] * tmp;
	CC[3+bs*2] -= CC[3+bs*0] * tmp;
	tmp = E[2+bs*1];
	CC[0+bs*2] -= CC[0+bs*1] * tmp;
	CC[1+bs*2] -= CC[1+bs*1] * tmp;
	CC[2+bs*2] -= CC[2+bs*1] * tmp;
	CC[3+bs*2] -= CC[3+bs*1] * tmp;
	tmp = inv_diag_E[2];
	CC[0+bs*2] *= tmp;
	CC[1+bs*2] *= tmp;
	CC[2+bs*2] *= tmp;
	CC[3+bs*2] *= tmp;

	if(kn==3)
		goto store;
	
	tmp = E[3+bs*0];
	CC[0+bs*3] -= CC[0+bs*0] * tmp;
	CC[1+bs*3] -= CC[1+bs*0] * tmp;
	CC[2+bs*3] -= CC[2+bs*0] * tmp;
	CC[3+bs*3] -= CC[3+bs*0] * tmp;
	tmp = E[3+bs*1];
	CC[0+bs*3] -= CC[0+bs*1] * tmp;
	CC[1+bs*3] -= CC[1+bs*1] * tmp;
	CC[2+bs*3] -= CC[2+bs*1] * tmp;
	CC[3+bs*3] -= CC[3+bs*1] * tmp;
	tmp = E[3+bs*2];
	CC[0+bs*3] -= CC[0+bs*2] * tmp;
	CC[1+bs*3] -= CC[1+bs*2] * tmp;
	CC[2+bs*3] -= CC[2+bs*2] * tmp;
	CC[3+bs*3] -= CC[3+bs*2] * tmp;
	tmp = inv_diag_E[3];
	CC[0+bs*3] *= tmp;
	CC[1+bs*3] *= tmp;
	CC[2+bs*3] *= tmp;
	CC[3+bs*3] *= tmp;

	store:

	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dgemm_dtrsm_nt_rl_inv_4x4_lib4(int kp, double *Ap, double *Bp, int km_, double *Am, double *Bm, double *C, double *D, double *E, double *inv_diag_E)
	{
	double alpha = 1.0;
	double beta  = 1.0;
	kernel_dgemm_nt_4x4_lib4(kp, &alpha, Ap, Bp, &beta, C, D);
	kernel_dtrsm_nt_rl_inv_4x4_lib4(km_, Am, Bm, &beta, D, D, E, inv_diag_E);
	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dgemm_dtrsm_nt_rl_inv_4x4_vs_lib4(int kp, double *Ap, double *Bp, int km_, double *Am, double *Bm, double *C, double *D, double *E, double *inv_diag_E, int km, int kn)
	{
	double alpha = 1.0;
	double beta  = 1.0;
	kernel_dgemm_nt_4x4_vs_lib4(kp, &alpha, Ap, Bp, &beta, C, D, km, kn);
	kernel_dtrsm_nt_rl_inv_4x4_vs_lib4(km_, Am, Bm, &beta, D, D, E, inv_diag_E, km, kn);
	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nt_rl_one_4x4_lib4(int kmax, double *A, double *B, double *C, double *D, double *E)
	{

	const int bs = 4;

	double tmp;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double alpha1 = -1.0;
	double beta1  = 1.0;

	kernel_dgemm_nt_4x4_lib4(kmax, &alpha1, A, B, &beta1, C, CC);

	tmp = E[1+bs*0];
	CC[0+bs*1] -= CC[0+bs*0] * tmp;
	CC[1+bs*1] -= CC[1+bs*0] * tmp;
	CC[2+bs*1] -= CC[2+bs*0] * tmp;
	CC[3+bs*1] -= CC[3+bs*0] * tmp;

	tmp = E[2+bs*0];
	CC[0+bs*2] -= CC[0+bs*0] * tmp;
	CC[1+bs*2] -= CC[1+bs*0] * tmp;
	CC[2+bs*2] -= CC[2+bs*0] * tmp;
	CC[3+bs*2] -= CC[3+bs*0] * tmp;
	tmp = E[2+bs*1];
	CC[0+bs*2] -= CC[0+bs*1] * tmp;
	CC[1+bs*2] -= CC[1+bs*1] * tmp;
	CC[2+bs*2] -= CC[2+bs*1] * tmp;
	CC[3+bs*2] -= CC[3+bs*1] * tmp;

	tmp = E[3+bs*0];
	CC[0+bs*3] -= CC[0+bs*0] * tmp;
	CC[1+bs*3] -= CC[1+bs*0] * tmp;
	CC[2+bs*3] -= CC[2+bs*0] * tmp;
	CC[3+bs*3] -= CC[3+bs*0] * tmp;
	tmp = E[3+bs*1];
	CC[0+bs*3] -= CC[0+bs*1] * tmp;
	CC[1+bs*3] -= CC[1+bs*1] * tmp;
	CC[2+bs*3] -= CC[2+bs*1] * tmp;
	CC[3+bs*3] -= CC[3+bs*1] * tmp;
	tmp = E[3+bs*2];
	CC[0+bs*3] -= CC[0+bs*2] * tmp;
	CC[1+bs*3] -= CC[1+bs*2] * tmp;
	CC[2+bs*3] -= CC[2+bs*2] * tmp;
	CC[3+bs*3] -= CC[3+bs*2] * tmp;

	D[0+bs*0] = CC[0+bs*0];
	D[1+bs*0] = CC[1+bs*0];
	D[2+bs*0] = CC[2+bs*0];
	D[3+bs*0] = CC[3+bs*0];

	D[0+bs*1] = CC[0+bs*1];
	D[1+bs*1] = CC[1+bs*1];
	D[2+bs*1] = CC[2+bs*1];
	D[3+bs*1] = CC[3+bs*1];

	D[0+bs*2] = CC[0+bs*2];
	D[1+bs*2] = CC[1+bs*2];
	D[2+bs*2] = CC[2+bs*2];
	D[3+bs*2] = CC[3+bs*2];

	D[0+bs*3] = CC[0+bs*3];
	D[1+bs*3] = CC[1+bs*3];
	D[2+bs*3] = CC[2+bs*3];
	D[3+bs*3] = CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nt_rl_one_4x4_vs_lib4(int kmax, double *A, double *B, double *C, double *D, double *E, int km, int kn)
	{

	const int bs = 4;

	double tmp;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double alpha1 = -1.0;
	double beta1  = 1.0;

	kernel_dgemm_nt_4x4_lib4(kmax, &alpha1, A, B, &beta1, C, CC);

	if(kn==1)
		goto store;
	
	tmp = E[1+bs*0];
	CC[0+bs*1] -= CC[0+bs*0] * tmp;
	CC[1+bs*1] -= CC[1+bs*0] * tmp;
	CC[2+bs*1] -= CC[2+bs*0] * tmp;
	CC[3+bs*1] -= CC[3+bs*0] * tmp;

	if(kn==2)
		goto store;
	
	tmp = E[2+bs*0];
	CC[0+bs*2] -= CC[0+bs*0] * tmp;
	CC[1+bs*2] -= CC[1+bs*0] * tmp;
	CC[2+bs*2] -= CC[2+bs*0] * tmp;
	CC[3+bs*2] -= CC[3+bs*0] * tmp;
	tmp = E[2+bs*1];
	CC[0+bs*2] -= CC[0+bs*1] * tmp;
	CC[1+bs*2] -= CC[1+bs*1] * tmp;
	CC[2+bs*2] -= CC[2+bs*1] * tmp;
	CC[3+bs*2] -= CC[3+bs*1] * tmp;

	if(kn==3)
		goto store;
	
	tmp = E[3+bs*0];
	CC[0+bs*3] -= CC[0+bs*0] * tmp;
	CC[1+bs*3] -= CC[1+bs*0] * tmp;
	CC[2+bs*3] -= CC[2+bs*0] * tmp;
	CC[3+bs*3] -= CC[3+bs*0] * tmp;
	tmp = E[3+bs*1];
	CC[0+bs*3] -= CC[0+bs*1] * tmp;
	CC[1+bs*3] -= CC[1+bs*1] * tmp;
	CC[2+bs*3] -= CC[2+bs*1] * tmp;
	CC[3+bs*3] -= CC[3+bs*1] * tmp;
	tmp = E[3+bs*2];
	CC[0+bs*3] -= CC[0+bs*2] * tmp;
	CC[1+bs*3] -= CC[1+bs*2] * tmp;
	CC[2+bs*3] -= CC[2+bs*2] * tmp;
	CC[3+bs*3] -= CC[3+bs*2] * tmp;

	store:

	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}
	
	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nt_ru_inv_4x4_lib4(int kmax, double *A, double *B, double *beta, double *C, double *D, double *E, double *inv_diag_E)
	{

	const int bs = 4;

	double tmp;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double alpha1 = -1.0;

	kernel_dgemm_nt_4x4_lib4(kmax, &alpha1, A, B, beta, C, CC);

	tmp = inv_diag_E[3];
	CC[0+bs*3] *= tmp;
	CC[1+bs*3] *= tmp;
	CC[2+bs*3] *= tmp;
	CC[3+bs*3] *= tmp;
	tmp = E[2+bs*3];
	CC[0+bs*2] -= CC[0+bs*3] * tmp;
	CC[1+bs*2] -= CC[1+bs*3] * tmp;
	CC[2+bs*2] -= CC[2+bs*3] * tmp;
	CC[3+bs*2] -= CC[3+bs*3] * tmp;
	tmp = E[1+bs*3];
	CC[0+bs*1] -= CC[0+bs*3] * tmp;
	CC[1+bs*1] -= CC[1+bs*3] * tmp;
	CC[2+bs*1] -= CC[2+bs*3] * tmp;
	CC[3+bs*1] -= CC[3+bs*3] * tmp;
	tmp = E[0+bs*3];
	CC[0+bs*0] -= CC[0+bs*3] * tmp;
	CC[1+bs*0] -= CC[1+bs*3] * tmp;
	CC[2+bs*0] -= CC[2+bs*3] * tmp;
	CC[3+bs*0] -= CC[3+bs*3] * tmp;

	tmp = inv_diag_E[2];
	CC[0+bs*2] *= tmp;
	CC[1+bs*2] *= tmp;
	CC[2+bs*2] *= tmp;
	CC[3+bs*2] *= tmp;
	tmp = E[1+bs*2];
	CC[0+bs*1] -= CC[0+bs*2] * tmp;
	CC[1+bs*1] -= CC[1+bs*2] * tmp;
	CC[2+bs*1] -= CC[2+bs*2] * tmp;
	CC[3+bs*1] -= CC[3+bs*2] * tmp;
	tmp = E[0+bs*2];
	CC[0+bs*0] -= CC[0+bs*2] * tmp;
	CC[1+bs*0] -= CC[1+bs*2] * tmp;
	CC[2+bs*0] -= CC[2+bs*2] * tmp;
	CC[3+bs*0] -= CC[3+bs*2] * tmp;

	tmp = inv_diag_E[1];
	CC[0+bs*1] *= tmp;
	CC[1+bs*1] *= tmp;
	CC[2+bs*1] *= tmp;
	CC[3+bs*1] *= tmp;
	tmp = E[0+bs*1];
	CC[0+bs*0] -= CC[0+bs*1] * tmp;
	CC[1+bs*0] -= CC[1+bs*1] * tmp;
	CC[2+bs*0] -= CC[2+bs*1] * tmp;
	CC[3+bs*0] -= CC[3+bs*1] * tmp;

	tmp = inv_diag_E[0];
	CC[0+bs*0] *= tmp;
	CC[1+bs*0] *= tmp;
	CC[2+bs*0] *= tmp;
	CC[3+bs*0] *= tmp;

	D[0+bs*0] = CC[0+bs*0];
	D[1+bs*0] = CC[1+bs*0];
	D[2+bs*0] = CC[2+bs*0];
	D[3+bs*0] = CC[3+bs*0];

	D[0+bs*1] = CC[0+bs*1];
	D[1+bs*1] = CC[1+bs*1];
	D[2+bs*1] = CC[2+bs*1];
	D[3+bs*1] = CC[3+bs*1];

	D[0+bs*2] = CC[0+bs*2];
	D[1+bs*2] = CC[1+bs*2];
	D[2+bs*2] = CC[2+bs*2];
	D[3+bs*2] = CC[3+bs*2];

	D[0+bs*3] = CC[0+bs*3];
	D[1+bs*3] = CC[1+bs*3];
	D[2+bs*3] = CC[2+bs*3];
	D[3+bs*3] = CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nt_ru_inv_4x4_vs_lib4(int kmax, double *A, double *B, double *beta, double *C, double *D, double *E, double *inv_diag_E, int km, int kn)
	{

	const int bs = 4;

	double tmp;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif

	double alpha1 = -1.0;

	kernel_dgemm_nt_4x4_lib4(kmax, &alpha1, A, B, beta, C, CC);

	if(kn>3)
		{
		tmp = inv_diag_E[3];
		CC[0+bs*3] *= tmp;
		CC[1+bs*3] *= tmp;
		CC[2+bs*3] *= tmp;
		CC[3+bs*3] *= tmp;
		tmp = E[2+bs*3];
		CC[0+bs*2] -= CC[0+bs*3] * tmp;
		CC[1+bs*2] -= CC[1+bs*3] * tmp;
		CC[2+bs*2] -= CC[2+bs*3] * tmp;
		CC[3+bs*2] -= CC[3+bs*3] * tmp;
		tmp = E[1+bs*3];
		CC[0+bs*1] -= CC[0+bs*3] * tmp;
		CC[1+bs*1] -= CC[1+bs*3] * tmp;
		CC[2+bs*1] -= CC[2+bs*3] * tmp;
		CC[3+bs*1] -= CC[3+bs*3] * tmp;
		tmp = E[0+bs*3];
		CC[0+bs*0] -= CC[0+bs*3] * tmp;
		CC[1+bs*0] -= CC[1+bs*3] * tmp;
		CC[2+bs*0] -= CC[2+bs*3] * tmp;
		CC[3+bs*0] -= CC[3+bs*3] * tmp;
		}

	if(kn>2)
		{
		tmp = inv_diag_E[2];
		CC[0+bs*2] *= tmp;
		CC[1+bs*2] *= tmp;
		CC[2+bs*2] *= tmp;
		CC[3+bs*2] *= tmp;
		tmp = E[1+bs*2];
		CC[0+bs*1] -= CC[0+bs*2] * tmp;
		CC[1+bs*1] -= CC[1+bs*2] * tmp;
		CC[2+bs*1] -= CC[2+bs*2] * tmp;
		CC[3+bs*1] -= CC[3+bs*2] * tmp;
		tmp = E[0+bs*2];
		CC[0+bs*0] -= CC[0+bs*2] * tmp;
		CC[1+bs*0] -= CC[1+bs*2] * tmp;
		CC[2+bs*0] -= CC[2+bs*2] * tmp;
		CC[3+bs*0] -= CC[3+bs*2] * tmp;
		}

	if(kn>1)
		{
		tmp = inv_diag_E[1];
		CC[0+bs*1] *= tmp;
		CC[1+bs*1] *= tmp;
		CC[2+bs*1] *= tmp;
		CC[3+bs*1] *= tmp;
		tmp = E[0+bs*1];
		CC[0+bs*0] -= CC[0+bs*1] * tmp;
		CC[1+bs*0] -= CC[1+bs*1] * tmp;
		CC[2+bs*0] -= CC[2+bs*1] * tmp;
		CC[3+bs*0] -= CC[3+bs*1] * tmp;
		}

	tmp = inv_diag_E[0];
	CC[0+bs*0] *= tmp;
	CC[1+bs*0] *= tmp;
	CC[2+bs*0] *= tmp;
	CC[3+bs*0] *= tmp;


	store:

	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}
	
	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dgetrf_nn_4x4_lib4(int kmax, double *A, double *B, int sdb, double *C, double *D, double *inv_diag_D)
	{

	const int bs = 4;

	int k;

	double tmp;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif
	
	double alpha1 = -1.0;
	double beta1  = 1.0;

	kernel_dgemm_nn_4x4_lib4(kmax, &alpha1, A, 0, B, sdb, &beta1, C, CC);

	// factorization

	// first column
	tmp = 1.0 / CC[0+bs*0];
	CC[1+bs*0] *= tmp;
	CC[2+bs*0] *= tmp;
	CC[3+bs*0] *= tmp;

	inv_diag_D[0] = tmp;

	// second column
	CC[1+bs*1] -= CC[1+bs*0] * CC[0+bs*1];
	CC[2+bs*1] -= CC[2+bs*0] * CC[0+bs*1];
	CC[3+bs*1] -= CC[3+bs*0] * CC[0+bs*1];

	tmp = 1.0 / CC[1+bs*1];
	CC[2+bs*1] *= tmp;
	CC[3+bs*1] *= tmp;
	
	inv_diag_D[1] = tmp;

	// third column
	CC[1+bs*2] -= CC[1+bs*0] * CC[0+bs*2];
	CC[2+bs*2] -= CC[2+bs*0] * CC[0+bs*2];
	CC[3+bs*2] -= CC[3+bs*0] * CC[0+bs*2];

	CC[2+bs*2] -= CC[2+bs*1] * CC[1+bs*2];
	CC[3+bs*2] -= CC[3+bs*1] * CC[1+bs*2];

	tmp = 1.0 / CC[2+bs*2];
	CC[3+bs*2] *= tmp;

	inv_diag_D[2] = tmp;

	// fourth column
	CC[1+bs*3] -= CC[1+bs*0] * CC[0+bs*3];
	CC[2+bs*3] -= CC[2+bs*0] * CC[0+bs*3];
	CC[3+bs*3] -= CC[3+bs*0] * CC[0+bs*3];

	CC[2+bs*3] -= CC[2+bs*1] * CC[1+bs*3];
	CC[3+bs*3] -= CC[3+bs*1] * CC[1+bs*3];

	CC[3+bs*3] -= CC[3+bs*2] * CC[2+bs*3];

	tmp = 1.0 / CC[3+bs*3];

	inv_diag_D[3] = tmp;

	D[0+bs*0] = CC[0+bs*0];
	D[1+bs*0] = CC[1+bs*0];
	D[2+bs*0] = CC[2+bs*0];
	D[3+bs*0] = CC[3+bs*0];

	D[0+bs*1] = CC[0+bs*1];
	D[1+bs*1] = CC[1+bs*1];
	D[2+bs*1] = CC[2+bs*1];
	D[3+bs*1] = CC[3+bs*1];

	D[0+bs*2] = CC[0+bs*2];
	D[1+bs*2] = CC[1+bs*2];
	D[2+bs*2] = CC[2+bs*2];
	D[3+bs*2] = CC[3+bs*2];

	D[0+bs*3] = CC[0+bs*3];
	D[1+bs*3] = CC[1+bs*3];
	D[2+bs*3] = CC[2+bs*3];
	D[3+bs*3] = CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dgetrf_nn_4x4_vs_lib4(int kmax, double *A, double *B, int sdb, double *C, double *D, double *inv_diag_D, int km, int kn)
	{

	const int bs = 4;

	int k;

	double tmp;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif
	
	double alpha1 = -1.0;
	double beta1  = 1.0;

	kernel_dgemm_nn_4x4_lib4(kmax, &alpha1, A, 0, B, sdb, &beta1, C, CC);

	// factorization

	// first column
	tmp = 1.0 / CC[0+bs*0];
	CC[1+bs*0] *= tmp;
	CC[2+bs*0] *= tmp;
	CC[3+bs*0] *= tmp;

	inv_diag_D[0] = tmp;

	if(kn==1)
		goto store;

	// second column
	CC[1+bs*1] -= CC[1+bs*0] * CC[0+bs*1];
	CC[2+bs*1] -= CC[2+bs*0] * CC[0+bs*1];
	CC[3+bs*1] -= CC[3+bs*0] * CC[0+bs*1];

	tmp = 1.0 / CC[1+bs*1];
	CC[2+bs*1] *= tmp;
	CC[3+bs*1] *= tmp;
	
	inv_diag_D[1] = tmp;

	if(kn==2)
		goto store;

	// third column
	CC[1+bs*2] -= CC[1+bs*0] * CC[0+bs*2];
	CC[2+bs*2] -= CC[2+bs*0] * CC[0+bs*2];
	CC[3+bs*2] -= CC[3+bs*0] * CC[0+bs*2];

	CC[2+bs*2] -= CC[2+bs*1] * CC[1+bs*2];
	CC[3+bs*2] -= CC[3+bs*1] * CC[1+bs*2];

	tmp = 1.0 / CC[2+bs*2];
	CC[3+bs*2] *= tmp;

	inv_diag_D[2] = tmp;

	if(kn==3)
		goto store;

	// fourth column
	CC[1+bs*3] -= CC[1+bs*0] * CC[0+bs*3];
	CC[2+bs*3] -= CC[2+bs*0] * CC[0+bs*3];
	CC[3+bs*3] -= CC[3+bs*0] * CC[0+bs*3];

	CC[2+bs*3] -= CC[2+bs*1] * CC[1+bs*3];
	CC[3+bs*3] -= CC[3+bs*1] * CC[1+bs*3];

	CC[3+bs*3] -= CC[3+bs*2] * CC[2+bs*3];

	tmp = 1.0 / CC[3+bs*3];

	inv_diag_D[3] = tmp;

	store:

	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nn_ll_inv_4x4_lib4(int kmax, double *A, double *B, int sdb, double *beta, double *C, double *D, double *E, double *inv_diag_E)
	{

	const int bs = 4;

	int k;

	double
		tmp,
		e_0, e_1, e_2, e_3;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif
	
	double alpha1 = -1.0;

	kernel_dgemm_nn_4x4_lib4(kmax, &alpha1, A, 0, B, sdb, beta, C, CC);

	// solution

	e_0 = inv_diag_E[0];
	e_1 = E[1+bs*0];
	e_2 = E[2+bs*0];
	e_3 = E[3+bs*0];
	CC[0+bs*0] *= e_0;
	CC[1+bs*0] -= e_1 * CC[0+bs*0];
	CC[2+bs*0] -= e_2 * CC[0+bs*0];
	CC[3+bs*0] -= e_3 * CC[0+bs*0];
	CC[0+bs*1] *= e_0;
	CC[1+bs*1] -= e_1 * CC[0+bs*1];
	CC[2+bs*1] -= e_2 * CC[0+bs*1];
	CC[3+bs*1] -= e_3 * CC[0+bs*1];
	CC[0+bs*2] *= e_0;
	CC[1+bs*2] -= e_1 * CC[0+bs*2];
	CC[2+bs*2] -= e_2 * CC[0+bs*2];
	CC[3+bs*2] -= e_3 * CC[0+bs*2];
	CC[0+bs*3] *= e_0;
	CC[1+bs*3] -= e_1 * CC[0+bs*3];
	CC[2+bs*3] -= e_2 * CC[0+bs*3];
	CC[3+bs*3] -= e_3 * CC[0+bs*3];

	e_1 = inv_diag_E[1];
	e_2 = E[2+bs*1];
	e_3 = E[3+bs*1];
	CC[1+bs*0] *= e_1;
	CC[2+bs*0] -= e_2 * CC[1+bs*0];
	CC[3+bs*0] -= e_3 * CC[1+bs*0];
	CC[1+bs*1] *= e_1;
	CC[2+bs*1] -= e_2 * CC[1+bs*1];
	CC[3+bs*1] -= e_3 * CC[1+bs*1];
	CC[1+bs*2] *= e_1;
	CC[2+bs*2] -= e_2 * CC[1+bs*2];
	CC[3+bs*2] -= e_3 * CC[1+bs*2];
	CC[1+bs*3] *= e_1;
	CC[2+bs*3] -= e_2 * CC[1+bs*3];
	CC[3+bs*3] -= e_3 * CC[1+bs*3];

	e_2 = inv_diag_E[2];
	e_3 = E[3+bs*2];
	CC[2+bs*0] *= e_2;
	CC[3+bs*0] -= e_3 * CC[2+bs*0];
	CC[2+bs*1] *= e_2;
	CC[3+bs*1] -= e_3 * CC[2+bs*1];
	CC[2+bs*2] *= e_2;
	CC[3+bs*2] -= e_3 * CC[2+bs*2];
	CC[2+bs*3] *= e_2;
	CC[3+bs*3] -= e_3 * CC[2+bs*3];

	e_3 = inv_diag_E[3];
	CC[3+bs*0] *= e_3;
	CC[3+bs*1] *= e_3;
	CC[3+bs*2] *= e_3;
	CC[3+bs*3] *= e_3;

	D[0+bs*0] = CC[0+bs*0];
	D[1+bs*0] = CC[1+bs*0];
	D[2+bs*0] = CC[2+bs*0];
	D[3+bs*0] = CC[3+bs*0];

	D[0+bs*1] = CC[0+bs*1];
	D[1+bs*1] = CC[1+bs*1];
	D[2+bs*1] = CC[2+bs*1];
	D[3+bs*1] = CC[3+bs*1];

	D[0+bs*2] = CC[0+bs*2];
	D[1+bs*2] = CC[1+bs*2];
	D[2+bs*2] = CC[2+bs*2];
	D[3+bs*2] = CC[3+bs*2];

	D[0+bs*3] = CC[0+bs*3];
	D[1+bs*3] = CC[1+bs*3];
	D[2+bs*3] = CC[2+bs*3];
	D[3+bs*3] = CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nn_ll_inv_4x4_vs_lib4(int kmax, double *A, double *B, int sdb, double *beta, double *C, double *D, double *E, double *inv_diag_E, int km, int kn)
	{

	const int bs = 4;

	int k;

	double
		tmp,
		e_0, e_1, e_2, e_3;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif
	
	double alpha1 = -1.0;

	kernel_dgemm_nn_4x4_lib4(kmax, &alpha1, A, 0, B, sdb, beta, C, CC);

	// solution

	e_0 = inv_diag_E[0];
	CC[0+bs*0] *= e_0;
	CC[0+bs*1] *= e_0;
	CC[0+bs*2] *= e_0;
	CC[0+bs*3] *= e_0;

	if(km==1)
		goto store;
	
	e_0 = E[1+bs*0];
	CC[1+bs*0] -= e_0 * CC[0+bs*0];
	CC[1+bs*1] -= e_0 * CC[0+bs*1];
	CC[1+bs*2] -= e_0 * CC[0+bs*2];
	CC[1+bs*3] -= e_0 * CC[0+bs*3];
	e_1 = inv_diag_E[1];
	CC[1+bs*0] *= e_1;
	CC[1+bs*1] *= e_1;
	CC[1+bs*2] *= e_1;
	CC[1+bs*3] *= e_1;

	if(km==2)
		goto store;
	
	e_0 = E[2+bs*0];
	CC[2+bs*0] -= e_0 * CC[0+bs*0];
	CC[2+bs*1] -= e_0 * CC[0+bs*1];
	CC[2+bs*2] -= e_0 * CC[0+bs*2];
	CC[2+bs*3] -= e_0 * CC[0+bs*3];
	e_1 = E[2+bs*1];
	CC[2+bs*0] -= e_1 * CC[1+bs*0];
	CC[2+bs*1] -= e_1 * CC[1+bs*1];
	CC[2+bs*2] -= e_1 * CC[1+bs*2];
	CC[2+bs*3] -= e_1 * CC[1+bs*3];
	e_2 = inv_diag_E[2];
	CC[2+bs*0] *= e_2;
	CC[2+bs*1] *= e_2;
	CC[2+bs*2] *= e_2;
	CC[2+bs*3] *= e_2;

	if(km==3)
		goto store;
	
	e_0 = E[3+bs*0];
	CC[3+bs*0] -= e_0 * CC[0+bs*0];
	CC[3+bs*1] -= e_0 * CC[0+bs*1];
	CC[3+bs*2] -= e_0 * CC[0+bs*2];
	CC[3+bs*3] -= e_0 * CC[0+bs*3];
	e_1 = E[3+bs*1];
	CC[3+bs*0] -= e_1 * CC[1+bs*0];
	CC[3+bs*1] -= e_1 * CC[1+bs*1];
	CC[3+bs*2] -= e_1 * CC[1+bs*2];
	CC[3+bs*3] -= e_1 * CC[1+bs*3];
	e_2 = E[3+bs*2];
	CC[3+bs*0] -= e_2 * CC[2+bs*0];
	CC[3+bs*1] -= e_2 * CC[2+bs*1];
	CC[3+bs*2] -= e_2 * CC[2+bs*2];
	CC[3+bs*3] -= e_2 * CC[2+bs*3];
	e_3 = inv_diag_E[3];
	CC[3+bs*0] *= e_3;
	CC[3+bs*1] *= e_3;
	CC[3+bs*2] *= e_3;
	CC[3+bs*3] *= e_3;

	store:

	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nn_ll_one_4x4_lib4(int kmax, double *A, double *B, int sdb, double *beta, double *C, double *D, double *E)
	{

	const int bs = 4;

	int k;

	double
		tmp,
		e_1, e_2, e_3;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif
	
	double alpha1 = -1.0;

	kernel_dgemm_nn_4x4_lib4(kmax, &alpha1, A, 0, B, sdb, beta, C, CC);

	// solution

	e_1 = E[1+bs*0];
	e_2 = E[2+bs*0];
	e_3 = E[3+bs*0];
	CC[1+bs*0] -= e_1 * CC[0+bs*0];
	CC[2+bs*0] -= e_2 * CC[0+bs*0];
	CC[3+bs*0] -= e_3 * CC[0+bs*0];
	CC[1+bs*1] -= e_1 * CC[0+bs*1];
	CC[2+bs*1] -= e_2 * CC[0+bs*1];
	CC[3+bs*1] -= e_3 * CC[0+bs*1];
	CC[1+bs*2] -= e_1 * CC[0+bs*2];
	CC[2+bs*2] -= e_2 * CC[0+bs*2];
	CC[3+bs*2] -= e_3 * CC[0+bs*2];
	CC[1+bs*3] -= e_1 * CC[0+bs*3];
	CC[2+bs*3] -= e_2 * CC[0+bs*3];
	CC[3+bs*3] -= e_3 * CC[0+bs*3];

	e_2 = E[2+bs*1];
	e_3 = E[3+bs*1];
	CC[2+bs*0] -= e_2 * CC[1+bs*0];
	CC[3+bs*0] -= e_3 * CC[1+bs*0];
	CC[2+bs*1] -= e_2 * CC[1+bs*1];
	CC[3+bs*1] -= e_3 * CC[1+bs*1];
	CC[2+bs*2] -= e_2 * CC[1+bs*2];
	CC[3+bs*2] -= e_3 * CC[1+bs*2];
	CC[2+bs*3] -= e_2 * CC[1+bs*3];
	CC[3+bs*3] -= e_3 * CC[1+bs*3];

	e_3 = E[3+bs*2];
	CC[3+bs*0] -= e_3 * CC[2+bs*0];
	CC[3+bs*1] -= e_3 * CC[2+bs*1];
	CC[3+bs*2] -= e_3 * CC[2+bs*2];
	CC[3+bs*3] -= e_3 * CC[2+bs*3];

	D[0+bs*0] = CC[0+bs*0];
	D[1+bs*0] = CC[1+bs*0];
	D[2+bs*0] = CC[2+bs*0];
	D[3+bs*0] = CC[3+bs*0];

	D[0+bs*1] = CC[0+bs*1];
	D[1+bs*1] = CC[1+bs*1];
	D[2+bs*1] = CC[2+bs*1];
	D[3+bs*1] = CC[3+bs*1];

	D[0+bs*2] = CC[0+bs*2];
	D[1+bs*2] = CC[1+bs*2];
	D[2+bs*2] = CC[2+bs*2];
	D[3+bs*2] = CC[3+bs*2];

	D[0+bs*3] = CC[0+bs*3];
	D[1+bs*3] = CC[1+bs*3];
	D[2+bs*3] = CC[2+bs*3];
	D[3+bs*3] = CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nn_ll_one_4x4_vs_lib4(int kmax, double *A, double *B, int sdb, double *beta, double *C, double *D, double *E, int km, int kn)
	{

	const int bs = 4;

	int k;

	double
		tmp,
		e_0, e_1, e_2, e_3;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif
	
	double alpha1 = -1.0;

	kernel_dgemm_nn_4x4_lib4(kmax, &alpha1, A, 0, B, sdb, beta, C, CC);

	// solution

	if(km==1)
		goto store;
	
	e_0 = E[1+bs*0];
	CC[1+bs*0] -= e_0 * CC[0+bs*0];
	CC[1+bs*1] -= e_0 * CC[0+bs*1];
	CC[1+bs*2] -= e_0 * CC[0+bs*2];
	CC[1+bs*3] -= e_0 * CC[0+bs*3];

	if(km==2)
		goto store;
	
	e_0 = E[2+bs*0];
	CC[2+bs*0] -= e_0 * CC[0+bs*0];
	CC[2+bs*1] -= e_0 * CC[0+bs*1];
	CC[2+bs*2] -= e_0 * CC[0+bs*2];
	CC[2+bs*3] -= e_0 * CC[0+bs*3];
	e_1 = E[2+bs*1];
	CC[2+bs*0] -= e_1 * CC[1+bs*0];
	CC[2+bs*1] -= e_1 * CC[1+bs*1];
	CC[2+bs*2] -= e_1 * CC[1+bs*2];
	CC[2+bs*3] -= e_1 * CC[1+bs*3];

	if(km==3)
		goto store;
	
	e_0 = E[3+bs*0];
	CC[3+bs*0] -= e_0 * CC[0+bs*0];
	CC[3+bs*1] -= e_0 * CC[0+bs*1];
	CC[3+bs*2] -= e_0 * CC[0+bs*2];
	CC[3+bs*3] -= e_0 * CC[0+bs*3];
	e_1 = E[3+bs*1];
	CC[3+bs*0] -= e_1 * CC[1+bs*0];
	CC[3+bs*1] -= e_1 * CC[1+bs*1];
	CC[3+bs*2] -= e_1 * CC[1+bs*2];
	CC[3+bs*3] -= e_1 * CC[1+bs*3];
	e_2 = E[3+bs*2];
	CC[3+bs*0] -= e_2 * CC[2+bs*0];
	CC[3+bs*1] -= e_2 * CC[2+bs*1];
	CC[3+bs*2] -= e_2 * CC[2+bs*2];
	CC[3+bs*3] -= e_2 * CC[2+bs*3];

	store:

	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nn_ru_inv_4x4_lib4(int kmax, double *A, double *B, int sdb, double *C, double *D, double *E, double *inv_diag_E)
	{

	const int bs = 4;

	int k;

	double
		tmp,
		e_00, e_01, e_02, e_03,
		      e_11, e_12, e_13,
			        e_22, e_23,
					      e_33;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif
	
	double alpha1 = -1.0;
	double beta1  = 1.0;

	kernel_dgemm_nn_4x4_lib4(kmax, &alpha1, A, 0, B, sdb, &beta1, C, CC);

	// solve

	e_00 = inv_diag_E[0];
	CC[0+bs*0] *= e_00;
	CC[1+bs*0] *= e_00;
	CC[2+bs*0] *= e_00;
	CC[3+bs*0] *= e_00;

	e_01 = E[0+bs*1];
	e_11 = inv_diag_E[1];
	CC[0+bs*1] -= CC[0+bs*0] * e_01;
	CC[1+bs*1] -= CC[1+bs*0] * e_01;
	CC[2+bs*1] -= CC[2+bs*0] * e_01;
	CC[3+bs*1] -= CC[3+bs*0] * e_01;
	CC[0+bs*1] *= e_11;
	CC[1+bs*1] *= e_11;
	CC[2+bs*1] *= e_11;
	CC[3+bs*1] *= e_11;

	e_02 = E[0+bs*2];
	e_12 = E[1+bs*2];
	e_22 = inv_diag_E[2];
	CC[0+bs*2] -= CC[0+bs*0] * e_02;
	CC[1+bs*2] -= CC[1+bs*0] * e_02;
	CC[2+bs*2] -= CC[2+bs*0] * e_02;
	CC[3+bs*2] -= CC[3+bs*0] * e_02;
	CC[0+bs*2] -= CC[0+bs*1] * e_12;
	CC[1+bs*2] -= CC[1+bs*1] * e_12;
	CC[2+bs*2] -= CC[2+bs*1] * e_12;
	CC[3+bs*2] -= CC[3+bs*1] * e_12;
	CC[0+bs*2] *= e_22;
	CC[1+bs*2] *= e_22;
	CC[2+bs*2] *= e_22;
	CC[3+bs*2] *= e_22;

	e_03 = E[0+bs*3];
	e_13 = E[1+bs*3];
	e_23 = E[2+bs*3];
	e_33 = inv_diag_E[3];
	CC[0+bs*3] -= CC[0+bs*0] * e_03;
	CC[1+bs*3] -= CC[1+bs*0] * e_03;
	CC[2+bs*3] -= CC[2+bs*0] * e_03;
	CC[3+bs*3] -= CC[3+bs*0] * e_03;
	CC[0+bs*3] -= CC[0+bs*1] * e_13;
	CC[1+bs*3] -= CC[1+bs*1] * e_13;
	CC[2+bs*3] -= CC[2+bs*1] * e_13;
	CC[3+bs*3] -= CC[3+bs*1] * e_13;
	CC[0+bs*3] -= CC[0+bs*2] * e_23;
	CC[1+bs*3] -= CC[1+bs*2] * e_23;
	CC[2+bs*3] -= CC[2+bs*2] * e_23;
	CC[3+bs*3] -= CC[3+bs*2] * e_23;
	CC[0+bs*3] *= e_33;
	CC[1+bs*3] *= e_33;
	CC[2+bs*3] *= e_33;
	CC[3+bs*3] *= e_33;

	D[0+bs*0] = CC[0+bs*0];
	D[1+bs*0] = CC[1+bs*0];
	D[2+bs*0] = CC[2+bs*0];
	D[3+bs*0] = CC[3+bs*0];

	D[0+bs*1] = CC[0+bs*1];
	D[1+bs*1] = CC[1+bs*1];
	D[2+bs*1] = CC[2+bs*1];
	D[3+bs*1] = CC[3+bs*1];

	D[0+bs*2] = CC[0+bs*2];
	D[1+bs*2] = CC[1+bs*2];
	D[2+bs*2] = CC[2+bs*2];
	D[3+bs*2] = CC[3+bs*2];

	D[0+bs*3] = CC[0+bs*3];
	D[1+bs*3] = CC[1+bs*3];
	D[2+bs*3] = CC[2+bs*3];
	D[3+bs*3] = CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nn_ru_inv_4x4_vs_lib4(int kmax, double *A, double *B, int sdb, double *C, double *D, double *E, double *inv_diag_E, int km, int kn)
	{

	const int bs = 4;

	int k;

	double
		tmp,
		e_00, e_01, e_02, e_03,
		      e_11, e_12, e_13,
			        e_22, e_23,
					      e_33;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif
	
	double alpha1 = -1.0;
	double beta1  = 1.0;

	kernel_dgemm_nn_4x4_lib4(kmax, &alpha1, A, 0, B, sdb, &beta1, C, CC);

	// solve

	e_00 = inv_diag_E[0];
	CC[0+bs*0] *= e_00;
	CC[1+bs*0] *= e_00;
	CC[2+bs*0] *= e_00;
	CC[3+bs*0] *= e_00;

	if(kn==1)
		goto store;
	
	e_01 = E[0+bs*1];
	e_11 = inv_diag_E[1];
	CC[0+bs*1] -= CC[0+bs*0] * e_01;
	CC[1+bs*1] -= CC[1+bs*0] * e_01;
	CC[2+bs*1] -= CC[2+bs*0] * e_01;
	CC[3+bs*1] -= CC[3+bs*0] * e_01;
	CC[0+bs*1] *= e_11;
	CC[1+bs*1] *= e_11;
	CC[2+bs*1] *= e_11;
	CC[3+bs*1] *= e_11;

	if(kn==2)
		goto store;
	
	e_02 = E[0+bs*2];
	e_12 = E[1+bs*2];
	e_22 = inv_diag_E[2];
	CC[0+bs*2] -= CC[0+bs*0] * e_02;
	CC[1+bs*2] -= CC[1+bs*0] * e_02;
	CC[2+bs*2] -= CC[2+bs*0] * e_02;
	CC[3+bs*2] -= CC[3+bs*0] * e_02;
	CC[0+bs*2] -= CC[0+bs*1] * e_12;
	CC[1+bs*2] -= CC[1+bs*1] * e_12;
	CC[2+bs*2] -= CC[2+bs*1] * e_12;
	CC[3+bs*2] -= CC[3+bs*1] * e_12;
	CC[0+bs*2] *= e_22;
	CC[1+bs*2] *= e_22;
	CC[2+bs*2] *= e_22;
	CC[3+bs*2] *= e_22;

	if(kn==3)
		goto store;
	
	e_03 = E[0+bs*3];
	e_13 = E[1+bs*3];
	e_23 = E[2+bs*3];
	e_33 = inv_diag_E[3];
	CC[0+bs*3] -= CC[0+bs*0] * e_03;
	CC[1+bs*3] -= CC[1+bs*0] * e_03;
	CC[2+bs*3] -= CC[2+bs*0] * e_03;
	CC[3+bs*3] -= CC[3+bs*0] * e_03;
	CC[0+bs*3] -= CC[0+bs*1] * e_13;
	CC[1+bs*3] -= CC[1+bs*1] * e_13;
	CC[2+bs*3] -= CC[2+bs*1] * e_13;
	CC[3+bs*3] -= CC[3+bs*1] * e_13;
	CC[0+bs*3] -= CC[0+bs*2] * e_23;
	CC[1+bs*3] -= CC[1+bs*2] * e_23;
	CC[2+bs*3] -= CC[2+bs*2] * e_23;
	CC[3+bs*3] -= CC[3+bs*2] * e_23;
	CC[0+bs*3] *= e_33;
	CC[1+bs*3] *= e_33;
	CC[2+bs*3] *= e_33;
	CC[3+bs*3] *= e_33;

	store:

	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nn_lu_inv_4x4_lib4(int kmax, double *A, double *B, int sdb, double *C, double *D, double *E, double *inv_diag_E)
	{

	const int bs = 4;

	int k;

	double
		tmp,
		a_0, a_1, a_2, a_3,
		b_0, b_1, b_2, b_3,
		e_00, e_01, e_02, e_03,
		      e_11, e_12, e_13,
			        e_22, e_23,
					      e_33;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif
	
	double alpha1 = -1.0;
	double beta1  = 1.0;

	kernel_dgemm_nn_4x4_lib4(kmax, &alpha1, A, 0, B, sdb, &beta1, C, CC);

	// solve

	e_03 = E[0+bs*3];
	e_13 = E[1+bs*3];
	e_23 = E[2+bs*3];
	e_33 = inv_diag_E[3];
	CC[3+bs*0] *= e_33;
	CC[3+bs*1] *= e_33;
	CC[3+bs*2] *= e_33;
	CC[3+bs*3] *= e_33;
	CC[0+bs*0] -= e_03 * CC[3+bs*0];
	CC[0+bs*1] -= e_03 * CC[3+bs*1];
	CC[0+bs*2] -= e_03 * CC[3+bs*2];
	CC[0+bs*3] -= e_03 * CC[3+bs*3];
	CC[1+bs*0] -= e_13 * CC[3+bs*0];
	CC[1+bs*1] -= e_13 * CC[3+bs*1];
	CC[1+bs*2] -= e_13 * CC[3+bs*2];
	CC[1+bs*3] -= e_13 * CC[3+bs*3];
	CC[2+bs*0] -= e_23 * CC[3+bs*0];
	CC[2+bs*1] -= e_23 * CC[3+bs*1];
	CC[2+bs*2] -= e_23 * CC[3+bs*2];
	CC[2+bs*3] -= e_23 * CC[3+bs*3];

	e_02 = E[0+bs*2];
	e_12 = E[1+bs*2];
	e_22 = inv_diag_E[2];
	CC[2+bs*0] *= e_22;
	CC[2+bs*1] *= e_22;
	CC[2+bs*2] *= e_22;
	CC[2+bs*3] *= e_22;
	CC[0+bs*0] -= e_02 * CC[2+bs*0];
	CC[0+bs*1] -= e_02 * CC[2+bs*1];
	CC[0+bs*2] -= e_02 * CC[2+bs*2];
	CC[0+bs*3] -= e_02 * CC[2+bs*3];
	CC[1+bs*0] -= e_12 * CC[2+bs*0];
	CC[1+bs*1] -= e_12 * CC[2+bs*1];
	CC[1+bs*2] -= e_12 * CC[2+bs*2];
	CC[1+bs*3] -= e_12 * CC[2+bs*3];

	e_01 = E[0+bs*1];
	e_11 = inv_diag_E[1];
	CC[1+bs*0] *= e_11;
	CC[1+bs*1] *= e_11;
	CC[1+bs*2] *= e_11;
	CC[1+bs*3] *= e_11;
	CC[0+bs*0] -= e_01 * CC[1+bs*0];
	CC[0+bs*1] -= e_01 * CC[1+bs*1];
	CC[0+bs*2] -= e_01 * CC[1+bs*2];
	CC[0+bs*3] -= e_01 * CC[1+bs*3];

	e_00 = inv_diag_E[0];
	CC[0+bs*0] *= e_00;
	CC[0+bs*1] *= e_00;
	CC[0+bs*2] *= e_00;
	CC[0+bs*3] *= e_00;

	D[0+bs*0] = CC[0+bs*0];
	D[1+bs*0] = CC[1+bs*0];
	D[2+bs*0] = CC[2+bs*0];
	D[3+bs*0] = CC[3+bs*0];

	D[0+bs*1] = CC[0+bs*1];
	D[1+bs*1] = CC[1+bs*1];
	D[2+bs*1] = CC[2+bs*1];
	D[3+bs*1] = CC[3+bs*1];

	D[0+bs*2] = CC[0+bs*2];
	D[1+bs*2] = CC[1+bs*2];
	D[2+bs*2] = CC[2+bs*2];
	D[3+bs*2] = CC[3+bs*2];

	D[0+bs*3] = CC[0+bs*3];
	D[1+bs*3] = CC[1+bs*3];
	D[2+bs*3] = CC[2+bs*3];
	D[3+bs*3] = CC[3+bs*3];

	return;

	}
#endif



#if defined(TARGET_GENERIC) || defined(TARGET_X86_AMD_BARCELONA) || defined(TARGET_X86_AMD_JAGUAR) || defined(TARGET_X64_INTEL_CORE) || defined(TARGET_X64_AMD_BULLDOZER) || defined(TARGET_ARMV7A_ARM_CORTEX_A15) || defined(TARGET_ARMV7A_ARM_CORTEX_A7) || defined(TARGET_ARMV8A_ARM_CORTEX_A57) || defined(TARGET_ARMV8A_ARM_CORTEX_A53)
void kernel_dtrsm_nn_lu_inv_4x4_vs_lib4(int kmax, double *A, double *B, int sdb, double *C, double *D, double *E, double *inv_diag_E, int km, int kn)
	{

	const int bs = 4;

	int k;

	double
		tmp,
		a_0, a_1, a_2, a_3,
		b_0, b_1, b_2, b_3,
		e_00, e_01, e_02, e_03,
		      e_11, e_12, e_13,
			        e_22, e_23,
					      e_33;

#if defined(TARGET_GENERIC)
	double CC[16] = {0};
#else
#if defined (_MSC_VER)
	double CC[16] __declspec(align(64)) = {0};
#else
	double CC[16] __attribute__ ((aligned (64))) = {0};
#endif
#endif
	
	double alpha1 = -1.0;
	double beta1  = 1.0;

	kernel_dgemm_nn_4x4_lib4(kmax, &alpha1, A, 0, B, sdb, &beta1, C, CC);

	// solve

	if(km>3)
		{
		e_03 = E[0+bs*3];
		e_13 = E[1+bs*3];
		e_23 = E[2+bs*3];
		e_33 = inv_diag_E[3];
		CC[3+bs*0] *= e_33;
		CC[3+bs*1] *= e_33;
		CC[3+bs*2] *= e_33;
		CC[3+bs*3] *= e_33;
		CC[0+bs*0] -= e_03 * CC[3+bs*0];
		CC[0+bs*1] -= e_03 * CC[3+bs*1];
		CC[0+bs*2] -= e_03 * CC[3+bs*2];
		CC[0+bs*3] -= e_03 * CC[3+bs*3];
		CC[1+bs*0] -= e_13 * CC[3+bs*0];
		CC[1+bs*1] -= e_13 * CC[3+bs*1];
		CC[1+bs*2] -= e_13 * CC[3+bs*2];
		CC[1+bs*3] -= e_13 * CC[3+bs*3];
		CC[2+bs*0] -= e_23 * CC[3+bs*0];
		CC[2+bs*1] -= e_23 * CC[3+bs*1];
		CC[2+bs*2] -= e_23 * CC[3+bs*2];
		CC[2+bs*3] -= e_23 * CC[3+bs*3];
		}
	
	if(km>2)
		{
		e_02 = E[0+bs*2];
		e_12 = E[1+bs*2];
		e_22 = inv_diag_E[2];
		CC[2+bs*0] *= e_22;
		CC[2+bs*1] *= e_22;
		CC[2+bs*2] *= e_22;
		CC[2+bs*3] *= e_22;
		CC[0+bs*0] -= e_02 * CC[2+bs*0];
		CC[0+bs*1] -= e_02 * CC[2+bs*1];
		CC[0+bs*2] -= e_02 * CC[2+bs*2];
		CC[0+bs*3] -= e_02 * CC[2+bs*3];
		CC[1+bs*0] -= e_12 * CC[2+bs*0];
		CC[1+bs*1] -= e_12 * CC[2+bs*1];
		CC[1+bs*2] -= e_12 * CC[2+bs*2];
		CC[1+bs*3] -= e_12 * CC[2+bs*3];
		}
	
	if(km>1)
		{
		e_01 = E[0+bs*1];
		e_11 = inv_diag_E[1];
		CC[1+bs*0] *= e_11;
		CC[1+bs*1] *= e_11;
		CC[1+bs*2] *= e_11;
		CC[1+bs*3] *= e_11;
		CC[0+bs*0] -= e_01 * CC[1+bs*0];
		CC[0+bs*1] -= e_01 * CC[1+bs*1];
		CC[0+bs*2] -= e_01 * CC[1+bs*2];
		CC[0+bs*3] -= e_01 * CC[1+bs*3];
		}
	
	e_00 = inv_diag_E[0];
	CC[0+bs*0] *= e_00;
	CC[0+bs*1] *= e_00;
	CC[0+bs*2] *= e_00;
	CC[0+bs*3] *= e_00;

	store:

	if(km>=4)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];
		D[3+bs*0] = CC[3+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];
		D[3+bs*1] = CC[3+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];
		D[3+bs*2] = CC[3+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		D[3+bs*3] = CC[3+bs*3];
		}
	else if(km>=3)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];
		D[2+bs*0] = CC[2+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];
		D[2+bs*1] = CC[2+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];
		D[2+bs*2] = CC[2+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		D[2+bs*3] = CC[2+bs*3];
		}
	else if(km>=2)
		{
		D[0+bs*0] = CC[0+bs*0];
		D[1+bs*0] = CC[1+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];
		D[1+bs*1] = CC[1+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];
		D[1+bs*2] = CC[1+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		D[1+bs*3] = CC[1+bs*3];
		}
	else //if(km>=1)
		{
		D[0+bs*0] = CC[0+bs*0];

		if(kn==1)
			return;

		D[0+bs*1] = CC[0+bs*1];

		if(kn==2)
			return;

		D[0+bs*2] = CC[0+bs*2];

		if(kn==3)
			return;

		D[0+bs*3] = CC[0+bs*3];
		}

	return;

	}
#endif





#if defined(BLAS_API)

#include "kernel_dgemm_4x4_lib.c"

#endif


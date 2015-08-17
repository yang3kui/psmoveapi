/**
* PS Move API - An interface for the PS Move Motion Controller
* Copyright (c) 2011, 2012 Thomas Perl <m@thp.io>
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*    1. Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*
*    2. Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
**/

/* General math utility functions */
#ifndef __PSMOVE_MATH_H
#define __PSMOVE_MATH_H

//-- includes -----
#include <float.h>
#include <math.h>

#include "psmove_platform_config.h"

//-- constants ----
#define k_real_max FLT_MAX
#define k_real_min FLT_MIN

#define k_positional_epsilon 0.001f
#define k_normal_epsilon 0.0001f
#define k_real_epsilon FLT_EPSILON

#define k_real_pi (float)M_PI
#define k_real_two_pi 2.f*k_real_pi
#define k_real_half_pi 0.5f*k_real_pi

//-- macros ----
#define is_valid_float(x) (!isnan(x) && isfinite(x))
#define is_nearly_equal(a, b, epsilon) (fabsf(a-b) <= epsilon)
#define is_nearly_zero(x) is_nearly_equal(x, 0.0f, k_real_epsilon)

#define safe_divide_with_default(numerator, denomenator, default_result) (is_nearly_zero(denomenator) ? (default_result) : (numerator / denomenator));

#ifndef sgn
#define sgn(x) (((x) >= 0) ? 1 : -1)
#endif

#ifndef sqr
#define sqr(x) (x*x)
#endif

#ifdef NDEBUG
#define assert_valid_float(x) assert(is_valid_float(x))
#else
#define assert_valid_float(x)     ((void)0)
#endif

//-- inline -----
__INLINE__ float clampf(float x, float lo, float hi)
{
	return fminf(fmaxf(x, lo), hi);
}

__INLINE__ float clampf01(float x)
{
	return clampf(x, 0.f, 1.f);
}

__INLINE__ float lerpf(float a, float b, float u)
{
	return a*(1.f - u) + b*u;
}

__INLINE__ float lerp_clampf(float a, float b, float u)
{
	return clampf(lerpf(a, b, u), a, b);
}

__INLINE__ float degrees_to_radians(float x)
{
	return ((x * k_real_pi) / 180.f);
}

__INLINE__ float radians_to_degrees(float x)
{
	return ((x * 180.f) / k_real_pi);
}

#endif // __PSMOVE_MATH_H
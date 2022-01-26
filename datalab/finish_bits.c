/* 
 * CS:APP Data Lab 
 * 
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
  int even_byte = 0x55;		//even_byte: 0101 0101
  int even_word = (even_byte << 8) | even_byte;		//even_word: 0101 0101 0101 0101
  int even_dword = (even_word << 16) | even_word;
  return even_dword;
}
/* 
 * isEqual - return 1 if x == y, and 0 otherwise 
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
  return !(x ^ y);
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {		//based on relation: x^x^y=y
  int _byte = 0xff;
  int nmul8 = n << 3, mmul8 = m << 3;		//number of shifting
  int mix = ((x >> nmul8) ^ (x >> mmul8)) & _byte;	//the value equals nth_byte^mth_byte
  							//&_byte in order to put higher 28 bits "0"
  return x ^ (mix << nmul8) ^ (mix << mmul8);	//use mix to change the nth byte and mth byte of x
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
  int x_lshift, x_rshift;
  int _bias = 32 + (~n) + 1;		//the value equals 32-n
  int high_n_0s = ~0 + (1 << _bias);	//0001...1111 including n "0"
  x_lshift = x << _bias;		//shift lower n bits to the highest
  x_rshift = (x >> n) & high_n_0s;		//shifting x
  return x_lshift | x_rshift;
}
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int x_unequ_negx = (~x + 1) | x;	//the highest value is 0 only when x=0, else 1
  return (x_unequ_negx >> 31) + 1;	//return 0+1 only when both value above are 0
  						//else return 0xffffffff+1=0
}
/* 
 * TMax - return maximum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
  return ~(1 << 31);
}
/* 
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
  int x_is_zero = !x;			//the value is 1 when x=0 and 0 when x!=0
  int x_isnot_zero = !x_is_zero;
  return x_isnot_zero | (x >> 31);
}
/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  //printf("x=%x, y=%x\n", x, y);
  int inv_x = ~x;
  int y_sub_x = y + (inv_x + 1);	//the highest bit is 1 only when x > y
  int xpos_yneg = inv_x & y;		//the highest bit is 1 only when x>=0 and y<0
  //printf("xpos_yneg = %x\n", xpos_yneg);
  int xy_samesign = ~(x ^ y);		//the highest bit is 1 only when sign of x same as y
  //printf("xy_samesign=%x, y_sub_x_sign=%x\n", xy_samesign, y_sub_x_sign);
  //printf("ret=%x\n", xy_samesign & y_sub_x_sign | xpos_yneg);
  int samesign_greater = xy_samesign & y_sub_x;
  return (samesign_greater | xpos_yneg) >> 31 & 1;	//return 1 when two cases happen
}
/* 
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) {
  int diff = x + ~y + 1;
  return !(((x ^ y) & (x ^ diff)) >> 31);	//not ok when sign of x is not same as neither y nor diff
  				//regardless when y=0: always ok
}
/*
 * satAdd - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: satAdd(0x40000000,0x40000000) = 0x7fffffff
 *             satAdd(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int satAdd(int x, int y) {
  //printf("x=%x, y=%x\n", x, y);
  int sum = x + y;
  int highest_1 = 1 << 31;
  int overflow = ((x ^ sum) & (y ^ sum)) >> 31;  //0xffffffff when overflow, else 0
  //printf("overflow=%x\n", overflow);
  int overflow_sign = ~((x >> 31) + highest_1);		//if overflow, set the return value according to the sign of x
  //printf("overflow_sign=%x\n", overflow_sign);
  return (overflow & overflow_sign) | (~overflow & sum);    //return two different values depending on whether overflowed
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  //int _0_or_minus1 = !x | !(~x);	//the value is 1 when x=0 or x=-1, else 0
  int _16bits, _8bits, _4bits, _2bits, _1bit, _0bit, bits;
  x = (x >> 31) ^ x;	//the value is x when x>=0 and ~x when x<=0
  			//when x<0, the bits required to represent x are the same as ~x
  _16bits = !(!(x >> 16)) << 4;	//the value is 16 if the highest "1" is above the 15th digit, else 0
  x = x >> _16bits;			//if the value above isn't 0, shift_right for 16 bits and deal with the rest
  _8bits = !(!(x >> 8)) << 3;	//the value is 8 if the highest "1" is above the 7th digit, else 0
  x = x >> _8bits;
  _4bits = !(!(x >> 4)) << 2;
  x = x >> _4bits;
  _2bits = !(!(x >> 2)) << 1;
  x = x >> _2bits;
  _1bit = x >> 1;		//original code: _1bit=!(!(x>>1)); but here x>>1 is 0 or 1
  x = x >> _1bit;
  _0bit = x;			//the last digit: 0 or 1
  bits = _16bits + _8bits + _4bits + _2bits + _1bit + _0bit + 1;
  return bits;			//"+1" represents the figit of sign. when x=0 or x=1, it is the only bit needed
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x){			//use binary-search to locate the highest "1"
  int _16bits, _8bits, _4bits, _2bits, _1bit;
  _16bits = !(!(x >> 16)) << 4;	//the value is 16 if the highest "1" is above the 15th digit, else 0
  x = x >> _16bits;			//if the value above isn't 0, shift_right for 16 bits and deal with the rest
  _8bits = !(!(x >> 8)) << 3;	//the value is 8 if the highest "1" is above the 7th digit, else 0
  x = x >> _8bits;
  _4bits = !(!(x >> 4)) << 2;
  x = x >> _4bits;
  _2bits = !(!(x >> 2)) << 1;
  x = x >> _2bits;
  _1bit = x >> 1;		//original code: _1bit=x>>1; but here x>>1 is 0 or 1
  return _16bits + _8bits + _4bits + _2bits + _1bit;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  int end_with_11 = (uf & 3) == 3; //the value is 1 only when last two digits are both 1
  if (!(uf & 0x7f000000)) {	//exponent=0 or 1: both shift_right the significand directly
     uf = (uf & 0xff000000) | (((uf & 0xffffff) >> 1) + end_with_11);	
     				//extract higher 8bits and shift the rest. if sig ends with 11, add 1 for rounding
  } else if ((uf & 0x7f800000) != 0x7f800000) {		//normalized number, exponent-1
     uf = uf - 0x800000;
  }		//else exponent is 0xff, uf=nan or uf=inf, return uf
  return uf;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
  int ret = 0;
  int exp = (uf & 0x7f800000) >> 23;	//extract the exponent
  int sig_after_dot = uf & 0x7fffff;	//significand without the omitted "1" before dot
  int sig = sig_after_dot | 0x800000;	//extract the significand. regardless of unnormalized number here
					//because later it will be identified as too small
  exp = exp - 150;			//exp - 127 - 23 = exp - 150
  //printf("uf=%x, exp=%x, sig=%x\n", uf, exp, sig);
  if (exp > 7) {			//out of range
    ret = 0x80000000;
  } else if(exp >= 0) {			//left shift without overflow
    ret = sig << exp;
  } else if(exp >= 0xffffffe8) {	//0xffffffe8=-24. right shift in this case
    //printf("sig=%x, exp=-%x\n", sig, ~exp+1);
    ret = sig >> (-exp);
  }					//else: too small, ret = 0
  if (uf >> 31) {			//deal with the sign
    ret = -ret;
  }
  return ret;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  //printf("uf=%x\n", uf);
  int exp = uf & 0x7f800000;
  if (!exp) {			//exponent is 0, left_shift the significand directly
    //printf("exponent = 0\n");
    uf = (uf & 0xff800000) | ((uf & 0x7fffff) << 1);	//extract the higher 9bits and shift the rest
  } else if (exp != 0x7f800000) {		//normalized number, exponent+1
     uf = uf + 0x800000;
  }		//else exponent is 0xff, uf=nan or uf=inf, return uf
  return uf;
}

---
description: "Learn more about: Why Floating-Point Numbers May Lose Precision"
title: "Why Floating-Point Numbers May Lose Precision"
ms.date: "11/04/2016"
helpviewer_keywords: ["DBL_EPSILON constant", "FLT_EPSILON constant", "floating-point numbers, precision"]
ms.assetid: 1acb1add-ac06-4134-a2fd-aff13d8c4c15
---
# Why Floating-Point Numbers May Lose Precision

Floating-point decimal values generally do not have an exact binary representation. This is a side effect of how the CPU represents floating point data. For this reason, you may experience some loss of precision, and some floating-point operations may produce unexpected results.

This behavior is the result of one of the following:

- The binary representation of the decimal number may not be exact.

- There is a type mismatch between the numbers used (for example, mixing float and double).

To resolve the behavior, most programmers either ensure that the value is greater or less than what is needed, or they get and use a Binary Coded Decimal (BCD) library that will maintain the precision.

Binary representation of floating-point values affects the precision and accuracy of floating-point calculations. Microsoft Visual C++ uses IEEE floating-point format.

## Example

```c
// Floating-point_number_precision.c
// Compile options needed: none. Value of c is printed with a decimal
// point precision of 10 and 6 (printf rounded value by default) to
// show the difference
#include <stdio.h>

#define EPSILON 0.0001   // Define your own tolerance
#define FLOAT_EQ(x,v) (((v - EPSILON) < x) && (x <( v + EPSILON)))

int main() {
   float a, b, c;

   a = 1.345f;
   b = 1.123f;
   c = a + b;
   // if (FLOAT_EQ(c, 2.468)) // Remove comment for correct result
   if (c == 2.468)            // Comment this line for correct result
      printf_s("They are equal.\n");
   else
      printf_s("They are not equal! The value of c is %13.10f "
                "or %f",c,c);
}
```

```Output
They are not equal! The value of c is  2.4679999352 or 2.468000
```

## Comments

For EPSILON, you can use the constants FLT_EPSILON, which is defined for float as 1.192092896e-07F, or DBL_EPSILON, which is defined for double as 2.2204460492503131e-016. You need to include float.h for these constants. These constants are defined as the smallest positive number x, such that x+1.0 is not equal to 1.0. Because this is a very small number, you should employ user-defined tolerance for calculations involving very large numbers.


...

---
# IEEE Floating-Point Representation

Microsoft C++ (MSVC) is consistent with the IEEE numeric standards. The IEEE-754 standard describes floating-point formats, a way to represent real numbers in hardware. There are at least five internal formats for floating-point numbers that are representable in hardware targeted by the MSVC compiler. The compiler only uses two of them. The *single-precision* (4-byte) and *double-precision* (8-byte) formats are used in MSVC. Single-precision is declared using the keyword **`float`**. Double-precision is declared using the keyword **`double`**. The IEEE standard also specifies *half-precision* (2-byte) and *quadruple-precision* (16-byte) formats, and a *double-extended-precision* (10-byte) format, which some C and C++ compilers implement as the **`long double`** data type. In the MSVC compiler, the **`long double`** data type is treated as a distinct type, but the storage type maps to **`double`**. There is, however, intrinsic and assembly language support for computations using the other formats, including the double-extended-precision format, where supported by hardware.

The values are stored as follows:

|Value|Stored as|
|-----------|---------------|
|single-precision|sign bit, 8-bit exponent, 23-bit significand|
|double-precision|sign bit, 11-bit exponent, 52-bit significand|

In single-precision and double-precision formats, there's an assumed leading 1 in the fractional part. The fractional part is called the *significand* (sometimes known as the *mantissa*). This leading 1 isn't stored in memory, so the significands are actually 24 or 53 bits, even though one less bit gets stored. The double-extended-precision format actually stores this bit.

The exponents are biased by half of their possible value. It means you subtract this bias from the stored exponent to get the actual exponent. If the stored exponent is less than the bias, it's actually a negative exponent.

The exponents are biased as follows:

|Exponent|Biased by|
|--------------|---------------|
|8-bit (single-precision)|127|
|11-bit (double-precision)|1023|

These exponents aren't powers of ten; they're powers of two. That is, 8-bit stored exponents can range from -127 to 127, stored as 0 to 254. The value 2<sup>127</sup> is roughly equivalent to 10<sup>38</sup>, which is the actual limit of single-precision.

The significand is stored as a binary fraction of the form 1.XXX... . This fraction has a value greater than or equal to 1 and less than 2. Real numbers are always stored in *normalized form*. That is, the significand is left-shifted such that the high-order bit of the significand is always 1. Because this bit is *always* 1, it's assumed (not stored) in the single-precision and double-precision formats. The binary (not decimal) point is assumed to be just to the right of the leading 1.

The format for floating-point representation is as follows:

|Format|byte 1|byte 2|byte 3|byte 4|...|byte n|
|------------|------------|------------|------------|------------|---------|------------|
|single-precision| `SXXXXXXX`|`XMMMMMMM`|`MMMMMMMM`|`MMMMMMMM`|||
|double-precision|`SXXXXXXX`|`XXXXMMMM`|`MMMMMMMM`|`MMMMMMMM`|...|`MMMMMMMM`|

`S` represents the sign bit, the `X`'s are the biased exponent bits, and the `M`'s are the significand bits. The leftmost bit is assumed in single-precision and double-precision formats.

To shift the binary point properly, you first unbias the exponent and then move the binary point to the right or left the appropriate number of bits.

## Special values

The floating-point formats include some values that are treated specially.

### Zero

Zero can't be normalized, which makes it unrepresentable in the normalized form of a single-precision or double-precision value. A special bit pattern of all zeroes represents 0. It's also possible to represent -0 as zero with the sign bit set, but -0 and 0 always compare as equal.

### Infinities

The +∞ and −∞ values are represented by an exponent of all ones, and a significand that's all zeroes. Positive and negative are represented by using the sign bit.

### Subnormals

It's possible to represent numbers of smaller magnitude than the smallest number in normalized form. They're called *subnormal* or *denormal* numbers. If the exponent is all zeroes and the significand is non-zero, then implicit leading bit of the significand is considered to be zero, not one. The precision of subnormal numbers goes down as the number of leading zeroes in the significand goes up.

### NaN - Not a Number

It's possible to represent values that aren't real numbers, such as 0 / 0, in the IEEE floating-point format. A value of this kind is called a *NaN*. A NaN is represented by an exponent of all ones and a non-zero significand. There are two kinds of NaNs, *quiet* NaNs, or QNaNs, and *signaling* NaNs, or SNaNs. Quiet NaNs have a leading one in the significand, and get propagated through an expression. They represent an indeterminate value, such as the result of dividing by infinity, or multiplying an infinity by zero. Signaling NaNs have a leading zero in the significand. They're used for operations that aren't valid, to signal a floating-point hardware exception.

## Examples

The following are some examples in single-precision format:

- For the value 2, the sign bit is zero. The stored exponent is 128, or 1000 0000 in binary, which is 127 plus 1. The stored binary significand is (1.) 000 0000 0000 0000 0000 0000, which has an implied leading 1 and binary point, so the actual significand is one.

   |Value|Formula|Binary representation|Hexadecimal|
   |-|-|-|-|
   |2|1 * 2<sup>1</sup>|0100 0000 0000 0000 0000 0000 0000 0000|0x40000000|

- The value -2. Same as +2 except that the sign bit is set. The same thing is true for the negative of all IEEE format floating-point numbers.

   |Value|Formula|Binary representation|Hexadecimal|
   |-|-|-|-|
   |-2|-1 * 2<sup>1</sup>|1100 0000 0000 0000 0000 0000 0000 0000|0xC0000000|

- The value 4. Same significand, exponent increases by one (biased value is 129, or 100 0000 1 in binary.

   |Value|Formula|Binary representation|Hexadecimal|
   |-|-|-|-|
   |4|1 * 2<sup>2</sup>|0100 0000 1000 0000 0000 0000 0000 0000|0x40800000|

- The value 6. Same exponent, significand is larger by half. It's (1.) 100 0000 ... 0000 0000, which, since it's a binary fraction, is 1 1/2 because the values of the fractional digits are 1/2, 1/4, 1/8, and so forth.

   |Value|Formula|Binary representation|Hexadecimal|
   |-|-|-|-|
   |6|1.5 * 2<sup>2</sup>|0100 0000 1100 0000 0000 0000 0000 0000|0x40C00000|

- The value 1. Same significand as other powers of two, the biased exponent is one less than two at 127, or 011 1111 1 in binary.

   |Value|Formula|Binary representation|Hexadecimal|
   |-|-|-|-|
   |1|1 * 2<sup>0</sup>|0011 1111 1000 0000 0000 0000 0000 0000|0x3F800000|

- The value 0.75. The biased exponent is 126, 011 1111 0 in binary, and the significand is (1.) 100 0000 ... 0000 0000, which is 1 1/2.

   |Value|Formula|Binary representation|Hexadecimal|
   |-|-|-|-|
   |0.75|1.5 * 2<sup>-1</sup>|0011 1111 0100 0000 0000 0000 0000 0000|0x3F400000|

- The value 2.5. Exactly the same as two except that the bit that represents 1/4 is set in the significand.

   |Value|Formula|Binary representation|Hexadecimal|
   |-|-|-|-|
   |2.5|1.25 * 2<sup>1</sup>|0100 0000 0010 0000 0000 0000 0000 0000|0x40200000|

- 1/10 is a repeating fraction in binary. The significand is a little less than 1.6, and the biased exponent says that 1.6 is to be divided by 16. (It's 011 1101 1 in binary, which is 123 in decimal.) The true exponent is 123 - 127 = -4, which means that the factor by which to multiply is 2<sup>-4</sup> = 1/16. The stored significand is rounded up in the last bit in an attempt to represent the unrepresentable number as accurately as possible. (The reason that 1/10 and 1/100 aren't exactly representable in binary is similar to the reason that 1/3 isn't exactly representable in decimal.)

   |Value|Formula|Binary representation|Hexadecimal|
   |-|-|-|-|
   |0.1|1.6 * 2<sup>-4</sup>|0011 1101 1100 1100 1100 1100 1100 1101|0x3DCCCCCD|

- Zero is a special case. It uses the formula for the minimum possible representable positive value, which is all zeroes.

   |Value|Formula|Binary representation|Hexadecimal|
   |-|-|-|-|
   |0|1 * 2<sup>-128</sup>|0000 0000 0000 0000 0000 0000 0000 0000|0x00000000|



# Optimizing your code

By optimizing an executable, you can achieve a balance between fast execution speed and small code size. This topic discusses some of the mechanisms that Visual Studio provides to help you optimize code.

### The optimize pragma

If an optimized section of code causes errors or a slowdown, you can use the optimize pragma to turn off optimization for that section.

Enclose the code between two pragmas, as shown here:

```cpp
#pragma optimize("", off)
// some code here
#pragma optimize("", on)
```

## Programming practices

You might notice additional warning messages when you compile your code with optimization. This behavior is expected because some warnings relate only to optimized code. You can avoid many optimization problems if you heed these warnings.

Paradoxically, optimizing a program for speed could cause code to run slower. This is because some optimizations for speed increase code size. For example, inlining functions eliminates the overhead of function calls. However, inlining too much code might make your program so large that the number of virtual-memory page faults increases. Therefore, the speed gained from eliminating function calls may be lost to memory swapping.

The following topics discuss good programming practices.
## See also

[Optimizing your code](https://github.com/MicrosoftDocs/cpp-docs/blob/main/docs/build/optimizing-your-code.md)


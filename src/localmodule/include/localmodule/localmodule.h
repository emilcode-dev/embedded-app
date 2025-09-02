#ifndef LOCALMODULE_H
#define LOCALMODULE_H

#include <stdint.h>

/**
 * @brief Subtracts two 32-bit integers.
 *
 * @param a Minuend integer.
 * @param b Subtrahend integer.
 * @return Result of a - b.
 */
int32_t localmod_subinteger(int32_t a, int32_t b);

#endif // LOCALMODULE_H
/*
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org>
 */

#include <limits.h>
#include <string.h>

#include "ush/reader.h"

#define BUFFER_SIZE ARG_MAX

static char buffer[BUFFER_SIZE];
static uint16_t pos = 0;
static uint16_t len = 0;

char *ush_rdlocate(void) {
  return buffer + pos;
}

int8_t ush_rdgetch(char *ch) {
	ssize_t rd;

	if (pos >= len) {
    if ((rd = read(STDIN_FILENO, buffer, BUFFER_SIZE)) < 0)
			return (int8_t)rd;
		len = (uint16_t)rd;
    pos = 0;
		return ush_rdgetch(ch);
	}
	*ch = buffer[pos++];
  return 0;
}

void ush_rdreset(void) {
  memmove(buffer, buffer + pos, len - pos);
  pos = 0;
  len -= pos;
}

int16_t ush_rdfill(void) {
  ssize_t rd;

  if (len == BUFFER_SIZE)
    return -1;
  if ((rd = read(STDIN_FILENO, buffer + len, (size_t)(BUFFER_SIZE - len))) < 0)
    return (int8_t)rd;
  len += (uint16_t)rd;
  return (int16_t)rd;
}

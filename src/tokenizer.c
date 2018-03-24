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

#include "ush/tokenizer.h"

int ush_tokenize(tok_t *id, char **word) {
  char ch;
  uint16_t wlen = 0;
  int8_t st;

  *id = TOK_END;
  while (!(st = ush_rdgetch(&ch))) {
    switch (ch) {
      case '\n':
        switch (*id) {
          case TOK_END:
            *id = TOK_EOL;
          default:
            return 0;
        }
      case '0'...'9':
        if (*id != TOK_END && *id != TOK_WORD)
          return -1;
        **word = ch;
        break;
      case '>':
        switch (*id) {
          case TOK_END:
            *id = TOK_ROUT;
            break;
          case TOK_ROUT:
            *id = TOK_RAOUT;
          default:
            return -1;
        }
        break;
      case '|':

      default:
        return -1;
    }
  }
  return st;
}

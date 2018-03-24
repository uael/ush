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

/**
 * @file ush/tokenizer.h
 * @author deltaevo
 * @author uael
 */
#ifndef _USH_TOKENIZER_H
# define _USH_TOKENIZER_H

#include "reader.h"

typedef enum tok {
  TOK_END = '\0',
  TOK_HEREDOC = TOK_END + 1,
  TOK_RAOUT,
  TOK_LAMP,
  TOK_RAMP,
  TOK_CMP,
  TOK_EOL = '\n',
  TOK_PIPEAND = TOK_EOL + 1,
  TOK_AMPR,
  TOK_AMPRA,
  TOK_LAND,
  TOK_LOR,
  TOK_WORD,
  TOK_ASSIGN,
  TOK_FI,
  TOK_DONE,
  TOK_THEN,
  TOK_DO,
  TOK_ELIF,
  TOK_ELSE,
  TOK_IF,
  TOK_WHILE,
  TOK_UNTIL,
  TOK_FOR,
  TOK_IN,
  TOK_FUNCTION,
  TOK_DRBRA,
  TOK_DLBRA,
  TOK_HERENOW,
  TOK_BANG = '!',
  TOK_AMP = '&',
  TOK_LPAR = '(',
  TOK_RPAR = ')',
  TOK_LCUR = '{',
  TOK_RCUR = '}',
  TOK_SEMICOLON = ';',
  TOK_RIN = '<',
  TOK_ROUT = '>',
  TOK_PIPE = '|'
} tok_t;

int ush_tokenize(tok_t *id, char **word);

#endif
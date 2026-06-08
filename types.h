#ifndef TYPES_H
#define TYPES_H

typedef enum {
  TOKEN_INT,
  TOKEN_OP,
  TOKEN_LPAREN,
  TOKEN_RPAREN,
  TOKEN_INVALID
} TokenType;

typedef enum {
  ERR_NONE,
  ERR_MISMATCH_PAREN,
  ERR_INVALID_CHAR,
  ERR_MALFORMED,
  ERR_DIV_ZERO,
  ERR_MEMORY
} ErrorStatus;

typedef struct {
  TokenType type;
  int int_val;
  char op_char;
}  Token;

#endif

#!/usr/bin/env python
#! -*- coding=utf-8 -*-

import os
import sys
import ply.yacc as yacc
from m_lex import MyLexer

mlexer = MyLexer()
tokens = MyLexer.tokens
mlexer.build()
lexer = mlexer.lexer

def p_expression_plus(p):
    'expression : expression PLUS term'
    p[0] = p[1] + p[3]

def p_expression_minus(p):
    'expression : expression MINUS term'
    p[0] = p[1] - p[3]

def p_expression_term(p):
    'expression : term'
    p[0] = p[1]

def p_term_times(p):
    'term : term TIMES factor'
    p[0] = p[1] * p[3]

def p_term_divide(p):
    'term : term DIVIDE factor'
    p[0] = p[1] / p[3]

def p_term_factor(p):
    'term : factor'
    p[0] = p[1]

def p_factor_num(p):
    'factor : NUMBER'
    p[0] = p[1]

def p_factor_expression(p):
    'factor : LPAREN expression RPAREN'
    p[0] = p[2]

def p_error(p):
    print "syntax error in input"


def test_yacc():
    while True:
        try:
            s = raw_input('calc > ')
        except EOFError:
            break
        if not s: continue
        ret = yacc.parse(s)
        print ret


if __name__=='__main__':
    yacc.yacc(debug=1)
    test_yacc()



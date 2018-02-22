#!/usr/bin/env python
#! -*- coding=utf-8 -*-

import os
import sys
#import ply
from ply import lex as lex


class MyLexer:
    tokens = (
                'NUMBER',
                'PLUS',
                'MINUS',
                'TIMES',
                'DIVIDE',
                'LPAREN',
                'RPAREN',
            )

    t_PLUS = r'\+'
    t_MINUS = r'-'
    t_TIMES = r'\*'
    t_DIVIDE = r'/'
    t_LPAREN = r'\('
    t_RPAREN = r'\)'

    t_ignore = ' \t'

    def __init__(self):
        self.num_count = 0

    def t_NUMBER(self, t):
        r'\d+'
        t.value = int(t.value)
        self.num_count += 1
        return t

    def t_newline(self, t):
        r'\n+'
        t.lexer.lineno += 1

    def t_error(self, t):
        print "illegal character %s" % t.value[0]
        t.lexer.skip(1)

    def build(self, **kwargs):
        self.lexer = lex.lex(module=self, **kwargs)

    def test(self, data):
        self.lexer.input(data)
        for tok in self.lexer:
            print tok,tok.lexpos
        print self.num_count

data = '''
 3 * 4 + 5
 + 20 / 5
'''

if __name__=='__main__':
    m = MyLexer()
    m.build(optimize=1, debug=1)
    m.test(data)


#!/usr/bin/env python
#! -*- encodine=utf-8 -*-

import os
import sys
import ply.lex as lex
from m_lex import MyLexer

class MyLexerStates(MyLexer):
    states = (
                #('ccode' ,'exclusive'),
            )
    
    def __init__(self):
        super(MyLexerStates, self).__init__()
        return

        '''
    def t_code(self, t):
        r'\{'
        t.lexer.code_start = t.lexer.lexpos
        t.lexer.level = 1
        t.lexer.begin('ccode')
        '''
    
    def test2(self, data):
        self.test(data)



if __name__=='__main__':
    m = MyLexerStates()
    m.build(debug=1)
    m.test('1+2/3*5')




# lextab.py. This file automatically created by PLY (version 3.11). Don't edit!
_tabversion   = '3.10'
_lextokens    = set(('DIVIDE', 'LPAREN', 'MINUS', 'NUMBER', 'PLUS', 'RPAREN', 'TIMES'))
_lexreflags   = 64
_lexliterals  = ''
_lexstateinfo = {'INITIAL': 'inclusive'}
_lexstatere   = {'INITIAL': [('(?P<t_NUMBER>\\d+)|(?P<t_newline>\\n+)|(?P<t_LPAREN>\\()|(?P<t_RPAREN>\\))|(?P<t_TIMES>\\*)|(?P<t_PLUS>\\+)|(?P<t_DIVIDE>/)|(?P<t_MINUS>-)', [None, ('t_NUMBER', 'NUMBER'), ('t_newline', 'newline'), (None, 'LPAREN'), (None, 'RPAREN'), (None, 'TIMES'), (None, 'PLUS'), (None, 'DIVIDE'), (None, 'MINUS')])]}
_lexstateignore = {'INITIAL': ' \t'}
_lexstateerrorf = {'INITIAL': 't_error'}
_lexstateeoff = {}

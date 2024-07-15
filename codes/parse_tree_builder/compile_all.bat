@echo off 

bison -d parser.y
flex lexer.l
gcc lex.yy.c parser.tab.c -o out.exe

if exist out.exe (
    if exist parse_tree_builder.exe (
        del parse_tree_builder.exe
    )
    ren out.exe parse_tree_builder.exe
    echo Successfully!
)

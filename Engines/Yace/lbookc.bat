rem create a dblearn.bin with Mogens white.pgn and black.pgn
@echo off
echo hash 0 > tmp.inp
echo tbldir nul >> tmp.inp
echo book_f dblearn.bin >> tmp.inp
echo book_c white.pgn 10000 50 1 0 1 >> tmp.inp
echo book_a black.pgn 50 0 1 >> tmp.inp
rem echo book_a start.pgn 100000 %1 >> tmp.inp
echo quit >> tmp.inp
echo Please ignore error message about not found dblearn.bin
yace < tmp.inp
del tmp.inp

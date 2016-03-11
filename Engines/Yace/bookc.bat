@echo off
rem bookc.bat
rem Create custom Yace book
if "%1"=="/h" goto usage
if "%1"=="/?" goto usage
if "%1"=="" goto usage
goto start
:usage
echo Usage:   bookc maxply
echo Example: bookc 30
echo          for creating a 30 ply book out of book.pgn and start.pgn
echo          If you use different names, edit the batch file accoringly
echo If you're going to build a very large book, you may need to edit
echo this batch file and increase the number 10000
goto end

:start
echo hash 0 > tmp.inp
echo tbldir nul >> tmp.inp
echo book_c book.pgn 100000 %1 2 4 >> tmp.inp
rem echo book_a start.pgn 100000 %1 >> tmp.inp
echo quit >> tmp.inp
yace < tmp.inp
del tmp.inp
:end

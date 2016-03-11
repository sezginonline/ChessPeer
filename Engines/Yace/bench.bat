REM bench.bat
REM Simulate Crafty's bench for Yace
REM If you changed the name of the executable, just change the last line
REM After the batch file was executed once, you can also just start Yace
REM and then type input bench.inp
REM Just search positions 2, 4, 8, 12, 22, 23 of
REM of  Bratko-Kopec 24 position test suite
REM No sd in Yace yet, so use nodes or st
echo st 30 > bench.inp
echo use_book off >> bench.inp
echo test bench.ci >> bench.inp
REM echo quit >> bench.inp
echo noop BK.ci: Bratko-Kopec 24 position test suite > bench.ci
echo echo position 02 >> bench.ci
echo svfe 3r1k2/4npp1/1ppr3p/p6P/P2PPPP1/1NR5/5K2/2R5 W - - 0 1 >> bench.ci
echo srch d5 >> bench.ci
echo echo position 04 >> bench.ci
echo svfe rnbqkb1r/p3pppp/1p6/2ppP3/3N4/2P5/PPP1QPPP/R1B1KB1R W KQkq - 0 1 >> bench.ci
echo srch e6 >> bench.ci
echo echo position 08 >> bench.ci
echo svfe 4b3/p3kp2/6p1/3pP2p/2pP1P2/4K1P1/P3N2P/8 W - - 0 1 >> bench.ci
echo srch f5 >> bench.ci
echo echo position 12 >> bench.ci
echo svfe r3r1k1/ppqb1ppp/8/4p1NQ/8/2P5/PP3PPP/R3R1K1 B - - 0 1 >> bench.ci
echo srch Bf5 >> bench.ci
echo echo position 22 >> bench.ci
echo svfe 2r2rk1/1bqnbpp1/1p1ppn1p/pP6/N1P1P3/P2B1N1P/1B2QPP1/R2R2K1 B - - 0 1 >> bench.ci
echo srch Bxe4 >> bench.ci
echo echo position 23 >> bench.ci
echo svfe r1bqk2r/pp2bppp/2p5/3pP3/P2Q1P2/2N1B3/1PP3PP/R4RK1 B kq - 0 1 >> bench.ci
echo srch f6 >> bench.ci
echo rtrn >> bench.ci
echo quit >> bench.ci
yace < bench.inp

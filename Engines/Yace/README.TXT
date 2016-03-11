Yace Version Paderborn (2003), by Dieter Buerssner (buers@gmx.de).

Some new brief documentation at the end of this file for Yace Paderborn.

Warning, Yace 0.23 or later need a differnent opening book than earlier
version.

Please, read also news.txt. There is some documentation in there.
Step by step instructions for setting up under ChessBase interface
(for example Fritz) can be found at http://home1.stofanet.dk/moq/WinBoard.htm
Please, also read yace.ini and make appropriate changes to hash
and tbldir. Nothing more should be needed.
If you have 64MB of RAM, and you are intending to do engine-engine matches,
20MB might be a good choice for the size of the hash tables. If you
are not intending to do engine engine matches, you should be able to
use 40MB.

Also, feel free to contribute more and/or better documentation ;)

Warning, this is a very early version of Yace. Expect a few problems.
It is also mainly for experienced winboard users. It is expected,
that you know, how to plug a chess engine together with winboard.
I am describing the most important commands here. Sorry, there
is no documentation for the other commands yet.

To input moves just type the move. e4 or e2e4, o-o, Nf3, Ng1f3,
g1f3, e8=q, R1e1 etc. When there is no ambigouty, the destination
square only is enough. (Everything can be left off from the algebraic
notation, as long as there is no ambigouty.)

Yace will play with very small hash-tables by default. It is strongly 
recommended to put a line

hash 30M

(where you can change 30M to any size, you find suitable) into a file
yace.ini in the current directory. (All supported commands can be put into
yace.ini, they will be executed immediately after program startup.)

To enable logging, put a line

loga yace.log

or similar into yace.ini. (When you use log instead of loga, the logfile
will be overwritten every time you start Yace).

You can also tell yace, to create a new log file for every game. The
names will be yace0001.log, yace0002.log etc. By default Yace will write
these file in the current yace folder. I would recommend to put the 
following into yace.ini

; First create a subdirectory logs. 
; Under Unix, the next line must read:
; log_path logs/
log_path logs\

To save all the games to yace.pgn put a line

sgames yacegam.pgn

into yace.ini. It is not suggested, to use the filename yace.pgn, because
some software will write information to a file yace.ini when processing
yace.pgn. This would destroy the ini file of yace. 

A list of all commands supported will be printed after typing help.
If this list is too long for your screen (I use 50 lines), type
log help.log first. Then you can view help.log with a text editor.

You can give shell commands, by appending them to a !. So on DOS/Windows

!dir

or under Unix

!ls -l

will give you a listing of the current directory.

The time command (when not under winboard or xboard) goes like this:

time firstmoves firstseconds secondmoves second_seconds increment

40 moves in one hour would be

time 40 3600

Game in one hour would be

time sd 3600 [sd for sudden death]

40 moves in one hour, all other moves in a half hour

time 40 3600 SD 1800

To use endgame tables, put a line

tbldir c:\egtb

into yace.ini. The Nalimov format (compressed with e:8192 or uncompressed)
is supported. 6 men tables are ignored currently.

Opening book creation
---------------------

You can download an opening book for Yace at Dann Corbit's ftp site
ftp://38.168.214.175/pub/Yace/dbbook.bin or from Mogen Chr. Larsen's
site http://home1.stofanet.dk/Moq/
The later is probably better, because it fills some holes from the former.

Mogens Larsen also made the source of the book available at
http://www.geocities.com/mogens72/Games/
You'll need a ChessBase product to change the format to PGN.

You can find the same game collection in PGN format at ftp://38.168.214.175/pub/contrib/games.zip.

You can create your own book from a PGN file.
The command is

book_create yourfile.pgn initial_entries maxply mincount useresult commentsonly.

This will create (or overwrite) the file dbbook.bin. You can select a
different file name, by typing

book_file mybook.bin

first. After this Yace will use mybook.bin for selecting bookmoves, and
also for all book operations (book_create and book_add). When still no book
with this name exists, Yace will print a warning, which you can ignore.

The last 3 parameters of book_create are optional. 

maxply is the maximum half move number, Yace will use the opening book
for. initial_entries needs some guessing. See below.

mingames is the minumum number of games needed, to store a move in the book.
It defaults to 1. Usually Yace will not select a move from the book, that was
only played in one game, but (rarely) can play a move, that was played in 2 games.
For this reason, I suggest to set mingames to at least 2. A move that has a 
??, ?, ?!, !?, ! or !! attached will allways be stored in the book, independent 
of the number of games. 

useresult can have values from 0 to 6 and defaults to 0. With the default, 
Yace will not look at the [Result ...] of the game. With the useresult 1,
Yace will only consider moves, that won or draw the game from the view
of the side to move. With useresult 2, also winning and drawing moves are 
considered, but now Yace counts the winning move twice as much (pretends,
as if it was played in 2 games instead of one game). This will influence the choice
of Yace, when selecting a move from the opening book, because normally
Yace will select moves with a probability, that depends on the number of 
games. With useresult 3 only winning moves will be counted. With useresult 4,
for white only winning moves are counted, and for black winning and drawing moves.
With useresult 5, the same is done as with 4, however winning moves are counted
twice for black. When there is no [Result ...] in the PGN, Yace will store the 
moves nevertheless in the opening book.

commentsonly defaults to 0. With commentsonly set to one, Yace will only
consider moves, that have !, ? etc. attached. This option may be most useful,
for the book_add command, or when building a special "preference book". 


initial_entries needs some guessing.
You can use pook_parse to help that guessing. book_parse will
show the number of moves found. For a reasonably large book pgn collection
and a book with maxply 30, start with about start with about 1% of this number
for initial_entries. The actual number is not too critical.
A too large number will waste disk storage, while a too small number will 
need longer for book creation and look-up.
Yace will show a "." on the screen for every 10000 moves, so you will
be able to estimate the time usage. Given a slightly modern computer,
you should be able to create a book out of 100000 games in a minute.
The book creation may need lots of memory for very large books. 
You can save some memory by typing
"hash 0" before creation of the book. 

One example for a book with 160000 games.

white ( 1): book_c book.pgn 100000 30 2
[Now Yace will read the first 15 moves of all games in book.pgn into memory]
... [...]
3177933 lines: ngames = 162179 nmoves = 12388210 found 4822418 rej 0
[There were 3177933 text lines in book.pgn, 163179 games and 12388210 moves]
[Of those moves, 4822418 moves were within the first 30 ply, no illegal moves]
[were found (rej 0)]
Deleting 1726106 book moves and relinking entries
[Now all the moves, with a count smaller 2 will be deleted, this phase
will be omitted, when you don't give a mincount]
nused 95839
...

Of the 100000 initial entries 95839 entries are used. I'd suggest, that
this number should be somewhere between 80% and 99% of the number of inititial 
entries. If the number is smaller 80% just start again with a smaller number for
initial_entries, if it is higher start again with a higher number for initial_entries.

You can add new games to the book by book_add

book_add new.pgn 30

Will add the games up to move 15.


Customizing the book.
---------------------

Yace will currently select moves from the book, by a probability
proporional to the number of counts, the move was played in that
situation. You can influence this by commenting moves with NAGs.

Moves with ?? will never be played.
Moves with ? will be played with a low probability, or perhaps never.
?! will lower the probability of playing.
!? will rise the probability of playing.
! will rise it much more.
When at least one move is present with !!, all other moves won't
be considered. When there is more than one move with !!, one of
those moves will be selected, all with equal probability.

When from the same position a move is commented once and commented
differently an other time, the later will overwrite the first.

To build a custom book, I suggest the following:
Create a file start.pgn. Say you want to practice French defense with
white and black. Just create a text file french.pgn.

[Allways play French defense]
e4!! e6!!

Then type

book_add french.pgn

Now Yace will allways play 1.e4 as white and allways reply to 1.e4 with
1...e6.

Note, that I haven't given the maxply here. Then Yace will default to
add all moves up to maxply 30.

You can delete the French defense again by "=". Create a file nofrench.pgn

[Don't want to practise French anymore]
e4= e6=

And type book_add nofrench.pgn.

In the Yace distribution, there is a file start.pgn created by Mogens Larsen.
It will may Yace play many different openings. You can add this to the book
by book_a start.pgn. If you have a look at the file, you will see, that there 
are for example 1.e4!!, 1.d4!!, 1.Nf3!! and 1.c4!!. This will mean, that on average 
every forth game Yace will play 1.e4 etc.
Yace will never play 1.f4. The game collection distributed by Mogens Larson
also has many games for 1.b3, 1.g3 and 1.f4. If you like, that Yace also chooses
those opening moves just add the following lines to start.pgn or create a file
b3g3f4.pgn

[]
b3!!
[]
g3!!
[]
f4!!

and type book_add b3g3f4.pgn.

There is a file bookc.bat, that creates a book automatically out of
book.pgn and start.pgn. Just type

bookc 30

at the DOS-prompt in the Yace directory, to create a 30 ply book.
You may need to customize the batch file, when you renamed Yace, or when
your PGNs have different file names, or when you're going to create
a very large book.

You can add games to a book with book_add. 

book_add games.pgn maxply useresult commentsonly

All parameters besides the name of the pgn-file are optional. Here maxply
defaults to 100. This command is not designed to add a large number of games.
It will be slow for this purpose. The main use of book_add will probably
be, to show Yace some preferences. For example you might want to create a
small file mystart.pgn. Note, that this is not necessarily a suggested
example, it is just to show the features. Some other examples are in the
yace.zip.

[Site "Never play Dutch as black"]
1. d4 f5?? {For "normal" PGN-files, there should be an emty line before and 
after this line, but Yace does not care}
[Site "As White play either..."]
1. c4!!
[]
1. d4!!
[]
1. e4!!
[]
1. Nf3!!
[Site "With Black play French, also with white only the main French line"] 
1. e4 e6!! 2. d4!! d5!! 3. Nc3 Bb4!! {You can add very forced lines for many
positions} 4. e5 c5!!
[Site "You can also use the FEN tag"]
[FEN "rnbq1rk1/ppp2ppp/4pb2/1B1p4/3PP3/2N2N2/PPP2PPP/R2QR1K1 b - -"]
c5!

You can also use different books with Yace. By default Yace will use the book
dbbook.bin in the yace directory. If type or have a line

book_file c:\the\path\to\mybook.bin

Yace will use that book instead. Also book_create and book_add will use that
book. If you have more then one book, and all of them are in the yace directory,
you don't need the path. When playing under Winboard, you can hit Alt+1 together
and then type e.g. book_f french.bin to select the french book from now on. If you type
Alt+1 again, and then type dbbook.bin, the default book will be used again.


Learning
--------

Yace can profit from positional learning. When you have an entry

pos_learn 1

in yace.ini this feature is enabled. From version 0.99 this is enabled 
by default. To disable, use "pos_learn 0". When Yace is still close to the
opening book (currently whithin 15 moves after the last move from the
book), and the score drops significantly, Yace will save some
information to the files learnpos.bin and learnpos.yac. When in a later
game a similar situations arises, Yace should be able to avoid the
bad position in advance.

The file learnpos.yac is an ASCII text file. If you should receive such
a file, you can import the information by typing

import_pos learnpos.yac

Any other filename works as well, as long as the information in the file
is in the correct format.

Yace will not write to its learn files, when in Analyze mode, or when the game
did not start from the initial start position.

From version 0.99.50 there is also book learning. The book learning intends to avoid
book-lines, with which Yace lost games already. To enable book_learning, the following
line in yace.ini is recommended:

book_learn 6

book_learn is the sum, of the following numbers:

1: write "old style" bklearn.pgn whith "old rules" (bad score, in the 
first 10 moves out of book). dblearn.bin will not be touched. This is mainly
useful for opening book authors.

2: When the game looks to be lost, write bklearn2.pgn and dblearn.bin. bklearn2.pgn
could be used, to import new learn information into an existing dblearn.bin, or
to create a new dblearn.bin.

4: Use the information in dblearn.bin for selecting book moves.

So: 7=1+2+4: do all of the above.
6=2+4. Don't write the old style bklearn.pgn, but do everything else
1: Like earlier versions of Yace, no difference. Only write 
bklearn.pgn, don't use dblearn.bin, etc.
0: Do nothing ...
etc. All numbers between 0 and 7 are possible for book_learn.

For booklearning, Yace uses an additional opening book - dblearn.bin. The name
can be changed by

lbook_file somename.bin

Technically, both opening books that Yace can use - dbbook.bin and dblearn.bin
are almost the same. So, you can also add games to dblearn.bin or lines
with !, !! etc. In the Yace distribution, there is already a dblearn.bin, that
contains also opening preferences suggested by Mogens Larsen. 

By default, Yace will not learn for very fast games (faster than 5 minutes).
You can change this time by:

min_learn_tc 600 

which would mean, that Yace will only learn for games not faster than 600 s 
(=10 minutes).

People, intested in creating there own custom opening books, and need to know
more details about all this, may want to contact me by email. I might have ready
a more detailed description of all this at some time in the future.

Opening names
-------------

Yace should be able to find out the name and ECO code of the opening you are
currently playing. It will also write this to the PGN file. To disable this feature
put the line

show_eco 0

into yace.ini. If you put show_eco 2 into yace.ini, Yace will also try, to display
the opening names under WinBoard. Because the PVs, Yace usually sends to Winboard,
may overwrite the opening name fast, it is also recommended to put the line

noise 500k

or similar into yace.ini. This will tell Yace, to not display PVs for the first
500000 nodes searched. You can type "Alt+1" (typing the Alt-key and the 1 key
together, if Yace runs as the second program under Winboard, use 2 instead of
1) and then eco. Yace will then report the opening name. With show_eco 2, Yace
will also whisper/kibitz the opening names in games played at internet chess servers.


Engine tuning
-------------

There are quite a few engine tuning parameters. The most important
are qexact, prune, pval, and the null move parameters.

For qexact, you can give a number between 0 and 9 (the default is 2)
So you can write (or put into yace.ini)

qexact 3
qexact=3
qe=3

Any of those lines should be identical. (You see, that commands
can be abbreviated.)

qexact tunes the heuristics of the quiescence (capture/promotions only)
search. There are essentially 4 different issues.

SKIP_LOOSERS: When set, capture moves that don't bring the
score close enough to alpha, will be skipped. This can speed
up the search much and is recommended.

ALL_MOVES_IN_CHECK: When set, and a capture checks the opponent,
essentially one non capture search will be done. This will need
a bit more time, but will find mates earlier.

CHECK_CHECK_WINNERS:
If we are entering qsearch, and find a good evaluation of the position,
check whether side is not in check. This needs some time, but will
give a more correct search tree.

CHECK_CHECK_ALWAYS:
Always check, whether side to move is in check when entering qsearch.
This will even need more time, but will find mates earlier.

After the qexact command it will be shown, which masks are set.
(Some combinations don't make sense, so there are only 11 instead
of 16 possibilities)

prune: 0 or 1. When 1 (default), at depth 2 certain very uninteresting
looking moves will be pruned off the search tree.

pval: from 0.5 to 2.0. Positional scores will be multiplied by this
factor (default: 1.0).

Null move heurists
------------------

In many situations in the search, Yace will try a null move. This means
that it just passes the right to mov to the opponent and searches
the position at a reduced depth. This is usually a very big disadvantage.
When the search indicates, that even without moving the position will be
"good" (score >= beta), you get a cutoff of the search tree. This will make
it search higher depths faster. The null move heuristics won't work,
when there is a Zugzwang situation. Yace tries to avoid errors from
such situations, by searching the position at an even more reduced
depth with no null move. Only when this also looks good, a null move
cutoff will be allowed.

Most of the null move algorithm user selectable. The commands are
null_low (default 3.0), null_high (3.0), null_endgame (2.0) and
null_split (4.5). The first three parameters are the depth reduction
done for the null move. The larger the values are, the faster Yace will
search a certain depth. The prize is, that the search will get more and
more inexact. In early game the null move algorithm will use
null_low when the current search depth is small (smaller or equal null_split)
and null_high, when it is high. (If you want to simulate Crafty
use null_high=4.0 and null_split=6.0, but I think 4.0 is too much). With
the current defaults, there is no difference between null_high and
null_low, the new code will just slow down the search a tiny little bit.
When at least one side has less than the equivalent of 8 pawns, and
two times the current ply is larger or equal the current search depth
null_endgame will be used. So Yace will use the nullmove algorithm
even in endgames at the leaves of the search tree, but not at the roots.
When one side has less than 3 pieces, no nullmove algorithm will be used.
Don't use values smaller 2.0 other then 0.0 to disable the null move
algorithm. Yace currently won't check if the values choosen make sense.

Fractional extensions:
----------------------

From version 0.18 on Yace will use fractional extensions. When
Yace considers a position interesting, it will extend the search.
The value on how much it will extend the search, can be set at the Yace
prompt or in yace.ini. Changing these values needs some understanding
of how chess engines work. The different parameters are:

icheck (default 1.0): When checking the opponent.
irepcheck (0.59): When checking the opponent for the second time in a row
ipawn7 (1.0): Pushing a pawn to row seven
inullthreat (1.0): When the nullmove indicated, that we are in trouble.
irecapture (0.59): Last move was a capture, and this move also (or promotion).

Internally, the values are set to integral factors of 1/64.

Depending on the situation, the extension may not be done, i.e. there
will not be two recapture extensions in a row. Also Yace will not allow
to increment the depth by more than 1.0, unless a repcheck extension was
found, in which case the depth may increase by 2.0.

Typing param gives an overview of the currently set tuning parameters.

I'd be very interested in feedback about these parameters. Currently
they are only tuned against test positions. (Yace is certainly overtuned
against test positions. I did almost no real ganes other than against
myself, and this really doesn't tell much :-( I found out about winboard
only about two weeks ago. Dann Corbit encourged me, to make a winboard port.
I turned out to be rather easy, and so I am very thankful for his
suggestion)

You can test Yace with test-suites. Just type

test wac.ci

where wac.ci looks like this

title position 001
setboard 2rr3k/pp3pp1/1nnqbN1p/3pN3/2pP4/2P3Q1/PPB4P/R4RK1 w - - 0 1
solution Qg6
title position 002
setboard 8/7p/5k2/5p2/p1p2P2/Pr1pPK2/1P1R3P/8 b - - 0 1
solution Rxb2
title position 003
setboard 5rk1/1ppb3p/p1pb4/6q1/3P1p1r/2P1R2P/PP1BQ1P1/5RKN w - - 0 1
...

You might want to give a command like

st 10 [search for 10 seconds]

or

nodes 100k [search for 100000 nodes]

first.

A different format is also possible
noop King and Pawn endgame tests from Fine, Basic Chess Endings
noop (New York: McKay, 1941)
echo Fine position 11
svfe 8/8/4k/8/4KK8/4P/8 w - - 0 1
srch e3
echo Fine position 13
svfe 8/8/8/8/8/P4p/k6K/8 w - - 0 1
srch a4
echo Fine position 14
svfe 8/8/5P/8/6K/7p/6k/8 w - - 0 1
srch f7
...


When the solution/srch has a '?' appended, the test-postion will be
solved, when Yace avoids this move. There can be more than one
solution:

title position 031
setboard rb3qk1/pQ3ppp/4p3/3P4/8/1P3N2/1P3PPP/3R2K1 w - - 0 1
solution Qxa8 d6 dxe6

Yace will write a few .ci files. I.e. lost.ci will contain the
tests, Yace couldn't solve. They can be used for further testing,
*after* renaming them. Also a file test.sum will be written (or appended to),
where all the testing done so far is protocolled.

Additionally, Yace will write 2 files - tmp.pgn and tmp.epd. These 2
files contain the testsuite in different formats, that can be used under
other chess software. E.g. the tmp.epd can be used under Shredder 5 and
the tmp.pgn can be used under Fritz 6. Note, that Fritz does not seem to
support test positions with more than 2 solutions, and test positions, where
the target is to avoid a move.

You can also use the epdtest command. For example:

st 10
epdtest wac.epd

Bitbases
--------

Bitbases are in concept similar to TBs. They can however be used from memory
instead of from hard disk in Yace, and so access to them is much faster. You
need all 3 and 4-men Nalimov TBs first. Then you can create the bitbases. 
Start yace.exe without GUI (console mode). Make sure, tbldir is set correctly.
Type

create_bitbases

and wait a bit. Type 

quit

To use bitbases, for the WB-version, put a line

bbpath .

into yace.ini. This will need about 14 Mb of memory. With UCI, use the engine
options. Note that it will not work with some versions of the Fritz GUIs, to
set up the bitbase path. In that case, you could use a minimal yace.ini with UCI,
just containing the above line. You could copy all the bitbases 
(extensions bbw and bbb) to a folder, and set the bitbase path accordingly.

In console mode, you can unload the bitbases (and free the memory) by just typing

bbpath

tbb

test the bitbases. You should not need this command :-)
When Yace loads the bitbases, it already calculates some error sums, to
test the consistancy, and refutes to load corrupted bitbases.

Annotationg games
-----------------

Note, that the command is in somewhat prelimary state

current syntax

annotate games.pgn annotated.pgn gameno side seconds fhmn lhmn margin

A game from games.pgn will be annotated. Some comments (scores, 
depth, variations) will be written in annotated.pgn. If annotated.pgn
already exists, the PGN will be appended. gameno is the number of the game
in games.pgn (if there is only one game, use 1). Seconds is the time to
analyze each move. fhmn and lhmn are the first/last *half* move numbers
to analyze. if smaller 0, the start/end of the game will be meant. side is
either w, b or a (for white, black, all). Margin is a score margin.  When
the score of the Yace suggested move is better than this margin, a
variation will be written in the game. It can be set to 0 or < 0, which
means any alternative will be shown.

example:

annotate match.pgn matchann.pgn 1 10 a -1 -1 0

In this example, the last four parameters would actually not be 
needed, because they are the defaults.

If you want to annotate more than one game (say over night), you could 
write an input file, ann.inp like:

annotate games.pgn gamesa.pgn 2 100 w 20 80 5
annotate games.pgn gamesa.pgn 5 100 w 20 80 5
annotate games.pgn gamesa.pgn 7 100 w 20 80 5

to annotate games 2 5 and 7. At the Yace prompt, you would type

inp ann.inp

At the moment all scores shown in the annotated pgns will be from
the view of the moving side. In later versions, this can be changed.

List of some other new command in Yace Paderborn:

posentries 30000

By default, Yace uses space for 10000 position for position learning.
Type the above *once* to make space for 30000 positions.

tb_usage n

n can be 0,1,2,3,4. Default is 3. With 0, TBs will only be probed at the root
of the position. The bigger the number, the more often Yace will access TBs.
This will slow down nodes/s in many endgame positions.

cadiz_pgn games.pgn new.pgn n

Will add Headers for openings and ECO to the pgn. When the letter n is
used above, the PGN will be reformated, and all comments and variations
will be deleted.

cadiz_pgn games.pgn new.pgn n 100

As above. Additionally, a maximum of 100 half moves will be written
in the output

cadiz_pgn games.pgn stat.txt s

Will create opening statistics of games of Yace ordered by color and
ECO code. 

armando_pgn games.pgn new.pgn

Will add a !! to all moves of the winner side in the PGN. No annotations
done to drawn games.

carlos_pgn games.pgn new.pgn out_format anow anob newline

Reformats PGN files or similar input of chess games. Documentation
will follow at a later time ...

book_random 0 (or 1)

default 1. book_random 0 will only play the mostly played book line.

book_split 12

If book_random is 1 (the default) Yace will still use book_random 0
after 12 half moves

book_clean

Will delete all annotations from the book.

perftest 6

will calculate the number of legal chess games of 6 half moves
from the current position.

win_all, win_computers, win_humans

After win_all 3, in ICS mode, Yace will automatically set finger
note 3 to a list of the last 6 opponents, who won against Yace.
Something like:
 3: Opponents that beat me: harimau, sayilose, abp, cro-magnon, TAL9000, RollingThunder
You can use another number than 3, but not 1. With the other 2 commands,
only computer winners or human winners will be shown. You can have all 3
of the above, with different finger note lines.

If you play on different servers, and want to make the list servers specific,
use for example

win_file icc

when you play on ICC and 

win_file fics

when you play on FICS

prompt_all, prompt_humans, prompt_computers

After 

prompt_all I got toasted by

Yace will write the fi note
I got toasted by: harimau, sayilose, abp, cro-magnon, TAL9000, RollingThunder

version tweaked

Will give Yace the name Yace Paderborn tweaked. This will be shown in
the PGNs, and should be shown in the GUI. 

nsgames _200302.pgn

Will save a pgn of each game under the name of the opponent. With the above
games vs. Crafty will be saved under crafty_200302.pgn. (Intention: games of
february 2003). If you have sgames, too, the games will be saved twice.

To use Yace with Fritz 7 or similar CB interfaces as an UCI engine, you have
to update the GUI. Note, that the GUI will crash with some versions of 
uci.dll (part of the CB software). In my tests, version 1.0.0.10 of uci.dll
seemed reliable. But you cannot set up the bitbase path with that version.
I guess, we can expect a newer version of uci.dll soon, which will fix the 
problem.

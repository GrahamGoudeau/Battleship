BATTLESHIP
==========

AUTHOR: Graham Goudeau

The classic game of battleship.  The user plays against the computer player; the
design of the AI is modeled after the algorithm at:

 * http://www.datagenetics.com/blog/december32011/

The AI builds a probability distribution for its board by superimposing all the 
possible ship locations, and firing on the most likely position.  When it scores
a hit, it searches the immedaite area until a "SUNK" is reported.

Use the provided Makefile to compile; run ./battleship

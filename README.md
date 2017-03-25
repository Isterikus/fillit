Our second project in UNIT Factory.

In this particular project, i create an algorithm which fits some Tetriminos together into the smallest possible square.
A Tetriminos is a 4-blocks geometric figure that most of you might knows thanks to the popular game Tetris.

The description of a Tetriminos must respect the following rules :
• Precisely 4 lines of 4 characters followed by a new line.
• A Tetriminos is a classic piece of Tetris composed of 4 blocks.
• Each character must be either a ’#’ when the character is one of the 4 blocks of a Tetriminos or a ’.’ if it’s empty.
• Each block of a Tetriminos must be in contact with at least one other block on any of his 4 sides.

In case of invalid figueres or multiply empty lines the programm will display error message.

Example of valid file to solve:
$> cat sample.fillit
....
##..
.#..
.#..

....
####
....
....

#...
###.
....
....

....
##..
.##.
....

Program output to such file:
$> ./fillit sample.fillit
DDAA
CDDA
CCCA
BBBB

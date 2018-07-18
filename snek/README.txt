Author: Andrew Frantzich
This replication of the classic game snake is arbitrarily 40 x 38.

To play, simply 'make' and run the executable snek './snek'

The key hooks of the given library mlx use key release which is less than
desirable, and with some research there might be a way to use a hook on key press.

Ending the game reads from the file high_scores.txt and adjusts it accordingly.
Changing this file will result in undefined behavior.
Getting a new high score may result in some garbage data before EOF.

The game starts immediately after running, implementing a start screen would
be a good idea.

Snake grows one block at a time, but could be modified by changing the grow_body
function, and adding a variable to the struct map containing how many cells to add.

Speed (difficulty) could be adjusted by simply changing the number passes to usleep
in the move function. Smaller number means a faster snake.

Other than the works in progress mentioned above, the game should be clean and stable.

Have fun!

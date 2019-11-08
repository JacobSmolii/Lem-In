# Lem-In

## Introduction: 
We need to make an ant farm, with tunnels and rooms. We place the ants on one side and we look how they find the exit. How do we build an ant farm? We need tubes and rooms. We join the rooms to one another with as many tubes as we need. A tube joins two rooms to each other. A room can be linked to an infinite number of rooms and by as many tubes as deemed necessary. Then we must bury the ant farm.

In two words you have to travel ants through the rooms from start to end. Only one ant per room is allowed, expect in start and end. The Goal is to send the ants in the shortest number of shots by finding the parallel paths.

## Rules
  * The project must be written in C language. 
  * Each ant may move one room per turn. 
  * Only one ant may occupy a room at a time expect for start and end.
  * Minimize the number of turns required to move all ants from start to end.
  * Algorithm must render within a reasonable time, even in a case with 4000 rooms more. 2 or 3 seconds is great, 9 seconds is      mediocre, 15 seconds is too much.
  * There are maps with sometimes more than 10,000 lines, the way you read and write data must also be fairly fast.
  * Finally, your algorithm should be able to use the best combination of paths according to the number of ants.
  
### About lem-in

At the beginning from standart output the program recieves information about number of ants had to be leaded through path, room names (can be numbers, words, character etc.) with coordinates(for vizualizer) and links. Here is an example:

```
10                  // Ants number
5 9 3               // Room name, X and Y coordinates
6 1 5               
##start             // Next room will be start room
1 23 3
2 16 7
#comment            // some comments, we don't care about tnem, need to skip
3 16 3
4 16 5
7 4 8
##end               // Next room will be end room
0 9 5
1-3                 // Relations between rooms. Room 1 and 2 are linked
0-4
0-6
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
#another comment
```


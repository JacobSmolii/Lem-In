# Lem-In

## Introduction: 
We need to make an ant farm, with tunnels and rooms. We place the ants on one side and we look how they find the exit. How do we build an ant farm? We need tubes and rooms. We join the rooms to one another with as many tubes as we need. A tube joins two rooms to each other. A room can be linked to an infinite number of rooms and by as many tubes as deemed necessary. Then we must bury the ant farm.

In two words you have to travel ants through the rooms from start to end. Only one ant per room is allowed, expect in start and end. The Goal is to send the ants in the shortest number of shots by finding the parallel paths.

## Rules
  * The project must be written in C language. 
  * Each ant may move one room per step. 
  * Only one ant may occupy a room at a time expect for start and end.
  * Any non compliant or empty lines will automatically stop the ant farm's reading as well as the orderly processing of the     acquired data.
  * If there isn't enough data to process normally you must display ERROR.
  * Minimize the number of turns required to move all ants from start to end.
  * Algorithm must render within a reasonable time, even in a case with 4000 rooms more. 2 or 3 seconds is great, 9 seconds is      mediocre, 15 seconds is too much.
  * There are maps with sometimes more than 10,000 lines, the way you read and write data must also be fairly fast.
  * Finally, your algorithm should be able to use the best combination of paths according to the number of ants.
  
## Input

* At the beginning from standart output the program recieves information. Here is an example:

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

* Which corresponds to the following representation:

![alt text](https://user-images.githubusercontent.com/45500862/68441139-0c2eee80-0182-11ea-90ff-9907b2f55b14.png)

* There are two parts:

  A) The rooms, which are define by: name coord_x coord_y <br />
  B) The links, which are define by: name1-name2 <br />
  C) All of it is broken by comments, which start with '#' <br />
  
The rooms names won't necessarily be numbers, and they won't necessarily be in the right and continuous order. But most importantly, a room will never start with the character L nor the character #. The rooms coordinates will always be integers.
Lines that start with ## are commands modifying the properties of the line that comes right after. For example, ##start signals the ant farm's entrance and ##end its exit.

## Output
L[ant]-[room]

```
~~~~~~~~~~~~~~~~~~~
Total paths     2
Total ants     10
Active paths    2

Path  1, Length  3, Amount of ants  6
Path  2, Length  4, Amount of ants  4

Steps           8

~~~~~~~~~~~~~~~~~~~
1.      1 [ 0] -> 3[ 2] -> 4[ 3] -> 0[ 7]
len of PATH: [3]
2.      1 [ 0] -> 2[ 1] -> 7[ 6] -> 6[ 5] -> 0[ 7]
len of PATH: [4]
~~~~~~~~~~~~~~~~~~~
L2-2 L1-3                                   // Step 1: ant number 1 go to room 3. Ant number 2 go to room 3
L4-2 L3-3 L2-7 L1-4 
L6-2 L5-3 L4-7 L3-4 L2-6 L1-0 
L8-2 L7-3 L6-7 L5-4 L4-6 L3-0 L2-0 
L9-3 L8-7 L7-4 L6-6 L5-0 L4-0 
L10-3 L9-4 L8-6 L7-0 L6-0 
L10-4 L9-0 L8-0 
L10-0 
```


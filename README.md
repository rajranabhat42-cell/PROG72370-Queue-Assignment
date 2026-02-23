# PROG72370-Queue-Assignment
This is my assignment repository for PROG72370. It's a queue program using linked lists. Each node in this program holds a game user with a username, level(1-60), and faction(red, blue, green).

# Files
I used 3 files in this program to make my code well structure and to increase the readbility. 

Names of those files are:

main.c- runs everything, takes nummber from command line

queue.h- has all the structs and function prototypes

queue.c- actual queue functions (enqueue, dequeue, etc.)

# How it works:

1. Get number of users from command line (like ./program.exe 10)
2. Make an empty queue 
3. Create that many random users (random username, level, faction)
4.Add them to queue
5. Take them out one by one and print them
6. Free memory, so there is no leaks

# Stuff I learned:


-Head and tail make queue fast


-I have to free memory or code might crash

- Random needs srand or you will get the same numbers every time
  
- Command-line args are useful.

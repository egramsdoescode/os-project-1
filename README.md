# Project 1: Implementing a Shell

### Group Members
- [Salman Abid](https://github.com/SlummyBoi) 
- [Ethan Grams](https://github.com/egramsdoescode) 
- [Matthew Perez](https://github.com/Rex-Perez) 

### Files and Directories included in Submission
-'main.c'    :Source code to implement the shell
-'Makefile'  :Builds the project and creates the 'project1' executable 
-'README.txt'  :Current File

### Instructions to Compile the Program:
$ make

### Instructions to Run the Program:
./project1

### Instructions to Clean the Build:
$ make clean

### Challenges Faced
- Managing memory properly with strdup() and freeing the tokens after they are used
- Getting the prompt to show the current directory and update it properly
- Understanding how to properly utilize fork(), execvp(), and waitpid()
- Coordinating work across differing team schedules

### Sources Used:
- Linux manual pages and documentation for execvp, getcwd, strtok, waitpid, and fork
- Course Lecture Slides 

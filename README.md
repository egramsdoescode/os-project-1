# Project 1: Implementing a Shell

### Group Members
- Salman Abid:   fvp216 
- Ethan Grams:   bib016 
- Matthew Perez: afk574

### Files and Directories included in Submission
-'main.c'    :Source code to implement the shell
-'Makefile'  :Builds the project and creates the 'project1' executable 
-'README.md'  :Current File

### Instructions to Compile and Program Run the Program: 
```bash
make run
```

### Instructions to Clean the Build:
```bash
make clean 
```

### Challenges Faced
- Managing memory properly with strdup() and freeing the tokens after they are used
- Getting the prompt to show the current directory and update it properly
- Understanding how to properly utilize fork(), execvp(), and waitpid()
- Coordinating work across differing team schedules

### Sources Used:
- Linux manual pages and documentation for execvp, getcwd, strtok, waitpid, and fork
- Course Lecture Slides 

# Unix-Utilities
Implementation a collection of basic Unix utilities using low-level system calls

# Usage

** The size utility prints the size of each file passed in as an argument.
./size file

** The newest utility determines which file is the newest
** -a option indicates that access times of the files will be compared
** -m option indicates that modification times of the files will be compared
** -c option indicates that change times of the files will be compared
** Program will be passed exactly one of the three options
./newest (-a | -m | -c) file1 file2


** Lists all the files in the current working directory
./dirlist


** Prints the largest files in the current working directory
./largest [-n #]


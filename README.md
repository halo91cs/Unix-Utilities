# Unix-Utilities
Implementation a collection of basic Unix utilities using low-level system calls

# Usage

** The size utility prints the size of each file passed in as an argument.<br/>
<b>./size file</b>

** The newest utility determines which file is the newest <br/>
** -a option indicates that access times of the files will be compared <br/>
** -m option indicates that modification times of the files will be compared <br/>
** -c option indicates that change times of the files will be compared <br/>
** Program will be passed exactly one of the three options <br/>
<b>./newest (-a | -m | -c) file1 file2 </b>


** Lists all the files in the current working directory </br>
<b>./dirlist </b>


** Prints the largest files in the current working directory <br/>
<b> ./largest [-n #] </b>


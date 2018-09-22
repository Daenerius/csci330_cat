#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;
 //fstat - to get size of file to know how big the array is
 //make array, then get file data size, make new array with correct size and dump file into array
 //output array into terminal, output one character at a time
 //next file 

void fileFunction(char data[]){

 ssize_t howManyBytes;
 char *stringbuf;
 struct stat fileStat;

 int file = open(data, O_RDONLY, 0755);

 if (file == -1)
 {
     perror("File open error");
 }
 else
 {
 fstat(file, &fileStat);
 stringbuf = new char[fileStat.st_size];
 howManyBytes = read(file, stringbuf, fileStat.st_size);
    for(int i = 0; i < fileStat.st_size; i++)
    {
     cout << stringbuf[i];
    }
 }
 int close(file);
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
       fileFunction(argv[i]);
    }
    return 0;
}
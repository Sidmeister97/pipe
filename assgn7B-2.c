//33158

#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
 

struct temp
{
     int noOfWords;
     int noOfChars;
}temp1; 
  
int main() 
{ 
    int fd1;
  
    // FIFO file path 
    char * myfifo = "/tmp/myfifo"; 
  
    // Creating FIFO 
    mkfifo(myfifo, 0666); 
    int i,noOfChars,noOfWords;
    char str1[80], str2[80]; 
    while (1) 
    { 
        // First open in read only and read 
        fd1 = open(myfifo,O_RDONLY); 
        read(fd1, str1, 80);
        int size = strlen(str1);
        noOfChars = 0;
        noOfWords = 0;
        for(i=0;i<size-1;i++)
        {
        	if((int)str1[i] == 32)
        	{
        		noOfWords++;
        	}
        	else
        		noOfChars++;
        } 
        // Print the read string and close 
        printf("User1: %s\n", str1); 
        close(fd1); 
  
        fd1 = open(myfifo,O_WRONLY);
        temp1.noOfWords = noOfWords;
        temp1.noOfChars = noOfChars;  
        write(fd1,&temp1,sizeof(temp1)); 
        close(fd1); 
    } 
    return 0; 
} 


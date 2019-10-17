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
    int fd; 
  
    // FIFO file path 
    char* myfifo = "/tmp/myfifo"; 
  
    // Creating the named file(FIFO) 
    mkfifo(myfifo, 0666); 
  
    char arr1[80], arr2[80]; 
    while (1) 
    { 
        // Open FIFO for write only 
        fd = open(myfifo, O_WRONLY); 
   
        fgets(arr2, 80, stdin); 
  
        // Write on the fifo 
        write(fd, arr2, strlen(arr2)+1); 
        close(fd); 
  
        // Open FIFO for Read only 
        fd = open(myfifo, O_RDONLY); 
  
        // Read from FIFO 
        read(fd,&temp1 ,sizeof(temp1)); 
  
        // Print the read message 
        printf("User2: No Of Characters - %d\n", temp1.noOfChars);
        printf("User2: No of Words - %d\n", temp1.noOfWords+1); 
        close(fd); 
    } 
    return 0; 
} 


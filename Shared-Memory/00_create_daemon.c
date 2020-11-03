#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void main(){
    FILE *fp;
    pid_t process_id = 0;
    pid_t sid = 0;
    //Create child process
    process_id = fork();
    //ERROR MESSAGE
    if(process_id < 0){
        printf("Fork failure, could not be created");
        exit(1);
    }
    //Killing Parent Process
    if(process_id > 0){
        printf("process id of child process: %d\n", process_id);
        exit(0);
    }
    umask(0);
    //set new session
    sid = setsid();
    if(sid < 0)
    {
        // Return failure
        exit(1);
    }
    // Change the current working directory to root.
    chdir("/");
    // Close stdin. stdout and stderr
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
    // Open a log file in write mode.
    fp = fopen ("Time.txt", "w+");
    

}
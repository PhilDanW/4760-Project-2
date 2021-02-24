#include "shared.h"

/*Prototypes of functions*/
int loadNumbers(char*);
void setTimer(int);
void spawnChild(int);
void sigHandler(int);

/*Set the option variables to their defaults to start with.
* they will change later on*/
int nChildren = PROCESS_MAX_DEFAULT;
int s = CON_PROCESS_DEFAULT;
int tSeconds = PROGRAM_TIME_MAX;

/*Flag to disable interrupt handler*/
bool interrupt = false;

/*main() function for controlling master*/
int main(int argc, char** argv) {
      
    signal(SIGINT, sigHandler);
  
    /*opens each file for writing, if a file with
		* that name already exists, it is deleted and 
		* treated as a new file
		*/
    openFile("sum.out");
	  openFile("output.log");
	
	  /*Get arguments from the command line*/
		while(int option = getopt(argc, argv, "hs:t:")) != -1) {
				swtich (option) {
					case 'h':
									programUsage(argv[0]);
                  return EXIT_SUCCESS;
					case 's':
									if(!isdigit(*optarg || (s = atoi(optarg)) < 0) {
											perror("Invalid timeout time '%s'", optarg);
									}
                  else {
                      nChildren = atoi(optarg);
                  }
									break;
					case 't':
									if(!isdigit(*optarg || (s = atoi(optarg)) < 0) {
											perror("Invalid timeout time '%s'", optarg);
									}
                  else {
                      tSeconds = atoi(optarg);
                  }
									break;
          case '?':
                  perror("Unknow option");
                  return EXIT_FAILURE;
					default:
								  perror ("Error: Illegal option found");
                  show_usage(argv[0]);
                  return EXIT_FAILURE;
					}
		}
		
		/*Display the usage screen if any of the options are invalid*/
    if (!check) 
        programUsage(EXIT_FAILURE);
    
    /*See if there was an input file give in the argument list*/
    if (argv[optind] == null) {
        perror("No input file given");
        programUsage(EXIT_FAILURE);
    }
     
    allocateSM();
                     
    int count = loadInts(argv[optind]);
                     
    /*now clamp the option arguments to their positions*/
    n = MIN(count, TOTAL_PROCESSES);
    s = MIN(s, n);
    t = MIN(t, PROGRAM_TIME);
                     
    /*Simulate the program exiting instantly*/
		if (n==0 || s==0 || t == 0) exit(EXIT_SUCCESS);
								
		/*set the number of programs to be in system to shared memory variable*/
		spm->total = n;
		
    /*Use the timeout option to initialize the timer*/
		setTimer(t);
		
    /*variables meant to help with child spawn logic*/
		int i = 0;
		int j = n;
		int k = n;
										 
		/*Spawn the initial children*/
		while (i < s)
						spawnChild(i++);
										
		/*Loop until the number of processes is equal to 0*/
		while(k > 0) {
          /*wait for the child to exit*/
					wait(NULL);
      
          /*write to the log at what time it finished*/
					logOutput("output.log", "%s: Process %d finished\n", getTime(), n - k);
			
          /*try to spawn another child process*/
					if (i < j) 
							spawnChild(i++);
			
					k--;
		}
		
		/*Remove the shared memory*/
		removeSM();
		
    /*use check variable to make sure entire program has finished, exit accordingly*/
		if (check) {
				EXIT_SUCCESS;
		}
		else {
				EXIT_FAILURE;
		}

 int loadInts(char* path) {
     FILE* file = fopen(path, "r");
     if (file == NULL) crash("File open failure: could not load numbers");
   
     int i = 0;
     char* line = NULL;
     size_t len = 0;
     ssize_t read;
   
     while ( i < n && (read = getline(&line, &len, file)) != -1) {
            removeNewline(line);
            spm->strings[i++], line);
     }
   
     fclose(file);
     if (line) free(line);
   
     return i;
 }
                     
 void setTimer(const int t) {
      struct sigaction action;
      memset(&action, 0, sizeof(action));
      action.sa_handler = signalHandler;
      if (sigaction(SIGALRM, &action, NULL) != 0) crash("Failure to set signal for timer");
   
      struct itimerval timer;
      timer.it_value.tv_sec = t;
	    timer.it_value.tv_usec = t;
	
	    timer.it_interval.tv_sec = 0;
	    timer.it_interval.tv_usec = 0;
	
	    if (setitimer(ITIMER_REAL, &timer, NULL) != 0) crash("Failed to set timer");
 }
                     
 void spawnChild(const int i) {
       pit_t pid = fork();
   
       if (pid == -1) perror("Failure to create child process");
   
       if (pid == 0) {
             flag = true'
               
             if (i == 0) spm->pgid = getpid();
             setpgid(0, spm->pgid);
         
             flag = false;
         
             logOutput("output.log", "%s: Process %d is starting up\n", getTime(), i);
             
             char id[256];
             sprintf(id, "%d", i);
         
             execl("./bin_adder", "bin_adder", id, (char*) NULL);
         
             exit(EXIT_SUCCESS);
       }
 }
                     
 void sigHandler(int s) {
       if (flag) sleep(1);
   
       char message[4096];
       strfcpy(message, "%s: Exiting program due to %s signal\n", getTime(), s == SIGALRM ? "timeout" : "interrupt");
   
       fprintf(perror, message);
       logOutput("output.log", message);
   
       kill(spm->pgid, s == SIGALRM ? SIGUSR1 : SIGTERM);
   
       while (wait(NULL) > 0);
   
       removeSM();
   
       exit(EXIT_SUCCESS);
 }
	
									
	
										
								

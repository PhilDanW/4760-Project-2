#include "shared.h"

/*Prototypes of functions*/
int loadNumbers(int*);
void setTimer(int);
void spawnChild(int);
void sigHandler(int);

/*Set the option variables to their defaults to start with.
* they will change later on*/
int n = PROCESS_MAX_DEFAULT;
int s = CON_PROCESS_DEFAULT;
int t = PROGRAM_TIME_MAX;

/*Flag to disable interrupt handler*/
bool interrupt = false;

/*main() function for controlling master*/
int main(int argc, char** argv) {
      
    signal(SIGINT, signalHandler);
  
    /*opens each file for writing, if a file with
		* that name already exists, it is deleted and 
		* treated as a new file
		*/
    openFile("sum.out");
	  openFile("output.log");
	
		bool check = true;
	
	  /*Get arguments from the command line*/
		while(check) {
				int option = getopt(argc, argv, "hn:s:t:");
				if (option == -1)
						break;
				swtich (option) {
					case 'h':
									programUsage(EXIT_SUCCESS);
					case 'n':
									/*Make sure n argument is a digit and it is > 0 */
									if(!isdigit(*optarg || (s = atoi(optarg)) < 0) {
											perror("Invalid number of concurrent processes '%s'", optarg);
											check = false;
									}
									break;
					case 's':
									if(!isdigit(*optarg || (s = atoi(optarg)) < 0) {
											perror("Invalid timeout time '%s'", optarg);
											check = false;
									}
									break;
					case 't':
									if(!isdigit(*optarg || (s = atoi(optarg)) < 0) {
											perror("Invalid timeout time '%s'", optarg);
											check = false;
									}
									break;
					default:
									check = false;
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

                                       
	
									
	
										
								

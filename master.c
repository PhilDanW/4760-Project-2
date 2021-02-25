#include "shared.h"

/*Set the option variables to their defaults to start with.
* they will change later on*/
const int maxChildren = 20;
const int maxSeconds = 100;

/*main() function for controlling master*/
int main(int argc, char** argv) {
	
		int option;
		int numChildren = 20;
		int numSeconds = 100;
      
    signal(SIGINT, sigHandler);
  
    /*opens each file for writing, if a file with
		* that name already exists, it is deleted and 
		* treated as a new file
		*/
    openFile("sum.out");
	  openFile("output.log");
	
		opterr = 0;
	  /*Get arguments from the command line*/
		while(option = getopt(argc, argv, "hs:t:")) != -1) {
				swtich (option) {
					case 'h':
									programUsage(argv[0]);
                  return EXIT_SUCCESS;
					case 's':
									if(!isdigit(*optarg || (s = atoi(optarg)) < 0) {
											perror("Invalid timeout time '%s'", optarg);
									}
                  else {
                      numChildren = atoi(optarg);
                  }
									break;
					case 't':
									if(!isdigit(*optarg || (s = atoi(optarg)) < 0) {
											perror("Invalid timeout time '%s'", optarg);
									}
                  else {
                      numSeconds = atoi(optarg);
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
										 
		numChildren = MIN(numChildren, maxChildren);
		numSeconds = MIN(numSeconds, maxSeconds);
    
    /*See if there was an input file give in the argument list*/
    int index = optind;
		if(index < argc) {
			char fileName[] = argv[index];
			
			printf("%d Max Children Processes", numChildren);
			printf("%d Seconds on Timer", numSeconds);
			printf("%s is the Input File", fileName);
		}
		else {
        perror("No input file given");
        programUsage(EXIT_FAILURE);
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
	
									
	
										
								

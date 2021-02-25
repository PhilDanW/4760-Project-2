#include "shared.h"

/*Set the option variables to their defaults to start with.
* they will change later on*/



/*main() function for controlling master*/
int main(int argc, char** argv) {
	
	int option;
	const int maxChildren = 20;
	const int maxSeconds = 100;
	int numChildren = 20;
	int numSeconds = 100
	int s;
	
		opterr = 0;
	  /*Get arguments from the command line*/
		while((option = getopt(argc, argv, "hs:t:")) != -1) {
				switch (option) {
					case 'h':
						      usage(argv);
                  return EXIT_SUCCESS;
					case 's':
                  numChildren = atoi(optarg);
									break;
					case 't':
                  numSeconds = atoi(optarg);
									break;
          case '?':
                  perror("Unknow option");
                  return EXIT_FAILURE;
					default:
								  perror ("Error: Illegal option found");
                  usage(argv);
                  return EXIT_FAILURE;
					}
		}
										 
		numChildren = MIN(numChildren, maxChildren);
		numSeconds = MIN(numSeconds, maxSeconds);
    
    /*See if there was an input file give in the argument list*/
    int index = optind;
		if(index < argc) {
			char fileName[30];
      strcpy(fileName, argv[index]);
			
			printf("%d Max Children Processes\n", numChildren);
			printf("%d Seconds on Timer\n", numSeconds);
			printf("%s is the Input File\n", fileName);
		}
		else {
        perror("No input file given");
        usage(argv);
    }
}
                                    

	
									
	
										
								

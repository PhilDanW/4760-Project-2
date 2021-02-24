#include "shared.h"

/*Prototypes of functions*/
int loadNumbers(int*);
void setTimer(int);
void spawnChild(int);
void sigHandler(int);

/*Set the option variables to their defaults to start with.
* they will change later on
*/
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
				if (c == -1)
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
								

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

#define N 0x100

#define NOMASOPC -1
#define INVALOPC '?'
 
#define USAGE "½s -v1.0\n"\
    "%s: Sends an email to a file. \n\n"\
    "USAGE :\n"\
    "%s -d<dominio> [-p<puerto|port name>=smtp] <email file> \n"\
    "\n" \
    "PARAMETERS:\n"\
    "-d, --domain Domain of the email server. \n"\
    "-p, --port Port (25) or port name (smtp). \n"\
    "when not present defaults to smtp.\n"\
    "-v, --verbose Echo inner working.\n"\
    "\n"\
    "EXAMPLE:\n" \
    "%s -d sharklasers.com email.txt\n"\
    "\n", (p), (p), (p)\

#define MAILMANDO "cat %s | telnet %s %s"

const char *program_name;


void print_usage (FILE *out, int status)
{
    fprintf ( out, USAGE(program_name) ); //Para que siga ese patron y lo hagas bien
    exit(status);
}

int main(int argc, char *argv[]){
        char mailmando[N]; //Comando del mail
        const char *servidor = NULL;
        char puerto[N] = "smtp";
        int verbose = 0;

        int sig_opcion;
        const char *op_cortas = "hd:p:v";
        const struct option op_largas[] = {
            { "help",    0, NULL,  'h'},
            { "domain",  1, NULL,  'd'},
            { "port",    1, NULL,  'p'},
            { "verbose", 0, NULL,  'v'}
            { NULL,      0, NULL,  '\0'}
        };


        program_name = argv[0];

        do{

            sig_opcion = getopt_long(op_cortas, op_largas, argc, argv, NULL);

            switch (sig_opcion){
                case 'h':
                    print_usage(stdout, EXIT_SUCCESS)
                    break;
                case 'v':
                	verbose = 1;
                	break;
                case 'd':
                	servidor = optarg;
                    break;
                case 'p':
                	strncpy(puerto, optarg, N);
                    break;
                case INVALOPC:
                	print_usage(stderr, EXIT_FAILURE);
                    break;
                case NOMASOPC:
                    break;
                default:
                    abort();
            }

        } while (sig_opcion);

        if(servidor == NULL){
        	fprintf(stderr, "you have to specify a mail server. \n");
        	print_usage(stderr, EXIT_FAILURE);
        }

        if(optind >= argc){
        	fprintf(stderr,"you have to specify an email file.\n" );
        	print_usage(stderr, EXIT_FAILURE);
        }


        sprintf(mailmando, MAILMANDO,
        		argv[optind],
        		servidor,
        		puerto); //El resultado del printf lo va a meter en mailmando cambiando los %s por los valores dados

        if(verbose)
        	printf("Command: %s\n", mailmando);

        system (mailmando);

        return EXIT_SUCCESS;
}

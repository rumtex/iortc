#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{

    int opt;
    while ((opt = getopt(argc, argv, "fc:")) != -1) {
        switch (opt) {
        case 'c':
            printf("config path = %s\n", optarg);
            break;
        case 'f':
            printf("i'mma watchdog! and follow logs..\n");
            break;
        default:
            fprintf(stderr, "Usage: %s [-f] [-c path]\n", argv[0]);
            return -1;
        }
    }

    return 0;
}
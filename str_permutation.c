#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int i, j;
    
    const char *top = "Such permutation.";
    const char *fail = "No permutation.";
    
    if (argc < 3) {
        printf("Usage: %s str1 str2\n", argv[0]);
        return 0;
    }
    if (strlen(argv[1]) != strlen(argv[2])) {
        printf("%s\n", fail);
        return 0;
    }
    
    int len = strlen(argv[1]);
    for (i = 0; (i < len - 1) && (strcmp(argv[1], argv[2]) != 0); i++) {
        for (j = i; j < len; j++) {
            if (argv[2][j] == argv[1][i]) {
                char x = argv[2][i];
                argv[2][i] = argv[2][j];
                argv[2][j] = x;
                break;
            }
        }
    }
        
    if (strcmp(argv[1], argv[2]) == 0) {
        printf("%s\n", top);
    } else {
        printf("%s\n", fail);
    }
    return 0;
}
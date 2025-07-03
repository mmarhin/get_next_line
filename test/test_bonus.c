#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line_bonus.h"

int main()
{
    int fd1, fd2, fd3;
    char *line;

    printf("=== PRUEBAS GET_NEXT_LINE BONUS ===\n");
    printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);

    // Abrir múltiples archivos
    fd1 = open("archivo_a.txt", O_RDONLY);
    fd2 = open("archivo_b.txt", O_RDONLY);
    fd3 = open("sin_newline.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
    {
        printf("Error: no se pudieron abrir los archivos\n");
        return 1;
    }

    printf("\nPrueba 1: Lectura alternada de 3 archivos\n");
    printf("fd1=%d, fd2=%d, fd3=%d\n\n", fd1, fd2, fd3);

    // Leer alternadamente
    for (int i = 1; i <= 4; i++)
    {
        printf("Ronda %d:\n", i);
        
        line = get_next_line(fd1);
        printf("  fd1: %s", line ? line : "(NULL)");
        if (line && strlen(line) > 0 && line[strlen(line) - 1] != '\n')
            printf(" (sin \\n)");
        printf("\n");
        if (line) free(line);

        line = get_next_line(fd2);
        printf("  fd2: %s", line ? line : "(NULL)");
        if (line && strlen(line) > 0 && line[strlen(line) - 1] != '\n')
            printf(" (sin \\n)");
        printf("\n");
        if (line) free(line);

        line = get_next_line(fd3);
        printf("  fd3: %s", line ? line : "(NULL)");
        if (line && strlen(line) > 0 && line[strlen(line) - 1] != '\n')
            printf(" (sin \\n)");
        printf("\n");
        if (line) free(line);

        printf("\n");
    }

    close(fd1);
    close(fd2);
    close(fd3);

    printf("Prueba 2: Mismo archivo, múltiples FDs\n");
    fd1 = open("archivo_normal.txt", O_RDONLY);
    fd2 = open("archivo_normal.txt", O_RDONLY);

    if (fd1 != -1 && fd2 != -1)
    {
        printf("fd1=%d, fd2=%d (mismo archivo)\n", fd1, fd2);
        
        line = get_next_line(fd1);
        printf("fd1 primera: %s", line ? line : "(NULL)");
        if (line) free(line);

        line = get_next_line(fd2);
        printf("fd2 primera: %s", line ? line : "(NULL)");
        if (line) free(line);

        line = get_next_line(fd1);
        printf("fd1 segunda: %s", line ? line : "(NULL)");
        if (line) free(line);

        close(fd1);
        close(fd2);
    }

    printf("\n=== FIN DE PRUEBAS BONUS ===\n");
    return 0;
}

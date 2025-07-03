#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

void test_archivo(char *filename)
{
    int fd;
    char *line;
    int count = 0;

    printf("\n--- Probando: %s ---\n", filename);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        printf("Error: no se pudo abrir %s\n", filename);
        return;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        count++;
        printf("Línea %d: %s", count, line);
        if (strlen(line) > 0 && line[strlen(line) - 1] != '\n')
            printf(" (sin \\n)");
        printf("\n");
        free(line);
    }
    
    if (count == 0)
        printf("Archivo vacío\n");
    
    close(fd);
}

int main()
{
    printf("=== PRUEBAS GET_NEXT_LINE BÁSICO ===\n");
    printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);

    test_archivo("archivo_normal.txt");
    test_archivo("archivo_vacio.txt");
    test_archivo("sin_newline.txt");
    test_archivo("linea_larga.txt");

    printf("\n=== FIN DE PRUEBAS ===\n");
    return 0;
}

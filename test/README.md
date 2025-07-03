# TESTS GET_NEXT_LINE

## Archivos incluidos:

### Código fuente:
- `get_next_line.h` - Header versión normal
- `get_next_line.c` - Función principal versión normal  
- `get_next_line_utils.c` - Utilidades versión normal
- `get_next_line_bonus.h` - Header versión bonus
- `get_next_line_bonus.c` - Función principal versión bonus
- `get_next_line_utils_bonus.c` - Utilidades versión bonus

### Tests:
- `test_basico.c` - Test para versión normal
- `test_bonus.c` - Test para versión bonus

### Archivos de prueba:
- `archivo_normal.txt` - Archivo con 3 líneas normales
- `archivo_vacio.txt` - Archivo completamente vacío
- `sin_newline.txt` - Archivo con línea sin \n final
- `archivo_a.txt` - Archivo A (2 líneas) para test bonus
- `archivo_b.txt` - Archivo B (3 líneas) para test bonus
- `linea_larga.txt` - Archivo con línea muy larga

## Comandos para compilar y ejecutar:

### Test básico (versión normal):
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 test_basico.c get_next_line.c get_next_line_utils.c -o test_basico
./test_basico
```

### Test bonus (múltiples FD):
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 test_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c -o test_bonus
./test_bonus
```

### Probar con diferentes BUFFER_SIZE:
```bash
# Buffer muy pequeño
gcc -D BUFFER_SIZE=1 test_basico.c get_next_line.c get_next_line_utils.c -o test_buffer1
./test_buffer1

# Buffer mediano
gcc -D BUFFER_SIZE=10 test_basico.c get_next_line.c get_next_line_utils.c -o test_buffer10
./test_buffer10
```

## Qué prueban los tests:

### Test básico:
- Archivo con líneas normales
- Archivo vacío
- Archivo sin newline final
- Archivo con línea muy larga

### Test bonus:
- Lectura alternada de múltiples archivos
- Mismo archivo abierto con múltiples FDs
- Verificación de que cada FD mantiene su estado independiente

## Notas:
- Recuerda hacer `free()` de cada línea retornada
- El test bonus demuestra la capacidad de manejar múltiples archivos simultáneamente
- Diferentes BUFFER_SIZE ayudan a encontrar bugs relacionados con lectura incremental

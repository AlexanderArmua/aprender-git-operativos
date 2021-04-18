TARGET := aprender_c.out # Nombre del archivo al compilar 
LIBS := -lreadline -lcommons -lcspecs # Dependencias necesarias
CC := gcc # Compilador a utilizar
CFLAGS := -g -Wall # Flags en la comilación (g: Debug) (Wall: Muestra todos los warnings)

# Si hay archivos con nombres similares a alguna regla, que no asuma el argumento es el archivo.
.PHONY: default all clean

default: $(TARGET) # Regla por defecto "aprender_c"
all: default # Si ejecutan all va a default

# No entendi que hace: Constantes para generar los .o
OBJECTS := $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS := $(wildcard *.h)

# Menos entendi
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Si matan al make con ctrl-c nos permite mantener los archivos temporales terminados
.PRECIOUS: $(TARGET) $(OBJECTS)

# Tampoco entendi muy bien
# Le pasamos a la tarea los objects ya compilados
	# Usamos el compilador para linkear los objects a las bibliotecas y tener nuestro binario
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) $(LIBS) -o $@
	
clean: # Finalmente creamos una tarea para eliminar todos los .o y el binario
	-rm -f *.o
	-rm -f $(TARGET)
	
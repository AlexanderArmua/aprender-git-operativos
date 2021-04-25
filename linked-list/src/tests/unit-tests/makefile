# TESTS
RM=rm -rf
CC=gcc

C_SPEC=../../../../../cspec
C_SPEC_BIN=$(C_SPEC)/release

# Devuelve todos los archivos con la extensión ".c"
C_SRCS=$(shell find ../../../src -type f \( -iname "*.c" ! -iname "main.c" \) | tr '\n' ' ')
# Al armnar todos los archivos hay un problema y toma el main.c hay que asegurarse que estén todos en una ruta específica para buildear
OBJS=$(C_SRCS:./%.c=build/%.o)

PROJECT_ROUTE := ../../../src
PROJECT_NAME := boludeces-test

all: build/$(PROJECT_NAME)

# Crea la carpeta "build" el "-p" es para que si ya existia no de error
create-dirs:
	mkdir -p build

# Antes llamaba a compilar la cspecs pero se va a asumir instalada para evitar errores
build/$(PROJECT_NAME): dependents create-dirs $(OBJS)
	$(CC) -L"$(PROJECT_ROUTE)" -L"$(C_SPEC_BIN)" -o "build/$(PROJECT_NAME)" $(OBJS) -lcommons -lcspecs
	#gcc -L"../../../src" -L"../../../../../cspec/release" -o "build/boludeces-test" build/test_saraza.o -lcommons -lcspecs

build/%.o: ./%.c
	$(CC) -I"$(PROJECT_ROUTE)" -I"$(C_SPEC)" -c -fmessage-length=0 -fPIC -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"

debug: CC += -DDEBUG -g
debug: all

clean:
	$(RM) build

# Solo queremos correr los tests
test: all
	LD_LIBRARY_PATH="$(PROJECT_ROUTE)/build/:$(C_SPEC_BIN)" build/$(PROJECT_NAME)

# Hace build del proyecto principal
dependents:
	-cd $(PROJECT_ROUTE)/ && $(MAKE) all

valgrind: all
	LD_LIBRARY_PATH="$(PROJECT_ROUTE)/build/:$(C_SPEC_BIN)" valgrind --error-exitcode=42 --leak-check=full -v ./build/$(PROJECT_NAME)

.PHONY: all create-dirs clean install-cspec valgrind


#include <stdint.h>

#define 	CERO		0x00
#define 	MAX_NUM_CABINAS 8
#define 	MAX_NUM_PISOS	128

enum{BAJADA,SUBIDA,DETENIDA};
enum{CORRECTO,FALLA};

typedef struct{
	uint8_t piso;
	uint8_t	sentido;
	uint8_t	estado;

}cabina_t;

// Estructura con información de la cabina.
cabina_t cabinas[MAX_NUM_CABINAS];

// Vectores de de llamados de palieres y cabinas hasta 128 pisos (16x8).
uint8_t 	vector_llamados_cabinas[MAX_NUM_CABINAS][16];
uint8_t 	vector_llamados_externos_subida[16];
uint8_t 	vector_llamados_externos_bajada[16];

// Función para inicializar los vectores con ceros
void inicializar_vectores(void);

// Función para cargar un nuevo llamado de una determinada cabina
// Retorna: -1 si piso 	 > MAX_NUM_PISOS
// 	    -1 si cabina > MAX_NUM_CABINAS
//	     0 si se cargó correctamente	
int8_t cargar_llamado_interno(uint8_t piso, uint8_t cabina);

// Función para cargar un nuevo llamado desde los palieres
// Retorna: -1 si piso 	 > MAX_NUM_PISOS
// 	    -1 si sentido != BAJADA o SUBIDA
//	     0 si se cargó correctamente
int8_t cargar_llamado_externo(uint8_t piso, uint8_t sentido);

//Función que da valores iniciales a la estrictura de las cabinas.
void inicializar_estructura_cabina(cabina_t *cabina);

// Función para cargar posición de la cabina
// Argumentos: 	piso: planta en que se encuentra la cabina
//		sentido: sentido de circulación de la cabina.
//		cabina: estructura de la cabina
// Retorna: -1 si piso 	 > MAX_NUM_PISOS
// 	    -1 si sentido != BAJADA, SUBIDA o DETENIDA
//	     0 si se cargó correctamente
int8_t cargar_posicion_cabina(uint8_t piso,uint8_t sentido,cabina_t *cabina);

// Función para obtener posición de la cabina
int8_t leer_piso_cabina(cabina_t *cabina);

// Función para obtener sentido de la cabina
int8_t leer_sentido_cabina(cabina_t *cabina);

// Función para obtener estado de la cabina
int8_t leer_estado_cabina(cabina_t *cabina);

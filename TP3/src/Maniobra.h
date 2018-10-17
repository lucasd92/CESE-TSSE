#include <stdint.h>

#define 	CERO		0x00
#define 	MAX_NUM_CABINAS 8
#define 	MAX_NUM_PISOS	128

enum{BAJADA,SUBIDA};

uint8_t 	vector_llamados_cabinas[MAX_NUM_CABINAS][16];
uint8_t 	vector_llamados_externos_subida[16];
uint8_t 	vector_llamados_externos_bajada[16];

void inicializar_vectores(void);

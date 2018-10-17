#include "Maniobra.h"


void inicializar_vectores(void){
	uint8_t i,j;
	
	for(i = 0; i < MAX_NUM_CABINAS; i++){
		for(j = 0; j < 16; j++){
			vector_llamados_cabinas[i][j] = CERO;
		}
	}
	
	for(j = 0; j < 16; j++){
		vector_llamados_externos_subida[j] = CERO;
		vector_llamados_externos_bajada[j] = CERO;
	}
	
}



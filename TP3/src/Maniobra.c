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


int8_t cargar_llamado_interno(uint8_t piso, uint8_t cabina){
	uint8_t cociente;
	uint8_t resto;
	
	if(piso >= MAX_NUM_PISOS){
		return -1;
	}
	if(cabina >= MAX_NUM_CABINAS){
		return -1;
	}
	cociente = piso / 8;
	resto = piso % 8;
	//pongo en 1 la ubicación correspondiente
	vector_llamados_cabinas[cabina][cociente] |= 1 << resto;
	
	return 0;
}

int8_t cargar_llamado_externo(uint8_t piso, uint8_t sentido){
	uint8_t cociente;
	uint8_t resto;
	
	if(piso >= MAX_NUM_PISOS){
		return -1;
	}
	if((sentido != SUBIDA) && (sentido != BAJADA) ){
		return -1;
	}
	cociente = piso / 8;
	resto = piso % 8;
	if(sentido == BAJADA)
		vector_llamados_externos_bajada[cociente] |= 1 << resto;
	else
		vector_llamados_externos_subida[cociente] |= 1 << resto;
	
	return 0;
}

void inicializar_estructura_cabina(cabina_t *cabina){
	cabina -> piso = 0xFF; 			// Un piso inválido indica que debe realizar maniobra de reconocimiento
	cabina -> sentido = DETENIDA;	// Por defecto inicia detenida
	cabina -> estado = CORRECTO;	// Debe inicial libre de fallas.
}

int8_t cargar_posicion_cabina(uint8_t piso,uint8_t sentido,cabina_t *cabina){
	
	if(piso >= MAX_NUM_PISOS){
		return -1;
	}
	if( cabina == 0 ){
		return -1;
	}
	if((sentido != SUBIDA) && (sentido != BAJADA) && (sentido != DETENIDA)){
		return -1;
	}
	
	cabina -> piso = piso;
	
	cabina -> sentido = sentido;
	
	return 0;
}

int8_t leer_piso_cabina(cabina_t *cabina){
	return cabina -> piso;
}

int8_t leer_sentido_cabina(cabina_t *cabina){
	return cabina -> sentido;
}

int8_t leer_estado_cabina(cabina_t *cabina){
	return cabina -> estado;
}
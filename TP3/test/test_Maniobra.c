#include "unity.h"
#include "Maniobra.h"

void setUp (void){
	uint8_t i,j;
	
	for(i = 0; i < MAX_NUM_CABINAS; i++){
		for(j = 0; j < 16; j++){
			vector_llamados_cabinas[i][j] = 0xFF;
		}
	}
	
	for(j = 0; j < 16; j++){
		vector_llamados_externos_subida[j] = 0xFF;
		vector_llamados_externos_bajada[j] = 0xFF;
	}
}


void test_inicializacion_vectores(void){
	uint8_t i,j;
	
	inicializar_vectores();
	
	for(i = 0; i < MAX_NUM_CABINAS; i++){
		for(j = 0; j < 16; j++){
			TEST_ASSERT_EQUAL(CERO, 0xFF & vector_llamados_cabinas[i][j]);
		}
	}
	
	for(j = 0; j < 16; j++){
		TEST_ASSERT_EQUAL(CERO, 0xFF & vector_llamados_externos_subida[j]);
		TEST_ASSERT_EQUAL(CERO, 0xFF & vector_llamados_externos_bajada[j]);
	}
}

void test_falla_llamado_interno_pisos(void){

	//Compruebo que falle si piso > MAX_NUM_PISOS
	TEST_ASSERT_EQUAL(-1,cargar_llamado_interno(130, 1));

}

void test_falla_llamado_interno_cabinas(void){

	//Compruebo que falle si piso > MAX_NUM_CABINAS
	TEST_ASSERT_EQUAL(-1,cargar_llamado_interno(5, 9));

}

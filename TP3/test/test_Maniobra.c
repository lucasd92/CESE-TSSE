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

void test_correcto_llamado_interno(void){
	
	inicializar_vectores();
	
	//Compruebo que devuelva 0 si los argumentos son correctos
	TEST_ASSERT_EQUAL(0,cargar_llamado_interno(5, 1));
	//Compruebo que se haya cargado correctamente el llamado.
	TEST_ASSERT_EQUAL((1 << 5),vector_llamados_cabinas[1][0]);

}

void test_falla_llamado_externo_pisos(void){

	//Compruebo que falle si piso > MAX_NUM_PISOS
	TEST_ASSERT_EQUAL(-1,cargar_llamado_externo(130, 1));

}

void test_falla_llamado_externo_sentido(void){

	//Compruebo que falle si piso > MAX_NUM_PISOS
	TEST_ASSERT_EQUAL(-1,cargar_llamado_externo(10, 5));

}

void test_correcto_llamado_externo(void){
	
	inicializar_vectores();
	
	//Compruebo que devuelva 0 si los argumentos son correctos
	TEST_ASSERT_EQUAL(0,cargar_llamado_externo(10, SUBIDA));
	//Compruebo que se haya cargado correctamente el llamado.
	TEST_ASSERT_EQUAL((1 << 2),vector_llamados_externos_subida[1]);

}

void test_correcto_inicializacion_estructura_cabinas(void){
	
	inicializar_estructura_cabina(&cabinas[0]);
	TEST_ASSERT_EQUAL(0xFF,cabinas[0].piso);
	TEST_ASSERT_EQUAL(DETENIDA,cabinas[0].sentido);
	TEST_ASSERT_EQUAL(CORRECTO,cabinas[0].estado);
}

void test_falla_carga_posicion_cabina_pisos(void){
	inicializar_estructura_cabina(&cabinas[0]);
	
	TEST_ASSERT_EQUAL(-1,cargar_posicion_cabina(128,BAJADA,&cabinas[0]));

}

void test_falla_carga_posicion_cabina_sentido(void){
	inicializar_estructura_cabina(&cabinas[0]);
	
	TEST_ASSERT_EQUAL(-1,cargar_posicion_cabina(2,5,&cabinas[0]));

}


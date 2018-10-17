#include "build/temp/_test_Maniobra.c"
#include "Maniobra.h"
#include "unity.h"


void setUp (void){

 uint8_t i,j;



 for(i = 0; i < 8; i++){

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



 for(i = 0; i < 8; i++){

  for(j = 0; j < 16; j++){

   UnityAssertEqualNumber((UNITY_INT)((0x00)), (UNITY_INT)((0xFF & vector_llamados_cabinas[i][j])), (

  ((void *)0)

  ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

  }

 }



 for(j = 0; j < 16; j++){

  UnityAssertEqualNumber((UNITY_INT)((0x00)), (UNITY_INT)((0xFF & vector_llamados_externos_subida[j])), (

 ((void *)0)

 ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((0x00)), (UNITY_INT)((0xFF & vector_llamados_externos_bajada[j])), (

 ((void *)0)

 ), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

 }

}



void test_falla_llamado_interno_pisos(void){





 UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((cargar_llamado_interno(130, 1))), (

((void *)0)

), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);



}



void test_falla_llamado_interno_cabinas(void){





 UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((cargar_llamado_interno(5, 9))), (

((void *)0)

), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);



}



void test_correcto_llamado_interno(void){



 inicializar_vectores();





 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cargar_llamado_interno(5, 1))), (

((void *)0)

), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((UNITY_INT)(((1 << 5))), (UNITY_INT)((vector_llamados_cabinas[1][0])), (

((void *)0)

), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);



}



void test_falla_llamado_externo_pisos(void){





 UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((cargar_llamado_externo(130, 1))), (

((void *)0)

), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_INT);



}



void test_falla_llamado_externo_sentido(void){





 UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((cargar_llamado_externo(10, 5))), (

((void *)0)

), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);



}



void test_correcto_llamado_externo(void){



 inicializar_vectores();





 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cargar_llamado_externo(10, SUBIDA))), (

((void *)0)

), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_INT);



 UnityAssertEqualNumber((UNITY_INT)(((1 << 2))), (UNITY_INT)((vector_llamados_externos_subida[1])), (

((void *)0)

), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);



}



void test_correcto_inicializacion_estructura_cabinas(void){



 inicializar_estructura_cabina(&cabinas[0]);

 UnityAssertEqualNumber((UNITY_INT)((0xFF)), (UNITY_INT)((cabinas[0].piso)), (

((void *)0)

), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((DETENIDA)), (UNITY_INT)((cabinas[0].sentido)), (

((void *)0)

), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((CORRECTO)), (UNITY_INT)((cabinas[0].estado)), (

((void *)0)

), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_INT);

}



void test_falla_carga_posicion_cabina_pisos(void){

 inicializar_estructura_cabina(&cabinas[0]);



 UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((cargar_posicion_cabina(128,BAJADA,&cabinas[0]))), (

((void *)0)

), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_INT);



}



void test_falla_carga_posicion_cabina_sentido(void){

 inicializar_estructura_cabina(&cabinas[0]);



 UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((cargar_posicion_cabina(2,5,&cabinas[0]))), (

((void *)0)

), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_INT);



}



void test_falla_carga_posicion_cabina_puntero(void){

 inicializar_estructura_cabina(&cabinas[0]);



 UnityAssertEqualNumber((UNITY_INT)((-1)), (UNITY_INT)((cargar_posicion_cabina(2,BAJADA,(void*) 0))), (

((void *)0)

), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_INT);



}



void test_correcto_carga_posicion_cabina(void){

 inicializar_estructura_cabina(&cabinas[0]);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((cargar_posicion_cabina(2,BAJADA,&cabinas[0]))), (

((void *)0)

), (UNITY_UINT)(119), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((BAJADA)), (UNITY_INT)((cabinas[0].sentido)), (

((void *)0)

), (UNITY_UINT)(120), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((cabinas[0].piso)), (

((void *)0)

), (UNITY_UINT)(121), UNITY_DISPLAY_STYLE_INT);

}



void test_correcto_leer_posicion_cabina(void){

 cargar_posicion_cabina(2,BAJADA,&cabinas[0]);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((leer_piso_cabina(&cabinas[0]))), (

((void *)0)

), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_INT);

}



void test_correcto_leer_sentido_cabina(void){

 cargar_posicion_cabina(2,BAJADA,&cabinas[0]);

 UnityAssertEqualNumber((UNITY_INT)((BAJADA)), (UNITY_INT)((leer_sentido_cabina(&cabinas[0]))), (

((void *)0)

), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_INT);

}



void test_correcto_leer_estado_cabina(void){

 inicializar_estructura_cabina(&cabinas[0]);

 UnityAssertEqualNumber((UNITY_INT)((CORRECTO)), (UNITY_INT)((leer_estado_cabina(&cabinas[0]))), (

((void *)0)

), (UNITY_UINT)(136), UNITY_DISPLAY_STYLE_INT);



 cabinas[0].estado = FALLA;

 UnityAssertEqualNumber((UNITY_INT)((FALLA)), (UNITY_INT)((leer_estado_cabina(&cabinas[0]))), (

((void *)0)

), (UNITY_UINT)(139), UNITY_DISPLAY_STYLE_INT);

}

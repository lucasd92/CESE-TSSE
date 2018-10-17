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

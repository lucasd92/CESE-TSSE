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

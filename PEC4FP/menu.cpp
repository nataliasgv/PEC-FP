#include <stdio.h>
#include <string.h>
#include "menu.h"

void menu::inicializar(){
    gesRAE.init();
}

void menu::menuPrincipal(){

  char input;

  do{

    printf("GesRAE: Gestión de Reservas Apartamentos-Edificios \n");
    printf("\n");
    printf("    Editar Edificio                   (Pulsar E) \n");
    printf("    Listar Edificios                  (Pulsar L) \n");
    printf("    Apartamentos Disponibles          (Pulsar A) \n");
    printf("    Reservar Apartamento              (Pulsar R) \n");
    printf("    Reservas Mensuales Apartamento    (Pulsar M) \n");
    printf("    Salir                             (Pulsar S) \n");
    printf("\n");
    printf("Teclear una opción válida\n");

    scanf(" %c" , &input);

    switch(input){
      case 'E':
        menuEditarEdif();
      break;
      case 'L':
        menuListEdifs();
      break;
      case 'A':
        menuApartsLibres();
      break;
      case 'R':
        menuResApart();
      break;
      case 'M':
        /*menuResMens();*/
      break;
      case 'S':
        printf("Saliendo del programa");
      break;
      default:
      printf("Opción no valida");
      }
    }while(input != 'S');
  }


void menu::menuEditarEdif(){

  char control;
  tipoString nombre;
  int id, numBasicos, numNormales, numLujos;

      printf("Editar Edificio: \n");
      printf("    Identificador(número entre 1 y 5)?");
      scanf("%d" , &id);
      printf("\n");

      printf("    Nombre(entre 1 y 20 caracteres)?");
      scanf("%20s" , &nombre);
      printf("\n");

      printf("    Numero de apartamentos Básicos?");
      scanf("%d" , &numBasicos);
      printf("\n");

      printf("    Numero de apartamentos Normales?");
      scanf("%d" , &numNormales);
      printf("\n");

      printf("    Numero de apartamentos de Lujo?");
      scanf("%d" , &numLujos);
      printf("\n");

      printf("IMPORTANTE: Esta opción borra los datos anteriores. \n");
      printf("Son correctos sus nuevos datos(S/N)? \n");
      scanf(" %c" , &control);
      printf("\n");

      if(control == 'S'){
        gesRAE.editarEdif(id, nombre, numBasicos, numNormales, numLujos);
        printf("Los datos se han guardado");
        menuPrincipal();
      }else{
        printf("Los datos no se han guardado\n");
        menuPrincipal();
        };
}

void menu::menuListEdifs(){
  gesRAE.listarEdifs();
  menuPrincipal();
  }

void menu::menuApartsLibres(){

  int id, dia, mes, anno, duracion;

  printf("Apartamentos disponibles: \n");
  printf("    Identificador del edificio?");
  scanf(" %d", &id);
  printf("\n");

  printf("    Fecha de Entrada: Dia?");
  scanf(" %d", &dia);
  printf("\n");

  printf("    Fecha de Entrada: Mes?");
  scanf(" %d", &mes);
  printf("\n");

  printf("    Fecha de Entrada: Año?");
  scanf(" %d", &anno);
  printf("\n");

  printf("    Dias de duracion de la estancia?");
  scanf(" %d", &duracion);
  printf("\n");

  gesRAE.listarApartsLibres(id, dia, mes, anno, duracion);

  menuPrincipal();
  }

void menu::menuResApart(){

  int id, dia, mes, anno, duracion;
  char tipo;
  TipoTipoApart tipoApart;

  printf("Reservar apartamento: \n");

  printf("    Identificador del edificio?");
  scanf(" %d", &id);
  printf("\n");

  printf("Tipo de Apartamento (B-Basico/N-Normal/L-Lujo)?");
  scanf(" %c", &tipo);
  printf("\n");

  printf("    Fecha de Entrada: Dia?");
  scanf(" %d", &dia);
  printf("\n");

  printf("    Fecha de Entrada: Mes?");
  scanf(" %d", &mes);
  printf("\n");

  printf("    Fecha de Entrada: Año?");
  scanf(" %d", &anno);
  printf("\n");

  printf("    Dias de duracion de la estancia?");
  scanf(" %d", &duracion);
  printf("\n");

  switch(tipo){

    case 'B':
      tipoApart = Basico;
      gesRAE.reservarApart(id, tipoApart, dia, mes, anno, duracion);
      menuPrincipal();
      break;

    case 'N':
      tipoApart = Normal;
      gesRAE.reservarApart(id, tipoApart, dia, mes, anno, duracion);
      menuPrincipal();
      break;

    case 'L':
      tipoApart = Lujo;
      gesRAE.reservarApart(id, tipoApart, dia, mes, anno, duracion);
      menuPrincipal();
      break;

    default:
    printf("Opción no valida");
    menuPrincipal();

    }
  }




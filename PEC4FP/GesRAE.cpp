
#include <stdio.h>
#include <string.h>
#include "GesRAE.h"


void GesRAE::init(){
  numReservas=1;

  for(int i = 0; i < maxEdifs; i++ ){
    listaEdifs[i].numAparts = 0;
    listaEdifs[i].numBasicos = 0;
    listaEdifs[i].numNormales = 0;
    listaEdifs[i].numLujos = 0;
    listaEdifs[i].numBasLibres = 0;
    listaEdifs[i].numNorLibres = 0;
    listaEdifs[i].numLujLibres = 0;
    listaEdifs[i].idEdif = i + 1;
    strcpy(listaEdifs[i].nombre, "EdifDeBaja");

    for(int k = 0; k < maxAparts; k ++){
      strcpy(listaEdifs[i].listaAparts[k].refApart, "APT00X00");

      for(int n = 0; n < 10; n++){
        listaEdifs[i].listaAparts[k].listaReservas[n].fechaEntrada.dia = 0;
        listaEdifs[i].listaAparts[k].listaReservas[n].fechaEntrada.mes = 1;
        listaEdifs[i].listaAparts[k].listaReservas[n].fechaEntrada.anno = 0;
        listaEdifs[i].listaAparts[k].listaReservas[n].duracion = 0;
        }
      }
    }
  }

/*Busca un edificio segun su identificador en la lista de edificios*/
int GesRAE::buscarEdif( int ident ) {
  for (int pos = 0; pos < numEdifs; pos++) {
    if (listaEdifs[pos].idEdif == ident){
        return pos;
      }
    }
    return -1; /*retorna -1 si el edifico no se ha encontrado*/
  }

  /*crea la referencia de cada apartamento de un edificio*/
void GesRAE::referenciaApart(int idEdif){

  int pos = buscarEdif(idEdif);

  if(pos != -1){
      for(int i = 0; i < listaEdifs[pos].numAparts; i++){

        if (listaEdifs[pos].listaAparts[i].tipoApart == Basico) {

          sprintf(listaEdifs[pos].listaAparts[i].refApart, "APT%02dB%02d", idEdif, i + 1);
        }else{
          if (listaEdifs[pos].listaAparts[i].tipoApart == Normal) {

            sprintf(listaEdifs[pos].listaAparts[i].refApart, "APT%02dN%02d", pos + 1, i + 1);
          }else{
           if (listaEdifs[pos].listaAparts[i].tipoApart == Lujo) {

            sprintf(listaEdifs[pos].listaAparts[i].refApart, "APT%02dL%02d", pos + 1, i + 1);
            }
          }
        }
      }
    }
  }

/*Edita los datos del edificio introducido*/
 void GesRAE::editarEdif(int id, tipoString nom, int basicos, int normales, int lujos) {
  int pos = buscarEdif(id);
  if(pos != -1){
      strcpy(listaEdifs[pos].nombre , nom);
      listaEdifs[pos].numBasicos = basicos;
      listaEdifs[pos].numNormales = normales;
      listaEdifs[pos].numLujos = lujos;
      listaEdifs[pos].numAparts = basicos + normales + lujos;


      for(int i = 0; i<basicos; i++){
        listaEdifs[pos].listaAparts[i].tipoApart = Basico;
      }

      for(int i = basicos; i<basicos+normales; i++){
        listaEdifs[pos].listaAparts[i].tipoApart = Normal;
      }

      for(int i = basicos+normales; i<basicos+normales+lujos; i++){
        listaEdifs[pos].listaAparts[i].tipoApart = Lujo;
      }

      referenciaApart(id);
    }
    else{
      printf("Edificio no encontrado \n");
    }
  }


/*por cada elemento de la lista de edificios que vaya imprimiendo cada edificio*/
void GesRAE::listarEdifs(){
  for (int pos = 0; pos < maxEdifs; pos++){
    printf("Id     Nombre     Aptos Basicos     Aptos Normales     Aptos de Lujo \n");
    printf("%d      %s             %d                 %d                 %d\n" ,pos + 1, listaEdifs[pos].nombre, listaEdifs[pos].numBasicos, listaEdifs[pos].numNormales, listaEdifs[pos].numLujos);
    }
  }

/*Se asegura de que la fecha es valida*/
bool GesRAE::fechaReal(int dia, int mes, int anno){

bool real;

  if (anno >= 1601 && anno <= 3000) {

    if(mes >= 1 && mes<= 12){


      if((dia >= 1 && dia <= 28)&&(mes == 2)){
        real = true;
        }
      else if((dia >= 1 && dia <= 30)&&(mes == 4 || mes == 6 || mes == 9 || mes == 11)){
        real = true;
      }
      else if((dia >= 1 && dia <= 31)&&(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)){
        real = true;
      }
      else if(dia ==29 && mes == 2&&((anno % 4 == 0) && (anno % 100 != 0)) || (anno % 400 == 0)){
        real = true;
      }
      else{
      real = false;
      }
    }
    else{
      real = false;
      }
  }
  else{
      real = false;
      }
  return real;
}

/*devuelve -1 si la primera fecha es anterior, 1 si es mayor y 0 si son iguales*/
int GesRAE::compararFechas(int dia1, int mes1, int anno1, int dia2, int mes2, int anno2){
  if(anno1 < anno2){
    return -1;
    }else if(anno1 > anno2){
      return 1;
      }else{
        if(mes1 < mes2){
          return -1;
          }else if(mes1 > mes2){
            return 1;
            }else{
              if(dia1 < dia2){
                return -1;
                }else if(dia1 > dia2){
                  return 1;
              }else {
                return 0;
                }
            }
      }
}

/*convierte la fecha en un numero de dias*/
int GesRAE::diasFecha(int dia, int mes, int anno){

  int dias = dia;
  int diasMes;


  /*establece el numero de dias de cada mes*/
  switch(mes){
    case 4: diasMes = 30;
    break;
    case 6: diasMes = 30;
    break;
    case 9: diasMes = 30;
    break;
    case 11: diasMes = 30;
    break;
    case 2:
    if((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)){
      diasMes = 29;
      }
    else{
      diasMes = 28;
      }
    break;
    default: diasMes = 31;
    }
  /*suma el dia al numero de dias del mes y lo guarda en dias*/
  for(int n =1; n<mes; n++){
    dias = dias + diasMes;
    }

  /*suma dias al numero de dias en el año*/
  for(int a = 1601; a<anno; a++){
    if((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0)){
      dias = dias + 366;
      }
     else{
       dias = dias + 365;
       }
    }
    return dias;
  }

/*retorna true si los periodos de reserva coinciden*/
bool GesRAE::coincidenciaFechas(int dia1, int mes1, int anno1, int duracion1, int dia2, int mes2, int anno2, int duracion2){

/*primero tine que ver que fecha1 sea anterior a fecha2*/
  int dia11;
  int mes11;
  int anno11;

  int dia22;
  int mes22;
  int anno22;

  int inic1;
  int fin1;
  int inic2;
  int fin2;

  if(compararFechas(dia1, mes1, anno1, dia2, mes2, anno2)== 1){
    dia11 = dia2;
    mes11 = mes2;
    anno11 = anno2;

    dia22 = dia1;
    mes22 = mes1;
    anno22 = anno1;
    }else{
      if(compararFechas(dia1, mes1, anno1, dia2, mes2, anno2)== -1){
        dia11 = dia1;
        mes11 = mes1;
        anno11 = anno1;

        dia22 = dia2;
        mes22 = mes2;
        anno22 = anno2;
        }else{
          return true; /*si ambas fechas son la misma los periodos coinciden*/
          }
      }


  inic1 = diasFecha(dia11, mes11, anno11);
  fin1 = inic1 + duracion1;
  inic2 = diasFecha(dia22, mes22, anno22);
  fin2 = inic2 + duracion2;

  /*si el inicio del primer periodo es antes del final del segundo y el inicio del segundo es antes del final del primero las fechas coinciden*/
  return(inic1 < fin2 && inic2 < fin1);
  }

/*método para reservar un apartamento*/
void GesRAE:: reservarApart(int idEdif, TipoTipoApart tipo, int dia1, int mes1, int anno1, int duracion1){
  int pos = buscarEdif(idEdif);

  int dia2;
  int mes2;
  int anno2;
  int duracion2;

  bool reservado;
  reservado = false; /*variable para cada apartamento*/

  if(pos != -1){

    edificio = listaEdifs[pos];

    switch(tipo){

      case Basico:
      completo = true;/*variable para ver si todos los apartamentos estan reservados*/

        for(int i = 0; i < edificio.numAparts; i++){
          if (edificio.listaAparts[i].tipoApart == Basico){

  /*mira cada una de las reservas de cada apartamento de un edificio y las compara con las dadas por el usuario*/
              for(int n = 0; n < 10; n++){
                dia2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.dia;
                mes2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.mes;
                anno2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.anno;
                duracion2 = edificio.listaAparts[i].listaReservas[n].duracion;

                if(coincidenciaFechas(dia1, mes1, anno1, duracion1, dia2, mes2, anno2, duracion2)== false && reservado == false){

                  edificio.listaAparts[i].listaReservas[n].fechaEntrada.dia = dia1;
                  edificio.listaAparts[i].listaReservas[n].fechaEntrada.mes = mes1;
                  edificio.listaAparts[i].listaReservas[n].fechaEntrada.anno = anno1;
                  edificio.listaAparts[i].listaReservas[n].duracion = duracion1;

                  printf("Apartamento reservado con exito \n");
                  reservado = true;
                  completo = false; /*hay un apartamento libre*/

                  printf("        Datos de la reserva: \n");
                  printf("\n");
                  printf("    Numero de Reserva: %d \n", numReservas);
                  printf("    Edificio: %s (Id=%d)\n", edificio.nombre, idEdif);
                  printf("    Referencia Apartamento: %s \n", edificio.listaAparts[i].refApart);
                  printf("    Fecha Entrada: %d/%d/%d \n", dia1, mes1, anno1);
                  printf("    Duracion estancia: %d \n", duracion1);
                  numReservas++;
                  }
              }
          }
        }
        if(completo){
          printf("Todos los apartamentos Basicos están reservados en la fecha introducida");
          }
        break;
        case Normal:
          completo = true;

          for(int i = 0; i < edificio.numAparts; i++){

          if (edificio.listaAparts[i].tipoApart == Normal) {

              for(int n = 0; n < 10; n++){
                dia2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.dia;
                mes2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.mes;
                anno2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.anno;
                duracion2 = edificio.listaAparts[i].listaReservas[n].duracion;

                if(coincidenciaFechas(dia1, mes1, anno1, duracion1, dia2, mes2, anno2, duracion2)== false && reservado == false){
                  edificio.listaAparts[i].listaReservas[n].fechaEntrada.dia = dia1;
                  edificio.listaAparts[i].listaReservas[n].fechaEntrada.mes = mes1;
                  edificio.listaAparts[i].listaReservas[n].fechaEntrada.anno = anno1;
                  edificio.listaAparts[i].listaReservas[n].duracion = duracion1;

                  printf("Apartamento reservado con exito \n");
                  reservado = true;
                  completo = false;

                  printf("        Datos de la reserva: \n");
                  printf("\n");
                  printf("    Numero de Reserva: %d \n", numReservas);
                  printf("    Edificio: %s (Id=%d)\n", edificio.nombre, idEdif);
                  printf("    Referencia Apartamento: %s \n", edificio.listaAparts[i].refApart);
                  printf("    Fecha Entrada: %d/%d/%d \n", dia1, mes1, anno1);
                  printf("    Duracion estancia: %d \n", duracion1);

                  numReservas++;
                  }
              }
            }
        }
        if(completo){
          printf("Todos los apartamentos Normales están reservados en la fecha introducida");
          }
        break;
        case Lujo:
         completo = true;

          for(int i = 0; i < edificio.numAparts; i++){

          if (edificio.listaAparts[i].tipoApart == Lujo) {

              for(int n = 0; n < 10; n++){
                dia2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.dia;
                mes2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.mes;
                anno2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.anno;
                duracion2 = edificio.listaAparts[i].listaReservas[n].duracion;

                if(coincidenciaFechas(dia1, mes1, anno1, duracion1, dia2, mes2, anno2, duracion2)== false && reservado == false){
                  edificio.listaAparts[i].listaReservas[n].fechaEntrada.dia = dia1;
                  edificio.listaAparts[i].listaReservas[n].fechaEntrada.mes = mes1;
                  edificio.listaAparts[i].listaReservas[n].fechaEntrada.anno = anno1;
                  edificio.listaAparts[i].listaReservas[n].duracion = duracion1;

                  printf("Apartamento reservado con exito \n");
                  reservado = true;
                  completo = false;

                  printf("        Datos de la reserva: \n");
                  printf("\n");
                  printf("    Numero de Reserva: %d \n", numReservas);
                  printf("    Edificio: %s (Id=%d)\n", edificio.nombre, idEdif);
                  printf("    Referencia Apartamento: %s \n", edificio.listaAparts[i].refApart);
                  printf("    Fecha Entrada: %d/%d/%d \n", dia1, mes1, anno1);
                  printf("    Duracion estancia: %d \n", duracion1);

                  numReservas++;
                  }
              }
            }
        }
        if(completo){
          printf("Todos los apartamentos de Lujo están reservados en la fecha introducida");
          }
        break;
      }
    }
    else{
      printf("Edificio no encontrado \n");
      }
  }



void GesRAE::listarApartsLibres(int idEdif, int dia1, int mes1, int anno1, int duracion1){
  int pos = buscarEdif(idEdif);

  int dia2;
  int mes2;
  int anno2;
  int duracion2;

  TipoTipoApart tipoApartamento;

  bool libre;
  libre = false;

  if(pos != -1){/*el edifificio existe*/
    edificio = listaEdifs[pos];

    edificio.numBasLibres = 0;
    edificio.numNorLibres = 0;
    edificio.numLujLibres = 0;

    for(int i = 0; i < edificio.numAparts; i++){

      for(int n = 0; n < 10; n++){

          dia2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.dia;
          mes2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.mes;
          anno2 = edificio.listaAparts[i].listaReservas[n].fechaEntrada.anno;
          duracion2 = edificio.listaAparts[i].listaReservas[n].duracion;

          if(coincidenciaFechas(dia1, mes1, anno1, duracion1, dia2, mes2, anno2, duracion2)== false){

           libre = true;
          }
        }
        if(libre==true){

          tipoApartamento = edificio.listaAparts[i].tipoApart;

          switch(tipoApartamento){
               case Basico:
               edificio.numBasLibres++;
               break;
               case Normal:
               edificio.numNorLibres++;
               break;
               case Lujo:
               edificio.numLujLibres++;
               break;
            }
          libre=false;
      }
    } /*mira todas las reservas de los apartamentos y cuenta cuantos apartamentos hay libres en esa fecha*/

    printf("El edificio %s desde el %d/%d/%d y %d días de estancia, tendría disponibles: \n", edificio.nombre, dia1, mes1, anno1, duracion1 );
    printf("%d apartamentos tipo Básico \n", edificio.numBasLibres);
    printf("%d apartamentos tipo Normal \n", edificio.numNorLibres);
    printf("%d apartamentos tipo Lujo \n", edificio.numLujLibres);
  }
  else{
    printf("Edificio no encontrado \n");
    }
  }


void GesRAE::reservasMensApart(tipoString ref, int mes, int anno){

  }







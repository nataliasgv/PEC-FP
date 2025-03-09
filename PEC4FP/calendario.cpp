#include <stdio.h>
#include "calendario.h"


/*comprueba si es bisiesto*/
bool Calendario::bisiesto ( int anno ) {
	  return ((anno % 4 == 0) && (anno % 100 != 0)) || (anno % 400 == 0);
  }


/*suma un numero de dias a un dia de la semana y retrna el dia de la semana en el que cae*/
   TipoDia Calendario::sumarDias (TipoDia dia , int n) {

	   const  int DiasSem = 7;
	   int aux;

	   aux = (int (dia) + n ) % DiasSem;
	   return TipoDia (aux);
	   }

/*retorna el numero de dias del mes*/
   int Calendario::diasDelMes (TipoFecha fecha) {
     switch (fecha.mes) {
       case 2:
          if (bisiesto (fecha.anno)) {
            return (29);
          } else { return (28);
          };
          break;
        case 4:
        case 6:
        case 9:
          return (30);
          break;
        default:
          return (31);
       }
     }


/*retorna el dia de la semana de una fecha*/
   TipoDia Calendario::diaSemana ( TipoFecha fecha ) {

	   int mes = fecha.mes;
	   int a = fecha.anno;
	   int IncreDias, IncreAnnos, IncreBisies;
	   const int AnnoRef= 1601;
	   const TipoDia DiaReferencia = DO;

	   if (mes == 1) {
		   IncreDias = 0;
	   } else if (mes ==2){
		   IncreDias = 3;
	   } else if (mes == 3 ) {
		   IncreDias = 3;
	   } else if (mes == 4 ) {
		   IncreDias = 6;
	   } else if (mes == 5) {
		   IncreDias = 	1;
	   } else if (mes == 6) {
		   IncreDias =  4;
	   } else if (mes == 7) {
		   IncreDias = 6;
	   } else if (mes == 8) {
		   IncreDias = 2;
	   } else if (mes == 9) {
		   IncreDias = 5;
	   } else if (mes == 10) {
		   IncreDias = 0;
	   } else if (mes == 11) {
		   IncreDias = 3;
	   } else {
	     IncreDias = 5;
	   }

    IncreAnnos = a - AnnoRef;
    IncreBisies = 0;

    /*calcula cuantos años bisiestos ha habido desde el 1601*/
    for (int n=1602; n<a; n++) {
      if (bisiesto(n)) {
        IncreBisies ++;
        }
      }

      /*si el año es bisiesto y el mes posterior a feb incrementa IncreDias*/
       if ( bisiesto(a) && ( mes > 2 )) {
         IncreDias ++;
         }

       IncreDias = IncreDias + IncreAnnos + IncreBisies + fecha.dia;

      /*calcula el dia de la semana sumando el incremento*/
       return sumarDias(DiaReferencia, IncreDias);
    }

void Calendario::imprimirCalendario(int mes, int anno) {

if(mes>=1 && mes<=12 && anno>=1601 && anno<=3000){

    fecha.dia = 1;
    fecha.mes = mes;
    fecha.anno = anno;

    primerDia = diaSemana (fecha);

      printf ("\n");

      switch (fecha.mes) {
      case 1:
      printf ("ENERO     ");
      break;
      case 2:
      printf ("FEBRERO   ");
      break;
      case 3:
      printf ("MARZO     ");
      break;
      case 4:
      printf ("ABRIL     ");
      break;
      case 5:
      printf ("MAYO      ");
      break;
      case 6:
      printf ("JUNIO     ");
      break;
      case 7:
      printf ("JULIO                  %d\n", fecha.anno);
      break;
      case 8:
      printf ("AGOSTO                 %d\n", fecha.anno);
      break;
      case 9:
      printf ("SEPTIEMBRE             %d\n", fecha.anno);
      break;
      case 10:
      printf ("OCTUBRE                %d\n", fecha.anno);
      break;
      case 11:
      printf ("NOVIEMBRE              %d\n", fecha.anno);
      break;
      case 12:
      printf ("DICIEMBRE              %d\n", fecha.anno);
      break;
      }

      printf ("             ");
      printf ("%d\n", fecha.anno);
      printf ("===========================\n");
      printf ("LU  MA  MI  JU  VI | SA  DO\n");
      printf ("===========================\n");

    i = 0;

/*imprime tantos puntos como espacios haya hasta el primer dia de la semana del mes*/
    for (int k = int (primerDia); k >= 1; k --) {
      if (i % 7 == 5) {
        printf ("| ");/*si i es igual a 5, 12, etc se imprime una columna, queda impresa en la sexta pos de la semana*/
      }
      if ( i %7 != 0 && i % 7 != 5 ) {
      printf (" ");
      }
      printf (" . ");
      i ++;
    }
/*imprime lso dias del mes*/
    for (int k = 0; k < diasDelMes(fecha); k ++) {
      if (i != 0) {
        if (i % 7 == 0) {
          printf ("\n");/*al final de la semana se pone un salto de linea*/
        }
      }
       if (i % 7 == 5) {
        printf ("| ");/*sexta posicion, columna*/
      }
      if ( i %7 != 0 && i % 7 != 5 ) {/*no es primera pos de la semana ni sexta*/
      printf (" ");
      }
      printf ("%2d ", k+1 );/*ocupa dos espacios mas un espacio mas despues*/
      i ++;
    }

    while ( i % 7 != 0 ) {
      if (i % 7 == 5) {
        printf ("| ");
      }
      if ( i %7 != 0 && i % 7 != 5 ) {
        printf (" ");
      }
      printf (" . ");
      i ++;
    }
    printf ("\n");
  }else{
    printf("Fecha no válida");
    }
}

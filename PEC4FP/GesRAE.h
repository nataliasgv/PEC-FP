#pragma once
#include "calendario.h"


const int maxEdifs = 5;
const int maxAparts = 20;


/*creamos un vector de caracteres que haga de string para los nombres*/
typedef char tipoString[11];

typedef enum TipoTipoApart {
  Basico, Normal, Lujo
  };


/*struct del tipo Reserva*/
typedef struct TipoReserva{
  TipoFecha fechaEntrada;
  int duracion;
};

/*struct del TipoApartamento*/
typedef struct TipoApart{
  int idEdif;
  tipoString refApart;
  TipoTipoApart tipoApart;

  TipoReserva listaReservas[10];
  /*se eligen diez reservas maximas para hacer*/
};
/*struct TipoEdificio con la lista de apartamentos*/
typedef struct TipoEdif{
  int idEdif;
  int numBasicos;
  int numNormales;
  int numLujos;
  tipoString nombre;
  int numAparts;
  int numBasLibres;
  int numNorLibres;
  int numLujLibres;

  TipoApart listaAparts[maxAparts];

};


/*interfaz de los metodos*/
typedef struct GesRAE{
  void init();
  int buscarEdif(int ident);
  void editarEdif(int idEdif, tipoString nombre, int basicos, int normales, int lujos);
  void listarEdifs();
  void listarApartsLibres(int idEdif, int dia1, int mes1, int anno1, int duracion1);
  void reservarApart(int idEdif, TipoTipoApart tipo, int dia1, int mes1, int anno1, int duracion1);
  void referenciaApart(int idEdif);
  void reservasMensApart(tipoString Ref, int mes, int anno);
  int compararFechas(int dia1, int mes1, int anno1, int dia2, int mes2, int anno2);
  bool fechaReal(int dia, int mes, int anno);
  int diasFecha(int dia, int mes, int anno);
  bool coincidenciaFechas(int dia1, int mes1, int anno1, int duracion1, int dia2, int mes2, int anno2, int duracion2);


  private:
  TipoEdif listaEdifs[maxEdifs];
  int numEdifs;
  TipoEdif edificio;
  bool reservado; /*si un apartamento esta reservado en una fecha concreta*/
  bool completo; /*si todos los apartamentos estan reservados en una fecha concreta*/
  int numReservas;

};





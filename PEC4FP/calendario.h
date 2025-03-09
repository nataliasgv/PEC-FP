#pragma once

typedef enum TipoDia {LU, MA, MI, JU, VI, SA, DO};

typedef struct TipoFecha {
	  int dia;
    int mes;
	  int anno;
};

typedef struct Calendario{
  bool bisiesto ( int anno );
  int diasDelMes (TipoFecha fecha);
  TipoDia sumarDias (TipoDia dia , int n);
  TipoDia diaSemana ( TipoFecha fecha );

  void imprimirCalendario(int mes, int anno);

  private:
  int i;
  TipoFecha fecha;
  TipoDia primerDia;

};

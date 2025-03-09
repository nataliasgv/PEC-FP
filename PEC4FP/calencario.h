#pragma once

typedef enum TipoMes {
	 Enero, Febrero, Marzo, Abril, Mayo, Junio, Julio, Agosto,
	 Septiembre, Octubre, Noviembre, Diciembre};

	 typedef enum TipoDia {LU, MA, MI, JUs, VI, SA, DO};

  typedef struct TipoFecha {
	  int dia;
	  TipoMes mes;
	  int anno;
  };

  typedef struct Calendario{

  bool bisiesto ( int anno );
  TipoDia sumarDias (TipoDia dia , int n);
  TipoDia diaSemana ( TipoFecha fecha );
  int diasDelMes (TipoFecha fecha);

  void imprimirCalendario ();

  private:
  int i;
  TipoFecha fecha;
  TipoDia primerDia;

};


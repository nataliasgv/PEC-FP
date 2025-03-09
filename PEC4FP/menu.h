#pragma once
#include "GesRAE.h"


typedef struct menu{
  void inicializar();
  void volver();
  void menuPrincipal();
  void menuEditarEdif();
  void menuListEdifs();
  void menuApartsLibres();
  void menuResApart();
  void menuResMens();

  private:

  GesRAE gesRAE;

  };

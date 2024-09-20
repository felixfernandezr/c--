#ifndef TIPOSDOCUMENTOS_H_INCLUDED
#define TIPOSDOCUMENTOS_H_INCLUDED

enum tiposDocumentos { DNI, PASAPORTE, LCLE, CI, OTRO };

#define tDocATexto(td) ( td == DNI ? "DNI" : td == PASAPORTE ? "PASAPORTE" : td == LCLE ? "LCLE" : td == CI ? "CI" : td == OTRO ? "OTRO" : "#ERROR#" )

#endif // TIPOSDOCUMENTOS_H_INCLUDED

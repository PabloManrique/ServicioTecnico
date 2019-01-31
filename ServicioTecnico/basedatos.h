#ifndef BASEDATOS_H
#define BASEDATOS_H

#include
class BaseDatos
{

public:
    BaseDatos();
    Conectarbd();
    ModeloTel(QString modelo);
    InsertarInfo(QString uuid);
};

#endif // BASEDATOS_H

#ifndef BASEDATOS_H
#define BASEDATOS_H

#include <QString>
class BaseDatos
{

public:
    BaseDatos();
    void Conectarbd();
    void InformacionRep(QString);
    void InsertarInfo(QString uuid);
private:
    int Buscmodelo(QString modelo);
    int Busctienda(QString tienda);
};

#endif // BASEDATOS_H

#include "basedatos.h"

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QString>


BaseDatos::BaseDatos()
{

}

void Conectarbd(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPort(5432);
    db.setPassword("");
    db.setDatabaseName("serviciotecnico");
}

void InformacionRep(QString uuid){
    QSqlQuery qry;
    QVector<QString> select;
    int i = 0;
    bool encontrado;
    if (qry.exec("SELECT * FROM informacion WHERE uuid_informacion like "+ uuid)){
        while (qry.next()) {
            select[i] = qry.value(0).toString();
            i++;
        }
    }
}

int Buscmodelo(QString modelo){
    QSqlQuery qry;
    if (qry.exec("SELECT id_modelos FROM Modelos WHERE nombre_modelos LIKE "+modelo)){
        while (qry.next()) {
            return qry.value(0).toInt();
        }
    }
}

int Busctienda(QString tienda){
    QSqlQuery qry;
    if (qry.exec("SELECT id_tienda FROM tiendas WHERE nombre_tiendas LIKE "+tienda))
        while(qry.next()){
            return qry.value(0).toInt();
        }
}

void Insertarinfo(QString modelo, QString averia, QString tienda){
    QSqlQuery qry;
    int idTienda = Busctienda(tienda);
    int idModelo = Buscmodelo(modelo);
    QUuid uuid = QUuid::createUuid();
    qry.exec("INSERT INTO informacion (id_informacion,uuid_informacion,fk_id_estadorep_informacion,fk_id_tiendas_informacion,fk_id_modelo_informacion, reparacion) values(2, :uuid_informacion, 1,:fk_id_tiendas_informacion,:fk_id_modelo_informacion,:reparacion)");
    qry.bindValue(":uuid_informacion", uuid);
    qry.bindValue(":fk_id_tiendas_informacion", idTienda);
    qry.bindValue(":fk_id_modelo_informacion", idModelo);
    qry.bindValue(":reparacion", averia);

}

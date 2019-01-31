#include "basedatos.h"

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>


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

    if(db.open()){
        QMessageBox::information(this, "Connection", "Database Connected Successfully");
    } else {
        QMessageBox::information(this, "Not Connected", "Database not Connected");
    }


}

int Buscmodelo(QString modelo){
    QSqlQuery qry;
    if (qry.exec("SELECT id_modelos FROM Modelos WHERE nombre_modelos LIKE "+modelo)){
        while (qry.next()) {
            return qry.value(0);
        }
    }
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

int Busctienda(QStrign tienda){
    QSqlQuery qry;
    if (qry.exec("SELECT id_tienda FROM tiendas WHERE nombre_tiendas LIKE "+tienda))
        while(qry.next()){
            return qry.value(0).toString();
        }
}

void InsertarInfo(QString modelo, QString averia, QString tienda){

    int idTienda = Busctienda(tienda);
    int idModelo = Buscmodelo(modelo);
    uuid = QUuid::createUuid();
    qry.exec("INSERT INTO informacion (id_informacion,uuid_informacion,fk_id_estadorep_informacion,fk_id_tiendas_informacion,fk_id_modelo_informacion, reparacion) values(2, :uuid_informacion, 1,:fk_id_tiendas_informacion,:fk_id_modelo_informacion,:reparacion)");
    qry.bindValue(":uuid_informacion", uuid);
    qry.bindValue(":fk_id_tiendas_informacion", idTienda);
    qry.bindValue(":fk_id_modelo_informacion", idModelo);
    qry.bindValue(":reparacion", averia);

}

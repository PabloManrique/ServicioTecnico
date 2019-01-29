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
    db.setPassword("");
    db.setDatabaseName("serviciotecnico");

    if(db.open()){
        QMessageBox::information(this, "Connection", "Database Connected Successfully");
    } else {
        QMessageBox::information(this, "Not Connected", "Database not Connected");
    }


}

void ModelosTel(QString m){
    QSqlQuery qry;
    QVector<QString> select;
    int i = 0;
    bool encontrado;
    if (qry.exec("SELECT modelo FROM Modelos")){
        while (qry.next()) {
            select[i] = qry.value(0).toString();
            i++;
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


#include "basedatos.h"

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>


BaseDatos::BaseDatos()
{


}

void Conectarbd(){
    QSqlDatabase db = QSqlDatabase::("QMYSQL");
    db.setHostName("LOCALHOST");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("");

    if(db.open()){
        QMessageBox::information(this, "Connection", "Database Connected Successfully");
    } else {
        QMessageBox::information(this, "Not Connected", "Database not Connected");
    }


}

void ModelosTel(QString m){
    QSqlQuery qry;
    bool encontrado;
    if (qry.exec("SELECT modelo FROM Modelos")){
        while (qry.next()) {
            if ()
        }
    }
}

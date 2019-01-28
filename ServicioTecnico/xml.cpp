#include "xml.h"

#include <QtCore>
#include <QtXml>
#include <QDebug>

Xml::Xml()
{

}

QString Readxml()
{
    QDomDocument document;

    QFile file("//orden.xml");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open xml";
    }
    else
    {
        QDomElement root = document.firstChildElement("reparacion");
        QDomElement m = root.firstChildElement("modelo");
        QDomElement a = root.firstChildElement("averia");
        QDomElement n = root.firstChildElement("nombre");
        QDomElement t = root.firstChildElement("tienda");

        QString modelo = m.text();
        QString averia = m.text();
        QString nombre = m.text();
        QString tienda = m.text();

        return modelo, averia, nombre, tienda;
    }
}

void WriteXml(QString modelo, QString averia, QString nombre, QString tienda, QString estado, int id)
{
     QXmlStreamWriter xmlWriter;
     QFile file("CentralRep.xml");

     if (!file.open(QIODevice::WriteOnly))
     {
        qDebug() << "Failed to open file for writing";
     }
     else
     {
        xmlWriter.setDevice(&file);

        xmlWriter.writeStartDocument();

        xmlWriter.writeStartElement("Reparacion");
        xmlWriter.writeAttribute("id", QString::number(id));


        xmlWriter.writeStartElement("modelo");
        xmlWriter.writeCharacters(modelo);
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("averia");
        xmlWriter.writeCharacters(averia);
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("nombre");
        xmlWriter.writeCharacters(nombre);
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("tienda");
        xmlWriter.writeCharacters(tienda);
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("estado");
        xmlWriter.writeCharacters(estado);
        xmlWriter.writeEndElement();

        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
        file.close();
      }

}

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
        QDomElement modeloxml = root.firstChildElement("modelo");
        QDomElement averiaxml = root.firstChildElement("averia");
        QDomElement tiendaxml = root.firstChildElement("tienda");

        QString modelo = modeloxml.text();
        QString averia = averiaxml.text();
        QString tienda = tiendaxml.text();

        return modelo, averia, tienda;
    }
}

void WriteXml(QString modelo, QString averia, QString uuid, QString tienda, QString estado, int id)
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

        xmlWriter.writeStartElement("uuid");
        xmlWriter.writeCharacters(uuid);
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

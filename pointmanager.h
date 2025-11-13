#ifndef POINTMANAGER_H
#define POINTMANAGER_H

#include <QString>
#include <QList>

struct PontoRecord {
    QString data;
    QString tipo;
    QString hora;
};

class PointManager {
public:
    static QString arquivoPonto();

    static void garantirArquivo();
    static QList<PontoRecord> carregarTodos();
    static PontoRecord registrarPonto(); // Entrada ou Saída automática
};

#endif // POINTMANAGER_H

#include "pointmanager.h"
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QDate>
#include <QTime>

QString PointManager::arquivoPonto() {
    return "ponto.csv"; // mesmo diretório do exe
}

void PointManager::garantirArquivo() {
    QString nome = arquivoPonto();
    QFileInfo info(nome);
    if (!info.exists()) {
        QFile f(nome);
        if (f.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&f);
            out << "Data,Tipo,Hora\n";
            f.close();
        }
    }
}

QList<PontoRecord> PointManager::carregarTodos() {
    garantirArquivo();
    QList<PontoRecord> lista;

    QFile f(arquivoPonto());
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
        return lista;

    QTextStream in(&f);
    bool primeiraLinha = true;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty())
            continue;

        if (primeiraLinha) { // pula cabeçalho
            primeiraLinha = false;
            continue;
        }

        const QStringList partes = line.split(',');
        if (partes.size() >= 3) {
            PontoRecord r;
            r.data = partes[0];
            r.tipo = partes[1];
            r.hora = partes[2];
            lista.append(r);
        }
    }

    f.close();
    return lista;
}

PontoRecord PointManager::registrarPonto() {
    garantirArquivo();
    PontoRecord novo;

    QString hoje = QDate::currentDate().toString("yyyy-MM-dd");
    QString agora = QTime::currentTime().toString("HH:mm:ss");

    // Ler última linha
    QFile f(arquivoPonto());
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // fallback: registra entrada
        novo.data = hoje;
        novo.tipo = "ENTRADA";
        novo.hora = agora;
    } else {
        QTextStream in(&f);
        QString lastLine;
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            if (!line.isEmpty())
                lastLine = line;
        }
        f.close();

        bool registrarEntrada = true;

        if (!lastLine.isEmpty()) {
            const QStringList partes = lastLine.split(',');
            if (partes.size() >= 3) {
                QString dataUlt = partes[0];
                QString tipoUlt = partes[1];

                if (dataUlt == hoje && tipoUlt == "ENTRADA") {
                    // se o último hoje foi ENTRADA → agora SAIDA
                    registrarEntrada = false;
                }
            }
        }

        novo.data = hoje;
        novo.hora = agora;
        novo.tipo = registrarEntrada ? "ENTRADA" : "SAIDA";
    }

    // Gravar nova linha no arquivo
    QFile f2(arquivoPonto());
    if (f2.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&f2);
        out << novo.data << "," << novo.tipo << "," << novo.hora << "\n";
        f2.close();
    }

    return novo;
}

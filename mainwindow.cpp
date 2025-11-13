#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pointmanager.h"

#include <QDateTime>
#include <QTableWidgetItem>
#include <QFile>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    // Configura tabela
    configurarTabela();
    carregarRegistrosNaTabela();

    // Conecta botão
    connect(ui->btnRegistrar, &QPushButton::clicked,
            this, &MainWindow::onRegistrarClicked);

    // Relógio
    connect(&timer, &QTimer::timeout, this, &MainWindow::atualizarRelogio);
    timer.start(1000);
    atualizarRelogio();

    QFile f("style.qss");
    if (f.open(QFile::ReadOnly)) {
        QString css = QLatin1String(f.readAll());
        qApp->setStyleSheet(css);
    }


    ui->labelStatus->setText("Status: pronto");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::configurarTabela() {
    ui->tableRegistros->setColumnCount(3);
    QStringList headers;
    headers << "Data" << "Tipo" << "Hora";
    ui->tableRegistros->setHorizontalHeaderLabels(headers);
    ui->tableRegistros->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::carregarRegistrosNaTabela() {
    auto registros = PointManager::carregarTodos();
    ui->tableRegistros->setRowCount(registros.size());

    for (int i = 0; i < registros.size(); ++i) {
        const auto &r = registros[i];
        ui->tableRegistros->setItem(i, 0, new QTableWidgetItem(r.data));
        ui->tableRegistros->setItem(i, 1, new QTableWidgetItem(r.tipo));
        ui->tableRegistros->setItem(i, 2, new QTableWidgetItem(r.hora));
    }
}

void MainWindow::onRegistrarClicked() {
    auto rec = PointManager::registrarPonto();

    int row = ui->tableRegistros->rowCount();
    ui->tableRegistros->insertRow(row);
    ui->tableRegistros->setItem(row, 0, new QTableWidgetItem(rec.data));
    ui->tableRegistros->setItem(row, 1, new QTableWidgetItem(rec.tipo));
    ui->tableRegistros->setItem(row, 2, new QTableWidgetItem(rec.hora));

    ui->labelStatus->setText(
        QString("Status: %1 registrada às %2")
            .arg(rec.tipo)
            .arg(rec.hora)
        );
}

void MainWindow::atualizarRelogio() {
    QString agora = QTime::currentTime().toString("HH:mm:ss");
    QString hoje = QDate::currentDate().toString("dd/MM/yyyy");
    ui->labelClock->setText(hoje + " " + agora);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QList>
#include <QMainWindow>
#include <controler.h>
#include <QFile>
#include<QFileDialog>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonSearch_clicked();

    void on_comboBoxSelecionar_activated(int index);

    void on_pushButtonSearch_2_clicked();

private:
    Ui::MainWindow *ui;
    QString filename;
    Controler *alunoControler;

};
#endif // MAINWINDOW_H

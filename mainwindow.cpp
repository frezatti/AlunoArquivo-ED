#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->comboBoxEspecifico->hide();
    ui->labelSelected->hide();
    QStringList headers{"Matricula","Nome do Aluno","Disciplinas"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setColumnWidth(0,254);
    ui->tableWidget->setColumnWidth(1,250);
    ui->tableWidget->setColumnWidth(2,265);
    ui->lineEditMatricula->hide();
    ui->labelMat->hide();
    ui->pushButtonSearch_2->hide();
    ui->comboBoxSelecionar->hide();
    ui->label_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void loadStudentTable( std::list<Aluno*> *studlist, Ui::MainWindow *ui){

    std::list<Aluno*>::iterator it;
    if(studlist->empty())throw QString("Deu merda");
    ui->tableWidget->clear();

    int i=0;
    for(int j = ui->tableWidget->rowCount(); j>0;j--){
        ui->tableWidget->removeRow(j);
    }
    for(it = studlist->begin();it!= studlist->end();it++,i++){
        ui->tableWidget->removeRow(i);
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem((*it)->getMatricula()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem((*it)->getName()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem((*it)->getDisciplinaStr()));
    }
    ui->tableWidget->resizeColumnsToContents();
    QStringList headers{"Matricula","Nome do Aluno","Disciplinas"};
    ui->tableWidget->setHorizontalHeaderLabels(headers) ;
}

void MainWindow::on_pushButtonSearch_clicked()
{

    try {

        filename = QFileDialog::getOpenFileName(this,"Abrir Arquivo",QDir::currentPath(),"Arquivos Textos (*.csv *.txt *.*)");
        if(filename.isEmpty()) throw QString("Arquivo nao foi selecionado");
        alunoControler = new Controler(filename);
        ui->lineEditPath->setText(filename);
        loadStudentTable(alunoControler->getStudantList(),ui);
        ui->comboBoxSelecionar->show();
        ui->label_2->show();
        } catch (QString &erro) {
            QMessageBox::information(this,"ERRO",erro);
        }
}


void MainWindow::on_comboBoxSelecionar_activated(int index)
{
    try {
        ui->lineEditMatricula->hide();
        ui->labelMat->hide();
       ui->comboBoxEspecifico->show();
       ui->pushButtonSearch_2->show();
       ui->labelSelected->show();
       std::list<QString> *option;
       std::list<QString>::iterator it ;
       switch (index) {
       case 1:
            option = alunoControler->getlist(index);
            ui->comboBoxEspecifico->clear();
            for(it = option->begin();it!=option->end();it++ ){
               ui->comboBoxEspecifico->addItem(*it);
            }
            break;
       case 2:

            option = alunoControler->getlist(index);
            ui->comboBoxEspecifico->clear();
            for(it = option->begin();it!=option->end();it++){
                ui->comboBoxEspecifico->addItem((*it));
            }
           break;
       case 3:

            option = alunoControler->getlist(index);
            ui->comboBoxEspecifico->clear();
            for(it = option->begin();it!=option->end();it++){
                ui->comboBoxEspecifico->addItem((*it));
            }
           break;
       case 4:
           ui->comboBoxEspecifico->hide();
           ui->labelSelected->hide();
           ui->lineEditMatricula->show();
           ui->labelMat->show();
           break;
        default:
           ui->pushButtonSearch_2->hide();
           ui->lineEditMatricula->hide();
           ui->labelMat->hide();
           ui->comboBoxEspecifico->hide();
           ui->labelSelected->hide();
           loadStudentTable(alunoControler->getStudantList(),ui);
            break;
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}



void MainWindow::on_pushButtonSearch_2_clicked()
{
    try {
        int index = ui->comboBoxSelecionar->currentIndex();
       switch (index) {
       case 1:
            loadStudentTable(alunoControler->searchTurma(ui->comboBoxEspecifico->currentText()),ui);
            break;
       case 2:
           loadStudentTable(alunoControler->searchCurso(ui->comboBoxEspecifico->currentText()),ui);

           break;
       case 3:
           loadStudentTable(alunoControler->searchDisciplina(ui->comboBoxEspecifico->currentText()),ui);
           break;
       case 4:
           loadStudentTable(alunoControler->searchAluno(ui->lineEditMatricula->text()),ui);
        default:

            break;
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}


#include "aluno.h"
#include<iostream>

Aluno::Aluno()
{
}

Aluno::Aluno(QString matricula, QString nome, QString disciplina): name(nome),matricula(matricula){
    setDisciplina(disciplina);
    QStringList curso =matricula.split(".");

    if(curso.size() >=2) this->curso =curso[2];
}

QString Aluno::getName() const
{
    return name;
}

void Aluno::setName(const QString &newName)
{
    name = newName;
}

QString Aluno::getMatricula() const
{
    return matricula;
}
QString Aluno::getCurso() const
{
    return curso;
}
void Aluno::setMatricula(const QString &newMatricula)
{
    matricula = newMatricula;
    QStringList curso =newMatricula.split(".");
    this->curso =curso[2];
}

QString Aluno::getDisciplinaStr()const{
    std::list<Disciplina*>::const_iterator k;
    QString exit;
    for(k = disciplinas.begin();k!=disciplinas.end();k++){
        exit+= (*k)->getFormated()+" ";
    }
    return exit;
}
void Aluno::setDisciplina( QString disciplina)
{
    QStringList strlist = disciplina.split(" ");
    for(int i = 0; i<strlist.size(); i++){
        if(strlist[i]!=" "){
            Disciplina *dis = new Disciplina;
            dis->setDisciplinaTurma(strlist[i]);
            disciplinas.push_back(dis);
        }
    }
}

bool Aluno::searchDisciplina(QString id){
    std::list<Disciplina*>::iterator it;


    for(it = disciplinas.begin();it !=disciplinas.end();it++){
        if((*it)->getDisciplina()==id){
           return true;
        }
    }
    return false;
}

bool Aluno::searchTurma(QString id){
    std::list<Disciplina*>::iterator it;

    for(it = disciplinas.begin();it !=disciplinas.end();it++){
        if((*it)->getFormated()==id){
           return true;
        }
    }
    return false;
}

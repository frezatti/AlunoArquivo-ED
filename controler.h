#ifndef CONTROLER_H
#define CONTROLER_H
#include<QString>
#include "aluno.h"
#include<list>
#include<vector>
#include <QFile>

class Controler
{
public:
    Controler(QString filename);

    std::list<Aluno*>* getStudantList();
    std::list<QString>* getlist(int list);
    std::list<Aluno*> * searchTurma(QString id);
    std::list<Aluno*> * searchDisciplina(QString id);
    std::list<Aluno*> * searchCurso(QString id);
    std::list<Aluno*> *searchAluno(QString id);
private:
    std::list<Aluno*>* studList;
    std::list<Aluno*>* search ;
    std::list<QString>  turma;
    std::list<QString>  disciplina;
    std::list<QString>  curso;
};

#endif // CONTROLER_H

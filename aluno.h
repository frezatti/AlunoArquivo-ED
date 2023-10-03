#ifndef ALUNO_H
#define ALUNO_H
#include "disciplina.h"
#include <QString>
#include <list>

class Aluno
{
public:
    Aluno();
    Aluno(QString name, QString Matricula,QString disciplina);

    QString getName() const;
    void setName(const QString &newName);

    QString getMatricula() const;
    QString getCurso()const;
    void setMatricula(const QString &newMatricula);

    QString getDisciplinaStr()const;
    void setDisciplina(QString disciplina);

    bool searchDisciplina(QString id);
    bool searchTurma(QString id);
private:
    QString name;
    QString matricula;
    QString curso;
    std::list<Disciplina*> disciplinas;
};

#endif // ALUNO_H

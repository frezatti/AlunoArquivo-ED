#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include<QString>
#include<QStringList>

class Disciplina
{
public:
    Disciplina();

    void setDisciplinaTurma(QString informacao);
    void setTurma(QString newturma);
    void setDisciplina(QString newdisciplina);

    QString getTurma();
    QString getDisciplina();
    QString getFormated()const;
private:
    QString turma;
    QString disciplina;
};

#endif // DISCIPLINA_H

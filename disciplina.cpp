#include "disciplina.h"
#include <iostream>
Disciplina::Disciplina()
{
}
void Disciplina::setDisciplinaTurma(QString info){

    QStringList strlist=info.split("-");
    if(strlist.size()==2){
    disciplina = strlist[0];
    if(strlist.endsWith("\n"))strlist[1].chop(1);
    strlist = strlist[1].split(" ");
    turma = strlist[0];
    }else{
        disciplina=strlist[0];
        turma="";
    }
}
void Disciplina::setDisciplina(QString newdisciplina){
    disciplina = newdisciplina;
}
void Disciplina::setTurma(QString newturma){
    turma = newturma;
}
QString Disciplina::getDisciplina(){
    return disciplina;
}

QString Disciplina::getTurma(){
    return turma;
}

QString Disciplina::getFormated()const{
    return disciplina+"-"+turma;
}

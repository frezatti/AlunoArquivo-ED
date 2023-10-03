#include "controler.h"

Controler::Controler(QString filename)
{
    try {
    QFile file(filename);
    std::string str;
    QStringList strlist;
    QStringList strcurso;
    QStringList strDisciplina;
    studList = new std::list<Aluno*>;
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    while(!file.atEnd()){
        str= file.readLine();
        strlist = QString::fromStdString(str).chopped(1).split(";");
        strcurso = strlist[0].split(".");
        if(strcurso.size() >=2){ curso.push_back(strcurso[2]);}
        if(strlist.size()>=3){
            Aluno *aluno = new Aluno(strlist[0],strlist[1],strlist[2]);

            strDisciplina = strlist[2].split(" ");
            for(int i = 0; i<strDisciplina.size();i++){
                if(strDisciplina[i]!=" "){
                    QStringList temp = strDisciplina[i].split("-");
                    disciplina.push_back(temp[0]);
                    if(strDisciplina[i].endsWith("\n")) strDisciplina[i].chop(1);
                    if(strDisciplina[i].split("-").size()==2)turma.push_back(strDisciplina[i]);
                    }
                }

            studList->push_back(aluno);
        }
        }

    file.close();
    turma.sort();
    disciplina.sort();
    curso.sort();
    turma.unique();
    disciplina.unique();
    curso.unique();
    } catch (std::bad_alloc &error) {
        throw QString("bad alloc");
    }
}

std::list<Aluno*>* Controler::getStudantList(){
    return studList;
}
std::list<QString>* Controler::getlist(int selector){
    if(selector== 1){
        return &turma;
    }

    if(selector==2){
        return &curso;
   }
    if(selector== 3){
        return &disciplina;
    }
    throw QString ("opcao nao existe");
}

std::list<Aluno*>* Controler::searchCurso(QString id){
    std::list<Aluno*>::iterator it;
    //delete search;
    search = new std::list<Aluno*>;

    for(it = studList->begin();it !=studList->end();it++){
        if((*it)->getCurso() == id){
            search->push_back((*it));
        }
    }
    return search;
}
std::list<Aluno*>* Controler::searchDisciplina(QString id){
    std::list<Aluno*>::iterator it;
   // delete search;
    search = new std::list<Aluno*>;

    for(it = studList->begin();it !=studList->end();it++){
        if((*it)->searchDisciplina(id)){
            search->push_back((*it));
        }
    }
    return search;
}

std::list<Aluno*>* Controler::searchTurma(QString id){
    std::list<Aluno*>::iterator it;
    //delete search;
    search = new std::list<Aluno*>;

    for(it = studList->begin();it !=studList->end();it++){
        if((*it)->searchTurma(id)){
            search->push_back((*it));
        }
    }
    return search;
}

std::list<Aluno*>* Controler::searchAluno(QString id){
    std::list<Aluno*>::iterator it;
   //delete search;
    search = new std::list<Aluno*>;

    for(it = studList->begin();it !=studList->end();it++){
        if((*it)->getMatricula() == id){
            search->push_back((*it));
        }
    }
    return search;
}

#include "DiarioClasse.hpp"

bool DiarioClasse::determinarAprovacao(double notaSemestre, double notaEspecial, double frequencia) {
    if( notaEspecial !=0)
    {
        if(notaEspecial >100 || notaEspecial <0)
             throw ExcecaoNotaEspecialInvalida();
        if(!((frequencia>=0.75 && notaSemestre<60) && notaSemestre>=40))
            throw ExcecaoNotaEspecialInvalida();
    }
    if( frequencia>1 || frequencia <0)
        throw ExcecaoFrequenciaInvalida();
    if (notaSemestre < 0)
        throw ExcecaoNotaSemestreInvalida();
    else if (notaSemestre > 100 )
        throw ExcecaoNotaSemestreInvalida();
    else if(frequencia < 0.75)
        return false;
    else if( frequencia>=0.75 && notaSemestre<60 && notaSemestre>=40)
    {
        if(notaEspecial<60)
            return false;
        else
            return true;
    }
    else if(notaSemestre<60)
        return false;
    else
        return true;
}

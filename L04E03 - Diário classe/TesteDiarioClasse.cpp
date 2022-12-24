#include "doctest.h"
#include "DiarioClasse.hpp"

TEST_CASE("Teste 01 - Aprovação Simples"){
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(60, 0, 0.75);
    CHECK(aprovado);
}

TEST_CASE("Teste 02 - Excecao Frequencia Invalida Inferior"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(100, 0, -1), ExcecaoFrequenciaInvalida);
}

TEST_CASE("Teste 03 - Reprovação frequencia"){
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(60, 0, 0.74);
    CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 04 - Reprovação no Exame Especial"){
    DiarioClasse diario;
    bool aprovado = diario.determinarAprovacao(50, 50, 0.75);
    CHECK_FALSE(aprovado);
}

TEST_CASE("Teste 05 - Exceção Nota Expecial Invalida Superior"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(50, 130, 1),ExcecaoNotaEspecialInvalida);
}
TEST_CASE("Teste 06 - Exceção Nota Expecial Invalida Inferior"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(50, -20, 1),ExcecaoNotaEspecialInvalida);
}

TEST_CASE("Teste 07 - Exceção Nota Semestre Inferior"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(-10, 0, 1), ExcecaoNotaSemestreInvalida);
}
TEST_CASE("Teste 08 - Exceção Nota Expecial Invalida Requisitos Invalidos- Nota Mínima"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(30, 60, 0.80), ExcecaoNotaEspecialInvalida);
}
TEST_CASE("Teste 09 - Exceção Nota Expecial Invalida Requisitos Invalidos- Nota Semestre e Frequencia Suficientes"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(60, 80, 0.75), ExcecaoNotaEspecialInvalida);
}
TEST_CASE("Teste 10 - Exceção Nota Expecial Invalida Requisitos Invalidos-Frequencia Insuficiente"){
    DiarioClasse diario;
    CHECK_THROWS_AS(diario.determinarAprovacao(50, 80, 0.70), ExcecaoNotaEspecialInvalida);
}

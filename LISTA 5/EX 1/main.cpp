#include "MagoBranco.h"
#include "MagoCinza.h"
#include "MagoRoxo.h"
#include "MagoVerde.h"


int main()
{
    MagoBranco magoBranco("Gandalf",2019,"Istari");

    magoBranco.falar("Olá!");// invoca a superclasse
    magoBranco.LancarCura();

    MagoCinza magoCinza("Radagast",2000,"Istari");

    magoCinza.falar("Bão");
    magoCinza.PrepararPocao();

    MagoRoxo magoRoxo("Elminster",1200,"Forgotten Realms");

    magoRoxo.falar("!!!!!");
    magoRoxo.CriarIlusao();

    MagoVerde magoVerde("Willow Ufgood",30,"Tir Asleen");

    magoVerde.falar("Hey");
    magoVerde.FalarComAnimais();

    return 0;
};
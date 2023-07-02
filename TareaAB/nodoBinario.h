#ifndef NODOBINARIO_H
#define NODOBINARIO_H

#define NULL __null

typedef int Tipo;

class NodoBinario
{
    private:
        Tipo dato;
        NodoBinario *izq;
        NodoBinario *der;
    public:
        NodoBinario();
        NodoBinario(Tipo val);
        NodoBinario(Tipo val, NodoBinario* puntIzq, NodoBinario* puntDer);
        void setDato(Tipo val);
        void setIzq(NodoBinario *punt);
        void setDer(NodoBinario *punt);
        Tipo getDato();
        NodoBinario *getIzq();
        NodoBinario *getDer();
};

    NodoBinario::NodoBinario(){
        setIzq(NULL);
        setDer(NULL);
    }

    NodoBinario::NodoBinario(Tipo val){
        setDato(val);
        setIzq(NULL);
        setDer(NULL);
    }

    NodoBinario::NodoBinario(Tipo val, NodoBinario* puntIzq, NodoBinario* puntDer){
        setDato(val);
        setIzq(puntIzq);
        setDer(puntDer);
    }

    void NodoBinario::setDato(Tipo val){
        dato = val;
    }
    void NodoBinario::setIzq(NodoBinario *punt){
        izq = punt;
    }
    void NodoBinario::setDer(NodoBinario *punt){
        der = punt;
    }
    Tipo NodoBinario:: getDato(){
        return dato;
    }
    NodoBinario* NodoBinario::getIzq(){
        return izq;
    }
    NodoBinario* NodoBinario::getDer(){
        return der;
    }
#endif
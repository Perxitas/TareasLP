package Tarea3.Zonas;

import Tarea3.Pikinim.Pikinim;

public abstract class Zona {
    protected boolean completada;
    protected String TipoZona;
    ////////////////////
    //Zona:
    //Constructor de Zona, superclase, empezando por el booleano en falso
    ///////////////////

    public Zona(){
        completada = false;
    }
    public String ZonaType(){return TipoZona;}

    ////////////////////
    //ZonaCompleta:
    //Esta funcion transforma las Zonas a completas
    ///////////////////

    public void ZonaCompleta(){
        completada = true;
    }

    ////////////////////
    //Complete:
    //Esta funcion simplemente devuelve el valor booleano para saber si la zona esta completa
    ///////////////////

    public boolean Complete(){ 
        return completada;
    }

    public abstract void interactuar(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki);
}

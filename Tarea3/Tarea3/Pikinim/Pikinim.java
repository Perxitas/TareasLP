package Tarea3.Pikinim;
public abstract class Pikinim {
    protected int cant; 
    protected int atk;
    protected int capacidad;
    
    ////////////////////
    //Pikinim(int cant,int atk,int capacidad):
    //cant: cantidad de pikinim
    //atk: ataque/daño del pikinim
    //capacidad: capacidad del pikinim para levantar
    //------------------
    //Constructor de pikinim, crea la cant atk y capacidad del pikinim segun lo que se entrege a travez de las variables
    ///////////////////

    public Pikinim(int cant,int atk,int capacidad){
        this.cant = cant;
        this.atk = atk;
        this.capacidad = capacidad;
    }

    ////////////////////
    //GetCant,GetCapacidad,GetATK:
    //Son todas funciones para obtener a traves de un return las variables cant, capacidad y atk
    ////////////////////

    public int GetCant(){return cant;}
    public int GetCapacidad(){return capacidad;}
    public int GetATK(){return atk;}

    ////////////////////
    //disminuir,multiplicar:
    //cantidad: numero por el cual se van a disminuir o multiplicar
    //-----------------
    //Estas son funciones declaradas que la tendran obligatoriamente todas las subclases
    ////////////////////
    public abstract void disminuir(int cantidad);
    public abstract void multiplicar(int cantidad);
}

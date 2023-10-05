package Tarea3.Zonas;
import Tarea3.Interfaz.Ilevantable;
import Tarea3.Pikinim.Pikinim;

public class Pieza extends Zona implements Ilevantable{
    private int Peso_Pieza;
    private boolean levantada;
    ////////////////////
    //Pieza:
    //Constructor de la subclase Pieza, con sus booleanos para saber si esta levantada, el peso que le entregara el jugador y el tipo de string 
    ///////////////////
    public Pieza(int Peso){
        this.levantada=false;
        this.Peso_Pieza=Peso;
        this.TipoZona = "Pieza";
    }
    ////////////////////
    //Getlevantada:
    //Esta funcion simplemente retorna el booleano de Pieza, para saber si esta levantado o no
    ///////////////////
    public boolean GetLevantada(){return levantada;}
    ////////////////////
    //interactuar(Pikinim cyanPiki,Pikinim magnetaPiki,Pikinim amarilloPiki):
    //cyan,magenta,amarillo - Piki: Son las subclases de cada color de pikinim
    //-----------------
    //Printea un texto ambiental y luego llama a la funcion levantar
    ///////////////////
    public void interactuar(Pikinim cyanPiki,Pikinim magnetaPiki,Pikinim amarilloPiki){
        System.out.println("Se ha llegado a un lugar...una pieza extraña, Lomiar nota que es de las que faltan para la nave..por lo tanto los Pikinims intentan tomarla.\n");
        this.levantar(cyanPiki, magnetaPiki, amarilloPiki);
    }   
    ////////////////////
    //levantar(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki):
    //cyan,magenta,amarillo - Piki: Son las subclases de cada color de pikinim
    //------------------
    //declara las variables de cada color de piki donde obtiene su cantidad * capacidad, luego se suman en total entrnado a un condicional para ver si es que efectivamente
    //se levanto o no la pieza
    ///////////////////
    public void levantar(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki){
        int SumCyan,SumAmarilla,SumMagenta,SumTotal;
        SumCyan = cyanPiki.GetCant() * cyanPiki.GetCapacidad();
        SumMagenta = magentaPiki.GetCant() * magentaPiki.GetCapacidad();
        SumAmarilla = amarilloPiki.GetCant() * amarilloPiki.GetCapacidad();
        SumTotal = SumCyan+SumAmarilla+SumMagenta;
        if(SumTotal >=this.Peso_Pieza){
            this.ZonaCompleta();
            this.levantada = true;
            System.out.println("Lomiar mira a sus Pikinims con orgullo...se ha logrado levantar la pieza y por ende, Lomiar esta mas cerca de salvarse!\n");
            System.out.println("--------------------------------------------------------------");
        }else if(SumTotal<this.Peso_Pieza){
            System.out.println("Lomiar mira a sus Pikinims se dan cuenta de que no pueden levantar esta pieza aun...quiza con unos pocos mas...\n");
            System.out.println("--------------------------------------------------------------");
        }
    }
    ////////////////////
    //GetPESOP:
    //Retorna el peso de la pieza
    ///////////////////
    public int GetPESOP(){return Peso_Pieza;}
}

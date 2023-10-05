package Tarea3.Pikinim;

public class Cyan extends Pikinim {

    ////////////////////
    //Magenta(int cant):
    //cant: cantidad de pikinims magenta
    //------------------
    //Crea los pikinims cyan, solo cambiando la cantidad a la deseada
    ////////////////////

    public Cyan(int cant){
        super(cant,1,1);
    }

    ////////////////////
    //disminuir(int cantidad):
    //cantidad: cantidad por lo cual se disminuira la cantidad
    //------------------
    //Disminuye la cantidad de pikinims por la cantidad introducida asi como, si la cantidad es negativa, simplemente pasa a 0
    //////////////////// 

    public void disminuir(int cantidad){
        this.cant -=cantidad;
        if(this.cant<0) this.cant=0;
    }

    ////////////////////
    //multiplicar(int cantidad):
    //cantidad: cantidad por lo cual se multiplicara la cantidad
    //------------------
    //Multiplica la cantidad de pikinims por la cantidad introducida * 3
    //////////////////// 
    public void multiplicar(int cantidad){
        this.cant = cantidad*3;
    }
}

package Tarea3.Zonas;
import Tarea3.Pikinim.Pikinim;
import java.util.Scanner;

public class Pildora extends Zona{
    private int PillsCant;
    ////////////////////
    //Pildora:
    //Constructor de la subclase pildora, empieza con la cantP indicada, y con su tipo en string
    ///////////////////
    public Pildora(int cantP){  
        this.PillsCant=cantP;
        this.TipoZona = "Pildora";
    }
    ////////////////////
    //interactuar(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki)
    //cyan,magenta,amarillo - Piki: Son las subclases de cada color de pikinim
    //--------------------------------
    //Esta funcion obtiene la opcion que entregara al jugador para saber que Pikinim multiplicara, luego esto lo representa con unos prints y completa la zona
    ///////////////////
    public void interactuar(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki){
        System.out.println(("Lomiar, se encuentra en un lugar, repleto de pildoras.\n\nQue color de pikinim multiplicaras? (cantidad a multiplicar:"+this.PillsCant+")\n1.Cyan 2.Magenta 3.Amarillo\n\nInput:"));
        Scanner scan = new Scanner(System.in);
        
        int opcion= scan.nextInt();
        if(opcion==1){
            cyanPiki.multiplicar(this.PillsCant);
            System.out.println("Has multiplicado a los Cyan Pikinim...ahora son mas fuertes..(Cantidad aumentada a:"+cyanPiki.GetCant()+")");
            System.out.println("--------------------------------------------------------------");
        }else if(opcion==2){
            magentaPiki.multiplicar(this.PillsCant);
            System.out.println("Has multiplicado a los Magenta Pikinim...ahora son mas fuertes..(Cantidad aumentada a:"+magentaPiki.GetCant()+")");
            System.out.println("--------------------------------------------------------------");
        }else{
            amarilloPiki.multiplicar(this.PillsCant);
            System.out.println("Has multiplicado a los Amarillo Pikinim...ahora son mas fuertes..(Cantidad aumentada a:"+amarilloPiki.GetCant()+")");
            System.out.println("--------------------------------------------------------------");
        }
       
        this.ZonaCompleta();  
    }
    ////////////////////
    //GetCANTP:
    //Esta funcion simplemente retorna la cantidad de pildoras que tiene la clase
    ///////////////////
    public int GetCANTP(){return PillsCant;}
}

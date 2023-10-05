package Tarea3.Zonas;
import Tarea3.Pikinim.Pikinim;

public class Muralla extends Zona {
    private int vidaMuralla;

    ////////////////////
    //Muralla:
    //Constructor de la subclase Muralla, declarando la vida de esta y su tipo
    ///////////////////
    public Muralla(int vidaM){
        this.vidaMuralla = vidaM;
        this.TipoZona = "Muralla";
    }

    ////////////////////
    //interactuar(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki):
    //cyan,magenta,amarillo - Piki: Son las subclases de cada color de pikinim
    //----------------
    //Llama a la funcion TryRomper, luego verifica si esta es verdad, entonces completa la zona y entrega un print ambiental
    ///////////////////

    public void interactuar(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki){
        boolean MurallaRota = this.TryRomper(cyanPiki, magentaPiki, amarilloPiki);
        if (MurallaRota){
            System.out.println("Los pikinims han logrado derrumbar la muralla...y Lomiar tiene paso libre para seguir con la exploracion..");
            System.out.println("--------------------------------------------------------------");
            this.ZonaCompleta();
        }
    }
    
    ////////////////////
    //TryRomper(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki):
    //cyan,magenta,amarillo - Piki: Son las subclases de cada color de pikinim
    //---------------------
    //Declara las variables atk, que van a ser el int de la cantidad * atk de cada pikinim para luego tenerlos en un total, es se le restara a la vida de la muralla
    //entramos al condicional donde, si la muralla se destruye entonces se devuelve un bool true, si no es asi entonces se printea y se retorna falso
    //---------------------
    //return: true/false
    ///////////////////

    public boolean TryRomper(Pikinim cyanPiki,Pikinim magentaPiki,Pikinim amarilloPiki){
        int ATKcyanPiki,ATKmagentaPiki,ATKamarilloPiki,ATKtotal;

        ATKcyanPiki= cyanPiki.GetCant()*cyanPiki.GetATK();
        ATKmagentaPiki=magentaPiki.GetCant()*magentaPiki.GetATK();
        ATKamarilloPiki =amarilloPiki.GetCant()*amarilloPiki.GetATK();
        ATKtotal =  ATKcyanPiki+ATKmagentaPiki+ATKamarilloPiki;

        this.vidaMuralla -= ATKtotal;
        if (this.vidaMuralla<=0){
            return true;
        }else{
            System.out.println("Los pikinims han fallado en derrumbarla....Lomiar se da cuenta del gap de poder entre el y la pared...");
            System.out.println("--------------------------------------------------------------");
            return false;
        }
    }

    ////////////////////
    //GetHPM:
    //Esta funcion simplemente retorna la vida de la muralla
    ///////////////////
    
    public int GetHPM(){return vidaMuralla;}
}

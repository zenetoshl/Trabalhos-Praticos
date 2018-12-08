package br.caf.ufv.biblioteca;

import br.caf.ufv.biblioteca.Visual.Interface;
import br.caf.ufv.biblioteca.Controle.Biblioteca;

import java.io.IOException;

public class Main {

    public static void main(String[] args)throws IOException{
        Biblioteca lib = new Biblioteca();
     Interface ui = new Interface(lib);
    }
}

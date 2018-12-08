package br.ufv.caf.poo;

import java.util.*;

public class Cartela {
    private LinkedList<Integer> listaNumeros;
    private final int qtdNumeros = 10;
    private final int numMax = 100;

    public int getQtdNumeros() {
        return qtdNumeros;
    }

    public int getNumMax() {
        return numMax;
    }

    public Cartela(){
        listaNumeros = new LinkedList<>();
        Random rand = new Random();
        int n;
        for(int i = 0; i < qtdNumeros; i++) {
            n = rand.nextInt(numMax) + 1;
            if (listaNumeros.contains(n))
                i--;
            else
                listaNumeros.add(n);
        }
    }

    public boolean RetiraNumero(int n){
        if(listaNumeros.contains(n)){
            listaNumeros.remove(listaNumeros.indexOf(n));
            return true;
        } else
            return false;
    }

    public boolean isVazia (){
        return listaNumeros.isEmpty();
    }

    public String toString() {
        String toString = "";
        toString = "" + listaNumeros;
        return toString;
    }
}

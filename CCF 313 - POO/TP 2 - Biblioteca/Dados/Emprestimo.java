package br.caf.ufv.biblioteca.Dados;

import java.util.*;
public class Emprestimo {
    private ArrayList<String> tituloList;
    private ArrayList<String> dataDevolucaoList;

    public Emprestimo (){
        tituloList = new ArrayList<>();
        dataDevolucaoList = new ArrayList<>();
    }

    public ArrayList<String> getTituloList() {
        return tituloList;
    }

    public ArrayList<String> getDataDevolucaoList() {
        return dataDevolucaoList;
    }

    public void NovoEmprestimo(String titulo){
        Date hoje = new Date();
        Calendar entrega = Calendar.getInstance();
        entrega.setTime(hoje);
        entrega.add(Calendar.DATE, 10);
        this.tituloList.add(titulo);
        this.dataDevolucaoList.add(entrega.getTime().toString());
    }

    public void RemoverEmprestimo(String titulo){
        for ( int i = 0; i < this.getTituloList().size(); i++){
            if(this.getTituloList().get(i).equals(titulo)){
                this.tituloList.remove(i);
                this.dataDevolucaoList.remove(i);
                break;
            }
        }
    }
}

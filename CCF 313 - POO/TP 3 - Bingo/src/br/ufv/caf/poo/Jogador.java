package br.ufv.caf.poo;

import java.util.LinkedList;

public class Jogador {
    private LinkedList<Cartela> cartela;
    private String nome;
    private final int numCartelas = 2;

    public Jogador(String nome){
        cartela = new LinkedList<>();
        this.nome = nome;
        for(int i = 0; i < numCartelas; i++) {
            Cartela cart = new Cartela();
            cartela.add(cart);
        }
    }

    public void NovaCartela(){
        cartela.clear();
        for(int i = 0; i < numCartelas; i++)
            cartela.add(new Cartela());
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public boolean Ganhou(){
        for(int i = 0; i < numCartelas; i++)
        if(cartela.get(i).isVazia())
            return true;
        return false;
    }

    public boolean RetirarNumero(int n){
        boolean flag = false;
        for(int i = 0; i < numCartelas; i++)
            if(cartela.get(i).RetiraNumero(n))
                flag = true;
        return flag;
    }

    public Cartela getCartela(int i) {
        return cartela.get(i);
    }

    public String getNome() {
        return nome;
    }

    public String StringCartela(int i){
        return cartela.get(i).toString();
    }
}

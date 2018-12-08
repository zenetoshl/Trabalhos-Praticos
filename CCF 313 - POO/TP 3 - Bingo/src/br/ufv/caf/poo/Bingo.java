package br.ufv.caf.poo;

import java.util.LinkedList;
import java.util.Random;

public class Bingo {
    private Jogador player1;
    private Jogador player2;
    LinkedList<Integer> numerosSorteados;

    public Bingo(){
        numerosSorteados = new LinkedList<>();
        player1 = new Jogador("player 1");
        player2 = new Jogador("Computador");
    }

    private int QuemGanhou(){
        if(player1.Ganhou() && player2.Ganhou()) return 3;
            else if(player1.Ganhou()) return 1;
            else if(player2.Ganhou()) return 2;
            else return 0;
    }

    private void Retira(int n){
        player2.RetirarNumero(n);
        player1.RetirarNumero(n);
    }

    public void setNomeJogador1(String nome){
        player1.setNome(nome);
    }

    public void setNomeJogador2(String nome){
        player2.setNome(nome);
    }

    public Jogador getPlayer1() {
        return player1;
    }

    public Jogador getPlayer2() {
        return player2;
    }

    public int Jogar(int n){

        Retira(n);
        return QuemGanhou();
    }

    public String ToStringPlayer1(int i){
        return player1.StringCartela(i);
    }

    public String ToStringPlayer2(int i){
        return player2.StringCartela(i);
    }

    public void Reset(){
        player1.NovaCartela();
        player2.NovaCartela();
        numerosSorteados.clear();
    }

    public int gerarNumero (){
        int num;
        Random rand = new Random();
        num = rand.nextInt(player1.getCartela(0).getNumMax()) + 1;
        while (numerosSorteados.contains(num)){
            num = rand.nextInt(player1.getCartela(0).getNumMax()) + 1;
        }
        numerosSorteados.add(num);
        return num;
    }
}

package br.caf.ufv.biblioteca.Controle;
import br.caf.ufv.biblioteca.Dados.Emprestimo;
import br.caf.ufv.biblioteca.Dados.Livro;
import br.caf.ufv.biblioteca.Dados.Usuario;

import java.util.*;
public class GestaoDeEmprestimos {
    private HashMap<Integer, Emprestimo> emprestimoList;
    private HashMap<String, Integer> quantidadeDisp;

    public GestaoDeEmprestimos(HashMap<Integer, Livro> listaLivros, HashMap<Integer, Usuario> listaUsuarios) throws NullPointerException{
        emprestimoList = new HashMap<>();
        quantidadeDisp = new HashMap<>();
        for (int key: listaUsuarios.keySet()) {
            emprestimoList.put(listaUsuarios.get(key).GetMatricula(),new Emprestimo());
        }
        for (int key: listaLivros.keySet()){
            quantidadeDisp.put(listaLivros.get(key).GetTitulo().trim(), listaLivros.get(key).GetQuantidadeExemplares());
        }

    }

    public boolean NovoEmprestimo(int matricula, String nome) throws NullPointerException{
        if(quantidadeDisp.containsKey(nome.trim()))
        if (emprestimoList.get(matricula).getTituloList().size() < 3 && quantidadeDisp.get(nome) > 0){
            emprestimoList.get(matricula).NovoEmprestimo(nome);
            int novo = quantidadeDisp.get(nome) - 1;
            quantidadeDisp.replace(nome, novo);
            return true;
        }
        return false;
    }

    public ArrayList<String> ConsultaEmprestimo (int matricula){
            return emprestimoList.get(matricula).getTituloList();
    }

    public boolean EntregarLivro(int matricula, String nome){
        if(this.emprestimoList.get(matricula).getTituloList().contains(nome)) {
            this.emprestimoList.get(matricula).RemoverEmprestimo(nome);
            int novo = 1 + this.quantidadeDisp.get(nome);
            this.quantidadeDisp.replace(nome, novo);
            return true;
        } return false;
    }
}

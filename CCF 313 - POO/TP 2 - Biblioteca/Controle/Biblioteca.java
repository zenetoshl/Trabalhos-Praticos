package br.caf.ufv.biblioteca.Controle;

import br.caf.ufv.biblioteca.Dados.Livro;

import java.io.*;
import java.util.*;

public class Biblioteca {
    private int matricula;
    private boolean usuarioAutenticado;
    private GestaoDeUsuarios gerenteUsuario;
    private GestaoDeLivros gerenteLivros;
    private GestaoDeEmprestimos gerenteEmprestimos;

    public boolean isUsuarioAutenticado() {
        return usuarioAutenticado;
    }

    public Biblioteca () throws IOException, NullPointerException {
        matricula = -1;
        gerenteLivros = new GestaoDeLivros();
        gerenteUsuario = new GestaoDeUsuarios();
        gerenteEmprestimos = new GestaoDeEmprestimos(gerenteLivros.getListaLivros(), gerenteUsuario.getUserList());
        usuarioAutenticado = false;
    }

    public void login(int matricula, String senha) throws NullPointerException{
        if (gerenteUsuario.Autentica(matricula, senha)){
            this.usuarioAutenticado = true;
            this.matricula = matricula;
        }
    }

    public ArrayList<Livro> pesquisa (String pesquisa){
        return gerenteLivros.PesquisaLivro(pesquisa);
    }

    public GestaoDeUsuarios getGerenteUsuario() {
        return gerenteUsuario;
    }

    public GestaoDeLivros getGerenteLivros() {
        return gerenteLivros;
    }

    public GestaoDeEmprestimos getGerenteEmprestimos() {
        return gerenteEmprestimos;
    }

    public ArrayList<String> ConsultaEmprestimos(){
        if(this.usuarioAutenticado){
            return gerenteEmprestimos.ConsultaEmprestimo(this.matricula);
        } else return new ArrayList<>();
    }

    public boolean EntregaEmprestimo(String entrega) {
        if (this.usuarioAutenticado) {
            return gerenteEmprestimos.EntregarLivro(this.matricula, entrega);
        } else return false;
    }

    public boolean FazerEmprestimo(String nome) {
        if (this.usuarioAutenticado)
            return gerenteEmprestimos.NovoEmprestimo(matricula, nome);
        else return false;
    }
}

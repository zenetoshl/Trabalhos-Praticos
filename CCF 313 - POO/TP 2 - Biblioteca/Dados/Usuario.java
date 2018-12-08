package br.caf.ufv.biblioteca.Dados;

public class Usuario {
    private int matricula;
    private String senha;
    private String endereco;

    public int GetMatricula() {
        return matricula;
    }

    public void SetMatricula(int matricula) {
        this.matricula = matricula;
    }

    public String GetSenha() {
        return senha;
    }

    public void SetSenha(String senha) {
        this.senha = senha;
    }

    public String GetEndereco() {
        return endereco;
    }

    public void SetEndereco(String endereco) {
        this.endereco = endereco;
    }

}

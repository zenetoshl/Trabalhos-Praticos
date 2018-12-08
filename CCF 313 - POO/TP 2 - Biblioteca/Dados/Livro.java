package br.caf.ufv.biblioteca.Dados;
import java.util.*;
public class Livro {
    //Cada livro possui identificador único, título, autores, editora, edição, dimensões,
    //peso e o número total de exemplares existentes na biblioteca (emprestados ou não)
    private String titulo;
    private String autores;
    private String editora;
    private int edicao;
    private int identificador;
    private int quantidadeExemplares;
    private String dimensoes;
    private double peso;

    public String GetTitulo() {
        return titulo;
    }

    public void SetTitulo(String titulo) {
        this.titulo = titulo;
    }

    public String GetAutores() {
        return autores;
    }

    public void SetAutores(String autores) {
        this.autores = autores;
    }

    public String GetEditora() {
        return editora;
    }

    public void SetEditora(String editora) {
        this.editora = editora;
    }

    public int GetEdicao() {
        return edicao;
    }

    public void SetEdicao(int edicao) {
        this.edicao = edicao;
    }

    public int GetIdentificador() {
        return identificador;
    }

    public void SetIdentificador(int identificador) {
        this.identificador = identificador;
    }

    public int GetQuantidadeExemplares() {
        return quantidadeExemplares;
    }

    public void SetQuantidadeExemplares(int quantidadeExemplares) {
        this.quantidadeExemplares = quantidadeExemplares;
    }


    public String GetDimensoes() {
        return dimensoes;
    }

    public void SetDimensoes(String dimensoes) {
        this.dimensoes = dimensoes;
    }

    public double GetPeso() {
        return peso;
    }

    public void SetPeso(double peso) {
        this.peso = peso;
    }

    public void PrintLivro(){
        // printa as informacoes do livro
    }
}

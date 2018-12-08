package br.caf.ufv.biblioteca.Controle;

import br.caf.ufv.biblioteca.Dados.Livro;

import java.util.*;
import java.io.*;

public class GestaoDeLivros {
    private HashMap<Integer, Livro> listaLivros = new HashMap<>();

    public HashMap<Integer, Livro> getListaLivros() {
        return listaLivros;
    }

    public GestaoDeLivros ()throws IOException{
        File file = new File("../POO1/src/br/caf/ufv/biblioteca/Texts/Livros.txt");
        Scanner s = new Scanner(file);
        int[] dim = new int[3];
        s.useDelimiter(";\\s*");
        while (s.hasNext()) {
            Livro book = new Livro();
            book.SetTitulo(s.next());
            book.SetAutores(s.next());
            book.SetEditora(s.next());
            book.SetEdicao(s.nextInt());
            book.SetIdentificador(s.nextInt());
            book.SetQuantidadeExemplares(s.nextInt());
            book.SetDimensoes(s.next());
            book.SetPeso(s.nextDouble());
            listaLivros.put(book.GetIdentificador(), book);
        }
    }

    public ArrayList<Livro> PesquisaLivro (String nome){
        ArrayList<Livro> pesquisa = new ArrayList<>();
        for (int key: this.listaLivros.keySet()) {
            if (this.listaLivros.get(key).GetTitulo().contains(nome)){
                pesquisa.add(this.listaLivros.get(key));
            }
        }

        return pesquisa;
    }
}

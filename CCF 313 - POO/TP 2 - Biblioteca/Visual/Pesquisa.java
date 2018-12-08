package br.caf.ufv.biblioteca.Visual;

import br.caf.ufv.biblioteca.Dados.Livro;
import br.caf.ufv.biblioteca.Controle.Biblioteca;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Pesquisa {
    private JTextField areaPesquisa;
    private JButton botaoPesquisar;
    private JLabel labelPesquisa;
    private JLabel labelResultado;
    private JPanel panelPesquisa;
    private JScrollPane hehehe;
    private JTextArea result;

    private JFrame framePesquisa;

    public JFrame getFramePesquisa() {
        return framePesquisa;
    }

    public Pesquisa(Biblioteca lib) {
        framePesquisa = new JFrame();
        result = new JTextArea();
        hehehe.setViewportView(result);
        framePesquisa.add(panelPesquisa);

        botaoPesquisar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                for(Livro S : lib.pesquisa(areaPesquisa.getText().trim())){

                    result.append(S.GetTitulo()+"\n--Autores:"+ S.GetAutores() + "\n--Editora:" + S.GetEditora()+
                            "\n--Edição:"+S.GetEdicao() + "\n--ID:"+S.GetIdentificador() + "\n--Quantidade disponivel:"+
                            S.GetQuantidadeExemplares()+"\n--Dimensões:"+S.GetDimensoes()+"\n--Peso:"+S.GetPeso() + "\n =======================\n");
                }


            }
        });
    }
}

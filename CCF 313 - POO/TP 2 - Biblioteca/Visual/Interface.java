package br.caf.ufv.biblioteca.Visual;

import br.caf.ufv.biblioteca.Controle.Biblioteca;

import javax.swing.*;
import java.awt.event.*;
import java.io.IOException;

public class Interface {
    private JPanel Principal;
    private JButton Login;
    private JButton Pesquisa;
    private JButton Consulta;
    private JLabel Biblioteca_UFV;
    private JTextField acesso;
    private JButton botaoEmprestimo;
    private Login loginUI;
    private Pesquisa pesquisaUI;
    private Consulta consultaUI;
    private TelaEmprestimo emprestimoUI;
    private JFrame headFrame;

    public Interface(Biblioteca lib)throws IOException{
        headFrame = new JFrame();
        loginUI = new Login(lib, acesso, Consulta, botaoEmprestimo);
        pesquisaUI = new Pesquisa(lib);
        emprestimoUI = new TelaEmprestimo(lib);
        consultaUI = new Consulta(lib);
        botaoEmprestimo.setEnabled(false);
        Consulta.setEnabled(false);
        acesso.setText("Nao Autenticado!");

        Login.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) { ShowLogin(); }
        });

        Pesquisa.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ShowPesquisa();
            }
        });

        botaoEmprestimo.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                ShowEmprestimo();
            }
        });

        Consulta.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                for(String consulta : lib.ConsultaEmprestimos()){
                    consultaUI.getResultado().append(consulta);
                }
                ShowConsulta();
            }
        });

        headFrame.add(Principal);
        ShowHeadFrame();
    }
    private void ShowHeadFrame(){
        headFrame.setBounds(100, 100, 420, 320);
        headFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        headFrame.setVisible(true);
    }

    private void ShowLogin(){
        loginUI.getLoginFrame().setBounds(100, 100, 400, 200);
        loginUI.getLoginFrame().setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        loginUI.getLoginFrame().setVisible(true);
    }

    private void ShowPesquisa(){
        pesquisaUI.getFramePesquisa().setBounds(100, 100, 320, 400);
        pesquisaUI.getFramePesquisa().setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        pesquisaUI.getFramePesquisa().setVisible(true);
    }

    private void ShowEmprestimo(){
        emprestimoUI.getEmprestimoFrame().setBounds(100, 100, 250, 170);
        emprestimoUI.getEmprestimoFrame().setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        emprestimoUI.getEmprestimoFrame().setVisible(true);
    }

    private void ShowConsulta(){
        consultaUI.getFrameConsulta().setBounds(100, 100, 320, 400);
        consultaUI.getFrameConsulta().setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        consultaUI.getFrameConsulta().setVisible(true);
    }
}
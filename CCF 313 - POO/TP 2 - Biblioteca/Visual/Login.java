package br.caf.ufv.biblioteca.Visual;

import br.caf.ufv.biblioteca.Controle.Biblioteca;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Login {
    private JPasswordField campoSenha;
    private JTextField campoMatricula;
    private JButton confirmaButton;
    private JLabel labelMatricula;
    private JLabel labelSenha;
    private JPanel panelLogin;
    private JLabel iconUFV;
    private JButton sairButton;
    private JFrame LoginFrame;

    public Login(Biblioteca lib, JTextField acesso, JButton Consulta, JButton botaoEmprestimo){
        this.LoginFrame = new JFrame();
        LoginFrame.add(panelLogin);
        confirmaButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int mat = Integer.parseInt(campoMatricula.getText().trim());
                String senha = campoSenha.getText();
                LoginFrame.dispose();
                lib.login(mat, senha);
                if (lib.isUsuarioAutenticado()){
                    acesso.setText("Autenticado!");
                    botaoEmprestimo.setEnabled(true);
                    Consulta.setEnabled(true);
                }else{ acesso.setText("Nao Autenticado!");
                    botaoEmprestimo.setEnabled(false);
                    Consulta.setEnabled(false);}
            }
        });
        sairButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                LoginFrame.dispose();
                acesso.setText("Nao Autenticado!");
                botaoEmprestimo.setEnabled(false);
                Consulta.setEnabled(false);
            }
        });
    }

    public JFrame getLoginFrame() {
        return LoginFrame;
    }
}

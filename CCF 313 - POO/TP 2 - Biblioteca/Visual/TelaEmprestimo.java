package br.caf.ufv.biblioteca.Visual;

import br.caf.ufv.biblioteca.Controle.Biblioteca;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TelaEmprestimo {
    private JTextField nomeLivro;
    private JButton emprestarBotao;
    private JLabel Emprestimolabel;
    private JPanel emprestimoPanel;
    private JFrame emprestimoFrame;


    public JFrame getEmprestimoFrame() {
        return emprestimoFrame;
    }

    public TelaEmprestimo(Biblioteca lib) {
        emprestimoFrame = new JFrame();
        emprestarBotao.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(lib.FazerEmprestimo(nomeLivro.getText()))
                    JOptionPane.showMessageDialog(null,"Emprestimo efetivado com sucesso!");
                else JOptionPane.showMessageDialog(null,"Emprestimo nao efetivado!");
            }
        });
        emprestimoFrame.add(emprestimoPanel);
    }
}

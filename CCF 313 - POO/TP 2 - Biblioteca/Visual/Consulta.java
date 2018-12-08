package br.caf.ufv.biblioteca.Visual;

import br.caf.ufv.biblioteca.Controle.Biblioteca;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Consulta {
    private JTextArea resultado;
    private JPanel panelConsulta;
    private JTextField devolverTexto;
    private JButton botaoDevolver;
    private JLabel labelConsulta;
    private JLabel labelDevolver;
    private JFrame frameConsulta;

    public JTextArea getResultado() {
        return resultado;
    }

    public Consulta(Biblioteca lib) {
        frameConsulta = new JFrame();
        frameConsulta.add(panelConsulta);
        botaoDevolver.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(lib.EntregaEmprestimo(devolverTexto.getText().trim()))
                    JOptionPane.showMessageDialog(null,"Devolucao efetivado com sucesso!");
                else JOptionPane.showMessageDialog(null,"Devolucao nao efetivado!");
                resultado.setText("");
                for(String consulta : lib.ConsultaEmprestimos()){
                    resultado.append(consulta);
                }
            }
        });

    }

    public JFrame getFrameConsulta() {
        return frameConsulta;
    }
}

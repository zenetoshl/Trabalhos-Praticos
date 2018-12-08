package br.ufv.caf.poo;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TelaInicial {
    private JPanel panelInicial;
    private JButton iniciarButton;
    private JButton sairButton;
    private JLabel Imagem;
    private JFrame headFrame;
    private TelaBingo telaBingo;

    public TelaInicial(Bingo bingo) {
        headFrame = new JFrame();
        headFrame.add(panelInicial);
        telaBingo = new TelaBingo(bingo);
        ShowTelaInicial();
        iniciarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                telaBingo.getNome1().setText(bingo.getPlayer1().getNome());
                telaBingo.getNome2().setText(bingo.getPlayer2().getNome());
                ShowBingo();
            }
        });
        sairButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                headFrame.dispose();
            }
        });
    }

    private void ShowTelaInicial(){
        headFrame.setBounds(100, 100, 300, 260);
        headFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        headFrame.setVisible(true);
    }

    private void ShowBingo(){
        telaBingo.getFrame().setBounds(100, 100, 570, 250);
        telaBingo.getFrame().setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        telaBingo.getFrame().setVisible(true);
    }
}

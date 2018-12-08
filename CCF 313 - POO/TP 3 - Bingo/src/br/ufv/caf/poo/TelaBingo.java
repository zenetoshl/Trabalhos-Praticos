package br.ufv.caf.poo;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.util.LinkedList;
import java.util.Random;

public class TelaBingo {
    private JPanel panel1;
    private JButton gerarNumeroButton;
    private JButton sairButton;
    private JButton resetarButton;
    private JLabel bingo1Text;
    private JLabel bingo2Text;
    private JLabel nome2;
    private JLabel nome1;
    private JLabel numeroGerado;
    private JLabel CartelaP1n2;
    private JLabel CartelaP2n2;
    private JFrame frame;

    public JLabel getNome1() {
        return nome1;
    }

    public JLabel getNome2() {
        return nome2;
    }


    public TelaBingo(Bingo bingo) {
        Random rand = new Random();
        frame = new JFrame();
        frame.add(panel1);
        nome1.setText(bingo.getPlayer1().getNome());
        nome2.setText(bingo.getPlayer2().getNome());
        bingo1Text.setText(bingo.ToStringPlayer1(0));
        bingo2Text.setText(bingo.ToStringPlayer2(0));
        CartelaP1n2.setText(bingo.ToStringPlayer1(1));
        CartelaP2n2.setText(bingo.ToStringPlayer2(1));
        gerarNumeroButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int num, resultado;
                num = bingo.gerarNumero();
                numeroGerado.setText(""+num);
                resultado = bingo.Jogar(num);
                if(resultado != 0){
                    if(resultado == 3){
                        JOptionPane.showMessageDialog(null, "Jogadores empataram!");
                    }else if ( resultado == 1) JOptionPane.showMessageDialog(null, nome1.getText()+" venceu!!");
                    else if (resultado == 2) JOptionPane.showMessageDialog(null, nome2.getText()+" venceu!!");
                    bingo.Reset();
                    numeroGerado.setText("0");
                }

                bingo1Text.setText(bingo.ToStringPlayer1(0));
                bingo2Text.setText(bingo.ToStringPlayer2(0));
                CartelaP1n2.setText(bingo.ToStringPlayer1(1));
                CartelaP2n2.setText(bingo.ToStringPlayer2(1));

            }
        });
        resetarButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                bingo.Reset();
                numeroGerado.setText("0");
                bingo1Text.setText(bingo.ToStringPlayer1(0));
                bingo2Text.setText(bingo.ToStringPlayer2(0));
                CartelaP1n2.setText(bingo.ToStringPlayer1(1));
                CartelaP2n2.setText(bingo.ToStringPlayer2(1));
            }
        });
        sairButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                frame.dispose();
            }
        });
    }

    public JFrame getFrame() {
        return frame;
    }
}

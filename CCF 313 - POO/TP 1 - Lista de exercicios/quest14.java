package com.company;

import java.util.Scanner;

public class quest14 {

    public static void main(String[] args) {
	// questao 14:
        double valorT = 50;
        double minT = 100, minBonus = 50, min;
        Scanner s = new Scanner(System.in);
        String op;
        dance:
        while(true){
            System.out.print(("Operação: "));
            op = s.next();
            switch (op){
                case "f":
                    System.out.print("Minutos: ");
                    min = s.nextDouble();
                    min = min/2;
                    minT = minT - min;
                    if(minT < 0){
                        valorT = valorT + (-0.65)*minT;
                        minT = 0;
                    }
                    break;
                case "o":
                    System.out.print("Minutos: ");
                    min = s.nextDouble();
                    minT = minT - min;
                    if(minT < 0){
                        valorT = valorT + (-0.65)*minT;
                        minT = 0;
                    }
                    break;
                case "v":
                    System.out.print("Minutos: ");
                    min = s.nextDouble();
                    minBonus = minBonus - min;
                    if (minBonus < 0){
                        minT = minT + minBonus;
                        if(minT < 0){
                            valorT = valorT + (-0.65)*minT;
                            minT = 0;
                        }
                        minBonus = 0;
                    }
                    break;
                default:
                    break dance;
            }
            System.out.println("saldo: " + minT + "    saldo bonus: " + minBonus);
            System.out.println("Valor a pagar: " + valorT);
        }
    }
}

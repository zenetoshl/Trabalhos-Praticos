package com.company;
import java.util.Scanner;

public class quest6 {

    public static void main(String[] args) {
	// questao 6:
        int ind1,ind2,dia,mes,ano;
        Scanner s = new Scanner(System.in);
        String aniversario= s.next();
        ind1 = aniversario.indexOf("/");

        String Buff = aniversario.substring((ind1+1));
        ind2 = Buff.indexOf("/");
        String D = aniversario.substring(0,ind1);
        String M = Buff.substring(0,(ind2));
        String A = aniversario.substring((ind2+ind1+2));
        dia = Integer.parseInt(D);
        mes = Integer.parseInt(M);
        ano = Integer.parseInt(A);
        System.out.println(M);
        switch (mes) {
            case 1:
                System.out.println("Janeiro");
                if (dia > 31)
                    System.out.println("entrada invalida! (dia)");
                else
                    System.out.println("aniversario valido!");
                break;
            case 2:
                System.out.println("fevereiro");
                if (dia > 29)
                    System.out.println("entrada invalida! (dia)");
                else{
                    if (ano%4 == 0 && ano%100 != 0){
                        System.out.println("aniversario valido!");
                    }
                    else{
                        if (dia > 28)
                            System.out.println("entrada invalida! (dia)");
                        else
                            System.out.println("aniversario valido!");
                    }
                }
                break;
            case 3:
                System.out.println("março");
                if (dia > 31)
                    System.out.println("entrada invalida! (dia)");
                else
                    System.out.println("aniversario valido!");
                break;
            case 4:
                System.out.println("abril");
                if (dia > 30)
                    System.out.println("entrada invalida! (dia)");
                else
                    System.out.println("aniversario valido!");
                break;
            case 5:
                System.out.println("maio");
                if (dia > 31)
                    System.out.println("entrada invalida! (dia)");
                else
                    System.out.println("aniversario valido!");
                break;
            case 6:
                System.out.println("junho");
                if (dia > 30)
                    System.out.println("entrada invalida! (dia)");
                else
                    System.out.println("aniversario valido!");
                break;
            case 7:
                System.out.println("julho");
                if (dia > 31)
                    System.out.println("entrada invalida! (dia)");
                else
                    System.out.println("aniversario valido!");
                break;
            case 8:
                System.out.println("agosto");
                if (dia > 31)
                    System.out.println("entrada invalida! (dia)");
                else
                    System.out.println("aniversario valido!");
                break;
            case 9:
                System.out.println("setembro");
                if (dia > 30)
                    System.out.println("entrada invalida! (dia)");
                else
                    System.out.println("aniversario valido!");
                break;
            case 10:
                System.out.println("outubro");
                if (dia > 31)
                    System.out.println("entrada invalida! (dia)");
                else
                    System.out.println("aniversario valido!");
                break;
            case 11:
                System.out.println("novembro");
                if (dia > 30)
                    System.out.println("entrada invalida! (dia)");
                else
                    System.out.println("aniversario valido!");
                break;
            case 12:
                System.out.println("dezembro");
                if (dia > 31)
                    System.out.println("entrada invalida! (dia)");
                else
                    System.out.println("aniversario valido!");
                break;
            default:
                System.out.println("entrada invalida (mes)");
        }

    }
}

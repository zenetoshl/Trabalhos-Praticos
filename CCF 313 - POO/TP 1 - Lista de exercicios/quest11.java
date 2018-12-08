package com.company;


import java.util.Scanner;

public class quest11 {

    public static void main(String[] args) {
	// questao 11:
        int ind1, result = -1;
        String buff;
        Scanner s = new Scanner(System.in);

        System.out.println("digite uma linha de comando: ");

        String comando= s.nextLine();
        ind1 = comando.indexOf(" ");
        String L1 = comando.substring(0,ind1);
        buff = comando.substring(ind1+1);
        ind1 = buff.indexOf(" ");
        String N1 = buff.substring(0,ind1);
        buff = buff.substring(ind1+1);
        ind1 = buff.indexOf(" ");
        String L2 = buff.substring(0,ind1);
        String N2 = buff.substring(ind1+1);

        int A = Integer.parseInt(N1);
        int B = Integer.parseInt(N2);
        switch (L1){
            case "MULTIPLICA":
                result = A*B;
                System.out.println("RESPOSTA: "+result);
                break;
            case "SUBTRAI":
                result = A-B;
                System.out.println("RESPOSTA: "+result);
                break;
            case "SOMA":
                result = A+B;
                System.out.println("RESPOSTA: "+result);
                break;
            case "DIVIDE":
                result = A/B;
                System.out.println("RESPOSTA: "+result);
                break;
            default:
                System.out.println("entrada invalida!");
        }

    }
}

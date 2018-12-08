package com.company;
import java.util.Scanner;

public class quest3 {

    public static void main(String[] args) {
	// questao 3:
        double num, den;
        int ind;
        Scanner s = new Scanner(System.in);
        System.out.println("digite o numero racional no seguinte formato (N/D): ");
        String frac = s.next();
        String frac2;
        ind = frac.indexOf("/");
        frac2 = frac.substring(0,(ind));
        frac = frac.substring(ind+1);
        den = Double.parseDouble(frac);
        num = Double.parseDouble(frac2);
        if(den != 0)
            System.out.println("Num real: "+ (num/den));
        else
            System.out.println("Erro, entrada invalida!");
    }
}

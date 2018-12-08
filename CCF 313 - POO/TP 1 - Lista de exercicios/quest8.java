package com.company;
import java.util.Scanner;

public class quest8 {

    public static void main(String[] args) {
	// questao 8:
        int soma = 0, prod = 1;
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();

        for (int i = 0; i < n;i++){
            int x = s.nextInt();
            soma+=x;
            prod = prod * x;
        }
        System.out.println("soma: "+ soma+ " produto: "+prod);
    }
}
